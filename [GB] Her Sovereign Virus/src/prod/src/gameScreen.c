/**
 * gameScreen.c
 * Quin Kennedy, David Frankel, Vivek Vimal, Party Skeleton, 2016
 */
#ifndef GAME_SCREEN_C
#define GAME_SCREEN_C

#include "include/gameScreen.h"
#include "tiles/sprite-data.c"
#include "player.c"
#include "background.c"
#include "sound.c"
#include "include/screen.h"
#include "npc.c"
#include <gb/gb.h>
#include <rand.h>

void gameScreen_enter(){
  DISPLAY_OFF;
  SHOW_SPRITES;
  SPRITES_8x16;

  //load game sprites into VRAM
  set_sprite_data(0x00, SPRITE_DATA_SIZE, sprite_tile_data);
  //set up the sprite registers to be different
  OBP0_REG = 0xE4U;//3-2-1-0
  OBP1_REG = 0x1BU;//0-1-2-3

  initrand(DIV_REG);
  player_init();
  npc_init();
  background_init();
  sound_init();

  DISPLAY_ON;
}

void gameScreen_update(){
  player_update();
  npc_update();
  background_update();
  sound_update();
}

void gameScreen_draw(){
  //player_draw();
  //background_draw();
}

#endif
