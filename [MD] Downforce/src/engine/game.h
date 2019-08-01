#ifndef _GAME_H_
#define _GAME_H_

#define scrollSpeed					1
#define max_num_players             6

#define initPlayer1PosX				36
#define initPlayer1PosY				76
#define initPlayer2PosX				84
#define initPlayer2PosY				76
#define initPlayer3PosX				132
#define initPlayer3PosY				76
#define initPlayer4PosX				52
#define initPlayer4PosY				132
#define initPlayer5PosX				100
#define initPlayer5PosY				132
#define initPlayer6PosX				148
#define initPlayer6PosY				132

#define dir_stand					0
#define dir_up						1					
#define dir_down					3

#define turn_frame_full_ani     	30
#define turn_frame_mid_ani      	20
#define turn_frame_basic_ani    	10

#define turbo_frame_basic_ani		5
#define turbo_frame_mid_ani			8

#define shipCollisionUp				2
#define shipCollisionFront			20
#define shipCollisionDown			14

#define scrollInitPosY				16

#define sparksTime					10

#define spriteMisc 					22
#define shipSpriteId				spriteMisc+16

////////////////////////////////////////////////////////////////////
// prototipos
void gameLoop( u8 mode, u8 circuit );

////////////////////////////////////////////////////////////////////
//	estructuras
// jugador
typedef struct{
    fix32 screenPosX, screenPosY;	// posicion x, y en pantalla
	u16 circuitPosX;
	fix32 circuitPosY;
	
	u8 energy, weapon, state;
	
	u8 lap, newLap;
	
	u8 speedPos;					// posicion en el vector constante de velocidad
	u8 collisionUpRear, collisionUpFront, collisionDownRear, collisionDownFront;
	
	u8 initPosY;
	
	u8 direction;
	u8 numFrame;
	u8 numFrameTurbo;
	u8 turbo;					// si dibujamos estela o no
	u8 sparksAnim;				// si dibujamos chispas o no
	u8 sparksPos;				// 1 Arriba, 2 Abajo
	
	SpriteDef sprite;       	// sprite
	SpriteDef shadow;			// sombra
	SpriteDef trail;			// estela
	SpriteDef sparks;			// chispas
}player_struct;

player_struct       player[max_num_players];

typedef struct{
	fix32 screenPosX, screenPosY;
	SpriteDef sprite;			// chispas
}shoot_struct;

shoot_struct shoot;

////////////////////////////////////////////////////////////////////
//	vars globales
fix32 scrollPos_x; 
fix32 scrollAPos_y, scrollBPos_y;	

u16 scrollBgTotal;

SpriteDef speedHud[3];
SpriteDef energyHud[2];
SpriteDef lapHud[2];
SpriteDef posHud[2];
SpriteDef timeHud[5];
SpriteDef bestHud[5];
SpriteDef miscHud[16];
SpriteDef weaponHud[2];
SpriteDef killsHud;

#endif
