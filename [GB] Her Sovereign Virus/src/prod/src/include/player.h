/**
 * player.h
 * Quin Kennedy, David Frankel, Vivek Vimal, Party Skeleton, 2016
 */
#ifndef PLAYER_H
#define PLAYER_H

#include <types.h>
#include "entity.h"

EntityData player_data;

void player_init();
void player_update();
UBYTE player_checkCollision(EntityData *entity);

#endif
