/**
 * input.h
 * Quin Kennedy, David Frankel, Vivekanand Vimal, Party Skeleton, 2016
 */

#ifndef INPUT
#define INPUT

#include <types.h>

#define J_DPAD 0x0FU

//if you want to check something like DPAD_DIR.NONE
// check `input.flags & J_DPAD`
enum DPAD_DIR {
  N, NE, E, SE, S, SW, W, NW
};

typedef struct InputData {
  //yes, these UWORDs will roll-over eventually
  UBYTE dpadFrames;
  UBYTE aFrames;
  UBYTE bFrames;
  enum DPAD_DIR direction;
  UBYTE flags;
} InputData;

InputData input_data;

void input_update();

#endif
