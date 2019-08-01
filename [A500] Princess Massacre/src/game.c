/* (c) 2016 Tenshiko + MB	*/
/* Made for bitbitjam 2016	*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "game.h"
#include "system.h"
#include "graphics.h"
#include "princess.h"
#include "teddy.h"
#include "font.h"

extern void init_music();
extern void update_music();
extern void end_music();

void draw_splat(int x, int y);
void clear_teddy(struct Teddy *teddy);
void reset_enemies();
void clear_enemies();
void update_score();
void start_level();
void play_sound(USHORT *sound, USHORT word_length, USHORT period);

struct Princess m_princess;
struct Teddy m_teddy[4];
int m_score;
BOOL m_first_run = TRUE;

BOOL lbutton_down()
{
	return (cia->ciapra & (1 << 6)) == 0;
}

/*
char map[] =
{
	"00000000000000000000"
	"02020022000000000000"
	"02200200200000000000"
	"02200200200000000000"
	"02020022000000000000"
	"00000000000000000000"
	"00220022002200022000"
	"0200020XXXXX20200000"
	"0200000IIIII20202000"
	"00220220002200022000"
	"00000000000000000000"
	"00000000000000000000"
	"00000000000000000000"
	"00000000000000000000"
	"00000000000000000000"
};*/


char block_map[] =
{
	"0000000000000000000000000000000000000000000XXXXXXX000XXXXXX000XXXXXXX0000XXXXXXX0XXXXXXX00000XXXXXXXXXXX0000000000XXXXXXXXX0000000000000XXXXX000000000000000XXXX000000000XXXX000XXX0000000XXXXXXX00XXX00000XXXXXXXX0000XXX0000XXXXXXXX00000XX00000XXXXXXXX00000XX0000000000000000000000000000000000000000000"
};
int map[] =
{
	3, 4, 18, 1, 1, 1, 2, 2, 1, 1, 9, 16, 13, 12, 2, 2, 1, 2, 2, 2, 4, 13, 12, 2, 2, 2, 2, 2, 2, 2, 2, 9, 12, 2, 2, 2, 2, 2, 2, 2, 13, 12, 2, 25, 21, 21, 21, 22, 26, 1, 1, 2, 2, 25, 21, 22, 21, 22, 26, 2, 12, 2, 25, 29, 20, 20, 20, 32, 28, 2, 2, 2, 1, 34, 20, 19, 20, 20, 30, 26, 2, 25, 29, 32, 23, 24, 23, 28, 2, 2, 1, 1, 1, 27, 31, 19, 20, 19, 32, 28, 22, 29, 32, 28, 2, 1, 1, 1, 2, 2, 5, 8, 2, 1, 27, 23, 31, 19, 35, 2, 32, 23, 28, 2, 2, 1, 5, 7, 6, 8, 9, 12, 1, 2, 1, 1, 33, 19, 30, 26, 28, 2, 2, 1, 5, 6, 14, 4, 13, 12, 2, 2, 1, 1, 2, 2, 33, 19, 32, 28, 2, 2, 2, 2, 9, 10, 11, 10, 12, 25, 22, 22, 26, 2, 1, 2, 33, 32, 28, 2, 1, 2, 2, 2, 2, 1, 25, 22, 21, 29, 32, 23, 28, 1, 2, 25, 29, 36, 2, 1, 1, 2, 2, 25, 22, 22, 29, 19, 20, 32, 28, 1, 2, 2, 2, 34, 32, 28, 2, 1, 2, 2, 25, 29, 19, 20, 19, 20, 32, 28, 1, 2, 2, 2, 2, 33, 35, 1, 2, 2, 1, 2, 27, 23, 23, 23, 23, 23, 28, 1, 2, 1, 1, 2, 2, 27, 28, 2, 1, 5, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 17, 2, 2, 1, 2, 2, 1, 1, 1, 1, 2, 1, 2, 1, 1, 2, 5, 7, 7, 6, 14
};

/*
UWORD map_index(char tile)
{
	switch (tile)
	{
	case ' ': return 0;
	case '.': return 1;
	case 'o': return 18;
	case 'O': return 19;	
	case 'n': return 20;
	case 'N': return 21;
	case 'i': return 22;
	case 'I': return 23;
	case '1': return 24;
	case '2': return 25;
	case '3': return 26;
	case '4': return 27;
	}

	return 18;
}
*/

UWORD __chip g_tiles[] =
{
	#include "data/terrain.BPL_UShort.INL"
};
UWORD __chip g_splats[] =
{
	#include "data/splat.BPL_UShort.INL"
};
BYTE __chip g_chainsaw_low_sound[] =
{
	#include "data/chainsaw_low.h"
};
BYTE __chip g_chainsaw_high_sound[] =
{
	#include "data/chainsaw_high.h"
};
BYTE __chip g_chainsaw_hit_sound[] =
{
	#include "data/chainsaw_hit.h"
};

UBYTE __chip terrain[320 * 256 * 4 / 8];
UBYTE __chip offscreen[320 * 256 * 4 / 8];

void cleanup()
{
	cleanup_system();
	cleanup_graphics();
}

int random(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

extern UWORD __chip blank[(16 / 8 + 2) * 16 / 2];
int main()
{
	int i;
	int frame = 0;
	int ttx = 0;
	int locked = -1;
	int hit = 0;
	BOOL fire_up = FALSE;

	memset(blank, 0, sizeof(blank));

	m_princess.x = 100;
	m_princess.y = 100;
	m_princess.frame = 0;
	m_princess.direction = 0;
	m_princess.locked = FALSE;
	m_princess.lives = 3;
	m_score = 0;

	for (i = 0; i < 4; i++)
	{
/*		m_teddy[i].startx = (((i%2)==0) ? 20 : 300) * 10;
		m_teddy[i].starty = (((i/2)==0) ? 20 : 220) * 10; */
		m_teddy[i].startx = (100 + i * 25) * 10;
		m_teddy[i].starty = 50 * 10;
		reset_teddy(m_teddy + i, m_teddy);
	}

	if (!init_system() || !init_graphics())
	{
		cleanup();
		return -1;
	}

	if (1)
	{
		init_music();
	}

	/* Start on the main/game over screen */
	m_princess.lives = 0;
	update_score();

	/* Wait for left mouse */
	while (!lbutton_down())
	{
		UWORD clx;

		/* Process input */
		int joy_mask;
		UWORD j = hardware->joy1dat;
		BOOL up = (((j >> 9) ^ (j >> 8)) & 1) != 0;
		BOOL down = (((j >> 1) ^ (j >> 0)) & 1) != 0;
		BOOL right = ((j >> 1) & 1) != 0;
		BOOL left = ((j >> 9) & 1) != 0;
		joy_mask = (left << 3) | (up << 2) | (right << 1) | (down);

		if (m_princess.lives == 0)
		{
			if (fire_down() && !fire_up) continue;

			fire_up = TRUE;

			if (fire_down())
			{
				start_level();
			}

			m_first_run = FALSE;

			continue;
		}

		if (fire_down() && m_princess.attack == FALSE)
		{
			play_sound((USHORT*)g_chainsaw_high_sound, sizeof(g_chainsaw_high_sound) / 2, 132);
		}
		else if (!fire_down() && m_princess.attack == TRUE)
		{
			play_sound((USHORT*)g_chainsaw_low_sound, sizeof(g_chainsaw_low_sound) / 2, 132);
		}

		update_princess(&m_princess, joy_mask);

		/* Wait for blitter to be ready */
		/*while ((hardware->dmaconr & (1<<14)) != 0);*/

		/* Update and render enemies */
		if (frame == 0)
		{
			for (i = 0; i < 4; i++)
			{
				struct Teddy *teddy = m_teddy + i;
				clear_teddy(teddy);
			}
		}

		for (i = 0; i < 4; i++)
		{
			struct Teddy *teddy = m_teddy + i;
			short tx = teddy->x / 10;
			short ty = teddy->y / 10;
			short px = m_princess.x;
			short py = m_princess.y;
#if 1

			/* Check for collision */
			if (abs(px - tx) < 8 && abs(py - ty) < 8)
			{
				if (!m_princess.attack || (locked != -1 && locked != i)) /* || abs(((m_princess.direction+4)%8) - teddy->direction)>3) */
				{
					/* Princess hit */
					fire_up = FALSE;
					m_princess.lives--;
					locked = -1;
					hit = 0;
					reset_enemies();
					reset_princess(&m_princess);
					play_sound((USHORT*)g_chainsaw_low_sound, sizeof(g_chainsaw_low_sound) / 2, 132);
					update_score();
				}
				else if (hit == 0)
				{
					play_sound((USHORT*)g_chainsaw_hit_sound, sizeof(g_chainsaw_hit_sound) / 2, 132);
					hit = 1;
					teddy->locked = TRUE;
					m_princess.locked = TRUE;
					locked = i;
				}
			}

			/* Update splats */
			if (locked == i && hit > 0)
			{
				hit++;
				if (hit > 30)
				{
					clear_teddy(teddy);
					reset_teddy(teddy, m_teddy);
					locked = -1;
					hit = 0;
					m_princess.locked = FALSE;
					m_score += 1;
					update_score();
					play_sound((USHORT*)g_chainsaw_low_sound, sizeof(g_chainsaw_low_sound) / 2, 132);
					m_princess.attack = FALSE;
				}
				else if ((hit % 4) == 0)
				{
					draw_splat(tx + random(-10, 10), ty + random(-10, 10));
				}
			}

			update_teddy(m_teddy, i, &m_princess);
#endif
			if (frame == 0)
			{
				render_teddy(teddy);
			}
		}
		
		if (frame == 1)
		{
			/* Blit offscreen to backbuffer */
			for (i = 0; i < 4; i++)
			{
				hardware->bltcon1 = 0;
				hardware->bltcon0 = 0x9f0;
				hardware->bltamod = 0;
				hardware->bltdmod = 0;
				hardware->bltdpt = backbuffer + 320*256/8*i;
				hardware->bltapt = offscreen + 320*256/8*i;
				hardware->bltsize = (320 / 16) | (240 << 6);
			}
		}
		frame = 1 - frame;

		/* Wait for vblank */
		waitline223();

		clear_enemies();
		render_princess(&m_princess);

		if (m_princess.lives == 0)
		{
			update_score();
		}
	}

	end_music();
	cleanup();

	return 0;
}

void draw_splat(int x, int y)
{
	int p;
	x -= 8;
	y -= 8;

	hardware->bltcon1 = ((x % 16) << 12);
	hardware->bltcon0 = ((x%16)<<12) | 0xfca;
	/*hardware->bltcon0 = ((x % 16) << 12) | 0x9f0;*/
	hardware->bltamod = 0;
	hardware->bltbmod = 0;
	hardware->bltcmod = (320 - 32) / 8;
	hardware->bltdmod = (320 - 32) / 8;

	/* Blit 4 planes */
	for (p = 0; p<4; p++)
	{
		/* Blit to terrain buffer */
		hardware->bltcpt = terrain + y*(320 / 8) + x / 8 + 320 * 256 * (p) / 8;
		hardware->bltdpt = terrain + y*(320 / 8) + x / 8 + 320 * 256 * (p) / 8;
		hardware->bltbpt = (p == 0 || p == 3) ? g_splats : blank;
		hardware->bltapt = g_splats;
		hardware->bltsize = (32 / 16) + (16 << 6);

		/* Blit to backbuffer */
		hardware->bltcpt = backbuffer + y*(320 / 8) + x / 8 + 320 * 256 * (p) / 8;
		hardware->bltdpt = backbuffer + y*(320 / 8) + x / 8 + 320 * 256 * (p) / 8;
		hardware->bltbpt = (p == 0 || p == 3) ? g_splats : blank;
		hardware->bltapt = g_splats;
		hardware->bltsize = (32 / 16) + (16 << 6);

		/* Blit to offscreen buffer */
		hardware->bltcpt = offscreen + y*(320 / 8) + x / 8 + 320 * 256 * (p) / 8;
		hardware->bltdpt = offscreen + y*(320 / 8) + x / 8 + 320 * 256 * (p) / 8;
		hardware->bltbpt = (p == 0 || p == 3) ? g_splats : blank;
		hardware->bltapt = g_splats;
		hardware->bltsize = (32 / 16) + (16 << 6);
	}
}

void reset_enemies()
{
	int i;
	for (i = 0; i < 4; i++)
	{
		struct Teddy *teddy = m_teddy + i;

		clear_teddy(teddy);
		reset_teddy(teddy, m_teddy);
	}
}

void clear_enemies()
{
	return;

	int i;
	for (i = 0; i < 4; i++)
	{
		struct Teddy *teddy = m_teddy + i;

		clear_teddy(teddy);
	}
}

void update_score()
{
	int i;
	static char temp[32];
	UWORD *bitmap = (UWORD*)(backbuffer + 320*240/8 + 320*256/8*3);

	if (m_princess.lives == 0)
	{
		if (m_first_run)
		{
			/* Display main menu text */
			memset(backbuffer, 0, 320 * 256 * 4 / 8);
			draw_text(&m_default_font, 64, 16, "PRINCESS MASSACRE\0");

			draw_text(&m_default_font, 46, 240, "Tenshiko and MB, 2016\0");

			draw_text(&m_default_font, 56, 62, "Kill the teddy bears\0");
			draw_text(&m_default_font, 62, 82, "with your chainsaw\0");
			draw_text(&m_default_font, 56, 112, "Press fire to start\0");

			m_princess.x = 146;
			m_princess.y = 154;
			render_princess(&m_princess);

			hardware->aud[3].ac_ptr = blank;
			hardware->aud[3].ac_len = 4;
			hardware->dmacon = 0x0008;
		}
		else
		{
			/* Display game over text */
			memset(backbuffer, 0, 320 * 256 * 4 / 8);
			draw_text(&m_default_font, 100, 80, "GAME OVER\0");

			sprintf(temp, "Score: %d", m_score);
			draw_text(&m_default_font, 110, 96, temp);

			draw_text(&m_default_font, 52, 112, "Press fire to restart\0");

			m_princess.x = 146;
			m_princess.y = 154;
			render_princess(&m_princess);

			hardware->aud[3].ac_ptr = blank;
			hardware->aud[3].ac_len = 4;
			hardware->dmacon = 0x0008;
		}
	}
	else
	{
		for (i = 0; i < 320 * 16 / 8 / 2; i++)
		{
			*bitmap++ = 0;
		}

		sprintf(temp, "Score: %d", m_score);
		draw_text(&m_default_font, 0, 240, temp);

		sprintf(temp, "Lives: %d", m_princess.lives);
		draw_text(&m_default_font, 254, 240, temp);
	}
}

void start_level()
{
	/* Clear backbuffer */
	memset(backbuffer, 0, 320 * 256 * 6 / 8);

	/* Terrain */
	if (1)
	{
		int p;
		int x;
		int y;
		static UWORD line_words = 16*4*16 / 16;

		waitline223();

		hardware->bltcon1 = 0;
		hardware->bltcon0 = 0x9f0;
		hardware->bltamod = 16 * 3 / 8;
		hardware->bltdmod = (320 - 16) / 8;

		for (y = 0; y<240; y += 16)
		{
			for (x = 0; x<320; x += 16)
			{
				int i = (y/16)*20 + (x/16);
				int data = map[i] - 1;

				int r = data / 4;
				int c = data % 4;

				UWORD *tile = g_tiles + (r * line_words + c);

				/* Blit 4 planes */
				for (p = 0; p<4; p++)
				{
					hardware->bltdpt = terrain + y*(320 / 8) + x / 8 + 320 * 256 * (p) / 8;
					hardware->bltapt = tile + p*(16 * 4 / 8) * 16 * 9 / 2;
					hardware->bltsize = (16 / 16) + (16 << 6);
				}
			}
		}

		waitline223();

		/* Blit terrain to offscreen buffer */
		hardware->bltamod = 0;
		hardware->bltdmod = 0;
		hardware->bltdpt = offscreen;
		hardware->bltapt = terrain;
		hardware->bltsize = (320 / 16) | (0x3ff << 6);

		waitline223();

		/* Blit terrain to backbuffer */
		hardware->bltamod = 0;
		hardware->bltdmod = 0;
		hardware->bltdpt = backbuffer;
		hardware->bltapt = terrain;
		hardware->bltsize = (320 / 16) | (0x3ff << 6);
	}

	reset_enemies();
	reset_princess(&m_princess);
	m_score = 0;
	m_princess.lives = 3;
	update_score();

	play_sound((USHORT*)g_chainsaw_low_sound, sizeof(g_chainsaw_low_sound) / 2, 132);
}

void play_sound(USHORT *sound, USHORT word_length, USHORT period)
{
	hardware->aud[3].ac_ptr = sound;
	hardware->aud[3].ac_len = word_length;
	hardware->aud[3].ac_per = 96;
	hardware->aud[3].ac_vol = 0x40;
	hardware->dmacon = 0x0008;
	hardware->dmacon = 0x8008;
}
