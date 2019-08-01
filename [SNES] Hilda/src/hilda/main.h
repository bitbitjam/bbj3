//---------------------------------------------------------------------------------==================================================================
// Defines and initial global variables

//STRUCTS
typedef struct {
	int x,y;
	int s_x, s_y;
	int xspeed,yspeed;
	int state;
	int flipx;
	int animStart;
	int animEnd;
	int animFrame;
	int animCount;
	int animSpeed;
	int health;
	int invencibility;
	u8 priority;
	bool charge;
	u8 cooldown;
} Player;
typedef struct {
	int x,y;
	int x_off, y_off;
} Screen;
typedef struct {
	unsigned int width;
	unsigned int height;
	unsigned int width_px;
	unsigned int height_px;
	u8 * coll_map;
} Map;

//ENUMS
enum {ANIM_STAND=0, ANIM_WALK=1, ANIM_ATK=5, ANIM_JUMP=6, ANIM_AJUMP=7};
enum {STATE_STAND=0, STATE_JUMP=1, STATE_ATTACK=2, STATE_THROW=3, STATE_WALK=4};

//CONSTANTS
#define PRECISSION 3
#define PRECVAL 8
#define WALK_MAXSPEED 32
#define WALK_ACCEL 8
#define WALK_DEACCEL 4
#define GRAVITY 2
#define MAX_FALL 64
#define JUMPVALUE (GRAVITY*10)
#define SCREENWIDTH 256
#define SCREENHEIGHT 224
#define HALF_SCREENWIDTH (SCREENWIDTH/2)
#define HALF_SCREENHEIGHT (SCREENHEIGHT/2)

#define CHAR_BIT 8

#define PLAYER_HEALTH 3

#define MAP_32x32 119
#define MAP_32x64 127
#define MAP_64x32 247
#define MAP_64x64 255

//Level and cut-scenes identificator
enum {
		LEVEL_BOOT			=0,		//Just a dummy scene for make a cut-scene
		LEVEL_TITLE			=1, 	//Title screen, isn't just levels here.
		LEVEL_1				=2,		//The actual test level
		LEVEL_2				=3,	
		LEVEL_3				=4,	
		LEVEL_4				=5,	
		LEVEL_5				=6,	
		LEVEL_6				=7,	
		LEVEL_ENDING		=8,
		LEVEL_GAMEOVER		=9,
		LEVEL_SISTER		=10,
};
	
//---------------------------------------------------------------------------------==================================================================
// Utilities
unsigned int abs(int v);
u16 getCollisionTile(u16 x, u16 y);
void setUpdate( void (*callback)(void) );
void callUpdate();
int makeSpriteNum(int n);
//---------------------------------------------------------------------------------==================================================================
// System
void system_init(void);
void screen_dispose();

void loadLevel(int level);

//---------------------------------------------------------------------------------==================================================================
// Level screen code
void platformer_init(void);
void setMapSize(u8 size);
void configureLevel(int level);
void platformer_dispose();
bool spriteCollision(unsigned int x,unsigned int y);
void playerUpdateScreenPos();
void playerStep();
void playerDraw();

void turnInvencibility();
void atHurt(int intensity);
void gotoGameOver();
void atRecover(int intensity);

void platformer_update();
void gotoLevel(int level);
void updateScroll();
void disposeText();

void gotoEnding(); //**

void gotoExit11();
void gotoExit12();
void gotoExit13();
void gotoExit14();
void gotoExit21();
void gotoExit31();
void gotoExit32();
void gotoExit41();
void gotoExit51();
void gotoExit61();
void resetBools();