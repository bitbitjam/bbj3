/**
 * loseScreen.h
 * Quin Kennedy, David Frankel, Vivek Vimal, Party Skeleton, 2016
 */
#ifndef LOSESCREEN_H
#define LOSESCREEN_H

#include <types.h>

typedef struct LoseScreenData{
  UBYTE losetime;
} LoseScreenData;

LoseScreenData loseScreen_data;

void loseScreen_enter();
void loseScreen_update();
void loseScreen_draw();

#endif
