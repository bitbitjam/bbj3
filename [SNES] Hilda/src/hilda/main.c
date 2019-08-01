/*---------------------------------------------------------------------------------


	Hilda


---------------------------------------------------------------------------------*/
//---------------------------------------------------------------------------------==================================================================
// Includes
#include <snes.h>
#include "libSuperAlex.h"
#include "recursos.h"
#include "enemies.h"
#include "cutscenes.h"
#include "main.h"

//define starting values
Screen screen; //screen struct
Player player; //player struct
Map map; //map struct

int actualLevel; //the actual level or scene.
int spawnPoint = 0;
int gameProgress = 0;

void (*call_update)(void); //update callback

void waitFadeOut();
void nothing();

brrsamples sound, sound2;
//---------------------------------------------------------------------------------==================================================================
// Utilities
unsigned int abs(int v) {
	int const mask = v >> sizeof(int) * CHAR_BIT - 1;
	return (v + mask) ^ mask;
}
u16 getCollisionTile(u16 x, u16 y) {
	u16 o_y = ((x>>3)/32)*31 + ((y>>3)/32)*32;
	u16 *ptrMap;

	
	ptrMap = (u16 *) map.coll_map + ((o_y+(y>>3))*32) + (x>>3);
	//if (actualLevel == LEVEL_1) ptrMap = (u16 *) &maproom1col + ((o_y+(y>>3))*32) + (x>>3);
	
	return (*ptrMap);
}
void setUpdate( void (*callback)(void) ) {
	call_update = callback;
}
void callUpdate() {
	if (call_update != NULL) {
		call_update();
	}
}
int makeSpriteNum(int n){
	int fours = (n / 4);
	return (n + (fours*12))*4;
}
//---------------------------------------------------------------------------------==================================================================
// System
void system_init(void) {
	alex_init();
	// Now Put in 16 color mode 
	setMode(BG_MODE1,BG3_MODE1_PRORITY_HIGH);
	alex_spriteSetSize(SPRITE_SIZE_16);
	bgSetDisable(0);
	bgSetDisable(1);
	bgSetDisable(2);
}
void screen_dispose() {
	oamClear(0,0);
	alex_cleanText();
	bgSetDisable(0);
	bgSetDisable(1);
	bgSetDisable(2);
	//alex_loop();
}

//---------------------------------------------------------------------------------==================================================================
// Levels and stages code.

void platformer_dispose() {
	//alex_screenFadeOut();
	bgSetScroll (0, 0, 0);
	ene_clearEnemiesMechanism();
	player.x = 0;
	player.y = 0;
	player.xspeed = 0;
	player.yspeed = 0;
	player.invencibility = 0;
	oamSetEx(0, OBJ_SMALL, OBJ_HIDE);
	
	screen_dispose();
}

void platformer_init(void) {

	//clear level status
	platformer_dispose();

	//configure player
	player.animFrame = ANIM_STAND; player.flipx = 1; player.xspeed = 0; player.yspeed = 0;
	player.animCount = 0; player.priority = 2; player.state = STATE_STAND;
	
	//give 3 health points to our little princess
	player.invencibility = 0;
	consoleDrawText(1,1,"Health: %d",player.health);
	
	//init enemies mechanism
	ene_initEnemiesMechanism();
	
	// Initialize text console with our font
	//consoleInitText(2, 0, &snesfont);
	consoleSetTextCol(RGB15(31,26,28),  RGB15(12,12,12));
	// Play music
    // Play file from the beginning
    //spcPlay(0);
	//spcSetModuleVolume(100);
    
    // Wait VBL 'and update sprites too ;-) )
    WaitForVBlank();
}

void setMapSize(u8 size){
  map.width = ((size>>4 & 0xF)+1)*4;
  map.height = ((size & 0xF)+1)*4;
}

void disposeText() {
	consoleDrawText(2,3, "                              ");
	consoleDrawText(2,4, "                              ");
	consoleDrawText(2,5, "                              ");
}

void gotoExit11(){
	spawnPoint = 1;
	gotoLevel(3);
}

void gotoExit12(){
	spawnPoint = 0;
	gotoLevel(4);
}

void gotoExit13(){
	spawnPoint = 0;
	gotoLevel(6);
	alex_melodyLoad(MOD_EVENT, MUSIC_VOL_DEFAULT);
	alex_melodyPlay();
}

void gotoExit14(){
	spawnPoint = 0;
	gotoLevel(5);
}

void gotoExit21(){
	disposeText();
	if (gameProgress == 1) {
		gameProgress++;
		alex_melodyLoad(MOD_AMBIENTE, MUSIC_VOL_DEFAULT);
		alex_melodyPlay();
	}
	alex_timerStop(1);
	spawnPoint = 0;
	gotoLevel(3);
}

void gotoExit31(){
	spawnPoint = 1;
	gotoLevel(2);
}

void gotoExit32(){
	spawnPoint = 0;
	gotoLevel(1);
}

extern bool sister_excecute;
extern bool sister_done;
extern bool sister_done_2;

void gotoExit41(){
	alex_timerStop(1);
	sister_excecute = false;
	if (sister_done == true && sister_done_2 == false) {
		gameProgress= 3;
		gotoSisterScene();
	} else {
		alex_melodyFade();
		spawnPoint = 1;
		gotoLevel(1);
	}
}

extern bool curandero_excecute;

void gotoExit51(){
	alex_timerStop(1);
	curandero_excecute = false;
	spawnPoint = 3;
	gotoLevel(1);
}

void gotoExit61(){
	spawnPoint = 2;
	gotoLevel(1);
}

void configureLevel(int level) {
	
	if (level == 1) {
		//============================================
		//LEVEL 1 - The "lobby" area.
		//============================================
		
		/*=========================================================
			MAP AND BACKGROUNDS
		===========================================================*/ 
		// Copy tiles to VRAM
		bgInitTileSet(0, &gfxroom1, &palroom1, 1, (&gfxroom1_end - &gfxroom1), 16*2, BG_16COLORS, 						0x2000);
		bgInitTileSet(1, &gfxbackground, &palbackground, 2, (&gfxbackground_end - &gfxbackground), 16*2, BG_16COLORS, 	0x6000);
		// Copy Map to VRAM
		bgInitMapSet(0, &maproom1, (&maproom1_end - &maproom1),SC_64x64, 												0x2C00);
		bgInitMapSet(1, &mapbackground, (&mapbackground_end - &mapbackground),SC_32x32,									0x3C00);
		
		//size in tiles
		setMapSize(MAP_64x64);
		
		map.width_px = map.width*8;  //size of tile
		map.height_px = map.height*8;
		ene_updateMapBoundaries(map);
		map.coll_map = &(maproom1col);
		/*=========================================================
			PLAYER AND AIRTFACTS
		=========================================================*/ 
		// Init Sprites gfx and palette
		oamInitGfxSet(&gfxplayer, (&gfxplayer_end-&gfxplayer), &palplayer, 128*2, 0, 0x4000, OBJ_SIZE32);
		
		// Player starting position (in map. S_x and S_y are configured automatically).
		if (spawnPoint == 0) {	
			player.x = 32<<PRECISSION; 
			player.y = 119<<PRECISSION;
		} else if (spawnPoint == 1) {
			player.x = 32<<PRECISSION; 
			player.y = 431<<PRECISSION;
		} else if (spawnPoint == 2) {
			player.x = 448<<PRECISSION; 
			player.y = 272<<PRECISSION;
		} else if (spawnPoint == 3) {
			player.x = 448<<PRECISSION; 
			player.y = 415<<PRECISSION;
		}
		
		oamSet(0,  player.x>>PRECISSION, player.y>>PRECISSION, player.priority, player.flipx, 0, 0, 0); 
		oamSetEx(0, OBJ_SMALL, OBJ_SHOW);
		
		//enemy
		ene_addEnemy(CATEGORY_WAS, 8, 216, 140, 1, BEHAIVOUR_WALK_LEFT, ACTION_HURT_1, NULL, 3, true, false,1);
		ene_addEnemy(CATEGORY_WAS, 8, 72, 424, 1, BEHAIVOUR_WALK_LEFT, ACTION_HURT_1, NULL, 3, true, false,1);
		ene_addEnemy(CATEGORY_JUMPER, 20, 64, 143, 0, BEHAIVOUR_JUMPER, ACTION_HURT_1, NULL, 2, false, false,1);
		ene_addEnemy(CATEGORY_JUMPER, 20, 96, 143, 0, BEHAIVOUR_JUMPER, ACTION_HURT_1, NULL, 2, false, false,1);
		ene_addEnemy(CATEGORY_JUMPER, 20, 296, 64, 0, BEHAIVOUR_JUMPER, ACTION_HURT_1, NULL, 2, false, false,1);
		ene_addEnemy(CATEGORY_JUMPER, 20, 312, 64, 0, BEHAIVOUR_JUMPER, ACTION_HURT_1, NULL, 2, false, false,1);
		ene_addEnemy(CATEGORY_JUMPER, 20, 328, 64, 0, BEHAIVOUR_JUMPER, ACTION_HURT_1, NULL, 2, false, false,1);
		ene_addEnemy(CATEGORY_JUMPER, 20, 408, 312, 0, BEHAIVOUR_JUMPER, ACTION_HURT_1, NULL, 2, false, false,1);
		
		//level end
		ene_addEnemy(CATEGORY_DUMMY, 16, 480, 270, 1, BEHAIVOUR_NONE, ACTION_CALL_FUNCTION, &(gotoExit13), -1, false, false,0);
		ene_addEnemy(CATEGORY_DUMMY, 15, 480, 415, 1, BEHAIVOUR_NONE, ACTION_CALL_FUNCTION, &(gotoExit14), -1, false, false,0);
		ene_addEnemy(CATEGORY_DUMMY, 14, 0, 432, 1, BEHAIVOUR_NONE, ACTION_CALL_FUNCTION, &(gotoExit12), -1, false, false,0);
		ene_addEnemy(CATEGORY_DUMMY, 14, 0, 111, 1, BEHAIVOUR_NONE, ACTION_CALL_FUNCTION, &(gotoExit11), -1, false, false,0);
		
		//ene_addEnemy(1, 74, 50, 3, BEHAIVOUR_NONE, ACTION_NONE, NULL, 3, true, false);
		//ene_addEnemy(2, 84, 50, 3, BEHAIVOUR_NONE, ACTION_NONE, NULL, 3, true, false);
		//ene_addEnemy(3, 94, 50, 3, BEHAIVOUR_NONE, ACTION_NONE, NULL, 3, true, false);
		
		/*===================
			MELODY AND SOUND LOAD
		===================*/ 
		//alex_melodyLoad(MOD_WIND, MUSIC_VOL_DEFAULT);
		//spcSetSoundEntry(15, 8, 6, &sound_jump_end - &sound_jump, &sound_jump, &sound2);
		
		
	} else if (level == 2) {
		//============================================
		//LEVEL 2 - The starting point.
		//============================================
		/*=========================================================
			MAP AND BACKGROUNDS
		===========================================================*/ 
		// Copy tiles to VRAM
		bgInitTileSet(0, &gfxroom2, &palroom2, 1, (&gfxroom2_end - &gfxroom2), 16*2, BG_16COLORS, 						0x2000);
		bgInitTileSet(1, &gfxbackground, &palbackground, 2, (&gfxbackground_end - &gfxbackground), 16*2, BG_16COLORS, 	0x6000);
		// Copy Map to VRAM
		bgInitMapSet(0, &maproom2, (&maproom2_end - &maproom2),SC_64x64, 												0x2C00);
		bgInitMapSet(1, &mapbackground, (&mapbackground_end - &mapbackground),SC_32x32, 								0x3C00);
		
		//size in tiles
		setMapSize(MAP_32x32);
		
		map.width_px = map.width*8;  //size of tile
		map.height_px = map.height*8;
		ene_updateMapBoundaries(map);
		map.coll_map = &(maproom2col);
		/*=========================================================
			PLAYER AND AIRTFACTS
		=========================================================*/ 
		// Init Sprites gfx and palette
		oamInitGfxSet(&gfxplayer, (&gfxplayer_end-&gfxplayer), &palplayer, 128*2, 0, 0x4000, OBJ_SIZE32);
				//alex_spriteShow(3, 24, 10, 10, 2, 0, 0, 0);
		
		// Player starting position (in map. S_x and S_y are configured automatically).
		if (spawnPoint == 0) {
			player.x = 136<<PRECISSION; 
			player.y = 135<<PRECISSION;
		} else if (spawnPoint == 1) {
			player.x = 200<<PRECISSION; 
			player.y = 135<<PRECISSION;
			player.flipx = 0;
		}
		
		oamSet(0,  player.x>>PRECISSION, player.y>>PRECISSION, player.priority, player.flipx, 0, 0, 0); 
		oamSetEx(0, OBJ_SMALL, OBJ_SHOW);
		
		//enemy
		//ene_addEnemy(CATEGORY_STATIC, 24, 80, 70, 1, BEHAIVOUR_NONE, ACTION_NONE, NULL, 3, true, false);
		
		//level end
		ene_addEnemy(CATEGORY_DUMMY, 14, 225, 135, 1, BEHAIVOUR_NONE, ACTION_CALL_FUNCTION, &(gotoExit21), -1, false, false,0);
		
		//ene_addEnemy(1, 74, 50, 3, BEHAIVOUR_NONE, ACTION_NONE, NULL, 3, true, false);
		//ene_addEnemy(2, 84, 50, 3, BEHAIVOUR_NONE, ACTION_NONE, NULL, 3, true, false);
		//ene_addEnemy(3, 94, 50, 3, BEHAIVOUR_NONE, ACTION_NONE, NULL, 3, true, false);
		
		/*===================
			MELODY AND SOUND LOAD
		===================*/ 
		//alex_melodyLoad(MOD_WIND, MUSIC_VOL_DEFAULT);
		//spcSetSoundEntry(15, 8, 6, &sound_jump_end - &sound_jump, &sound_jump, &sound2);
		
		if (gameProgress==0) {
			consoleDrawText(2,3,"I must get out from here...");
			gameProgress++;
			alex_timerSet(1,TIMER_SECOND*3, &(disposeText));
		}
		
	}  else if (level == 3) {
		//============================================
		//LEVEL 3 - The road between start and lobby.
		//============================================
		/*=========================================================
			MAP AND BACKGROUNDS
		===========================================================*/ 
		// Copy tiles to VRAM
		bgInitTileSet(0, &gfxroom3, &palroom3, 1, (&gfxroom3_end - &gfxroom3), 16*2, BG_16COLORS, 						0x2000);
		bgInitTileSet(1, &gfxbackground, &palbackground, 2, (&gfxbackground_end - &gfxbackground), 16*2, BG_16COLORS, 	0x6000);
		// Copy Map to VRAM
		bgInitMapSet(0, &maproom3, (&maproom3_end - &maproom3),SC_64x64, 												0x2C00);
		bgInitMapSet(1, &mapbackground, (&mapbackground_end - &mapbackground),SC_32x32, 								0x3C00);
		
		//size in tiles
		setMapSize(MAP_64x32);
		
		map.width_px = map.width*8;  //size of tile
		map.height_px = map.height*8;
		ene_updateMapBoundaries(map);
		map.coll_map = &(maproom3col);
		/*=========================================================
			PLAYER AND AIRTFACTS
		=========================================================*/ 
		// Init Sprites gfx and palette
		oamInitGfxSet(&gfxplayer, (&gfxplayer_end-&gfxplayer), &palplayer, 128*2, 0, 0x4000, OBJ_SIZE32);
		
		// Player starting position (in map. S_x and S_y are configured automatically).
		if (spawnPoint == 0) {
			player.x = 32<<PRECISSION; 
			player.y = 135<<PRECISSION;
		} else if (spawnPoint == 1) {
			player.x = 450<<PRECISSION; 
			player.y = 111<<PRECISSION;
		}

		
		oamSet(0,  player.x>>PRECISSION, player.y>>PRECISSION, player.priority, player.flipx, 0, 0, 0); 
		oamSetEx(0, OBJ_SMALL, OBJ_SHOW);
		
		//enemy
		ene_addEnemy(CATEGORY_JUMPER, 20, 160, 120, 0, BEHAIVOUR_JUMPER, ACTION_HURT_1, NULL, 2, false, false,1);
		ene_addEnemy(CATEGORY_WAS, 8, 328, 143, 1, BEHAIVOUR_WALK_LEFT, ACTION_HURT_1, NULL, 3, true, false,1);
		
		//level end
		ene_addEnemy(CATEGORY_DUMMY, 14, 480, 111, 1, BEHAIVOUR_NONE, ACTION_CALL_FUNCTION, &(gotoExit32), -1, false, false,0);
		ene_addEnemy(CATEGORY_DUMMY, 14, 0, 135, 1, BEHAIVOUR_NONE, ACTION_CALL_FUNCTION, &(gotoExit31), -1, false, false,0);
		
		//ene_addEnemy(1, 74, 50, 3, BEHAIVOUR_NONE, ACTION_NONE, NULL, 3, true, false);
		//ene_addEnemy(2, 84, 50, 3, BEHAIVOUR_NONE, ACTION_NONE, NULL, 3, true, false);
		//ene_addEnemy(3, 94, 50, 3, BEHAIVOUR_NONE, ACTION_NONE, NULL, 3, true, false);
		
		/*===================
			MELODY AND SOUND LOAD
		===================*/ 
		//alex_melodyLoad(MOD_WIND, MUSIC_VOL_DEFAULT);
		//spcSetSoundEntry(15, 8, 6, &sound_jump_end - &sound_jump, &sound_jump, &sound2);

	} else if (level == 4) {
		//============================================
		//LEVEL 4 - Cave of the cleric.
		//============================================
		/*=========================================================
			MAP AND BACKGROUNDS
		===========================================================*/ 
		// Copy tiles to VRAM
		bgInitTileSet(0, &gfxroom4, &palroom4, 1, (&gfxroom4_end - &gfxroom4), 16*2, BG_16COLORS, 						0x2000);
		bgInitTileSet(1, &gfxbackground, &palbackground, 2, (&gfxbackground_end - &gfxbackground), 16*2, BG_16COLORS, 	0x6000);
		// Copy Map to VRAM
		bgInitMapSet(0, &maproom4, (&maproom4_end - &maproom4),SC_64x64, 												0x2C00);
		bgInitMapSet(1, &mapbackground, (&mapbackground_end - &mapbackground),SC_32x32, 								0x3C00);
		
		//size in tiles
		setMapSize(MAP_32x32);
		
		map.width_px = map.width*8;  //size of tile
		map.height_px = map.height*8;
		ene_updateMapBoundaries(map);
		map.coll_map = &(maproom4col);
		/*=========================================================
			PLAYER AND AIRTFACTS
		=========================================================*/ 
		// Init Sprites gfx and palette
		oamInitGfxSet(&gfxplayer, (&gfxplayer_end-&gfxplayer), &palplayer, 128*2, 0, 0x4000, OBJ_SIZE32);
		
		// Player starting position (in map. S_x and S_y are configured automatically).
		player.x = 200<<PRECISSION; 
		player.y = 182<<PRECISSION;

		oamSet(0,  player.x>>PRECISSION, player.y>>PRECISSION, player.priority, player.flipx, 0, 0, 0); 
		oamSetEx(0, OBJ_SMALL, OBJ_SHOW);
		
		//enemy
		//ene_addEnemy(CATEGORY_WAS, 8, 80, 70, 1, BEHAIVOUR_WALK_LEFT, ACTION_HURT_1, NULL, 3, true, false);
		//Sister event
		ene_addEnemy(CATEGORY_STATIC, 24, 12, 143, 1, BEHAIVOUR_NONE, ACTION_CALL_FUNCTION, (&sisterSceneInit), 3, true, false,0);
		//level end
		ene_addEnemy(CATEGORY_DUMMY, 14, 224, 184, 1, BEHAIVOUR_NONE, ACTION_CALL_FUNCTION, &(gotoExit41), -1, false, false,0);
		
		//ene_addEnemy(1, 74, 50, 3, BEHAIVOUR_NONE, ACTION_NONE, NULL, 3, true, false);
		//ene_addEnemy(2, 84, 50, 3, BEHAIVOUR_NONE, ACTION_NONE, NULL, 3, true, false);
		//ene_addEnemy(3, 94, 50, 3, BEHAIVOUR_NONE, ACTION_NONE, NULL, 3, true, false);
		
		/*===================
			MELODY AND SOUND LOAD
		===================*/ 
		//alex_melodyLoad(MOD_WIND, MUSIC_VOL_DEFAULT);
		//spcSetSoundEntry(15, 8, 6, &sound_jump_end - &sound_jump, &sound_jump, &sound2);

	} else if (level == 5) {
		//============================================
		//LEVEL 5 - A place to look the scenery.
		//============================================
		/*=========================================================
			MAP AND BACKGROUNDS
		===========================================================*/ 
		// Copy tiles to VRAM
		bgInitTileSet(0, &gfxroom5, &palroom5, 1, (&gfxroom5_end - &gfxroom5), 16*2, BG_16COLORS, 						0x2000);
		bgInitTileSet(1, &gfxbackground, &palbackground, 2, (&gfxbackground_end - &gfxbackground), 16*2, BG_16COLORS, 	0x6000);
		// Copy Map to VRAM
		bgInitMapSet(0, &maproom5, (&maproom5_end - &maproom5),SC_64x64, 												0x2C00);
		bgInitMapSet(1, &mapbackground, (&mapbackground_end - &mapbackground),SC_32x32, 								0x3C00);
		
		//size in tiles
		setMapSize(MAP_64x32);
		
		map.width_px = map.width*8;  //size of tile
		map.height_px = map.height*8;
		ene_updateMapBoundaries(map);
		map.coll_map = &(maproom5col);
		/*=========================================================
			PLAYER AND AIRTFACTS
		=========================================================*/ 
		// Init Sprites gfx and palette
		oamInitGfxSet(&gfxplayer, (&gfxplayer_end-&gfxplayer), &palplayer, 128*2, 0, 0x4000, OBJ_SIZE32);
		
		// Player starting position (in map. S_x and S_y are configured automatically).
		player.x = 32<<PRECISSION; 
		player.y = 142<<PRECISSION;

		oamSet(0,  player.x>>PRECISSION, player.y>>PRECISSION, player.priority, player.flipx, 0, 0, 0); 
		oamSetEx(0, OBJ_SMALL, OBJ_SHOW);
		
		//enemy
		//ene_addEnemy(CATEGORY_WAS, 8, 80, 70, 1, BEHAIVOUR_WALK_LEFT, ACTION_HURT_1, NULL, 3, true, false);
		//Curandero (let's call it cleric too if what you read is English but anyway, he heals).
		ene_addEnemy(CATEGORY_STATIC, 8, 80, 70, 1, BEHAIVOUR_NONE, ACTION_CALL_FUNCTION, (&curanderoSceneInit), -1, true, false,2);
		
		//level end
		ene_addEnemy(CATEGORY_DUMMY, 14, 0, 142, 1, BEHAIVOUR_NONE, ACTION_CALL_FUNCTION, &(gotoExit51), -1, false, false,0);
		
		//ene_addEnemy(1, 74, 50, 3, BEHAIVOUR_NONE, ACTION_NONE, NULL, 3, true, false);
		//ene_addEnemy(2, 84, 50, 3, BEHAIVOUR_NONE, ACTION_NONE, NULL, 3, true, false);
		//ene_addEnemy(3, 94, 50, 3, BEHAIVOUR_NONE, ACTION_NONE, NULL, 3, true, false);
		
		/*===================
			MELODY AND SOUND LOAD
		===================*/ 
		//alex_melodyLoad(MOD_WIND, MUSIC_VOL_DEFAULT);
		//spcSetSoundEntry(15, 8, 6, &sound_jump_end - &sound_jump, &sound_jump, &sound2);

	} else if (level == 6) {
		//============================================
		//LEVEL 6 - The summit. Final boss arises!
		//============================================
		/*=========================================================
			MAP AND BACKGROUNDS
		===========================================================*/ 
		// Copy tiles to VRAM
		//bgInitTileSet(0, &gfxroom1, &palroom1, 1, (&gfxroom1_end - &gfxroom1), 16*2, BG_16COLORS, 						0x2000);
		bgInitTileSet(1, &gfxroom6, &palroom6, 2, (&gfxroom6_end - &gfxroom6), 16*2, BG_16COLORS, 	0x6000);
		// Copy Map to VRAM
		//bgInitMapSet(0, &maproom1, (&maproom1_end - &maproom1),SC_64x64, 												0x2C00);
		bgInitMapSet(1, &maproom6, (&maproom6_end - &maproom6),SC_32x32,									0x3C00);
		
		//size in tiles
		setMapSize(118);
		
		map.width_px = map.width*8;  //size of tile
		map.height_px = map.height*8;
		ene_updateMapBoundaries(map);
		map.coll_map = &(maproom6col);
		/*=========================================================
			PLAYER AND AIRTFACTS
		=========================================================*/ 
		// Init Sprites gfx and palette
		oamInitGfxSet(&gfxplayer, (&gfxplayer_end-&gfxplayer), &palplayer, 128*2, 0, 0x4000, OBJ_SIZE32);
		
		// Player starting position (in map. S_x and S_y are configured automatically).
		player.x = 45<<PRECISSION; 
		player.y = 215<<PRECISSION;

		oamSet(0,  player.x>>PRECISSION, player.y>>PRECISSION, player.priority, player.flipx, 0, 0, 0); 
		oamSetEx(0, OBJ_SMALL, OBJ_SHOW);
		
		//enemy
		if (gameProgress== 3){
			//condition if girl scene was done or not
			alex_spriteShow(3, 			22, 192, 32, 2, 0, 0, 2);
			alex_spriteShow(4, 			23, 224, 32, 2, 0, 0, 2);
			ene_addEnemy(CATEGORY_BOSS, 26, 192, 64, 0, BEHAIVOUR_FAST_SINE, ACTION_HURT_1, NULL,5, false, false,2);
			alex_spriteShow(5, 			27, 224, 64, 2, 0, 0, 2);
		}else{
			//level end
			ene_addEnemy(CATEGORY_DUMMY, 14, 0, 215, 1, BEHAIVOUR_NONE, ACTION_CALL_FUNCTION, &(gotoExit61), -1, false, false,0);
		}
		//ending thing
		//ene_addEnemy(CATEGORY_STATIC, 25, 80, 185, 1, BEHAIVOUR_NONE, ACTION_CALL_FUNCTION, &(gotoEnding), -1, false, false,1);
		
		//level end
		//ene_addEnemy(CATEGORY_DUMMY, 14, 0, 215, 1, BEHAIVOUR_NONE, ACTION_CALL_FUNCTION, &(gotoExit61), -1, false, false,0);
		
		//ene_addEnemy(1, 74, 50, 3, BEHAIVOUR_NONE, ACTION_NONE, NULL, 3, true, false);
		//ene_addEnemy(2, 84, 50, 3, BEHAIVOUR_NONE, ACTION_NONE, NULL, 3, true, false);
		//ene_addEnemy(3, 94, 50, 3, BEHAIVOUR_NONE, ACTION_NONE, NULL, 3, true, false);
		
		/*===================
			MELODY AND SOUND LOAD
		===================*/ 
		//alex_melodyLoad(MOD_WIND, MUSIC_VOL_DEFAULT);
		//spcSetSoundEntry(15, 8, 6, &sound_jump_end - &sound_jump, &sound_jump, &sound2);

	} 
	
	// And let's show :P
	if (level != 6) bgSetEnable(0);
	bgSetEnable(1);
	bgSetEnable(2);
	playerUpdateScreenPos();
	updateScroll();
	alex_screenFadeIn();
}

//
bool spriteCollision(unsigned int x,unsigned int y) {
	bool ret = false;
	x = x>>PRECISSION;
	y = y>>PRECISSION;
	if( getCollisionTile(x+ 8	,y)==1 ||
		getCollisionTile(x+16	,y)==1 ||
		getCollisionTile(x+24	,y)==1 ||
		
		getCollisionTile(x+8	,y+8)==1 ||
		getCollisionTile(x+8	,y+16)==1 ||
		getCollisionTile(x+8	,y+24)==1 ||
		getCollisionTile(x+24	,y+8)==1 ||
		getCollisionTile(x+24	,y+16)==1 ||
		getCollisionTile(x+24	,y+24)==1 ||
		
		getCollisionTile(x+ 8	,y+32)==1 ||
		getCollisionTile(x+16	,y+32)==1 ||
		getCollisionTile(x+24	,y+32)==1)
		return true;
	
	return false;
}
void updateScrollMap() {
	int i;
	u16 *ptrMap;
	u16 ptrVRAM;
}
void updateScroll() {
	screen.x = (player.x>>PRECISSION)-(HALF_SCREENWIDTH);
	if(screen.x > map.width_px) screen.x=0;
	if(screen.x > (map.width_px-SCREENWIDTH)) screen.x = (map.width_px-SCREENWIDTH);
	
	screen.y = (player.y>>PRECISSION)-(HALF_SCREENHEIGHT);
	if(screen.y > map.height_px) screen.y=0;
	if(screen.y > (map.height_px-SCREENHEIGHT)) screen.y = (map.height_px-SCREENHEIGHT);
		
	bgSetScroll (0, screen.x, screen.y);
	/**alex_cleanText();
	consoleDrawText(1,3,"chrX=%d chrY=%d           ",player.x>>PRECISSION, player.y>>PRECISSION);
	consoleDrawText(1,1,"w=%d h=%d           ",map.width, map.height);
	consoleDrawText(1,1,"scrX=%d scrY=%d           ",screen.x, screen.y);
	consoleDrawText(1,2,"scrXoff=%d scrYoff=%d           ",screen.x_off, screen.y_off);
	
	consoleDrawText(1,4,"chr_sX=%d chr_sY=%d           ",player.s_x, player.s_y);
	/**/
}

void attackEnd(){
	player.state = STATE_STAND;
	player.animStart = ANIM_STAND;
	player.animEnd = ANIM_STAND+1;
	player.animFrame = 0;
	player.animCount = 0;
	player.animSpeed = 16;
}

//Player updates
void playerStep() {
	//Manage Input
	if(alex_buttonIsPressed(0, KEY_LEFT)) {
		player.xspeed -= WALK_ACCEL;
		player.flipx = 0;
		if (player.animStart != ANIM_WALK && player.state==STATE_STAND) {
			player.animStart = ANIM_WALK;
			player.animEnd = ANIM_WALK+4;
			player.animFrame = player.animStart;
			player.animCount = 0;
			player.animSpeed = 8;
		}
	}
	else if(alex_buttonIsPressed(0, KEY_RIGHT)) {
		player.xspeed += WALK_ACCEL;
		player.flipx = 1;
		if (player.animStart != ANIM_WALK && player.state==STATE_STAND) {
			player.animStart = ANIM_WALK;
			player.animEnd = ANIM_WALK+4;
			player.animFrame = player.animStart;
			player.animCount = 0;
			player.animSpeed = 8;
		}
	}
	else {
		if (player.animStart != ANIM_STAND  && player.state==STATE_STAND) {
			player.animStart = ANIM_STAND;
			player.animEnd = ANIM_STAND+1;
			player.animFrame = player.animStart;
			player.animCount = 0;
			player.animSpeed = 16;
		}
	}
	if(alex_buttonIsPressed(0, KEY_A)) {
		if (spriteCollision(player.x, player.y+PRECVAL) && player.state==STATE_STAND) {
			player.yspeed = -JUMPVALUE;
			player.state = STATE_JUMP;
			player.animStart = ANIM_JUMP;
			player.animEnd = ANIM_JUMP+1;
			player.animFrame = player.animStart;
			player.animCount = 0;
			player.animSpeed = 16;
			player.charge = true;
		}
		if(player.charge==true && player.state==STATE_JUMP) {
			if(player.animCount>1) player.yspeed = -(JUMPVALUE+GRAVITY*5);
			if(player.animCount>2) player.yspeed = -(JUMPVALUE*2);
			if(player.animCount > 8) player.charge = false;
		}
	}if(alex_buttonIsPressed(0, KEY_B)) {
		if (player.state!=STATE_ATTACK && player.cooldown==0) {
			player.state = STATE_ATTACK;
			player.animStart = ANIM_ATK;
			player.animEnd = ANIM_ATK+1;
			player.animFrame = player.animStart;
			player.animCount = 0;
			player.animSpeed = 16;
			player.cooldown = 8;
			alex_timerSet(2, 4, &(attackEnd) );
		}
	}
	if(player.cooldown > 0){
		player.cooldown--;
	}
	
	//Apply deacceleration and speed "clamping".
	if(player.xspeed > 0) {	//moving right
		player.xspeed -= WALK_DEACCEL;
		if(player.xspeed < 0) player.xspeed = 0;
		if(player.xspeed > WALK_MAXSPEED) player.xspeed = WALK_MAXSPEED;
	}
	if(player.xspeed < 0) { //moving left
		player.xspeed += WALK_DEACCEL;
		if(player.xspeed > 0) player.xspeed = 0;
		if(player.xspeed < -WALK_MAXSPEED) player.xspeed = -WALK_MAXSPEED;
	}
	player.yspeed += GRAVITY;
	if(player.yspeed > MAX_FALL) player.yspeed = MAX_FALL;
	
	//Collision check
	if( spriteCollision(player.x, player.y + player.yspeed) ) {
		//int sign = (player.yspeed / abs(player.yspeed))<<PRECISSION;
		//while(spriteCollision(player.x, player.y + sign)==false ) player.y += sign;
		player.yspeed = 0;
		player.charge = false;
		
		if (spriteCollision(player.x, player.y+PRECVAL) && player.state==STATE_JUMP) {
			player.state = STATE_STAND;
			player.animStart = ANIM_STAND;
			player.animEnd = ANIM_STAND+1;
			player.animFrame = 0;
			player.animCount = 0;
			player.animSpeed = 16;
		}
	}
	if( spriteCollision(player.x + player.xspeed, player.y) ) {
		//int sign = (player.xspeed / abs(player.xspeed))<<PRECISSION;
		//while(spriteCollision(player.x + sign, player.y)==false ) player.x += sign;
		player.xspeed = 0;
	}
	if( spriteCollision(player.x, player.y) ) {
		if( spriteCollision(player.x, player.y+PRECVAL*4)==false ){
			player.y += PRECVAL;
		}else{
			player.y -= PRECVAL;
		}
	}
	
	//Commit movement
	player.x += player.xspeed;
	player.y += player.yspeed;
}
//

bool spriteShown = true;

void turnInvencibility(){
	if (spriteShown == false) {
		oamSetVisible(0,OBJ_SHOW);
		spriteShown = true;
	} else {
		oamSetVisible(0,OBJ_HIDE);
		spriteShown = false;
	}
	player.invencibility--;
	if (player.invencibility <= 0) {
		//turn on sprite
		player.invencibility =0;
		oamSetVisible(0,OBJ_SHOW);
		spriteShown = true;
	} else {
		alex_timerSet(3,1, &(turnInvencibility));
	}
}

void atHurt(int intensity){
	//just hurt if player isnt invencible
	if (player.invencibility== 0) {
		player.health-=intensity;
		consoleDrawText(1,1,"Health: %d",player.health);
		if (player.health == 0){
			gotoGameOver();//alex_die("GAME OVER");
			title_init();
		} else {
			//jump beacuse impact
			if (spriteCollision(player.x, player.y+PRECVAL) && player.state==STATE_STAND) {
				player.yspeed = -JUMPVALUE;
				player.state = STATE_JUMP;
				player.animStart = ANIM_JUMP;
				player.animEnd = ANIM_JUMP+1;
				player.animFrame = player.animStart;
				player.animCount = 0;
				player.animSpeed = 8;
			}
			player.invencibility = 60;
			alex_timerSet(3,1, &(turnInvencibility));
		}
	}
}

void gotoLevel(int level){
	alex_screenFadeOut();
	platformer_dispose();
	if (level == 1) loadLevel(LEVEL_1);
	if (level == 2) loadLevel(LEVEL_2);
	if (level == 3) loadLevel(LEVEL_3);
	if (level == 4) loadLevel(LEVEL_4);
	if (level == 5) loadLevel(LEVEL_5);
	if (level == 6) loadLevel(LEVEL_6);
}

void gotoGameOver(){
	alex_screenFadeOut();
	platformer_dispose();
	loadLevel(LEVEL_GAMEOVER);
}

void gotoEnding(){
	alex_screenFadeOut();
	platformer_dispose();
	loadLevel(LEVEL_ENDING);
}

void atRecover(int intensity){
	
	if (player.health + intensity <= PLAYER_HEALTH ) {
		player.health+= intensity;
	} else {
		player.health= PLAYER_HEALTH;
	}
	consoleDrawText(1,1,"Health: %d",player.health);
}

void playerUpdateScreenPos(){
	//Calculate screen position
	player.s_x = player.x>>PRECISSION;
	if((player.s_x > HALF_SCREENWIDTH) && (player.s_x < (map.width_px-HALF_SCREENWIDTH))){
		player.s_x = HALF_SCREENWIDTH;
	}
	
	player.s_y = player.y>>PRECISSION;
	if((player.s_y > HALF_SCREENHEIGHT) && (player.s_y < (map.height_px-HALF_SCREENHEIGHT))){
		player.s_y = HALF_SCREENHEIGHT;
	} else if(player.s_y > (map.height_px-HALF_SCREENHEIGHT-1)) {
		player.s_y -= 32;
	}
	//Commit sprite placement
	oamSet(0,  player.s_x, player.s_y, player.priority, player.flipx, 0, makeSpriteNum(player.animFrame), 0);
}
void playerDraw() {
	//Update animation
	player.animCount += 1;
	if(player.animCount >= player.animSpeed) {
		player.animFrame += 1;
		if(player.animFrame >= player.animEnd) player.animFrame=player.animStart;
		player.animCount = 0;
	}
	
	playerUpdateScreenPos();
}
//
void platformer_update(){
	_ene_updateSprites(player);
	if (actualLevel == LEVEL_5) {
		if (player.y > 1700) gotoGameOver();
	}else if(actualLevel == LEVEL_6){
		if(gameProgress== 3){
			if(getEnemyActive(0)==true){
				alex_spriteUpdateCoordinates(3, getEnemySX(0), 	getEnemySY(0)-32);
				alex_spriteUpdateCoordinates(4, getEnemySX(0)+32,getEnemySY(0)-32);
				alex_spriteUpdateCoordinates(5, getEnemySX(0)+32,getEnemySY(0));
			}else{
				alex_spriteRemove(3);
				alex_spriteRemove(4);
				alex_spriteRemove(5);
				if(gameProgress < 9){
					ene_addEnemy(CATEGORY_STATIC, 25, 80, 185, 1, BEHAIVOUR_NONE, ACTION_CALL_FUNCTION, &(gotoEnding), -1, false, false,1);
					gameProgress = 9;
				}
			}
		}
	}
	playerStep();
	playerDraw();
	updateScroll();
}

// ====================================

void loadLevel(int level) {
	
	if (level == LEVEL_BOOT) {
		//Show splash screen
		actualLevel =LEVEL_BOOT;
		splash_init();
		setUpdate(&(nothing));
		return;
	}
	
	if (level == LEVEL_TITLE) {
		resetBools();
		//Initialize the active screen
		actualLevel =LEVEL_TITLE;
		title_init();
		setUpdate(&(title_update));
		return;
	}
	
	if (level == LEVEL_ENDING) {
		//Initialize the active screen
		actualLevel =LEVEL_ENDING;
		ending_init();
		setUpdate(&(nothing));
		return;
	}
	
	if (level == LEVEL_GAMEOVER) {
		//Initialize the active screen
		actualLevel =LEVEL_GAMEOVER;
		gameover_init();
		setUpdate(&(nothing));
		return;
	}
	
	if (level == LEVEL_SISTER) {
		//Initialize the active screen
		actualLevel =LEVEL_SISTER;
		sister_2_init();
		setUpdate(&(nothing));
		return;
	}
	
	//in the case if there's any playable level
	if (level == LEVEL_1 || level == LEVEL_2 || level == LEVEL_3 || level == LEVEL_4 || level == LEVEL_5 || level == LEVEL_6) {
		platformer_init();
		setUpdate(&(platformer_update));
	}
	
	if (level == LEVEL_1) {
		actualLevel = LEVEL_1;
		configureLevel(1);
		return;
	}
	
	if (level == LEVEL_2) {
		actualLevel = LEVEL_2;
		configureLevel(2);
		return;
	}
	
	if (level == LEVEL_3) {
		actualLevel = LEVEL_3;
		configureLevel(3);
		return;
	}
	
	if (level == LEVEL_4) {
		actualLevel = LEVEL_4;
		configureLevel(4);
		return;
	}
	
	if (level == LEVEL_5) {
		actualLevel = LEVEL_5;
		configureLevel(5);
		return;
	}
	
	if (level == LEVEL_6) {
		actualLevel = LEVEL_6;
		configureLevel(6);
		return;
	}
	
	alex_die("Level not defined :P");
	
}
void resetBools(){
	sister_excecute=false;
	sister_done=false;
	sister_done_2=false;
	curandero_excecute=false;
}
//---------------------------------------------------------------------------------==================================================================
//Main cycle code
int main(void) {

	// Initialize SNES (Alex and other stuff)
	system_init();
	actualLevel = -1;
	
	//Load boot cut-scene.
	loadLevel(LEVEL_BOOT);
	
	// Infinite loop to keep the program running
	while(1) {	
	
		callUpdate();
		alex_loop();
	}
	return 0;
}