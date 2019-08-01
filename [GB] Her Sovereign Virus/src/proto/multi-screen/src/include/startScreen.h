/**
 * startScreen.h
 * Quin Kennedy, David Frankel, Vivek Vimal, Party Skeleton, 2016
 */
#ifndef START_SCREEN
#define START_SCREEN

#include <types.h>

typedef struct StartScreenData {
  UBYTE showStart;
} StartScreenData;

StartScreenData startScreen_data;

void startScreen_enter();
void startScreen_update();
void startScreen_draw();

#endif
