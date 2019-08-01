/**
 * winScreen.c
 * Quin Kennedy, David Frankel, Vivek Vimal, Party Skeleton, 2016
 */
#ifndef WIN_SCREEN_C
#define WIN_SCREEN_C

#include "include/winScreen.h"
#include <stdio.h>
#include <gb/font.h>
#include "include/screen.h"
#include <gb/gb.h>
#include "include/input.h"

void winScreen_enter(){
  font_t ibm_font;
  UBYTE i;
  //clear screen
  //put all sprites behind text
  for( i = 0; i != 40; i++){
    set_sprite_prop(i, 0x80);
  }
  //and change sprite palette to something light
  OBP0_REG = OBP1_REG = 0x40;
  //reset background
  BGP_REG = 0xE4U;

  //although I guess the whole printing thing 
  // uses the background layer, so lets put it at 0,0
  SCX_REG = SCY_REG = 0;


  //load the font we want to use
  font_init();
  ibm_font = font_load(font_ibm);
  //turn off scrolling
  mode(get_mode() | M_NO_SCROLL);

  font_set(ibm_font);
  //write our title
  printf("\n\
 You are deserving \n\
  of your royal    \n\
 crown oh majesty! \n\
                   \n\
  With your help   \n\
  we could claim   \n\
 this whole world  \n\
    as our own!    \n\
\n\n\n\n\n\n\n");
  //time out after 4 seconds
  winScreen_data.wintime = 240;
}

void winScreen_update(){
  //if any key is pressed
  if (joypad() & (J_DPAD ^ 0xFF)){
    screen_data.state = START;
  } else {
    if (winScreen_data.wintime != 0){
      if (winScreen_data.wintime == 1){
        printf("\
        press START");
      }
      winScreen_data.wintime--;
    }
  }
}
  
void winScreen_draw(){}

#endif
