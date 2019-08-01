/**
 * player.c
 * Quin Kennedy, David Frankel, Vivek Vimal, Party Skeleton, 2016
 */
#ifndef PLAYER_C
#define PLAYER_C

#include "include/player.h"
#include "tiles/sprite-data.c"
#include <gb/gb.h>
#include "include/input.h"
#include "entity.c"

void player_init(){
  set_sprite_tile(0, virus_tiles[0]);
  //set_sprite_prop(0, 0)//use palette 0
  //for now we are always a virus
  player_data.type = VIRUS;
  // set up variables
  player_data.speed.straight.w = 0x0005;
  player_data.speed.diagonal.w = 0x0003;
  player_data.speed.decelerate.w = 0x0001;
  player_data.animMask = 1;//magic number
  player_data.animFrame = 0;
  player_data.visibility = FULL;
  // center player on screen
  player_data.position.x.w = 0x5000;
  player_data.position.y.w = 0x5000;
  player_data.position.z = 2;
  player_data.speed.x.w = 0x0000;
  player_data.speed.y.w = 0x0000;
  // set registers
  move_sprite(0, player_data.position.x.b.h, player_data.position.y.b.h);
  //the player is responsible for sprite 2 too,
  // in case it wants to be 16pixels wide
  move_sprite(1, 0, 0);
}

void player_update(){
  input_update();

  //if any of the d-pad buttons are pressed
  if (input_data.flags & J_DPAD){
    moveToward(input_data.direction, &player_data);
  } 
  // otherwise you are decelerating
  else {
    slowDown(&player_data);
  }

  if ((input_data.flags & J_A) &&
      !(input_data.aFrames & 0xF) &&
      (player_data.position.z != 0)){
    player_data.position.z--;
    npc_playerChangedLayer();
  } else if ((input_data.flags & J_B) &&
             !(input_data.bFrames & 0xF) &&
             (player_data.position.z != MAX_LAYER)){
    player_data.position.z++;
    npc_playerChangedLayer();
  }
  animate(0, &player_data);
}

UBYTE player_checkCollision(EntityData *entity){
  UBYTE player_hit_x, player_hit_y, entityBorder;
  //if the entity is on the player's same level
  //and not a VIRUS (virus doesn't hit virus)
  if (player_data.position.z == entity->position.z &&
      entity->type != VIRUS){
    switch (entity->type){
      case IMMUNE:
        entityBorder = 4;
        break;
      case SKIN:
      case NEURON:
        entityBorder = 2;
        break;
    }
    player_hit_x = player_data.position.x.b.h + 4;
    player_hit_y = player_data.position.y.b.h + 4;
    
    if (player_hit_x >= (entity->position.x.b.h + entityBorder) &&
        player_hit_y >= (entity->position.y.b.h + entityBorder) &&
        player_hit_x <= (entity->position.x.b.h + 16 - entityBorder) &&
        player_hit_y <= (entity->position.y.b.h + 16 - entityBorder)){
      return 1;
    }
  }
  return 0;
}

#endif
