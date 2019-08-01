/* (c) 2016 Tenshiko + MB	*/
/* Made for bitbitjam 2016	*/

struct Princess
{
	int x;
	int y;
	int direction;
	int frame;
	enum State
	{
		PRINCESS_IDLE = 0,
		PRINCESS_WALKING = 1,
		PRINCESS_NUM_STATES,
	} state;
	BOOL attack;
	BOOL locked;
	BYTE lives;
};

void update_princess(struct Princess *princess, int joy_mask);
void render_princess(struct Princess *princess);
void reset_princess(struct Princess *princess);
