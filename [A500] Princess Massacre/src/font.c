/* (c) 2016 Tenshiko + MB	*/
/* Made for bitbitjam 2016	*/

#include <exec/types.h>
#include "system.h"
#include "graphics.h"
#include "font.h"
#include <stdio.h>

UWORD __chip g_font_bits[] =
{
	#include "data/font.BPL_UShort.INL"
};
BYTE __chip g_font_remap[] =
{
	#include "data/font.FAR_UChar.INL"
};
UWORD __chip g_font_glyphs[] =
{
	#include "data/font.BOB_UShort.INL"
};

struct Font m_default_font = { g_font_bits, g_font_remap, (struct Glyph*)g_font_glyphs };

short render_glyph(struct Font *font, UBYTE index, int x, int y);

void draw_text(struct Font *font, int x, int y, char *text)
{
	int i;
	int gx = x;
	for (i=0; text[i] != 0; i++)
	{
		/* Get character */
		UBYTE c = text[i];

		/* Get bob index */
		UBYTE index = font->remap[c];

		/* Check for valid index */
		if (index == 0xff)
		{
			gx += 12;
			continue;
		}
		
		/* Render glyph */
		gx += render_glyph(font, index, gx, y);
	}
}

short render_glyph(struct Font *font, UBYTE index, int x, int y)
{
	/* Get glyph */
	struct Glyph *glyph = font->glyphs + index;

	/* Blit glyph */
	int p;

	hardware->bltcon1 = ((x % 16) << 12);
	hardware->bltcon0 = ((x % 16) << 12) | 0xfca;
	hardware->bltamod = 0;
	hardware->bltbmod = 0;
	hardware->bltcmod = 320/8 - glyph->word_size*2;
	hardware->bltdmod = 320/8 - glyph->word_size*2;

	/* Blit 1 plane */
	for (p = 0; p<1; p++)
	{
		hardware->bltcpt = backbuffer + y*(320 / 8) + x / 8 + 320 * 256 * (p+3) / 8;
		hardware->bltdpt = backbuffer + y*(320 / 8) + x / 8 + 320 * 256 * (p+3) / 8;
		hardware->bltbpt = font->bits + glyph->offset / 2;
		hardware->bltapt = font->bits + glyph->offset / 2;
		hardware->bltsize = glyph->word_size + (glyph->height << 6);
	}

	return glyph->width + 2;
}
