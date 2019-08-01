/* (c) 2016 Tenshiko + MB	*/
/* Made for bitbitjam 2016	*/

struct Teddy
{
	short startx;
	short starty;

	short x;
	short y;
	short frame;
	short direction;
	BOOL locked;

	short forcex;
	short forcey;
};

void reset_teddy(struct Teddy *teddy, struct Teddy *teddies);
void render_teddy(struct Teddy *teddy);
void update_teddy(struct Teddy *teddies, int index, struct Princess *princess);
