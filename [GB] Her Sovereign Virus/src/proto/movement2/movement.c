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
//get random generator
#include <rand.h>
//background data - re-used from galaxy demo
#include "background-data.c"
//custom sprite data
#include "cell-data.c"
#include "herpes-data.c"

#include "movement.h"

/* Scroll the background, the window and the sprite */
void scroll()
{
  UBYTE i, j;
  /* Update background */
  bposx.w += sspx.w>>2;
  bposy.w += sspy.w>>2;
  SCX_REG = bposx.b.h;
  SCY_REG = bposy.b.h;
  /* update enemy positions */
  for( i=0, j=2; i != 10; i++){
    eX[i].w -= sspx.w;
    eY[i].w -= sspy.w;
  }
  place_sprite();
}

/* Set sprite tiles */
void tile_sprite()
{
  UBYTE s, i, j;

  //update background palette
  BGP_REG=bgPalettes[zHeight];

  s = herpesFrame << 1;
  set_sprite_tile(0, herpes_tiles[s]);
  set_sprite_tile(1, herpes_tiles[s+1]);
  for( i=0, j=2; i != 10; i++){
    s = eH[i] << 1;
    set_sprite_tile(j++, fmri_tiles[s]);
    set_sprite_tile(j++, fmri_tiles[s+1]);
  }
}

/* Place sprite */
void place_sprite()
{
  UBYTE i, j;
  for( i=0, j=2; i != 10; i++){
    move_sprite(j++, eX[i].b.h, eY[i].b.h);
    move_sprite(j++, eX[i].b.h+8, eY[i].b.h);
  }
}

void handle_input()
{
  UBYTE j, i = joypad();
  bool changedSpeed = false;
  bool changedZ = false;

  if (i & J_UP){
    if (i & (J_LEFT | J_RIGHT)){
      sspy.w -= ACTIVE_ACCEL_DIAG;
    } else {
      sspy.w -= ACTIVE_ACCEL;
    }
    changedSpeed = true;
  }
  if (i & J_DOWN){
    if (i & (J_LEFT | J_RIGHT)){
      sspy.w += ACTIVE_ACCEL_DIAG;
    } else {
      sspy.w += ACTIVE_ACCEL;
    }
    changedSpeed = true;
  }
  if (i & J_LEFT){
    if (i & (J_UP | J_DOWN)){
      sspx.w -= ACTIVE_ACCEL_DIAG;
    } else {
      sspx.w -= ACTIVE_ACCEL;
    }
    changedSpeed = true;
  }
  if (i & J_RIGHT){
    if (i & (J_UP | J_DOWN)){
      sspx.w += ACTIVE_ACCEL_DIAG;
    } else {
      sspx.w += ACTIVE_ACCEL;
    }
    changedSpeed = true;
  }

  if (!changedSpeed){
    if (sspx.w != 0){
      if ((WORD)sspx.w > 0){
        if (sspx.w < PASSIVE_DECEL){
          sspx.w = 0;
        } else {
          sspx.w -= PASSIVE_DECEL;
        }
      } else {
        sspx.w += PASSIVE_DECEL;
      }
    }
    if (sspy.w != 0){
      if ((WORD)sspy.w > 0){
        if (sspy.w < PASSIVE_DECEL){
          sspy.w = 0;
        } else {
          sspy.w -= PASSIVE_DECEL;
        }
      } else {
        sspy.w += PASSIVE_DECEL;
      }
    }
  }

  //every other frame
  //  good combination of responsive and controllable
  //if((time&0x01) == 0) {
    if (i & J_A && zHeight != MAX_Z){// rise
      zHeight++;
      for( j=0; j!=10; j++){
        eH[j]++;
        if (eH[j] == NBSFRAMES){
          eH[j] = 0;
        }
      }
      changedZ = true;
    } else if (i & J_B && zHeight != 0){// dive
      zHeight--;
      for( j = 0; j != 10; j++){
        if (eH[j] == 0){
          eH[j] = NBSFRAMES - 1;
        } else {
          eH[j]--;
        }
      }
      changedZ = true;
    }
  //}

  if (changedZ){
    tile_sprite();
  }
}

void init_bg()
{
  UBYTE i, j;
  SHOW_BKG;
  BGP_REG = bgPalettes[zHeight];

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
}

void init_ship()
{
  /* Initialize the sprite */
  set_sprite_data(0x00, 0x18, herpes_data);
  set_sprite_prop(0, 0x00);
  set_sprite_prop(1, 0x00);
  herpesFrame = 0;
  // center on window
  sposx.w  = 0x5000;
  sposy.w  = 0x5000;
  sspx.w  = 0x0000;
  sspy.w  = 0x0000;
  //place ship in the center, don't move it any more!
  move_sprite(0, sposx.b.h, sposy.b.h);
  move_sprite(1, sposx.b.h+8, sposy.b.h);
  zHeight = 2;
}

void init_enemy()
{
  UBYTE i;

  set_sprite_data(0x22, 0x20, cell_data); 
  for (i = 0; i != 10; i++){
    eX[i].b.h = 16+(((UBYTE)rand()) >> 1);//[16,144]
    eY[i].b.h = 16+(((UBYTE)rand()) >> 1);//[16,144]
    eH[i] = ((UBYTE)rand()) & 0x7;//[0,7]
  }
}

void main()
{
  UBYTE i;

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
  init_ship();
  init_bg();
  OBP0_REG = OBP1_REG = 0x34U;

  initrand(DIV_REG);
  init_enemy();
  tile_sprite();
  place_sprite();

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
