// Copyright 2016 - Ridiculous Glitch <info@ridiculousglitch.com>
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
//
// 1. Redistributions of source code must retain the above copyright
// 	 notice, this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright
// 	 notice, this list of conditions and the following disclaimer in
// 	 the documentation and/or other materials provided with the
// 	 distribution.
//
// 3. Neither the name of the copyright holder nor the names of its
// 	 contributors may be used to endorse or promote products derived
// 	 from this software without specific prior written permission.
//
// 4. Redistributions of any form whatsoever must retain the following
// 	 acknowledgment: 'This product includes software developed by
// 	 Ridiculous Glitch (http://www.ridiculousglitch.com/).'
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
// TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
// PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
// LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
// NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#include "gnes.h"
#include "princess.h"
#include "levels.h"
#include "character.h"
#include "bullets.h"
#include "alien.h"

#include <stdlib.h>

#define SCROLL_BOUND_RIGHT   180
#define SCROLL_BOUND_LEFT    50
#define PRINCESS_WALK_SPEED  5
#define GROUND_Y             0Xbf
#define ENEMIES_MAX          3

enum {
    ENEMY_ALIEN
};

const anim_t ENEMIES_ANIMS_PROTO[][2] = {
  { // Alien
    {  1, 0, 0,  TRUE, ALIEN_WALK_FRAMES_NUM, ALIEN_WALK_FRAMES },
    {  2, 0, 0, FALSE, ALIEN_MASH_FRAMES_NUM, ALIEN_MASH_FRAMES } }
};

static character_t princess[1];
static uint8_t enemies_num = 0, enemies_ids[ENEMIES_MAX];
static lite_character_t enemies[ENEMIES_MAX];
static anim_t enemies_anims[ENEMIES_MAX][2];

int8_t enemy_add(uint8_t enemy_type, uint16_t x, uint16_t y)
{
lite_character_t *enemy;
anim_t *enemy_anims;
uint8_t eid;

  if(enemies_num >= ENEMIES_MAX)
    return -1;

  eid = enemies_ids[enemies_num++];
  enemy = enemies + eid;
  enemy_anims = enemies_anims[eid];
  enemy_anims[0] = ENEMIES_ANIMS_PROTO[enemy_type][0];
  enemy_anims[1] = ENEMIES_ANIMS_PROTO[enemy_type][1];
  //enemies_ids[enemies_num] = enemies_num;

  lite_character_init(enemy_anims, x, y, enemy);
  lite_character_setwalk(0, enemy);
  lite_character_setmash(1, enemy);
  lite_character_add(enemy);
  return eid;
}

void __fastcall__ enemy_remove(int8_t j)
{
uint8_t i;
uint8_t eid = enemies_ids[j];

  lite_character_remove(&enemies[eid]);
  --enemies_num;
  for(i = j; i < enemies_num; ++i)
    enemies_ids[i] = enemies_ids[i + 1];
  enemies_ids[i] = eid;
}

void __fastcall__ princess_init(anim_t* princess_anims, uint16_t x, uint16_t y, character_t* princess)
{
  character_init(princess_anims, x, y, princess);
  character_setidle(PRINCESS_IDLE, princess);
  character_setwalk(PRINCESS_WALK, princess);
  character_setjump(PRINCESS_JUMP, 2, 10, 50, princess);
  character_setshot(PRINCESS_SHOT, princess);
  character_setroll(PRINCESS_ROLL, princess);
  character_setmash(PRINCESS_MASH, princess);
}

int main()
{
uint8_t j1, i, princess_respawn_timeout = 0;
int8_t eid, bid;
bullet_t* bullet;
anim_t princess_anims[] = {
  {  6, 0, 0,  TRUE, PRINCESS_IDLE_FRAMES_NUM, PRINCESS_IDLE_FRAMES },
  {  1, 0, 0,  TRUE, PRINCESS_WALK_FRAMES_NUM, PRINCESS_WALK_FRAMES },
  {  5, 0, 0, FALSE, PRINCESS_JUMP_FRAMES_NUM, PRINCESS_JUMP_FRAMES },
  {  5, 0, 0,  TRUE, PRINCESS_SHOT_FRAMES_NUM, PRINCESS_SHOT_FRAMES },
  {  2, 0, 0, FALSE, PRINCESS_ROLL_FRAMES_NUM, PRINCESS_ROLL_FRAMES },
  {  1, 0, 0, FALSE, PRINCESS_MASH_FRAMES_NUM, PRINCESS_MASH_FRAMES }
};

  bullets_init();
  level_load(level1);

  princess_init(princess_anims, 0x70, GROUND_Y, princess);
  character_add(princess);

  for(i = 0; i < ENEMIES_MAX; ++i)
    enemies_ids[i] = i;

  gnes_start();

  while(1) {
    for(i = 0; i < enemies_num; ++i) {
      for(bid = bullet_first(); bid >= 0; bid = bullet_next(bid)) {
        bullet = bullet_get(bid);

        eid = enemies_ids[i];
        if((lite_character_x(&enemies[eid]) + lite_character_width(&enemies[eid]) < sprite_x(bullet))
          || (sprite_x(bullet) + sprite_width(bullet) < lite_character_x(&enemies[eid])))
            continue;

        // Bullet hit
        lite_character_mash(&enemies[eid]);
        bullet_remove(bid);
        break;
      }
    }

    for(i = 0; i < enemies_num;) {
      eid = enemies_ids[i];

      if((lite_character_mashing(&enemies[eid]) && lite_character_anim_finished(&enemies[eid])) || lite_character_x(&enemies[eid]) < -lite_character_width(&enemies[eid]) || lite_character_x(&enemies[eid]) > cur_level_getwidth())
        enemy_remove(i);
      else
        ++i;
    }

    if(character_mashing(princess) && character_y(princess) != GROUND_Y) {
      if(character_y(princess) + 3 < GROUND_Y)
        character_y(princess) += 3;
      else
        character_y(princess) = GROUND_Y;
    }

    if(princess_respawn_timeout) {
      if(!(--princess_respawn_timeout)) {
        princess_init(princess_anims, sprite_x(princess), GROUND_Y, princess);
      }
      gnes_update();
      continue;
    }

    if(character_mashing(princess) && character_anim_finished(princess)) {
      princess_respawn_timeout = 0x3f;
      continue;
    }

    // Handle user input
    j1 = (character_mashing(princess) ? 0 : joy_read(JOY_1));

    if(JOY_BTN_LEFT(j1))
      character_walk_speed(princess) = -PRINCESS_WALK_SPEED;
    else if(JOY_BTN_RIGHT(j1))
      character_walk_speed(princess) = PRINCESS_WALK_SPEED;
    else
      character_walk_speed(princess) = 0;

    if(JOY_BTN_FIRE(j1)) {
      if(JOY_BTN_DOWN(j1))
        character_roll(princess);
      else if(!character_jumping(princess))
        character_jump_start(princess);
    }
    else if(character_jumping(princess))
      character_jump_stop(princess);

    if(JOY_BTN_FIRE2(j1)) {
      if(!character_shooting(princess))
        character_shot_start(rand() % 2, 10, princess);
    }
    else
      character_shot_stop(princess);

    // Collision check

    if(!character_mashing(princess)) {
      for(i = 0; i < enemies_num; ++i) {
        eid = enemies_ids[i];
        if((character_y(princess) + character_height(princess)) < lite_character_y(&enemies[eid]))
          continue;

        if((lite_character_x(&enemies[eid]) + lite_character_width(&enemies[eid]) < character_x(princess))
          || (character_x(princess) + character_width(princess) < lite_character_x(&enemies[eid])))
            continue;

        // Enemy hit
        character_mash(princess);
      }
    }

    // Scrolling

    if(sprite_x(princess) > level1->viewport_x + SCROLL_BOUND_RIGHT && level_hasscreendir(DIR_RIGHT, level1))
      level1->viewport_x = sprite_x(princess) - SCROLL_BOUND_RIGHT;
    else if(sprite_x(princess) > SCROLL_BOUND_LEFT && sprite_x(princess) < level1->viewport_x + SCROLL_BOUND_LEFT)
      level1->viewport_x = sprite_x(princess) - SCROLL_BOUND_LEFT;

    // Spawn enemy

    if(rand() % 10 == 0) {
      i = rand() % 2;
      eid = enemy_add(ENEMY_ALIEN, (i ? 4 : cur_level_getwidth() - 4), GROUND_Y);
      if(eid >= 0)
        lite_character_walk_speed(&enemies[eid]) = (i ? 3 : -3);
    }

    gnes_update();
  }

  //joy_uninstall();
  return 0;
}




/*
uint8_t princess_collide(const level_t* level, uint16_t pos_x, uint16_t pos_y)
{
uint8_t x, y;
uint16_t i, j;
uint16_t x0 = pos_x >> 3, y0 = pos_y >> 3;
const uint8_t** collisions = level->collisions;
uint8_t cols = level->cols;

  for(y = 0; y <= PRINCESS_HEIGHT; y += PRINCESS_HEIGHT) {
    for(x = 0; x < PRINCESS_WIDTH + 1; ++x) {
      i = y0 + y;
      j = x0 + x;
      if(collisions[(i / 30) * cols + (j / 32)][(i % 30) * 32 + j % 32])
        return 1;
    }
  }

  for(x = 0; x <= PRINCESS_WIDTH; x += PRINCESS_WIDTH) {
    for(y = 0; y < PRINCESS_HEIGHT + 1; ++y) {
      i = y0 + y;
      j = x0 + x;
      if(collisions[(i / 30) * cols + (j / 32)][(i % 30) * 32 + j % 32])
        return 1;
    }
  }

  return 0;
}
*/
