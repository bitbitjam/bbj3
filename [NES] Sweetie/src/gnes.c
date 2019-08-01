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
#include <string.h>
#include <time.h>

#define OAM_DMA *((unsigned char*)0x4014)

static tile_t *TILES = (tile_t*)0x200;
static sprite_t *_sprites[SPRITES_MAX];
static uint8_t _sprites_num = 0;
level_t *cur_level = 0;

//#pragma bss-name(push, "ZEROPAGE")
uint8_t _cur_nametable = 0, _scroll_x = 0, _scroll_y = 0;

void __fastcall__ level_load(level_t* l)
{
  cur_level = l;
  screen_load(_cur_nametable, level_getscreencur(l));

  // WRONG!!!!!!!!!!!!!!!!

  screen_load((_cur_nametable + 1) % 2, level_getscreendir(DIR_RIGHT, l));
}

// uint8_t __fastcall__ screen_get_collision_info(uint16_t x, uint16_t y, const level_t* level)
// {
// uint8_t i = (y / 30), j = (x / 32), lx = x % 32, ly = y % 30;
//
//   return level->collisions[i * level->cols + j][ly * 32 + lx];
// }

const uint8_t* __fastcall__ level_getscreendir(uint8_t dir, const level_t* level)
{
uint8_t i = level->i, j = level->j;

  if(!level_hasscreendir(dir, level))
    return 0;

  switch(dir) {
    case DIR_LEFT:
      --j;
      break;
    case DIR_RIGHT:
      ++j;
      break;
    case DIR_UP:
      --i;
      break;
    case DIR_DOWN:
      ++i;
      break;
  }

  return level->screens[i * level->cols + j];
}

const uint8_t* __fastcall__ level_setscreendir(uint8_t dir, level_t* level)
{
  if(!level_hasscreendir(dir, level))
    return 0;

  switch(dir) {
    case DIR_LEFT:
      --(level->j);
      break;
    case DIR_RIGHT:
      ++(level->j);
      break;
    case DIR_UP:
      --(level->i);
      break;
    case DIR_DOWN:
      ++(level->i);
      break;
  }

  return level->screens[level->i * level->cols + level->j];
}

bool_t __fastcall__ level_hasscreendir(uint8_t dir, const level_t* level)
{
  switch(dir) {
    case DIR_LEFT:
      if(level->j == 0)
        return FALSE;
      break;
    case DIR_RIGHT:
      if(level->j >= level->cols - 1)
        return FALSE;
      break;
    case DIR_UP:
      if(level->i == 0)
        return FALSE;
      break;
    case DIR_DOWN:
      if(level->i >= level->rows - 1)
        return FALSE;
      break;
  }

  return TRUE;
}

const uint8_t* __fastcall__ level_getscreencur(const level_t* level) {
  if(level->i >= level->rows || level->j >= level->cols)
    return 0;
  return level->screens[level->i * level->cols + level->j];
}

uint8_t __fastcall__ level_getscreeni(const level_t* level)
{
  return level->i;
}

uint8_t __fastcall__ level_getscreenj(const level_t* level)
{
  return level->j;
}

const uint8_t* __fastcall__ level_setscreen(uint8_t i, uint8_t j, level_t* level) {
  level->i = i;
  level->j = j;
  return level_getscreencur(level);
}

void __fastcall__ gnes_start(void)
{
  PPU.control = 0x90;
  PPU.mask = 0;

  // Init _sprites
  memset(TILES, 0, 64 * sizeof(sprite_t));

  joy_install(joy_static_stddrv);

  waitvblank();
}

void __fastcall__ gnes_update(void)
{
sprite_t* s;
anim_t *anim;
const frame_t *frame;
const tile_t *frame_tiles;
uint16_t x, y;
uint8_t w, h, k, a, x_screen, y_screen;
uint8_t cur_tile_id = 0;
uint8_t sprite_id = 0;
register uint8_t j;
clock_t t0 = clock();

  // Update viewport (not general, only 2 screens + horizontal scrolling)
  j = cur_level->viewport_x >> 8;
  //i = cur_level->viewport_y / 240;
  if(j != cur_level->j) {
    cur_level->j = j;
    //cur_level->i = i;
    _cur_nametable = j;
    //_cur_nametable = i; // Which one?! XD
  }

  _scroll_x = (j == cur_level->cols - 1 ? 0 : cur_level->viewport_x & 0xff);
  //_scroll_y = (i == cur_level->rows - 1 ? 0 : cur_level->viewport_y % 240);

  while(sprite_id < _sprites_num) {
    s = _sprites[sprite_id];
    if(s->update && s->update(s))
      sprite_remove(s);
    else
      ++sprite_id;
  }

  // Update sprites
  for(sprite_id = 0; sprite_id < _sprites_num && cur_tile_id < 64; ++sprite_id) {
    s = _sprites[sprite_id];
    x = sprite_x(s);
    y = sprite_y(s);
    anim = sprite_cur_anim(s);

    if(anim->next_frame_count >= 0) {
      if(anim->next_frame_count == 0) {
        if(anim->cur_frame < anim->frames_num - 1) {
          ++(anim->cur_frame);
          anim->next_frame_count = anim->anim_speed;
        }
        else if(anim->loop) {
          anim->cur_frame = 0;
          anim->next_frame_count = anim->anim_speed;
        }
      }
      else
        --(anim->next_frame_count);
    }

    frame = anim->frames + anim->cur_frame;

    if((uint8_t)((x - _scroll_x - 1) >> 8) != cur_level->j || (uint8_t)((x - _scroll_x + (frame->width << 3) - 1) >> 8) != cur_level->j || (uint8_t)((y - _scroll_y) / 240) != cur_level->i) {
      // Out of screen
      continue;
    }

    frame_tiles = frame->tiles;

    w = frame->width;
    h = frame->height;
    x_screen = (uint8_t)x;
    y_screen = (uint8_t)y;
    for(j = 0; j < w * h && cur_tile_id < 64; ++j) {
      if(sprite_get_hflip(s)) {
        k = (j / w + 1) * w - j % w - 1;
        a = frame_tiles[j].attrib | 0x40;
      }
      else {
        k = j;
        a = frame_tiles[j].attrib & 0xbf;
      }

      TILES[cur_tile_id].y = frame_tiles[k].y + y_screen - _scroll_y;
      TILES[cur_tile_id].tile = frame_tiles[j].tile;
      TILES[cur_tile_id].attrib = a;
      TILES[cur_tile_id].x = frame_tiles[k].x + x_screen - _scroll_x;

      ++cur_tile_id;
    }
  }

  memset(TILES + cur_tile_id, 0, (64 - cur_tile_id) * sizeof(tile_t));

  while(clock() - t0 < 2);
  waitvblank();
  PPU.sprite.address = 0;
  OAM_DMA = 2;

  // // Set nametable
  // PPU.control = 0x10 | _cur_nametable;
  // PPU.mask = 0x1e;
  //
  // // Set scroll
	// PPU.scroll = _scroll_x;
	// PPU.scroll = _scroll_y;
  //
  // // Push all the sprite data from the ram at 200-2ff to the sprite memory
  // PPU.sprite.address = 0;
  // OAM_DMA = 2;
}

void __fastcall__ sprite_init(anim_t* anims, int16_t x, int16_t y, callback_t update, sprite_t* s)
{
  s->x = x;
  s->y = y;
  s->status = 0;
  s->anims = anims;
  s->update = update;
}

void __fastcall__ sprite_add(sprite_t* s)
{
  if(_sprites_num < SPRITES_MAX)
    _sprites[_sprites_num++] = s;
}

void __fastcall__ sprite_remove(sprite_t* s)
{
uint8_t i, j;

  for(i = 0; i < _sprites_num; ++i) {
    if(_sprites[i] == s) {
      --_sprites_num;
      for(j = i; j < _sprites_num; ++j)
        _sprites[j] = _sprites[j + 1];
      break;
    }
  }
}

void __fastcall__ sprite_setframe(uint8_t anim_id, uint8_t frame_id, bool_t run_anim, sprite_t* s)
{
anim_t* anim = s->anims + anim_id;

  sprite_set_cur_anim_id(anim_id, s);
  anim->cur_frame = frame_id;
  anim->next_frame_count = (run_anim ? 0 : -1);
}

void __fastcall__ sprite_setanim(uint8_t anim_id, uint8_t loop, sprite_t* s)
{
anim_t* anim = s->anims + anim_id;

  sprite_set_cur_anim_id(anim_id, s);
  anim->cur_frame = 0;
  anim->next_frame_count = anim->anim_speed;
  anim->loop = loop;
}

void __fastcall__ sprite_endanim(sprite_t* s)
{
anim_t* anim = s->anims + sprite_get_cur_anim_id(s);

  anim->next_frame_count = 0;
  anim->cur_frame = anim->frames_num - 1;
  anim->loop = FALSE;
}

bool_t __fastcall__ sprite_anim_finished(sprite_t* s)
{
anim_t* anim = s->anims + sprite_get_cur_anim_id(s);

    return (anim->next_frame_count == 0 && anim->cur_frame == anim->frames_num - 1 && !anim->loop);
}
