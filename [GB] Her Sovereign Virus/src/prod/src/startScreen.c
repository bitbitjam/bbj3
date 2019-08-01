/**
 * startScreen.c
 * Quin Kennedy, David Frankel, Vivek Vimal, Party Skeleton, 2016
 */
#ifndef START_SCREEN_C
#define START_SCREEN_C

#include "include/startScreen.h"
#include <stdio.h>
#include <gb/font.h>
#include "include/screen.h"
#include "tiles/splash-data.c"

void startScreen_splash(){
  set_bkg_data(0x00, SPLASH_DATA_SIZE, splash_sprite_data);
  set_bkg_tiles(0, 0, 20, 14, splash_tiles);
  set_bkg_tiles(0, 14, 20, 4, splash_blank_tiles);
}

void startScreen_enter(){
  DISPLAY_OFF;
  HIDE_SPRITES;
  NR52_REG = 0x00;// TURN SOUND OFF
  BGP_REG = 0x50;
  SCX_REG = SCY_REG = 0;
  //initialize graphic
  startScreen_splash();
  //no font, text is burned into the splash screen
  startScreen_data.showStart = 255;
  DISPLAY_ON;
}

void startScreen_update(){
  if (joypad() & J_START){
    screen_data.state = DIALOG;
  } else if (joypad() & J_SELECT){
    screen_data.state = CONTROLS;
  } else {
    if (startScreen_data.showStart != 0){
      switch(startScreen_data.showStart){
        case 220:
          BGP_REG = 0xA4;
          break;
        case 180:
          BGP_REG = 0xE4;
          break;
        case 120:
          set_bkg_tiles(0, 14, 20, 2, splash_tiles + (20 * 14));
          break;
        case 60:
          set_bkg_tiles(0, 16, 20, 2, splash_blank_tiles);
          break;
        case 1:
          set_bkg_tiles(0, 16, 20, 2, splash_tiles + (20 * 16));
          startScreen_data.showStart = 119;
          break;
      }
      startScreen_data.showStart--;
    }
  }
}

void startScreen_draw(){}

#endif
