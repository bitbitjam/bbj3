/* (c) 2016 Tenshiko + MB	*/
/* Made for bitbitjam 2016	*/

#include <exec/types.h>
#include <stdio.h>
#include <string.h>
#include "system.h"
#include "graphics.h"

#define diwstrt 0x8e
#define diwstop 0x90
#define ddfstrt 0x92
#define ddfstop 0x94
#define INTREQ 0x9c
#define bplpt 0xe0
#define bplcon0 0x100
#define bplcon1 0x102
#define bplcon2 0x104
#define bpl1mod 0x108
#define bpl2mod 0x10a
#define sprpt 0x120
#define color 0x180
#define fmode 0x1fc

UBYTE __chip backbuffer[320 * 256 * 4 / 8];
ULONG __chip blank_sprite[] =
{
	0x20002100, 0, 0
};

/* Screen starts @ 0x2c07 */
UWORD __chip copper_list[] =
{
	fmode, 0,			/* Slow fetch mode for AGA compatibility */
	bplcon0, 0x0200,	/* No bitplanes, colour */
	bplcon1, 0,			/* Disable blitting */
	diwstrt, 0x2c81,	/* Display window start */
	diwstop, 0x2cc1,	/* Display window end */
	ddfstrt, 0x0038,	/* DMA start */
	ddfstop, 0x00d0,	/* DMA stop */
	bpl1mod, 0,
	bpl2mod, 0,

	/* Bitplanes */
	bplpt + 0, 0, bplpt + 2, 0,		/* Pointer to first bitplane */
	bplpt + 4, 0, bplpt + 6, 0,		/* Pointer to second bitplane */
	bplpt + 8, 0, bplpt + 10, 0,		/* Pointer to third bitplane */
	bplpt + 12, 0, bplpt + 14, 0,		/* Pointer to fourth bitplane */
	bplpt + 16, 0, bplpt + 18, 0,		/* Pointer to fifth bitplane */
	bplpt + 20, 0, bplpt + 22, 0,		/* Pointer to sixth bitplane */

	/* Sprites */
	sprpt +  0, 0, sprpt +  2, 0,		/* Pointer to first sprite */
	sprpt +  4, 0, sprpt +  6, 0,		/* Pointer to second sprite */
	sprpt +  8, 0, sprpt + 10, 0,		/* Pointer to second sprite */
	sprpt + 12, 0, sprpt + 14, 0,		/* Pointer to second sprite */
	sprpt + 16, 0, sprpt + 18, 0,		/* Pointer to second sprite */
	sprpt + 20, 0, sprpt + 22, 0,		/* Pointer to second sprite */
	sprpt + 24, 0, sprpt + 26, 0,		/* Pointer to second sprite */
	sprpt + 28, 0, sprpt + 30, 0,		/* Pointer to second sprite */

	/* Palette */
	#include "data/terrain.COP_UShort.INL"
	#include "data/princess_walk_0.COP_UShort.INL"
	,

	0x2b07,0xfffe,		/* Wait for screen start */
	bplcon0, 0x4200,	/* 4 bitplanes, colour */

	/* Toggle interrupt flag when we reach line 240 */
	/*0xf001,0xff00,INTREQ,0x8010,*/

	0xffdf, 0xfffe,		/* Wait for... */
	0x0c07,0xfffe,		/* ...screen end */
	/*color, 0xf00,*/
	INTREQ,0x8010,		/* Toggle interrupt */

	/* Copper end */
	0xffff, 0xfffe,
};

BOOL init_graphics()
{
	int i;

	/* Clear backbuffer */
	memset(backbuffer, 0, sizeof(backbuffer));

	/* Setup copper */
	for (i = 0; i<6; i++)
	{
		copper_list[19 + i * 4] = HIWORD((int)(backbuffer + 320 * 256 * i / 8));
		copper_list[21 + i * 4] = LOWORD((int)(backbuffer + 320 * 256 * i / 8));
	}

	/* Clear unused sprites */
	for (i = 0; i<6; i++)
	{
		copper_list[51 + i * 4] = HIWORD((int)(blank_sprite));
		copper_list[53 + i * 4] = LOWORD((int)(blank_sprite));
	}

	/* Set copper */
	hardware->bltafwm = 0xffff;
	hardware->bltalwm = 0xffff;
	hardware->cop1lc = (ULONG)copper_list;
	hardware->copjmp1 = 0;

	/* Turn interrupts back on */
	hardware->dmacon = 0x87e0;
	hardware->intreq = 0x7fff;
	hardware->intreq = 0x7fff;
	hardware->clxcon = 0x1fc4;

	return TRUE;
}

void cleanup_graphics()
{
}

void waitline223()
{
	while (!(hardware->intreqr & 16));
	hardware->intreq = 16;
}
