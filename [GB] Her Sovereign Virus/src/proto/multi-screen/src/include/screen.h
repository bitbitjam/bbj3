/**
 * screen.h
 * Quin Kennedy, David Frankel, Vivek Vimal, Party Skeleton, 2016
 */
#ifndef SCREEN
#define SCREEN

typedef enum ScreenState{
  START, DIALOG, GAME, END
} ScreenState;

typedef struct ScreenData{
  ScreenState state;
} ScreenData;
ScreenData screen_data;

void screen_setup();
void screen_update();
void screen_draw();

void (*screen_updates[4])();
void (*screen_draws[4])();
void (*screen_enters[4])();

#endif
