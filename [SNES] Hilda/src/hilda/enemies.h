#include "libSuperAlex.h"
#include "recursos.h"
#include "main.h"

#ifndef __HILDA_ENEMIES__
#define __HILDA_ENEMIES__

//number of enemies and start position in OAM.
#define ENEMIES_NUMBER 16
#define ENEMIES_LAYER 16
#define ENEMIES_TOUCH_CLOSE 16
#define ENEMIES_ATTACK_CLOSE 48

typedef struct {
	bool active;
	bool visible;
	int screen_x;
	int screen_y;
	int map_x;
	int map_y;
	int distance_x;
	int distance_y;
	int invencibility;
	bool invencibility_toogle;
	int speed;
	int category;	//For sprite animation kind
	u8 spr_num; //sprite graphic offset start (gfx start + offset in the picture)
	int flipx;
	int animStart;
	int animEnd;
	int animFrame;
	int animCount;
	int animSpeed;
	int state;
	int behaivour;	//See below
	int touchAction;	//See below
	void (*callback)(void); //For special touch action
	int power; //HP. -1 is unkillable.
	bool gravity; //Gravity ON or OFF (flying).
	bool kamikaze; //After touch action kill ON or OFF.
	int pallete; //Pallete number for the enemy.
}Enemy;

//Behaivour
enum {
		BEHAIVOUR_NONE			=0,		//Static
		BEHAIVOUR_WALK_LEFT		=1, 	//Walk left, right, left...
		BEHAIVOUR_WALK_RIGHT	=2,		//Walk right, left, right...
		BEHAIVOUR_DEATH_LEFT	=3,		//Walk left and kills itself.
		BEHAIVOUR_DEATH_RIGHT	=4,		//Walk right and kills itself.
		BEHAIVOUR_FAST_SINE 	=5,		//Runs towards player in X. Y changes in a sine wave.
		BEHAIVOUR_JUMPER 		=6,		//Jumps if the character is close.
		BEHAIVOUR_MIMIC1		=7,
		BEHAIVOUR_MIMIC2		=8,
		BEHAIVOUR_MIMIC3		=9,
	};
	
//Touch action
enum {
		ACTION_NONE			=0,	//None
		ACTION_HURT_1		=1, //Hurt 1 HP
		ACTION_HURT_2		=2,	//Hurt 2 HP
		ACTION_HURT_3		=3,	//Hurt 3 HP
		ACTION_RECOVER_1		=4,	//Recover 1 HP
		ACTION_RECOVER_2		=5,	//Recover 2 HP
		ACTION_RECOVER_3		=6, //Recover 3 HP
		ACTION_CALL_FUNCTION	=7, //Call callback
	};
//Animation category
enum {
		CATEGORY_STATIC 	= 0, //No animation
		CATEGORY_JUMPER 	= 1, //1frame for standing, 1frame for jump
		CATEGORY_WAS 		= 2, //3frames for walk, 3frames for close-range attack, 2frames for long-range
		CATEGORY_DUMMY		= 3, //No sprite. Just for touch-events
		CATEGORY_BOSS		= 4,
	};

//==========================================

bool getEnemyActive(int id);
int getEnemySX(int id);
int getEnemySY(int id);
void ene_initEnemiesMechanism();
void ene_clearEnemiesMechanism();
//void ene_updateMapBoundaries(Map map);
void ene_removeEnemy(int id);
void ene_explodeEnemy(int i);

void ene_addEnemy(
	int category, //animation kind
	u8 spr_num, //sprite offset
	int map_x, 
	int map_y, 
	int speed, //1 to infinite xD Be careful, we dont want to bug the game
	int behaivour, //See enum
	int touchAction, //See enum
	void (*callback)(void), //For special touch action. If none, NULL.
	int power, //HP. -1 is unkillable.
	bool gravity, //Gravity ON or OFF (flying).
	bool kamikaze, //After touch action kill ON or OFF.
	int pallete
	);
//void _ene_updateSprites(Player player);

//==========================================

#endif // __HILDA_ENEMIES__