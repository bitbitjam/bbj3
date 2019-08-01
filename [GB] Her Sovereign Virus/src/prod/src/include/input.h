/**
 * input.h
 * Quin Kennedy, David Frankel, Vivekanand Vimal, Party Skeleton, 2016
 */
#ifndef INPUT_H
#define INPUT_H

#include <types.h>

#define J_DPAD 0x0FU

//if you want to check something like DPAD_DIR.NONE
// check `input.flags & J_DPAD`
typedef enum DPAD_DIR {
  N, NE, E, SE, S, SW, W, NW
} DPAD_DIR;

typedef struct InputData {
  //yes, these UWORDs will roll-over eventually
  UBYTE dpadFrames;
  UBYTE aFrames;
  UBYTE bFrames;
  DPAD_DIR direction;
  UBYTE flags;
} InputData;

InputData input_data;

void input_update();

#endif
