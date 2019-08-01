/**
 * background.h
 * Quin Kennedy, David Frankel, Vivek Vimal, Party Skeleton, 2016
 */
#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "entity.h"

//typedef struct BackgroundData{
//  Position position;
//} BackgroundData;

EntityData background_data;
//1-0-0-0, 2-1-0-0, 3-2-1-0, 3-3-2-1, 3-3-3-2{0x40U,0x90U,0xE4U,0xF9U,0xFEU}
//3-3-3-2, 3-3-2-1, 3-3-2-0, 3-2-1-0, 2-1-1-0
UBYTE background_palettes[NUM_LAYERS] = {0xFEU,0xF9U,0xF4U,0xE4U,0x94U};

void background_init();
void background_update();

#endif
