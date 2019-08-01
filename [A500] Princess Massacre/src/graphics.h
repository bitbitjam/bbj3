/* (c) 2016 Tenshiko + MB	*/
/* Made for bitbitjam 2016	*/

#define LOWORD(l) ((WORD)(l))
#define HIWORD(l) ((WORD)(((LONG)(l) >> 16) & 0xFFFF))

extern UBYTE __chip backbuffer[320 * 256 * 4 / 8];
/*extern UBYTE *backbuffer;*/
extern UWORD __chip copper_list[];

BOOL init_graphics();
void cleanup_graphics();
void waitline223();
