/**
 * dialogScreen.c
 * Quin Kennedy, David Frankel, Vivek Vimal, Party Skeleton, 2016
 */
#ifndef DIALOG_SCREEN_C
#define DIALOG_SCREEN_C

#include "include/dialogScreen.h"
#include <stdio.h>
#include <gb/font.h>
#include "include/screen.h"
#include <gb/gb.h>
#include "tiles/portrait-data.c"
#include "tiles/splash-data.c"
#include "include/input.h"

void showDialog(DialogEntry *dialog){
  //turn off scrolling
  mode(get_mode() | M_NO_SCROLL);

  if (dialog->speaker == 0){
    //full-screen text
    HIDE_SPRITES;
  } else {
    SHOW_SPRITES;
    //skip over the portraits
    printf("\n\n\n\n\n\n");

    //and change sprite palette based on who is talking
    if (dialog->speaker == 1){
      OBP0_REG = DIALOG_SPEAKER_PALETTE;
      OBP1_REG = DIALOG_LISTENER_PALETTE;
    } else if (dialog->speaker == 2){
      OBP1_REG = DIALOG_SPEAKER_PALETTE;
      OBP0_REG = DIALOG_LISTENER_PALETTE;
    }
  }

  //write our dialog
  printf(dialog->text);
  //show key prompt after 1 second
  dialogScreen_data.dialogTime = 60;
}

void dialogScreen_enter(){
  font_t ibm_font;
  UBYTE i,j,spriteIndex,tileOffset;
  DISPLAY_OFF;
  //change all sprites to 8x8
  SPRITES_8x8;
  set_sprite_data(0, PORTRAIT_DATA_SIZE, portrait_sprite_data);
  //load a blank cell into space 0 (that's what the background defaults to)
  set_bkg_data(0, 1, splash_sprite_data + (0x0D * 16));
  //clear screen
  //place princess on the left
  spriteIndex = 0;
  for( i = 0, tileOffset = 0; i != 32; i+=8){
    for( j = 0; j != 32; j+=8, spriteIndex++, tileOffset++){
      set_sprite_tile(spriteIndex, portrait_tiles[tileOffset + 0x10]);
      move_sprite(spriteIndex, 16 + j, 24 + i);
      set_sprite_prop(spriteIndex, 0x00);//use palette 0
    }
  }
  //place skeletor on the right
  for( i=0, tileOffset = 0; i != 32; i+=8){
    for( j=0; j != 32; j+=8, spriteIndex++, tileOffset++){
      set_sprite_tile(spriteIndex, portrait_tiles[tileOffset + 0x20]);
      move_sprite(spriteIndex, 124 + j, 24 + i);
      set_sprite_prop(spriteIndex, 0x10);//use palette 1
    }
  }
  //move unused sprites offscreen
  for( ; spriteIndex != 40; spriteIndex++){
    set_sprite_tile(spriteIndex, 0);
    move_sprite(spriteIndex, 0, 0);
  }
  //reset background
  BGP_REG = 0xE4U;

  //text output uses background
  SCX_REG = SCY_REG = 0;


  //load the font we want to use
  font_init();
  ibm_font = font_load(font_ibm);
  font_set(ibm_font);
  
  dialogScreen_data.dialogNum = 0;
  showDialog(&(dialog[0]));
  DISPLAY_ON;
}

void dialogScreen_update(){
  input_update();

  //if the a key
  if ((input_data.flags & J_A) &&
      (input_data.aFrames == 0)){
    dialogScreen_data.dialogNum++;
    if (dialogScreen_data.dialogNum == DIALOG_LENGTH){
      screen_data.state = GAME;
    } else {
      showDialog(&(dialog[dialogScreen_data.dialogNum]));
    }
  } else {
    if (dialogScreen_data.dialogTime != 0){
      if (dialogScreen_data.dialogTime == 1){
        printf("\
            press A");
      }
      dialogScreen_data.dialogTime--;
    }
  }
}
  
void dialogScreen_draw(){}

#endif
