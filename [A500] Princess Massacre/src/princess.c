/* (c) 2016 Tenshiko + MB	*/
/* Made for bitbitjam 2016	*/

#include <exec/types.h>
#include "princess.h"
#include "graphics.h"
#include <stdio.h>

UWORD __chip g_princess_walk[] =
{
	#include "data/princess_walk_0.ASP_UShort.INL"
	,
	#include "data/princess_walk_1.ASP_UShort.INL"
	,
	#include "data/princess_walk_2.ASP_UShort.INL"
	,
	#include "data/princess_walk_3.ASP_UShort.INL"
	,
	#include "data/princess_walk_4.ASP_UShort.INL"
	,
	#include "data/princess_walk_5.ASP_UShort.INL"
	,
	#include "data/princess_walk_6.ASP_UShort.INL"
	,
	#include "data/princess_walk_7.ASP_UShort.INL"
	,
	#include "data/princess_walk_8.ASP_UShort.INL"
	,
	#include "data/princess_walk_9.ASP_UShort.INL"
	,
	#include "data/princess_walk_10.ASP_UShort.INL"
	,
	#include "data/princess_walk_11.ASP_UShort.INL"
	,
	#include "data/princess_walk_12.ASP_UShort.INL"
	,
	#include "data/princess_walk_13.ASP_UShort.INL"
	,
	#include "data/princess_walk_14.ASP_UShort.INL"
	,
	#include "data/princess_walk_15.ASP_UShort.INL"
	,
	#include "data/princess_walk_16.ASP_UShort.INL"
	,
	#include "data/princess_walk_17.ASP_UShort.INL"
	,
	#include "data/princess_walk_18.ASP_UShort.INL"
	,
	#include "data/princess_walk_19.ASP_UShort.INL"
	,
	#include "data/princess_walk_20.ASP_UShort.INL"
	,
	#include "data/princess_walk_21.ASP_UShort.INL"
	,
	#include "data/princess_walk_22.ASP_UShort.INL"
	,
	#include "data/princess_walk_23.ASP_UShort.INL"
	,
	#include "data/princess_walk_24.ASP_UShort.INL"
	,
	#include "data/princess_walk_25.ASP_UShort.INL"
	,
	#include "data/princess_walk_26.ASP_UShort.INL"
	,
	#include "data/princess_walk_27.ASP_UShort.INL"
	,
	#include "data/princess_walk_28.ASP_UShort.INL"
	,
	#include "data/princess_walk_29.ASP_UShort.INL"
	,
	#include "data/princess_walk_30.ASP_UShort.INL"
	,
	#include "data/princess_walk_31.ASP_UShort.INL"
	,
};

UWORD __chip g_princess_idle[] =
{
	#include "data/princess_idle_0.ASP_UShort.INL"
	,
	#include "data/princess_idle_1.ASP_UShort.INL"
	,
	#include "data/princess_idle_2.ASP_UShort.INL"
	,
	#include "data/princess_idle_3.ASP_UShort.INL"
	,
	#include "data/princess_idle_4.ASP_UShort.INL"
	,
	#include "data/princess_idle_5.ASP_UShort.INL"
	,
	#include "data/princess_idle_6.ASP_UShort.INL"
	,
	#include "data/princess_idle_7.ASP_UShort.INL"
	,
	#include "data/princess_idle_8.ASP_UShort.INL"
	,
	#include "data/princess_idle_9.ASP_UShort.INL"
	,
	#include "data/princess_idle_10.ASP_UShort.INL"
	,
	#include "data/princess_idle_11.ASP_UShort.INL"
	,
	#include "data/princess_idle_12.ASP_UShort.INL"
	,
	#include "data/princess_idle_13.ASP_UShort.INL"
	,
	#include "data/princess_idle_14.ASP_UShort.INL"
	,
	#include "data/princess_idle_15.ASP_UShort.INL"
	,
};

UWORD __chip g_princess_walk_attack[] =
{
	#include "data/princess_walk_attack_0.ASP_UShort.INL"
	,
	#include "data/princess_walk_attack_1.ASP_UShort.INL"
	,
	#include "data/princess_walk_attack_2.ASP_UShort.INL"
	,
	#include "data/princess_walk_attack_3.ASP_UShort.INL"
	,
	#include "data/princess_walk_attack_4.ASP_UShort.INL"
	,
	#include "data/princess_walk_attack_5.ASP_UShort.INL"
	,
	#include "data/princess_walk_attack_6.ASP_UShort.INL"
	,
	#include "data/princess_walk_attack_7.ASP_UShort.INL"
	,
	#include "data/princess_walk_attack_8.ASP_UShort.INL"
	,
	#include "data/princess_walk_attack_9.ASP_UShort.INL"
	,
	#include "data/princess_walk_attack_10.ASP_UShort.INL"
	,
	#include "data/princess_walk_attack_11.ASP_UShort.INL"
	,
	#include "data/princess_walk_attack_12.ASP_UShort.INL"
	,
	#include "data/princess_walk_attack_13.ASP_UShort.INL"
	,
	#include "data/princess_walk_attack_14.ASP_UShort.INL"
	,
	#include "data/princess_walk_attack_15.ASP_UShort.INL"
	,
	#include "data/princess_walk_attack_16.ASP_UShort.INL"
	,
	#include "data/princess_walk_attack_17.ASP_UShort.INL"
	,
	#include "data/princess_walk_attack_18.ASP_UShort.INL"
	,
	#include "data/princess_walk_attack_19.ASP_UShort.INL"
	,
	#include "data/princess_walk_attack_20.ASP_UShort.INL"
	,
	#include "data/princess_walk_attack_21.ASP_UShort.INL"
	,
	#include "data/princess_walk_attack_22.ASP_UShort.INL"
	,
	#include "data/princess_walk_attack_23.ASP_UShort.INL"
	,
	#include "data/princess_walk_attack_24.ASP_UShort.INL"
	,
	#include "data/princess_walk_attack_25.ASP_UShort.INL"
	,
	#include "data/princess_walk_attack_26.ASP_UShort.INL"
	,
	#include "data/princess_walk_attack_27.ASP_UShort.INL"
	,
	#include "data/princess_walk_attack_28.ASP_UShort.INL"
	,
	#include "data/princess_walk_attack_29.ASP_UShort.INL"
	,
	#include "data/princess_walk_attack_30.ASP_UShort.INL"
	,
	#include "data/princess_walk_attack_31.ASP_UShort.INL"
	,
};

UWORD __chip g_princess_idle_attack[] =
{
	#include "data/princess_idle_attack_0.ASP_UShort.INL"
	,
	#include "data/princess_idle_attack_1.ASP_UShort.INL"
	,
	#include "data/princess_idle_attack_2.ASP_UShort.INL"
	,
	#include "data/princess_idle_attack_3.ASP_UShort.INL"
	,
	#include "data/princess_idle_attack_4.ASP_UShort.INL"
	,
	#include "data/princess_idle_attack_5.ASP_UShort.INL"
	,
	#include "data/princess_idle_attack_6.ASP_UShort.INL"
	,
	#include "data/princess_idle_attack_7.ASP_UShort.INL"
	,
	#include "data/princess_idle_attack_8.ASP_UShort.INL"
	,
	#include "data/princess_idle_attack_9.ASP_UShort.INL"
	,
	#include "data/princess_idle_attack_10.ASP_UShort.INL"
	,
	#include "data/princess_idle_attack_11.ASP_UShort.INL"
	,
	#include "data/princess_idle_attack_12.ASP_UShort.INL"
	,
	#include "data/princess_idle_attack_13.ASP_UShort.INL"
	,
	#include "data/princess_idle_attack_14.ASP_UShort.INL"
	,
	#include "data/princess_idle_attack_15.ASP_UShort.INL"
	,
};

int g_princess_framess[PRINCESS_NUM_STATES] = { 2, 4 };
UWORD *g_anims[PRINCESS_NUM_STATES*2] = { g_princess_idle, g_princess_walk, g_princess_idle_attack, g_princess_walk_attack };
extern char block_map[];

void update_princess(struct Princess *princess, int joy_mask)
{
	static int tick = 0;

	if (princess->locked)
	{
		joy_mask = 0;
	}

	if (!princess->attack || (tick % 2) == 0)
	{
		if (joy_mask & (1 << 3) && princess->x >   8)	princess->x--;		/*  Left */
		if (joy_mask & (1 << 1) && princess->x < 312)	princess->x++;		/* Right */
		if (joy_mask & (1 << 2) && princess->y >   8)	princess->y--;		/*    Up */
		if (joy_mask & (1 << 0) && princess->y < 232)	princess->y++;		/*  Down */
	}

	/* Collision testing with background */
	{
		short   left = (princess->x - 4) / 16;
		short  right = (princess->x + 4) / 16;
		short    top = (princess->y - 4) / 16;
		short bottom = (princess->y + 4) / 16;

		if (block_map[   top * 20 +  left] == 'X' || block_map[bottom * 20 +  left] == 'X') princess->x++;
		if (block_map[   top * 20 + right] == 'X' || block_map[bottom * 20 + right] == 'X') princess->x--;
		if (block_map[   top * 20 +  left] == 'X' || block_map[   top * 20 + right] == 'X') princess->y++;
		if (block_map[bottom * 20 +  left] == 'X' || block_map[bottom * 20 + right] == 'X') princess->y--;
	}

	switch (joy_mask)
	{
	case 0x1: princess->direction = 0; break;
	case 0x3: princess->direction = 1; break;
	case 0x2: princess->direction = 2; break;
	case 0x6: princess->direction = 3; break;
	case 0x4: princess->direction = 4; break;
	case 0xc: princess->direction = 5; break;
	case 0x8: princess->direction = 6; break;
	case 0x9: princess->direction = 7; break;
	}

	if (tick++ >= 8)
	{
		tick = 0;
		princess->frame++;
	}
	if (joy_mask == 0)
	{
		princess->state = PRINCESS_IDLE;
	}
	else
	{
		princess->state = PRINCESS_WALKING;
	}

	princess->attack = fire_down() || princess->locked;

	if (princess->state == PRINCESS_IDLE && !princess->attack)
	{
		princess->frame = 0;
	}

	princess->frame = princess->frame % g_princess_framess[princess->state];
}

void render_princess(struct Princess *princess)
{
	/* Get data for current animation frame */
	static const int sprite_num_words = 16*16/8*2/2 + 4;	/* 2 bitplanes, 2 control words, 2 end words */
	const int block_num_words = sprite_num_words * 2 + 2;	/* 2 sprites, 2 offset words */
	int l = g_princess_framess[princess->state];
	int offset = (princess->attack) ? 2 : 0;
	UWORD *data = g_anims[princess->state+offset] + princess->direction * block_num_words*l + princess->frame * block_num_words;

	/* Get sprite pointers */
	UWORD *sprite1 = data + data[0] / 2;
	UWORD *sprite2 = data + data[1] / 2;

	/* Set sprite pointers in copper */
	copper_list[43] = HIWORD((int)sprite1);
	copper_list[45] = LOWORD((int)sprite1);
	copper_list[47] = HIWORD((int)sprite2);
	copper_list[49] = LOWORD((int)sprite2);

	/* Set sprite control words */
	{
		short x = princess->x - 8;
		short y = princess->y - 8;
		sprite1[0] = sprite2[0] = 0x2c40 + (y << 8) + x / 2;
		sprite1[1] = (sprite1[0] & 0xff00) + 0x1000;
		sprite2[1] = sprite1[1] | 0x80;
	}
}

void reset_princess(struct Princess *princess)
{
	princess->direction = 0;
	princess->frame = 0;
	princess->state = PRINCESS_IDLE;
	princess->attack = FALSE;
	princess->locked = FALSE;
	princess->x = 100;
	princess->y = 100;
}
