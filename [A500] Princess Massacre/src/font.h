/* (c) 2016 Tenshiko + MB	*/
/* Made for bitbitjam 2016	*/

struct Glyph
{
	UWORD word_size;
	UWORD height;
	UWORD width;
	ULONG offset;
	UWORD anchor_x;
	UWORD anchor_y;
};

struct Font
{
	UWORD			*bits;
	BYTE			*remap;
	struct Glyph	*glyphs;
};

extern struct Font m_default_font;

void draw_text(struct Font *font, int x, int y, char *text);
