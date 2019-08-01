/*
 * movement.h
 *
 * An initial test program exploring movement.
 * This demo is based on the 'galaxy' demo included with the GBDK

 * I have used fixed-point values for both the position and
 *  speed of objects to get smooth movements
 * 
 * OBJ data             : 0x8000 -> 0x8FFF (unsigned)
 * Window data          : 0x8800 -> 0x97FF (unsigned)
 * Background data      : 0x8800 -> 0x97FF (signed)
 * 
 * Tiled 0xFC -> 0xFF are standard tiles (all black -> all white)
 */

//gbdk API
#include <gb/gb.h>
//background data - re-used from galaxy demo
#include "data.c"
//custom sprite data
#include "ship.c"
#include "movement.h"

/* Scroll the background, the window and the sprite */
void scroll()
{
  /* Update background */
  bposx.w += bspx.w;
  bposy.w += bspy.w;
  SCX_REG = bposx.b.h;
  SCY_REG = bposy.b.h;

  /* Update sprite */
  sposx.w += sspx.w;
  sposy.w += sspy.w;
  place_sprite();
}

void update_speed()
{
  switch(shipDir){
    case DIR_N:
      sspx.w = 0;
      sspy.w = -shipSpeed.w;
      break;
    case DIR_NE:
      sspx.w = (shipSpeed.w*3)>>2;
      sspy.w = -sspx.w;
      break;
    case DIR_E:
      sspx.w = shipSpeed.w;
      sspy.w = 0;
      break;
    case DIR_SE:
      sspx.w = (shipSpeed.w*3)>>2;
      sspy.w = sspx.w;
      break;
    case DIR_S:
      sspx.w = 0;
      sspy.w = shipSpeed.w;
      break;
    case DIR_SW:
      sspx.w = -((shipSpeed.w*3)>>2);
      sspy.w = -sspx.w;
      break;
    case DIR_W:
      sspx.w = -shipSpeed.w;
      sspy.w = 0;
      break;
    case DIR_NW:
      sspx.w = -((shipSpeed.w*3)>>2);
      sspy.w = sspx.w;
      break;
  }
}

/* Set sprite tiles */
void tile_sprite()
{
  UBYTE s;

  s = shipDir<<1;
  set_sprite_tile(0, ship_tiles[s]);
  set_sprite_tile(1, ship_tiles[s+1]);
}

/* Place sprite */
void place_sprite()
{
  move_sprite(0, sposx.b.h, sposy.b.h);
  move_sprite(1, sposx.b.h+8, sposy.b.h);
}

void handle_input()
{
  UBYTE i = joypad();
  bool changedDir = false;
  bool changedSpeed = false;
#ifdef USE_CARDINAL
  UBYTE prevDir = shipDir;
  if (i & J_UP){
    if (i & J_RIGHT){// North-East
      shipDir = DIR_NE;
    } else if (i & J_LEFT){// North-West
      shipDir = DIR_NW;
    } else { // North
      shipDir = DIR_N;
    }
  } else if (i & J_DOWN){
    if (i & J_RIGHT){// South-East
      shipDir = DIR_SE;
    } else if (i & J_LEFT){// South-West
      shipDir = DIR_SW;
    } else { // South
      shipDir = DIR_S;
    }
  } else if (i & J_RIGHT){// East
    shipDir = DIR_E;
  } else if (i & J_LEFT){// West
    shipDir = DIR_W;
  }
  
#ifndef CONST_VELOCITY
  if (i & (J_UP | J_DOWN | J_LEFT | J_RIGHT)){
    if (shipSpeed.w == 0){
      shipSpeed.w = 0x0080;
      changedSpeed = true;
    }
  } else if (shipSpeed.w != 0){
    shipSpeed.w = 0;
    changedSpeed = true;
  }
#endif // CONST_VELOCITY

  changedDir = (prevDir != shipDir);
#else // !USE_CARDINAL
  //every other frame
  //  good combination of responsive and controllable
  if((time&0x01) == 0) {
    if (i & J_RIGHT){// Clockwise
      if (shipDir == DIR_NW){
        shipDir = DIR_N;
      } else {
        shipDir++;
      }
    } else if (i & J_LEFT){// Counter-Clockwise
      if (shipDir == DIR_N){
        shipDir = DIR_NW;
      } else {
        shipDir--;
      }
    }
    changedDir = true;
  }

#ifndef CONST_VELOCITY
  //I was running into bugs with negavite shipSpeed, 
  //  so no reverse right now
  if (i & J_UP){
    if (shipSpeed.w <= 0){
      shipSpeed.w = 0x0080;
      changedSpeed = true;
    }
  } else if (shipSpeed.w != 0){
    shipSpeed.w = 0;
    changedSpeed = true;
  }
#endif // CONST_VELOCITY

#endif // USE_CARDINAL

  if (changedDir){
    tile_sprite();
  }

  if (changedDir || changedSpeed){
    update_speed();
  }

/*
  if(i & J_UP)
    sspy.w -= 0x0010;
  if(i & J_DOWN)
    sspy.w += 0x0010;
  if(i & J_LEFT)
    sspx.w -= 0x0010;
  if(i & J_RIGHT)
    sspx.w += 0x0010;
  if(i & J_B) {
    if(i & J_UP)
      bspy.w -= 0x0010;
    if(i & J_DOWN)
      bspy.w += 0x0010;
    if(i & J_LEFT)
      bspx.w -= 0x0010;
    if(i & J_RIGHT)
      bspx.w += 0x0010;
  } else if(i & J_A) {
  } else {
    if(i & J_SELECT){}
    if(i & J_START){}
  }
*/
}

void main()
{
  UBYTE i, j;

  disable_interrupts();
  LCDC_REG = 0x46;// 01000110
  /*
   * LCD        = Off
   * WindowBank = 0x9C00
   * Window     = Off
   * BG Chr     = 0x8800
   * BG Bank    = 0x9800
   * OBJ        = 8x16
   * OBJ        = On
   * BG         = Off
   */
#ifdef SHOW_BG
  SHOW_BKG;
#endif

  /* Set palettes */
  BGP_REG = 0xE4U;
#ifdef SHOW_BG
  OBP0_REG = OBP1_REG = 0x34U;
#else
  OBP0_REG = OBP1_REG = 0xE4U;
#endif

  /* Initialize the background */
  set_bkg_data(0xFC, 0x04, std_data);
  set_bkg_data(0x00, 0x2D, bkg_data);
  /*
   * Draw the background
   *
   * Width  = 0x100 = 0x20 * 8
   * Height = 0x100 = 0x20 * 8
   */
  for(i = 0; i < 32; i+=8)
    for(j = 0; j < 32; j+=8)
      set_bkg_tiles(i, j, 8, 8, bkg_tiles);
  bposx.w = 0;
  SCX_REG = 0;
  bposy.w = 0;
  SCY_REG = 0;
  bspx.w = 0x0000;
  bspy.w = 0x0000;

  /* Initialize the sprite */
  set_sprite_data(0x00, 0x40, ship_data);
  set_sprite_prop(0, 0x00);
  set_sprite_prop(1, 0x00);
  shipDir = DIR_N;
  sposx.w  = 0x5000;
  sposy.w  = 0x5000;
#ifdef CONST_VELOCITY
  shipSpeed.w = 0x0080;;
#else
  shipSpeed.w = 0x0000;
#endif
  sspx.w  = 0x0000;
  sspy.w  = 0x0000;
  tile_sprite();
  place_sprite();
  update_speed();

  DISPLAY_ON;
  enable_interrupts();

  while(1) {
    /* Skip four VBLs (slow down animation) */
    for(i = 0; i < 4; i++)
      wait_vbl_done();
    time++;
    scroll();
    //animate_sprite();
    handle_input();
  }
}
