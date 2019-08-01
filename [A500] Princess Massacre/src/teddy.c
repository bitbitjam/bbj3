/* (c) 2016 Tenshiko + MB	*/
/* Made for bitbitjam 2016	*/

#include <exec/types.h>
#include "princess.h"
#include "teddy.h"
#include "system.h"
#include "graphics.h"
#include <stdio.h>
#include <stdlib.h>

extern UBYTE __chip terrain[320 * 256 * 4 / 8];
extern char block_map[];
extern UBYTE __chip offscreen[320 * 256 * 4 / 8];

void move_towards_princess(struct Teddy *self, struct Princess *princess, short *tx, short *ty, short *dx, short *dy);
void move_forced(struct Teddy *forced, short *tx, short *ty);
BOOL collides_with_background(struct Teddy *self, struct Teddy *teddies, short tx, short ty, BOOL check_teddies);

UWORD __chip g_teddy_idle[] =
{
	#include "data/teddy_idle_0.BPL_UShort.INL"
	#include "data/teddy_idle_1.BPL_UShort.INL"
	#include "data/teddy_idle_2.BPL_UShort.INL"
	#include "data/teddy_idle_3.BPL_UShort.INL"
	#include "data/teddy_idle_4.BPL_UShort.INL"
	#include "data/teddy_idle_5.BPL_UShort.INL"
	#include "data/teddy_idle_6.BPL_UShort.INL"
	#include "data/teddy_idle_7.BPL_UShort.INL"
};
UWORD __chip g_teddy_walk[] =
{
	#include "data/teddy_walk_0.BPL_UShort.INL"
	#include "data/teddy_walk_1.BPL_UShort.INL"
	#include "data/teddy_walk_2.BPL_UShort.INL"
	#include "data/teddy_walk_3.BPL_UShort.INL"
	#include "data/teddy_walk_4.BPL_UShort.INL"
	#include "data/teddy_walk_5.BPL_UShort.INL"
	#include "data/teddy_walk_6.BPL_UShort.INL"
	#include "data/teddy_walk_7.BPL_UShort.INL"
	#include "data/teddy_walk_8.BPL_UShort.INL"
	#include "data/teddy_walk_9.BPL_UShort.INL"
	#include "data/teddy_walk_10.BPL_UShort.INL"
	#include "data/teddy_walk_11.BPL_UShort.INL"
	#include "data/teddy_walk_12.BPL_UShort.INL"
	#include "data/teddy_walk_13.BPL_UShort.INL"
	#include "data/teddy_walk_14.BPL_UShort.INL"
	#include "data/teddy_walk_15.BPL_UShort.INL"
	#include "data/teddy_walk_16.BPL_UShort.INL"
	#include "data/teddy_walk_17.BPL_UShort.INL"
	#include "data/teddy_walk_18.BPL_UShort.INL"
	#include "data/teddy_walk_19.BPL_UShort.INL"
	#include "data/teddy_walk_20.BPL_UShort.INL"
	#include "data/teddy_walk_21.BPL_UShort.INL"
	#include "data/teddy_walk_22.BPL_UShort.INL"
	#include "data/teddy_walk_23.BPL_UShort.INL"
	#include "data/teddy_walk_24.BPL_UShort.INL"
	#include "data/teddy_walk_25.BPL_UShort.INL"
	#include "data/teddy_walk_26.BPL_UShort.INL"
	#include "data/teddy_walk_27.BPL_UShort.INL"
	#include "data/teddy_walk_28.BPL_UShort.INL"
	#include "data/teddy_walk_29.BPL_UShort.INL"
	#include "data/teddy_walk_30.BPL_UShort.INL"
	#include "data/teddy_walk_31.BPL_UShort.INL"
};
UWORD __chip blank[(16 / 8 + 2) * 16 / 2];

void render_teddy(struct Teddy *teddy)
{
	int p;

	static const int bitplane_words = (16 / 16 + 1) * 16;	/* 16x16 bits plus one word per line */
	const int bob_words = bitplane_words * 3;		/* 2 bitplanes per bob + mask */

	short x = teddy->x / 10 - 8;
	short y = teddy->y / 10 - 8;

	hardware->bltcon1 = ((x % 16) << 12);
	hardware->bltcon0 = ((x%16)<<12) | 0xfca;
	/* hardware->bltcon0 = ((x % 16) << 12) | 0x9f0; */
	hardware->bltamod = 0;
	hardware->bltbmod = 0;
	hardware->bltcmod = (320 - 32) / 8;
	hardware->bltdmod = (320 - 32) / 8;

	/* Blit first 2 planes */
	for (p = 0; p<2; p++)
	{
		hardware->bltcpt = offscreen + y*(320 / 8) + x / 8 + 320 * 256 * (p) / 8;
		hardware->bltdpt = offscreen + y*(320 / 8) + x / 8 + 320 * 256 * (p) / 8;
		hardware->bltbpt  = g_teddy_walk + teddy->direction*bob_words*4 + teddy->frame*bob_words + p*bitplane_words;
		hardware->bltapt  = g_teddy_walk + teddy->direction*bob_words*4 + teddy->frame*bob_words + 2*bitplane_words;
		hardware->bltsize = (32 / 16) + (16 << 6);
	}
	/* Blit second 2 planes */
	for (p = 2; p<4; p++)
	{
		hardware->bltcpt = offscreen + y*(320 / 8) + x / 8 + 320 * 256 * (p) / 8;
		hardware->bltdpt = offscreen + y*(320 / 8) + x / 8 + 320 * 256 * (p) / 8;
		hardware->bltbpt = blank;
		hardware->bltapt = g_teddy_walk + teddy->direction*bob_words * 4 + teddy->frame*bob_words + 2 * bitplane_words;
		hardware->bltsize = (32 / 16) + (16 << 6);
	}
}

void clear_teddy(struct Teddy *teddy);

void reset_teddy(struct Teddy *teddy, struct Teddy *teddies)
{
	clear_teddy(teddy);
	teddy->x = teddy->startx;
	teddy->y = teddy->starty;
	teddy->frame = 0;
	teddy->locked = FALSE;
	teddy->direction = 0;
	teddy->forcex = ((rand()%2)==0) ? -1 : 1;
	teddy->forcey = 0;

	teddy->x = rand() % 3200;
	teddy->y = rand() % 2400;
	while (collides_with_background(teddy, teddies, teddy->x, teddy->y, TRUE))
	{
		teddy->x = rand() % 3200;
		teddy->y = rand() % 2400;
	}
}

#if 1
void clear_teddy(struct Teddy *teddy)
{
	int p;
	short tx = teddy->x / 10 - 8;
	short ty = teddy->y / 10 - 8;

	/* Clear old bob */
	hardware->bltcon0 = 0x9f0;
	hardware->bltamod = (320 - 32) / 8;
	hardware->bltbmod = 0;
	hardware->bltcmod = (320 - 32) / 8;
	hardware->bltdmod = (320 - 32) / 8;

	/* Clear 4 planes */
	for (p = 0; p<4; p++)
	{
		hardware->bltdpt = offscreen + ty*(320 / 8) + tx / 8 + 320 * 256 * (p) / 8;
		hardware->bltapt = terrain + ty*(320 / 8) + tx / 8 + 320 * 256 * (p) / 8;
		hardware->bltsize = (32 / 16) + (16 << 6);
	}
}
#else
void clear_teddy(struct Teddy *teddy)
{
	int p;

	static const int bitplane_words = (16 / 16 + 1) * 16;	/* 16x16 bits plus one word per line */
	const int bob_words = bitplane_words * 3;		/* 2 bitplanes per bob + mask */

	short x = teddy->x / 10 - 8;
	short y = teddy->y / 10 - 8;

	hardware->bltcon1 = ((x % 16) << 12);
	hardware->bltcon0 = ((x % 16) << 12) | 0xfca;
	/* hardware->bltcon0 = ((x % 16) << 12) | 0x9f0; */
	hardware->bltamod = 0;
	hardware->bltbmod = 0;
	hardware->bltcmod = (320 - 32) / 8;
	hardware->bltdmod = (320 - 32) / 8;

	/* Blit first 2 planes */
	for (p = 0; p<4; p++)
	{
		hardware->bltcpt = offscreen + y*(320 / 8) + x / 8 + 320 * 256 * (p) / 8;
		hardware->bltdpt = offscreen + y*(320 / 8) + x / 8 + 320 * 256 * (p) / 8;
		hardware->bltbpt = terrain + y*(320 / 8) + x / 8 + 320 * 256 * (p) / 8;
		hardware->bltapt = g_teddy_walk + teddy->direction*bob_words * 4 + teddy->frame*bob_words + 2 * bitplane_words;
		hardware->bltsize = (32 / 16) + (16 << 6);
	}
}
#endif

void update_teddy(struct Teddy *teddies, int index, struct Princess *princess)
{
	static int tick = 0;
	short tx, ty, pdx, pdy;
	int i;
	struct Teddy *self = teddies + index;
	if (self->locked) return;

	tx = self->x;
	ty = self->y;

	move_towards_princess(self, princess, &tx, &ty, &pdx, &pdy);
	if (collides_with_background(self, teddies, tx, ty, TRUE))
	{
		BOOL new_force = FALSE;
		if (abs(pdx) > abs(pdy))
		{
			if (self->forcey == 0) new_force = TRUE;
		}
		else if (self->forcex == 0) new_force = TRUE;

		move_forced(self, &tx, &ty);
		if (new_force || collides_with_background(self, teddies, tx, ty, FALSE))
		{
			if (abs(pdx) > abs(pdy))
			{
				self->forcex = 0;
				self->forcey = ((rand() % 2) == 0) ? -1 : 1;
			}
			else
			{
				self->forcex = ((rand() % 2) == 0) ? -1 : 1;
				self->forcey = 0;
			}
		}
	}

	/* Make sure enemies don't overlap with each other */
#if 0
	for (i = 0; i < 4; i++)
	{
		struct Teddy *other = teddies + i;
		short ox = other->x;
		short oy = other->y;
		short dx = abs(ox - tx);
		short dy = abs(oy - ty);

		if (i == index) continue;
		if (other->locked) continue;
		if (dx < 120 && dy < 120)
		{
			if (dx < abs(ox - self->x)) tx = self->x;
			if (dy < abs(oy - self->y)) ty = self->y;
		}
	}
#endif

	{
		self->x = tx;
		self->y = ty;
	}

	/* Update animation */
	if (tick++ >= 8)
	{
		tick = 0;
		self->frame++;
	}
	self->frame = self->frame % 4;
}

BOOL collides_with_background(struct Teddy *self, struct Teddy *teddies, short tx, short ty, BOOL check_teddies)
{
	int i;
	short   left = (tx - 40) / 160;
	short  right = (tx + 40) / 160;
	short    top = (ty - 40) / 160;
	short bottom = (ty + 40) / 160;

	if (tx < 80 || tx > 3120 || ty < 80 || ty > 3120) return TRUE;
	if (block_map[   top * 20 +  left] == 'X' || block_map[bottom * 20 +  left] == 'X') return TRUE;
	if (block_map[   top * 20 + right] == 'X' || block_map[bottom * 20 + right] == 'X') return TRUE;
	if (block_map[   top * 20 +  left] == 'X' || block_map[   top * 20 + right] == 'X') return TRUE;
	if (block_map[bottom * 20 +  left] == 'X' || block_map[bottom * 20 + right] == 'X') return TRUE;

	if (check_teddies)
	{
		for (i = 0; i < 4; i++)
		{
			struct Teddy *other = teddies + i;
			short ox = other->x;
			short oy = other->y;
			short dx = abs(ox - tx);
			short dy = abs(oy - ty);

			if (other == self) continue;
			if (other->locked) continue;
			if (dx < 120 && dy < 120)
			{
				return TRUE;
			}
		}
	}

	return FALSE;
}

void move_towards_princess(struct Teddy *self, struct Princess *princess, short *tx, short *ty, short *dx, short *dy)
{
	int i;
	short m;
	short x = self->x / 10;
	short y = self->y / 10;
	*dx = princess->x - x;
	*dy = princess->y - y;
	m = (abs(*dx) > abs(*dy)) ? abs(*dx) : abs(*dy);

	if (m == 0) m = 1;

	*tx = self->x + (*dx) * 10 / m * 7 / 10;
	*ty = self->y + (*dy) * 10 / m * 7 / 10;
}

void move_forced(struct Teddy *self, short *tx, short *ty)
{
	*tx = self->x;
	*ty = self->y;
	*tx += self->forcex * 7;
	*ty += self->forcey * 7;
}
