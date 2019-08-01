/**
 * background.c
 * Quin Kennedy, David Frankel, Vivek Vimal, Party Skeleton, 2016
 */
#ifndef BACKGROUND_C
#define BACKGROUND_C

#include "include/background.h"
#include "tiles/background-data.c"
#include "include/player.h"
#include <gb/gb.h>
#include <rand.h>

void background_init(){
  UBYTE i, j, k;
  SHOW_BKG;
  BGP_REG = background_palettes[player_data.position.z];

  /* Initialize the background */
  // load background tiles into VRAM
  set_bkg_data(0x01, BACKGROUND_DATA_SIZE, background_sprite_data);

  background_data.speed.x.w = 0;
  background_data.speed.y.w = 0;

  // create a random background
  for(i = 0, k=0; i != 32; i++){
    for(j = 0; j != 32; j++){
      k++;
      if (k == BACKGROUND_DATA_SIZE){
        k = 0;
      }
      set_bkg_tiles(i, j, 
                    1, 1, 
                    background_tiles +
                      (((UBYTE)rand()) % BACKGROUND_DATA_SIZE));
    }
  }

  //start at 0,0
  background_data.position.x.w = 0;
  background_data.position.y.w = 0;
  SCX_REG = 0;
  SCY_REG = 0;
}

void background_update(){
  UWORD addBy;
  
  addBy = player_data.speed.x.w >> 1;
  //if this is a negative number
  if (player_data.speed.x.b.h & 0x80){
    // pad the addBy number with 1's
    addBy = addBy | 0xC000;
  }
  background_data.position.x.w += addBy;
  addBy = player_data.speed.y.w >> 1;
  //if this is a negative number
  if (player_data.speed.y.b.h & 0x80){
    // pad the addBy number with 1's
    addBy = addBy | 0xC000;
  }
  background_data.position.y.w += addBy;

  SCX_REG = background_data.position.x.b.h;
  SCY_REG = background_data.position.y.b.h;
  BGP_REG = background_palettes[player_data.position.z];
}

#endif
