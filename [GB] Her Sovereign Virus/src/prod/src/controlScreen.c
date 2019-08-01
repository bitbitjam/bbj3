/**
 * controlScreen.c
 * Quin Kennedy, David Frankel, Vivek Vimal, Party Skeleton, 2016
 */
#ifndef CONTROL_SCREEN_C
#define CONTROL_SCREEN_C

#include "include/controlScreen.h"
#include <stdio.h>
#include <gb/font.h>
#include "include/screen.h"
#include <gb/gb.h>
#include "tiles/portrait-data.c"
#include "tiles/splash-data.c"
#include "include/npc.h"
#include "include/input.h"

void controlScreen_setSprites(){
  UBYTE i;

  switch(controlScreen_data.screen){
    case 0:
      //change sprites to 8x16
      SPRITES_8x16;
      set_sprite_data(0, SPRITE_DATA_SIZE, sprite_tile_data);

      controlScreen_data.sprites[IMMUNE].position.y.b.h = 75;
      controlScreen_data.sprites[SKIN].position.y.b.h = 100;
      controlScreen_data.sprites[NEURON].position.y.b.h = 128;
      for(i = 0; i != 3; i++){
        controlScreen_data.sprites[i].type = i;
        controlScreen_data.sprites[i].animMask = 7;
        controlScreen_data.sprites[i].speed.x.w = 0;
        controlScreen_data.sprites[i].speed.y.w = 0;
        controlScreen_data.sprites[i].visibility = FULL;
        controlScreen_data.sprites[i].animFrame = 0;
        controlScreen_data.sprites[i].position.x.b.h = 144;
        tileSprite( i << 1, entity_tiles_ref[i][0], i);
        placeSprite( i << 1, &(controlScreen_data.sprites[i]) );
      }
      //can someone tell me why, if I don't do this,
      //  when I call "animate" in update, all the sprites turn into 
      //  immunity cells?
      controlScreen_data.sprites[IMMUNE].type = IMMUNE;
      controlScreen_data.sprites[SKIN].type = SKIN;
      controlScreen_data.sprites[NEURON].type = NEURON;

      //set all other sprites off screen
      for( i = 6; i != 40; i++){
        move_sprite(i, 0, 0);
      }
      SHOW_SPRITES;
      break;
    default:
      HIDE_SPRITES;
      break;
  }
}

void controlScreen_setText(){
  font_t ibm_font;
  //load the font we want to use
  font_init();
  ibm_font = font_load(font_ibm);
  font_set(ibm_font);

  //turn off scrolling -- also resets background to 0,0
  mode(get_mode() | M_NO_SCROLL);

  switch (controlScreen_data.screen){
    case 0:
      printf("\
\n\
   Use the D-Pad    \
   to move in X/Y   \
\n\
      Use A/B       \
    to move in Z    \
\n\n\
     Avoid these:\n\
\n\n\
 Intercept these:\n\
\n\
 Win by getting\n\
            this:\n\n\n");
      break;
    default:
      printf("\
\n\n\
   Only one team\n\
  could have been\n\
    assembled to\n\
  create this epic\n\
\n\
\n\
 David Frankel\n\
\n\
 Vivekanand Vimal\n\
\n\
 Quin Kennedy\n\
\n\
 The Party Skeleton\
\n\n\n");
      break;
  }
}

void controlScreen_enter(){
  DISPLAY_OFF;
  BGP_REG = OBP0_REG = OBP1_REG = 0xE4U;
  //load a blank cell into space 0 (that's what the background defaults to)
  set_bkg_data(0, 1, splash_sprite_data + (0x0D * 16));

  controlScreen_data.screen = 0;
  controlScreen_setText();
  controlScreen_setSprites();
  controlScreen_data.timer = 60;
  
  DISPLAY_ON;
}

void controlScreen_update(){
  UBYTE i;
  input_update();

  //animate the sprites
  for( i=0; i != 3; i++){
    animate( i << 1, &(controlScreen_data.sprites[i]));
  }

  //check/update user interface
  if ((input_data.flags & J_A) &&
      (input_data.aFrames == 0)){
    if (controlScreen_data.screen == 1){
      screen_data.state = START;
    } else {
      controlScreen_data.screen++;
      controlScreen_setText();
      controlScreen_setSprites();
      controlScreen_data.timer = 60;
    }
  } else {
    if (controlScreen_data.timer != 0){
      if (controlScreen_data.timer == 1){
        printf("\
            press A");
      }
      controlScreen_data.timer--;
    }
  }
}
  
void controlScreen_draw(){}

#endif
