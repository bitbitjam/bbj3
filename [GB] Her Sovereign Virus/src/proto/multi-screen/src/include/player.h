/**
 * player.h
 * Quin Kennedy, David Frankel, Vivek Vimal, Party Skeleton, 2016
 */
#ifndef PLAYER
#define PLAYER

#include <types.h>

typedef struct Position{
  fixed x;
  fixed y;
  UBYTE z;
} Position;

typedef struct Speed{
  fixed x;
  fixed y;
  fixed straight;
  fixed diagonal;
  fixed decelerate;
} Speed;

typedef struct PlayerData{
  Position position;
  Speed speed;
} PlayerData;

PlayerData player_data;

void player_init();
void player_update();

#endif
