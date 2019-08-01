/* (c) 2016 Tenshiko + MB	*/
/* Made for bitbitjam 2016	*/

#include "system.h"

struct GfxBase *gfx = NULL;
struct Custom *hardware = (struct Custom*)0xdff000;
struct CIA *cia = (struct CIA*)0xbfe001;

/* Cached system pointers */
UWORD SystemInts;
UWORD SystemDMA;
ULONG Level2Vector;
ULONG Level3Vector;

/* Takes control over the system */
void take_system()
{
	/*Save current interrupts and DMA settings so we can restore them upon exit. */
	SystemInts = hardware->intenar;
	SystemDMA = hardware->dmaconr;

	/*Kill all interrupts and DMA. */
	hardware->intena = 0x7fff;
	hardware->dmacon = 0x7fff;

	/*Also kill interrupts at the CIA controller itself, which handles keyboard interrupts among others, just to be on the safe side. */
	cia->ciaicr = 0x7f;

	/*Save current vectors for level 2 and 3 interrupts (those dealing with keyboard and other I/O and with the video hardware), so that we can replace them with new routines. */
	Level2Vector = *(ULONG*)0x68;
	Level3Vector = *(ULONG*)0x6c;
}

/* Releases control over the system */
void free_system()
{
	/*Restore level 2 and 3 interrupt vectors. */
	*(ULONG*)0x68 = Level2Vector;
	*(ULONG*)0x6c = Level3Vector;

	/*Restore system copper list(s). */
	hardware->cop1lc = (ULONG)gfx->copinit;
	hardware->cop2lc = (ULONG)gfx->LOFlist;

	/*Restore all interrupts and DMA settings. */
	hardware->intena = (SystemInts | 0xc000);
	hardware->dmacon = (SystemDMA | 0x8100);
	cia->ciaicr = 0x9b;
}

/* Take control of the system and open libraries */
BOOL init_system()
{
	take_system();

	if (!(gfx = (struct GfxBase*)OldOpenLibrary("graphics.library"))) return FALSE;

	return TRUE;
}

/* Free libraries and return control over the system */
void cleanup_system()
{
	if (gfx) CloseLibrary(gfx);

	free_system();
}

/* Check for joy button */
BOOL fire_down()
{
	return (cia->ciapra & (1 << 7)) == 0;
}
