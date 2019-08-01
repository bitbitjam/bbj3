/**
 * player.c
 * Quin Kennedy, David Frankel, Vivek Vimal, Party Skeleton, 2016
 */

#include "include/player.h"
#include "player-data.c"
#include <gb/gb.h>
#include "input.c"

void player_init(){
  // load sprite into VRAM
  set_sprite_data(0x00, 0x18, player_sprite_data);
  set_sprite_prop(0, 0x00);
  // set up variables
  player_data.speed.straight.w = 0x0030;
  player_data.speed.diagonal.w = 0x0022;
  player_data.speed.decelerate.w = 0x0006;
  // center player on screen
  player_data.position.x.w = 0x5000;
  player_data.position.y.w = 0x5000;
  player_data.position.z = 2;
  player_data.speed.x.w = 0x0000;
  player_data.speed.y.w = 0x0000;
  // set registers
  move_sprite(0, player_data.position.x.b.h, player_data.position.y.b.h);
}

void player_update(){
  input_update();

  //if any of the d-pad buttons are pressed
  if (input_data.flags & J_DPAD){
    switch(input_data.direction){
      case N:
        player_data.speed.y.w -= player_data.speed.straight.w;
        break;
      case NE:
        player_data.speed.y.w -= player_data.speed.diagonal.w;
        player_data.speed.x.w += player_data.speed.diagonal.w;
        break;
      case E:
        player_data.speed.x.w += player_data.speed.straight.w;
        break;
      case SE:
        player_data.speed.y.w += player_data.speed.diagonal.w;
        player_data.speed.x.w += player_data.speed.diagonal.w;
        break;
      case S:
        player_data.speed.y.w += player_data.speed.straight.w;
        break;
      case SW:
        player_data.speed.y.w += player_data.speed.diagonal.w;
        player_data.speed.x.w -= player_data.speed.diagonal.w;
        break;
      case W:
        player_data.speed.x.w -= player_data.speed.straight.w;
        break;
      case NW:
        player_data.speed.y.w -= player_data.speed.diagonal.w;
        player_data.speed.x.w -= player_data.speed.diagonal.w;
        break;
    }
  } 
  // otherwise you are decelerating
  else {
    if (player_data.speed.x.w != 0){
      if ((WORD)player_data.speed.x.w > 0){
        if (player_data.speed.x.w < player_data.speed.decelerate.w){
          player_data.speed.x.w = 0;
        } else {
          player_data.speed.x.w -= player_data.speed.decelerate.w;
        }
      } else {
        player_data.speed.x.w += player_data.speed.decelerate.w;
      }
    }
    if (player_data.speed.y.w != 0){
      if ((WORD)player_data.speed.y.w > 0){
        if (player_data.speed.y.w < player_data.speed.decelerate.w){
          player_data.speed.y.w = 0;
        } else {
          player_data.speed.y.w -= player_data.speed.decelerate.w;
        }
      } else {
        player_data.speed.y.w += player_data.speed.decelerate.w;
      }
    }
  }
}
