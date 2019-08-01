/**
 * multi.c
 * Quin Kennedy, David Frankel, Vivek Vimal, Party Skeleton, 2016
 */

#include "include/multi.h"
#include "screen.c"

void main(void){
  setup();
  while(1){
    screen_update();
    screen_draw();
    wait_vbl_done();
  }
}

void setup(){
  screen_setup();
}

