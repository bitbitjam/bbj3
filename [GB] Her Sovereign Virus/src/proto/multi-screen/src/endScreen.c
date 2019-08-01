/**
 * endScreen.c
 * Quin Kennedy, David Frankel, Vivek Vimal, Party Skeleton, 2016
 */

#include "include/endScreen.h"
#include <stdio.h>
#include <gb/font.h>
#include "include/screen.h"
#include <gb/gb.h>

void endScreen_enter(){
  font_t ibm_font;
  //clear screen
  UBYTE i, j;
  UBYTE blankTile = 0xFCU;
  DISPLAY_OFF;
  //reset background to 0,0
  SCX_REG = 0;
  SCY_REG = 0;
  //hide sprites
  //HIDE_SPRITES;
  //we just need to do enough to cover the screen
  for(i = 0; i != 20; i++){
    for(j = 0; j != 18; j++){
      set_bkg_tiles(i, j, 1, 1, &blankTile);
    }
  }

  //load the font we want to use
  font_init();
  ibm_font = font_load(font_ibm);
  //turn off scrolling
  mode(get_mode() | M_NO_SCROLL);

  font_set(ibm_font);
  //write our title
  printf("\n\n\n\n\n\
    GAME OVER");
  //time out after 2 seconds
  endScreen_data.endtime = ((UBYTE)sys_time) + 120;
  DISPLAY_ON;
}

void endScreen_update(){
  if (((UBYTE)sys_time) == endScreen_data.endtime){
    screen_data.state = START;
  }
}
  
void endScreen_draw(){}
