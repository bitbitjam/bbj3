#include <snes.h>
#include "libSuperAlex.h"
#include "recursos.h"
#include "enemies.h"
#include "cutscenes.h"
#include "main.h"


extern Screen screen; //screen struct
extern Player player; //player struct
extern Map map; //map struct

extern int gameProgress;

//============================
//SPLASH
//============================
void splash_init(void){
	alex_melodyLoad(MOD_ENDING, MUSIC_VOL_DEFAULT);
	bgInitTileSet(0, &gfxsplashback, &palsplashback, 0, (&gfxsplashback_end - &gfxsplashback), (&palsplashback_end - &palsplashback), BG_16COLORS, 	0x2000);
	bgInitMapSet(0, &mapsplashback, (&mapsplashback_end - &mapsplashback),SC_32x32, 								0x5000);
	
	bgSetScroll (0, 64, 0);
	bgSetEnable(0);
	bgSetEnable(1);
	
	alex_screenFadeIn();
	
	alex_timerSet (0, TIMER_SECOND*3, &(splash_end) );
}

void splash_end(void){
	alex_screenFadeOut();
	bgSetScroll (0, 0, 0);
	alex_timerSet (0, TIMER_SECOND*2, &(opening_init) );
	//alex_timerSet (0, TIMER_SECOND*2, &(ending_init) );
}

//============================
//OPENING
//============================
void opening_init(void) {
	//we dont need backgrounds yet, but text
	alex_melodyPlay();
	
	bgSetDisable(0);
	bgSetDisable(1);
	bgSetEnable(2);
	
	setUpdate(&(skip_loop));
	
	consoleSetTextCol(RGB15(255,255,255),  RGB15(0,0,0));
	consoleDrawText(2,13,"She was the last");
	consoleDrawText(2,14,"of the princesses of");
	consoleDrawText(2,15,"the so name-cold lands...");
	alex_screenFadeIn();
	
	alex_timerSet (0, TIMER_SECOND*12, &(opening_11) );
}

void skip_loop(){
	if(alex_buttonIsPressed(0, KEY_A) || alex_buttonIsPressed(0, KEY_START)) {
		alex_timerStop(0);
		alex_timerStop(1);
		alex_screenFadeOut();
		alex_melodyFade();
		alex_cleanText();	
		consoleDrawText(2,13,"");
		consoleDrawText(2,14,"");
		consoleDrawText(2,15,"");
		alex_spriteStopMove(0);
		alex_spriteRemove(0);
		setUpdate(&(nothing));
		alex_timerSet (0, TIMER_SECOND*3, &(end_opening) );
	}
}

void opening_11() {
	alex_screenFadeOut();
	alex_cleanText();
	alex_timerSet (0, TIMER_SECOND*3, &(opening_21) );
}

void opening_21() {
	consoleDrawText(2,13,"Her red eyes and red spirit");
	consoleDrawText(2,14,"has just seen so much blood");
	consoleDrawText(2,15,"from all beloved ones...");
	alex_screenFadeIn();
	
	alex_timerSet (0, TIMER_SECOND*12, &(opening_22) );
}

void opening_22() {
	alex_screenFadeOut();
	alex_cleanText();
	alex_timerSet (0, TIMER_SECOND*3, &(opening_31) );
}

void opening_31() {
		alex_timerSet (1, TIMER_HALF_SECOND, &(scroll_below) );
		consoleDrawText(2,13,"The only reason for she");
		consoleDrawText(2,14,"to stay alive was her");
		consoleDrawText(2,15,"little sister ... ");
		// Copy tiles to VRAM
		bgInitTileSet(0, &gfxroom2, &palroom2, 1, (&gfxroom2_end - &gfxroom2), 16*2, BG_16COLORS, 						0x2000);
		bgInitTileSet(1, &gfxbackground, &palbackground, 2, (&gfxbackground_end - &gfxbackground), 16*2, BG_16COLORS, 	0x6000);
		// Copy Map to VRAM
		bgInitMapSet(0, &maproom2, (&maproom2_end - &maproom2),SC_64x64, 												0x2C00);
		bgInitMapSet(1, &mapbackground, (&mapbackground_end - &mapbackground),SC_32x32, 								0x3C00);
		bgSetEnable(0);
		bgSetEnable(1);
		alex_screenFadeIn();
		alex_timerSet (0, TIMER_SECOND*12, &(opening_32) );
}

int opening_scroll = 0;

void scroll_below() {
	opening_scroll++;
	bgSetScroll (0, 0, opening_scroll);
	alex_timerSet (1, TIMER_HALF_SECOND, &(scroll_below) );
}

void opening_32(){
	alex_screenFadeOut();
	alex_timerStop(1);
	bgSetScroll (0, 0, 0);
	alex_cleanText();
	alex_timerSet (0, TIMER_SECOND*3, &(opening_41) );
}

void opening_41(){
	bgSetDisable(0);
	bgSetDisable(1);
	
	oamInitGfxSet(&gfxplayer, (&gfxplayer_end-&gfxplayer), &palplayer, 16*2, 0, 0x4000, OBJ_SIZE32);
	alex_spriteShow(0, 0, 170, 80, 2, 1, 0, 0);
	
	consoleDrawText(2,13,"But It's time...");
	consoleDrawText(2,14,"");
	consoleDrawText(2,15,"... Hilda ... ");
	
	alex_spriteMove(0, 170, 150, TIMER_SECOND*12 , NULL );
	alex_screenFadeIn();
	alex_timerSet (0, TIMER_SECOND*12, &(opening_42) );
}

void opening_42(){
	alex_screenFadeOut();
	alex_spriteStopMove(0);
	alex_spriteRemove(0);
	alex_cleanText();
	alex_timerSet (0, TIMER_SECOND*3, &(opening_51) );
}

void opening_51() {
	consoleDrawText(2,13,"Do you want to die?");
	consoleDrawText(2,14,"Or revenge others?...");
	consoleDrawText(2,15,"");
	alex_screenFadeIn();
	
	alex_timerSet (0, TIMER_SECOND*12, &(opening_52) );
}

void opening_52(){
	alex_screenFadeOut();
	alex_melodyFade();
	alex_cleanText();
	consoleDrawText(2,13,"");
	consoleDrawText(2,14,"");
	consoleDrawText(2,15,"");
	alex_timerSet (0, TIMER_SECOND*3, &(end_opening) );
}

void end_opening(){
	consoleSetTextCol(RGB15(31,26,28),  RGB15(12,12,12));
	loadLevel(LEVEL_TITLE);
}

//============================
//ending
//============================

void ending_init(){
	//we dont need backgrounds yet, but text
	alex_melodyLoad(MOD_ENDING, MUSIC_VOL_DEFAULT);
	alex_melodyPlay();
	
	bgSetDisable(0);
	bgSetDisable(1);
	bgSetEnable(2);
	
	setUpdate(&(nothing));
	
	consoleSetTextCol(RGB15(255,255,255),  RGB15(0,0,0));
	consoleDrawText(2,13,"So, Hilda defeated the ");
	consoleDrawText(2,14,"murderer of her sister.");
	consoleDrawText(2,15,"");
	alex_screenFadeIn();
	
	alex_timerSet (0, TIMER_SECOND*12, &(ending_12) );
}

void ending_12(){
	alex_screenFadeOut();
	alex_cleanText();
	alex_timerSet (0, TIMER_SECOND*3, &(ending_21) );
}

void ending_21(){
	consoleDrawText(2,13,"But that's not over Hilda.");
	consoleDrawText(2,14,"The monsters ahead want you ");
	consoleDrawText(2,15,"to bleed till dead.");
	alex_screenFadeIn();
	
	alex_timerSet (0, TIMER_SECOND*12, &(ending_22) );
}

void ending_22(){
	alex_screenFadeOut();
	alex_cleanText();
	alex_timerSet (0, TIMER_SECOND*3, &(ending_31) );
}

void ending_31(){
		consoleDrawText(2,13,"");
		consoleDrawText(2,14,"");
		consoleDrawText(2,15,"");
		// Copy tiles to VRAM
		bgInitTileSet(0, &gfxroom2, &palroom2, 1, (&gfxroom2_end - &gfxroom2), 16*2, BG_16COLORS, 						0x2000);
		bgInitTileSet(1, &gfxbackground, &palbackground, 2, (&gfxbackground_end - &gfxbackground), 16*2, BG_16COLORS, 	0x6000);
		// Copy Map to VRAM
		bgInitMapSet(0, &maproom2, (&maproom2_end - &maproom2),SC_64x64, 												0x2C00);
		bgInitMapSet(1, &mapbackground, (&mapbackground_end - &mapbackground),SC_32x32, 								0x3C00);
		
		oamInitGfxSet(&gfxplayer, (&gfxplayer_end-&gfxplayer), &palplayer, 16*2, 0, 0x4000, OBJ_SIZE32);
		alex_spriteShow(3, 25, 135, 135, 2, 0, 0, 0);
		alex_spriteShow(4, 1, 155, 135, 2, 0, 0, 0);
	
		bgSetEnable(0);
		bgSetEnable(1);
		alex_screenFadeIn();
		alex_timerSet (1, TIMER_SECOND*8, &(flip_sprite_ending) );
		alex_timerSet (0, TIMER_SECOND*12, &(ending_32) );
}

void flip_sprite_ending(){
	alex_spriteRemove(4);
	alex_spriteShow(4, 1, 155, 135, 2, 1, 0, 0);
	alex_spriteMove(4, 175, 135, TIMER_SECOND*4, NULL);
}

void ending_32(){
	alex_screenFadeOut();
	alex_cleanText();
	bgSetDisable(0);
	bgSetDisable(1);
	alex_spriteStopMove(4);
	alex_spriteRemove(3);
	alex_spriteRemove(4);
	
	alex_timerSet (0, TIMER_SECOND*3, &(ending_41) );
}

void ending_41(){
	consoleDrawText(2,13,"The journey already begun. ");
	consoleDrawText(2,14,"There's no turning back.");
	consoleDrawText(2,15,"");
	alex_screenFadeIn();
	
	alex_timerSet (0, TIMER_SECOND*12, &(ending_42) );
}

void ending_42(){
	alex_screenFadeOut();
	alex_cleanText();
	alex_timerSet (0, TIMER_SECOND*3, &(ending_51) );
}

void ending_51(){
	//just the background
	bgSetEnable(1);
	consoleSetTextCol(RGB15(0,0,0),  RGB15(0,0,0));
	consoleDrawText(6,13,"To be continued ... ");
	consoleDrawText(5,14,"Thanks for playing! :) ");
	consoleDrawText(2,15,"");
	setUpdate(&(waitEndtoEnd));
	alex_screenFadeIn();
}

void waitEndtoEnd() {
	if(alex_buttonIsPressed(0, KEY_A) || alex_buttonIsPressed(0, KEY_START)) {
		alex_timerStop(0);
		alex_timerStop(1);
		alex_screenFadeOut();
		alex_melodyFade();
		alex_cleanText();	
		consoleDrawText(2,13,"");
		consoleDrawText(2,14,"");
		consoleDrawText(2,15,"");
		alex_spriteStopMove(0);
		alex_spriteRemove(0);
		setUpdate(&(nothing));
		alex_timerSet (0, TIMER_SECOND*3, &(end_opening) );
	}
}

//============================
//GAME OVER
//============================

void gameover_init(){
	//we dont need backgrounds yet, but text
	//alex_melodyFade();
	
	bgSetDisable(0);
	bgSetDisable(1);
	bgSetEnable(2);
	
	consoleSetTextCol(RGB15(255,255,255),  RGB15(0,0,0));
	consoleDrawText(2,13,"Hilda choose the destiny");
	consoleDrawText(2,14,"of the fallen ones... ");
	consoleDrawText(2,15,"GAME OVER");
	
	alex_screenFadeIn();
	alex_timerSet (0, TIMER_SECOND*8, &(end_gameover) );
}

void end_gameover() {
		alex_timerStop(0);
		alex_timerStop(1);
		alex_screenFadeOut();
		alex_melodyFade();
		alex_cleanText();	
		consoleDrawText(2,13,"");
		consoleDrawText(2,14,"");
		consoleDrawText(2,15,"");
		alex_spriteStopMove(0);
		alex_spriteRemove(0);
		setUpdate(&(nothing));
		alex_timerSet (0, TIMER_SECOND*3, &(end_opening) );
}
//---------------------------------------------------------------------------------==================================================================
// Title screen code
void title_init(void) {
	
	//recover player (here beacuse recover at each level load doesnt have sense)
	player.health= PLAYER_HEALTH;
	gameProgress = 0;
	/*===================
		BACKGROUNDS
	===================*/ 
    // Copy tiles to VRAM
	bgInitTileSet(0, &gfxtitlefore, &paltitlefore, 2, (&gfxtitlefore_end - &gfxtitlefore), 16*2, BG_16COLORS, 	0x2000);
    bgInitTileSet(1, &gfxtitleback, &paltitleback, 1, (&gfxtitleback_end - &gfxtitleback), 16*2, BG_16COLORS, 	0x6000);
	// Copy Map to VRAM
	bgInitMapSet(0, &maptitlefore, (&maptitlefore_end - &maptitlefore),SC_32x32, 								0x5000);
	bgInitMapSet(1, &maptitleback, (&maptitleback_end - &maptitleback),SC_32x32, 								0x5400);
	/*===================
		SPRITES
	===================*/ 
	
	/*===================
		MELODY AND SOUND LOAD
	===================*/ 
	//spcSetSoundEntry(15, 8, 6, &sound_accept_end - &sound_accept, &sound_accept, &sound);
	alex_melodyLoad(MOD_TITLE, MUSIC_VOL_DEFAULT);
	
	
	/*===================
		FINAL TOUCHES
	===================*/
	bgSetEnable(0);
	bgSetEnable(1);
	//bgSetEnable(2);
	
	// And let's show :P
	alex_screenFadeIn();
	
	// Initialize text console with our font
	//consoleInitText(2, 0, &snesfont);
	consoleSetTextCol(RGB15(31,26,28),  RGB15(12,12,12));
	consoleDrawText(14,12,"Press START.");
	// Play music
	alex_melodyPlay();
	//Timer for press start thing
	alex_timerSet (0, TIMER_SECOND, &(t_enableBG2) );
}
void title_dispose() {
	alex_timerStop(0);
	alex_melodyFade();
	alex_screenFadeOut();
	setUpdate(&(nothing));
	alex_timerSet (0, TIMER_SECOND*2, &(waitFadeOut) );

}
void title_update(){
	if(alex_buttonIsPressed(0, KEY_A) || alex_buttonIsPressed(0, KEY_START)) title_dispose();
}

void waitFadeOut(){
	//screen_dispose();
	spcStop();

	loadLevel(LEVEL_2);
}

void nothing(){
	//nothing :P
}

void t_enableBG2(){
	bgSetEnable(2);
	alex_timerSet (0, TIMER_SECOND, &(t_disableBG2) );
}
void t_disableBG2(){
	bgSetDisable(2);
	alex_timerSet (0, TIMER_SECOND, &(t_enableBG2) );
}

	/*===================
		CURANDERO SCENE
	===================*/
bool curandero_excecute = false;
bool curandero_done = false;

void curanderoSceneInit() {
	if (curandero_excecute == false) {
		curandero_excecute = true;
		consoleDrawText(2,3,"I'm not like others. ");
		consoleDrawText(2,4,"I'm just a good monster. ");
		if (curandero_done == true){ 
			alex_timerSet (1, TIMER_SECOND * 5, &(curandero_3) );
		} else {
			alex_timerSet (1, TIMER_SECOND * 5, &(curandero_2) );
		}
		
	}
}

void curandero_2() {
	curandero_done = true;
	player.health= PLAYER_HEALTH;
	consoleDrawText(1,1,"Health: %d",player.health);
	consoleDrawText(2,3,"                              ");
	consoleDrawText(2,4,"                              ");
	consoleDrawText(2,3,"Let me heal you. And well,");
	consoleDrawText(2,4,"sorry for the poor quality ");
	consoleDrawText(2,5,"of this game. ");
	 alex_timerSet (1, TIMER_SECOND * 5, &(curandero_3) );
}

void curandero_3() {
	consoleDrawText(2,3,"                              ");
	consoleDrawText(2,4,"                              ");
	consoleDrawText(2,5,"                              ");
	consoleDrawText(2,3,"Please understand that was");
	consoleDrawText(2,4,"our first SNES, and console");
	consoleDrawText(2,5,"game.");
	 alex_timerSet (1, TIMER_SECOND * 5, &(curandero_4) );
}

void curandero_4() {
	consoleDrawText(2,3,"                              ");
	consoleDrawText(2,4,"                              ");
	consoleDrawText(2,5,"                              ");
	consoleDrawText(2,3,"Hope you like it and hope");
	consoleDrawText(2,4,"you like all games from");
	consoleDrawText(2,5,"#bitbitjam3! :D");
	 alex_timerSet (1, TIMER_SECOND * 5, &(curandero_5) );
}

void curandero_5() {
	consoleDrawText(2,3,"                              ");
	consoleDrawText(2,4,"                              ");
	consoleDrawText(2,5,"                              ");
	curandero_excecute = false;
}

	/*===================
		SISTER SCENE 1
	===================*/
bool sister_excecute = false;
bool sister_done = false;
bool sister_done_2 = false;

void sisterSceneInit() {
	if (sister_excecute == false && sister_done == false) {
		sister_excecute = true;
		alex_melodyLoad(MOD_EVENT, MUSIC_VOL_DEFAULT);
		alex_melodyPlay();
		consoleDrawText(2,3,"Sister... Are you ok?");
		alex_timerSet (1, TIMER_SECOND * 5, &(sister_11) );
	}
}

void sister_11() {
	consoleDrawText(2,3,"                              ");
	consoleDrawText(2,4,"                              ");
	consoleDrawText(2,5,"                              ");
	consoleDrawText(2,3,"Don't be a joker in a time");
	consoleDrawText(2,4,"like this. You need to ");
	consoleDrawText(2,5,"wake up!");
	 alex_timerSet (1, TIMER_SECOND * 5, &(sister_12) );
}

void sister_12() {
	consoleDrawText(2,3,"                              ");
	consoleDrawText(2,4,"                              ");
	consoleDrawText(2,5,"                              ");
	consoleDrawText(2,3,"No... sister. My life has ");
	consoleDrawText(2,4,"no sense without you.");
	consoleDrawText(2,5,"Wake up! Please!");
	 alex_timerSet (1, TIMER_SECOND * 5, &(sister_13) );
}

void sister_13() {
	consoleDrawText(2,3,"                              ");
	consoleDrawText(2,4,"                              ");
	consoleDrawText(2,5,"                              ");
	consoleDrawText(2,3,"NOOOOOOOOOOOOOOOOOO!");
	 alex_timerSet (1, TIMER_SECOND * 5, &(sister_14) );
}

void sister_14() {
	consoleDrawText(2,3,"                              ");
	consoleDrawText(2,4,"                              ");
	consoleDrawText(2,5,"                              ");
	sister_excecute = false;
	sister_done = true;
}

void gotoSisterScene() {
	alex_screenFadeOut();
	platformer_dispose();
	loadLevel(LEVEL_SISTER);
}
	/*===================
		SISTER SCENE 2
	===================*/
void sister_2_init(){
	//we dont need backgrounds yet, but text
	//alex_melodyFade();
	
	bgSetDisable(0);
	bgSetDisable(1);
	bgSetEnable(2);
	
	consoleSetTextCol(RGB15(255,255,255),  RGB15(0,0,0));
	consoleDrawText(2,13,"I promise to kill you.");
	consoleDrawText(2,14,"And put end to this ");
	consoleDrawText(2,15,"never-ending history.");
	
	alex_screenFadeIn();
	alex_timerSet (0, TIMER_SECOND*12, &(end_2_sister1) );
}

void end_2_sister1() {
	alex_screenFadeOut();
	alex_melodyFade();
	alex_cleanText();
	consoleDrawText(2,13,"");
	consoleDrawText(2,14,"");
	consoleDrawText(2,15,"");
	alex_timerSet (0, TIMER_SECOND*3, &(end_2_sister2) );
}

extern int spawnPoint;
void end_2_sister2(){
	sister_done_2 = true;
	consoleSetTextCol(RGB15(31,26,28),  RGB15(12,12,12));
	spawnPoint = 1;
	loadLevel(LEVEL_1);
}