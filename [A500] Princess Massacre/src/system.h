/* (c) 2016 Tenshiko + MB	*/
/* Made for bitbitjam 2016	*/

#include <intuition/intuition.h>
#include <graphics/gfxbase.h>
#include <proto/intuition.h>
#include <hardware/custom.h>
#include <hardware/cia.h>
#include <exec/memory.h>

extern struct GfxBase *gfx;
extern struct DosLibrary *dos;
extern struct Custom *hardware;
extern struct CIA *cia;

BOOL init_system();
void cleanup_system();
BOOL fire_down();
