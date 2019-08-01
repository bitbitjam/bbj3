/**
 * npc.c
 * Quin Kennedy, David Frankel, Vivek Vimal, Party Skeleton, 2016
 */
#ifndef NPC_C
#define NPC_C

#include "include/npc.h"
#include "tiles/sprite-data.c"
#include <gb/gb.h>
#include <types.h>
#include <rand.h>
#include "include/player.h"
#include "include/screen.h"

void placeSprite(UBYTE index, EntityData *entity){
  move_sprite(index, entity->position.x.b.h, entity->position.y.b.h);
  if (entity->type != VIRUS){
    move_sprite(index+1, entity->position.x.b.h + 8, entity->position.y.b.h);
  }
}

void tileSprite(UBYTE index, const unsigned char tile, EntityType type){
  set_sprite_tile(index, tile);
  if (type != VIRUS){
    set_sprite_tile(index+1, tile + 2);
  }
}

void npc_setVisibility(EntityData *npc, UBYTE spriteIndex){
  //if we are dying, we can keep the dying animation visible
  if (!(npc->dying)){
    //if we are one layer off from the player, 
    // we will be showing the shadow
    if ((npc->position.z == (player_data.position.z + 1)) ||
        ((npc->position.z + 1) == player_data.position.z)){
      npc->visibility = SHADOW;
      //cheaper than doing a Modulo
      npc->animFrame = 0;//npc->animFrame & (NUM_SHADOW_FRAMES - 1);
      tileSprite(spriteIndex, shadow_tiles[npc->animFrame], npc->type);
    } else if (npc->position.z != player_data.position.z){
      npc->visibility = NONE;
      //hide the sprite
      move_sprite(spriteIndex, 0, 0);
      move_sprite(spriteIndex+1, 0, 0);
    } else {
      npc->visibility = FULL;
      tileSprite(spriteIndex, 
                 entity_tiles_ref[npc->type][npc->animFrame], 
                 npc->type);
    }
  }
}

void createNPC(UBYTE index, EntityType type){
  fixed r;
  UBYTE spriteIndex = (index + 1) << 1;
  EntityData *npc = &(npc_data[index]);
  npc_counts[type]++;

  //TODO: figure out why this doesn't work??!?
  //npc->type = type;

  //place at a random location off-screen
  r.w = rand();
  if (r.b.l & 1){
    npc->position.x.b.h = r.b.l << 4;
    npc->position.y.b.h = (r.b.l % 96) + 160;
  } else {
    npc->position.x.b.h = (r.b.l % 80) + 168;
    npc->position.y.b.h = r.b.l << 4;
  }
  //TEMP start with random speed
  r.w = rand();
  //first 3 for x speed
  npc->speed.x.w = (r.b.l & 0x7) - 3;//(-3,4)
  r.w = r.w >> 2;
  //another 3 for y speed (speeds share a bit)
  npc->speed.y.w = (r.b.l & 0x7) - 3;//(-3,4)
  r.w = r.w >> 2;
  //initialize sprite tile reference register
  //make sure sprite is in front of background
  set_sprite_prop(spriteIndex, 0);
  set_sprite_prop(spriteIndex + 1, 0);
  tileSprite(spriteIndex, entity_tiles_ref[type][0], type);
  placeSprite(spriteIndex, npc);

  //last 4 for randomizing animation start point (nice-to-have)
  npc->animFrame = 0;//r.b.l & (entity_anim_frames[type] - 1);

  npc_setVisibility(npc, spriteIndex);
}

void npc_init(){
  UBYTE i;

  for( i=0; i != 4; i++){
    npc_counts[i] = 0;
  }
  for( i=0; i != MAX_NUM_NPC; i++){
    //start with half immune cells and half skin cells
    npc_data[i].type = i & 1;
    //evenly distribute between layers
    //  lets try only setting this once
    npc_data[i].position.z = i % 5;
    //anim mask is now constant too
    npc_data[i].animMask = 7;//magic number
    //set random values
    createNPC(i, npc_data[i].type);
  }
  //update NPC visibility
  npc_playerChangedLayer();
}

void npc_playerChangedLayer(){
  UBYTE i, j;
  for( i=0, j=2; i != MAX_NUM_NPC; i++, j+=2){
    npc_setVisibility(&(npc_data[i]), j);
  }
}

void npc_update(){
  UBYTE i, j, prev_frame, is_player_speed_negative;
  EntityData *npc;
  for( i=0, j=2; i != MAX_NUM_NPC; i++, j+=2){
    npc = &(npc_data[i]);

    //move based on the player's and NPCs speed
    npc->position.x.w = 
      npc->position.x.w + 
      npc->speed.x.w - 
      player_data.speed.x.w;
    npc->position.y.w = 
      npc->position.y.w + 
      npc->speed.y.w - 
      player_data.speed.y.w;

    //animate dying sprites, whether they are visible or not
    if (npc->dying){
      prev_frame = npc->animFrame;
      animate(j, npc);
      //if we looped back to frame 0
      // the cell is now officially dead
      if (prev_frame && !(npc->animFrame)){
        npc->dying = 0;
        //now one fewer skin cell
        npc_counts[SKIN]--;
        //if that was the last skin cell, start the endgame!
        if (npc_counts[SKIN] == 0){
          npc_data[i].type = NEURON;
          //force it to another position
          //TODO: beware, this could mess some stuff up
          npc_data[i].position.z = i % 4;
          if (npc_data[i].position.z == player_data.position.z){
            npc_data[i].position.z++;
          }
          createNPC(i, npc_data[i].type);
          //hopefuly just setting visibility is enough
          npc_setVisibility(&(npc_data[i]), j);
        } else {
          //randomly create another SKIN or IMMUNE cell
          npc_data[i].type = ((UBYTE)rand()) & 1;
          //visibility won't change since z-placement won't change
          createNPC(i, npc_data[i].type);
        }
      } else {
        //keep the sprite moving
        placeSprite(j, npc);
      }
    } else if (npc->visibility != NONE){
      if (player_checkCollision(npc)){
        switch (npc->type){
          case NEURON:
            screen_data.state = WIN;
            return;
          case IMMUNE:
            screen_data.state = LOSE;
            return;
          case SKIN:
            //cut the player's speed in half
            is_player_speed_negative = 
              (player_data.speed.x.b.h & 0x80U);
            player_data.speed.x.w = player_data.speed.x.w >> 1;
            if (is_player_speed_negative){
              player_data.speed.x.b.h = player_data.speed.x.b.h | 0x80U;
            }
            is_player_speed_negative = 
              (player_data.speed.y.b.h & 0x80U);
            player_data.speed.y.w = player_data.speed.y.w >> 1;
            if (is_player_speed_negative){
              player_data.speed.y.b.h = player_data.speed.y.b.h | 0x80U;
            }
            npc->dying = 1;
            npc->animFrame = 0;
        }
      }
      placeSprite(j, npc);
      animate(j, npc);
    }
  }
}

void npc_draw(){
}

#endif
