/**
 * screen.h
 * Quin Kennedy, David Frankel, Vivek Vimal, Party Skeleton, 2016
 */
#ifndef SCREEN_H
#define SCREEN_H

#include <types.h>

#define NUM_SCREENS 6
typedef enum ScreenState{
  START, DIALOG, GAME, WIN, LOSE, CONTROLS
} ScreenState;

typedef struct ScreenData{
  ScreenState state;
} ScreenData;
ScreenData screen_data;

UBYTE my_sys_time;

void screen_setup();
void screen_update();
void screen_draw();

void (*screen_updates[NUM_SCREENS])();
void (*screen_draws[NUM_SCREENS])();
void (*screen_enters[NUM_SCREENS])();

#endif
