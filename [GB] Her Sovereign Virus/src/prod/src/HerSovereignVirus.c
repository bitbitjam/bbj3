/**
 * HerSovereignVirus.c
 * Quin Kennedy, David Frankel, Vivek Vimal, Party Skeleton, 2016
 */
#ifndef HER_SOVEREIGN_VIRUS_C
#define HER_SOVEREIGN_VIRUS_C

#include "include/HerSovereignVirus.h"
#include "screen.c"
#include "input.c"
#include <gb/gb.h>

int main(void){
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

#endif
