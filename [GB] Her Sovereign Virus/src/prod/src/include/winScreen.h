/**
 * winScreen.h
 * Quin Kennedy, David Frankel, Vivek Vimal, Party Skeleton, 2016
 */
#ifndef WINSCREEN_H
#define WINSCREEN_H

#include <types.h>

typedef struct WinScreenData{
  UBYTE wintime;
} WinScreenData;

WinScreenData winScreen_data;

void winScreen_enter();
void winScreen_update();
void winScreen_draw();

#endif
