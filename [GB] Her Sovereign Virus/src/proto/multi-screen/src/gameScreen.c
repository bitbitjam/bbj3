/**
 * gameScreen.c
 * Quin Kennedy, David Frankel, Vivek Vimal, Party Skeleton, 2016
 */

#include "include/gameScreen.h"
#include "player.c"
#include "background.c"
#include "include/screen.h"

void gameScreen_enter(){
  player_init();
  background_init();
  //npcs_init();
}

void gameScreen_update(){
  player_update();
  //npcs_update();
  background_update();

  if (joypad() & J_START){
    screen_data.state = END;
  }
}

void gameScreen_draw(){
  //player_draw();
  //background_draw();
}
