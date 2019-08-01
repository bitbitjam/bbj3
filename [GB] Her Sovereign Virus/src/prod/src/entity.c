/**
 * entity.c
 * Quin Kennedy, David Frankel, Vivek Vimal, Party Skeleton, 2016
 */
#ifndef ENTITY_C
#define ENTITY_C

#include "include/entity.h"
#include <gb/gb.h>
#include "include/player.h"
//for the tile sprite method
#include "include/npc.h"
//for my_sys_time
#include "include/screen.h"

void moveToward(DPAD_DIR direction, EntityData *data){
  switch(direction){
    case N:
      data->speed.y.w -= data->speed.straight.w;
      break;
    case NE:
      data->speed.y.w -= data->speed.diagonal.w;
      data->speed.x.w += data->speed.diagonal.w;
      break;
    case E:
      data->speed.x.w += data->speed.straight.w;
      break;
    case SE:
      data->speed.y.w += data->speed.diagonal.w;
      data->speed.x.w += data->speed.diagonal.w;
      break;
    case S:
      data->speed.y.w += data->speed.straight.w;
      break;
    case SW:
      data->speed.y.w += data->speed.diagonal.w;
      data->speed.x.w -= data->speed.diagonal.w;
      break;
    case W:
      data->speed.x.w -= data->speed.straight.w;
      break;
    case NW:
      data->speed.y.w -= data->speed.diagonal.w;
      data->speed.x.w -= data->speed.diagonal.w;
      break;
  }
}

void slowDown(EntityData *data){
  if (data->speed.x.w != 0){
    if (((WORD)data->speed.x.w) > 0){
      if (data->speed.x.w < data->speed.decelerate.w){
        data->speed.x.w = 0;
      } else {
        data->speed.x.w -= data->speed.decelerate.w;
      }
    } else {
      data->speed.x.w += data->speed.decelerate.w;
    }
  }
  if (data->speed.y.w != 0){
    if (((WORD)data->speed.y.w) > 0){
      if (data->speed.y.w < data->speed.decelerate.w){
        data->speed.y.w = 0;
      } else {
        data->speed.y.w -= data->speed.decelerate.w;
      }
    } else {
      data->speed.y.w += data->speed.decelerate.w;
    }
  }
}

//will animate regardless of visibility
void animate(UBYTE spriteIndex, EntityData *data){
  if ((my_sys_time & data->animMask) == 0){
    data->animFrame++;
    if (data->dying){
      if (data->animFrame == NUM_SKIN_DEATH_FRAMES){
        //if the death frames looped back to zero, 
        // we shouldn't need to update the visible sprite
        // someone else should clean it up
        data->animFrame = 0;
      } else {
        tileSprite(spriteIndex,
                   //the death animation is defined after the dwell animation
                   skin_tiles[data->animFrame + entity_anim_frames[SKIN]],
                   data->type);
      }
    } else if (data->visibility == FULL){
      if (data->animFrame == entity_anim_frames[data->type]){
        data->animFrame = 0;
      }
      tileSprite(spriteIndex, 
                 entity_tiles_ref[data->type][data->animFrame],
                 data->type);
    } else {
      if (data->animFrame == NUM_SHADOW_FRAMES){
        data->animFrame = 0;
      }
      tileSprite(spriteIndex,
                 shadow_tiles[data->animFrame],
                 data->type);
    }
  }
}

#endif
