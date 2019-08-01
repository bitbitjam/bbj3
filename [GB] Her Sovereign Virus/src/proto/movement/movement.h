//#define SHOW_BG
//#define USE_CARDINAL
//#define CONST_VELOCITY

/** TODO **/
#ifdef SHOW_BG
  //#define MOVE_BG
#endif
//#define USE_ACCEL

static UBYTE time;  /* Global "time" value (counter) */
static UBYTE color; /* Current color for fading effect */
UBYTE shipDir;       /* Current direction the ship is facing*/
fixed shipSpeed;     /* Current ship velocity */
fixed bposx, bposy; /* Background position (fixed point) */
fixed bspx, bspy;   /* Background speed (fixed point) */
fixed sposx, sposy; /* Sprite position (fixed point) */
fixed sspx, sspy;   /* Sprite speed (fixed point) */

void fade();
void scroll();
void animate_sprite();
void tile_sprite();
void place_sprite();
void handle_input();
void update_speed();

#define DIR_N  0
#define DIR_NE 1
#define DIR_E  2
#define DIR_SE 3
#define DIR_S  4
#define DIR_SW 5
#define DIR_W  6
#define DIR_NW 7

typedef UBYTE bool;
#define true 1
#define false 0
