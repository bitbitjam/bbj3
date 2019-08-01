/**
 * background.c
 * Quin Kennedy, David Frankel, Vivek Vimal, Party Skeleton, 2016
 */

#include "include/background.h"
#include "background-data.c"
#include <gb/gb.h>

void background_init(){
  UBYTE i, j;
  SHOW_BKG;
  BGP_REG = background_palettes[player_data.position.z];

  /* Initialize the background */
  set_bkg_data(0xFC, 0x04, std_sprite_data);
  set_bkg_data(0x00, 0x2D, background_sprite_data);
  /*
   * Draw the background
   *
   * Width  = 0x100 = 0x20 * 8
   * Height = 0x100 = 0x20 * 8
   */
  for(i = 0; i < 32; i+=8)
    for(j = 0; j < 32; j+=8)
      set_bkg_tiles(i, j, 8, 8, background_tiles);
  background_data.position.x.w = 0;
  background_data.position.y.w = 0;
  SCX_REG = 0;
  SCY_REG = 0;
}

void background_update(){
  background_data.position.x.w += (player_data.speed.x.w >> 2);
  background_data.position.y.w += (player_data.speed.y.w >> 2);
  SCX_REG = background_data.position.x.b.h;
  SCY_REG = background_data.position.y.b.h;
  BGP_REG = background_palettes[player_data.position.z];
}
