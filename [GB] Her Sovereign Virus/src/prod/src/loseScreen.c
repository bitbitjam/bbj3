/**
 * loseScreen.c
 * Quin Kennedy, David Frankel, Vivek Vimal, Party Skeleton, 2016
 */
#ifndef LOSE_SCREEN_C
#define LOSE_SCREEN_C

#include "include/loseScreen.h"
#include <stdio.h>
#include <gb/font.h>
#include "include/screen.h"
#include <gb/gb.h>
#include "include/input.h"

void loseScreen_enter(){
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
  printf("\
\n\
  Because of your   \
    incompetence    \
  there are still   \
\n\
   3,000,000,000    \
\n\
    BARBARIANS      \
  unconquered by    \
  our sovereignty.  \
                    \
  I can only hope   \
 a superior strain  \
 will succeed you.  \
\n\n\n");
  //time out after 4 seconds
  loseScreen_data.losetime = 240;
}

void loseScreen_update(){
  //if any key is pressed
  if (joypad() & (J_DPAD ^ 0xFF)){
    screen_data.state = START;
  } else {
    if (loseScreen_data.losetime != 0){
      if (loseScreen_data.losetime == 1){
        printf("\
        press START");
      }
      loseScreen_data.losetime--;
    }
  }
}
  
void loseScreen_draw(){}

#endif
