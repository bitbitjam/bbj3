/**
 * input.c
 * Quin Kennedy, David Frankel, Vivek Vimal, Party Skeleton, 2016
 */

#include "include/input.h"
#include <gb/gb.h>

static void input_update(){
  UBYTE newFlags = joypad();
  UBYTE oldFlags = input_data.flags;

  if (newFlags & J_A == oldFlags & J_A){
    input_data.aFrames++;
  } else {
    input_data.aFrames = 0;
  }

  if (newFlags & J_B == oldFlags & J_B){
    input_data.bFrames++;
  } else {
    input_data.bFrames = 0;
  }

  if (newFlags & J_DPAD){
    if (!(oldFlags & J_DPAD)){
      input_data.dpadFrames = 0;
    } else {
      input_data.dpadFrames++;
    }

    if (newFlags & J_UP){
      if (newFlags & J_LEFT){
        input_data.direction = NW;
      } else if (newFlags & J_RIGHT){
        input_data.direction = NE;
      } else {
        input_data.direction = N;
      }
    } else if (newFlags & J_DOWN){
      if (newFlags & J_LEFT){
        input_data.direction = SW;
      } else if (newFlags & J_RIGHT){
        input_data.direction = SE;
      } else {
        input_data.direction = S;
      }
    } else if (newFlags & J_LEFT){
      input_data.direction = W;
    } else if (newFlags & J_RIGHT){
      input_data.direction = E;
    }
  } else {
    if (oldFlags & J_DPAD){
      input_data.dpadFrames = 0;
    } else {
      input_data.dpadFrames++;
    }
  }


  input_data.flags = newFlags;
}

