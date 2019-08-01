/**
 * controlScreen.h
 * Quin Kennedy, David Frankel, Vivek Vimal, Party Skeleton, 2016
 */
#ifndef CONTROL_SCREEN_H
#define CONTROL_SCREEN_H

#include "entity.h"

typedef struct ControlData{
  UBYTE timer;
  EntityData sprites[3];
  UBYTE screen;
} ControlData;

ControlData controlScreen_data;

void controlScreen_enter();
void controlScreen_update();
void controlScreen_draw();

#endif
