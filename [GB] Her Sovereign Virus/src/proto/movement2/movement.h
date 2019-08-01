
static UBYTE time;  /* Global "time" value (counter) */
static UBYTE color; /* Current color for fading effect */
UINT8 herpesFrame;
fixed bposx, bposy; /* Background position (fixed point) */
fixed bspx, bspy;   /* Background speed (fixed point) */
fixed sposx, sposy; /* Sprite position (fixed point) */
fixed sspx, sspy;   /* Sprite speed (fixed point) */
fixed eX[10], eY[10];
UINT8 eH[10];
UINT8 zHeight;// (0,4)
UINT8 bgPalettes[5] = {0x40U,0x90U,0xE4U,0xF9U,0xFEU};

void fade();
void scroll();
void animate_sprite();
void tile_sprite();
void place_sprite();
void handle_input();

#define DIR_N  0
#define DIR_NE 1
#define DIR_E  2
#define DIR_SE 3
#define DIR_S  4
#define DIR_SW 5
#define DIR_W  6
#define DIR_NW 7

#define PASSIVE_DECEL 0x0006
#define ACTIVE_ACCEL 0x0030
//diagonal is *0.71 in each direction
#define ACTIVE_ACCEL_DIAG 0x0022
#define MAX_SPEED 0x0300

#define MAX_Z 4

typedef UBYTE bool;
#define true 1
#define false 0
