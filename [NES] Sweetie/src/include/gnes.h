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

#ifndef _GNES_H
#define _GNES_H

#include <nes.h>
#include <joystick.h>

#define GRAVITY_EXP 3
#define SPRITES_MAX 48

enum {
	FALSE,
	TRUE
};

enum {
	DIR_LEFT,
	DIR_RIGHT,
	DIR_UP,
	DIR_DOWN
};

typedef signed char bool_t;
typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef signed int int16_t;
typedef unsigned int uint16_t;
typedef signed long int int32_t;
typedef unsigned long int uint32_t;

typedef bool_t __fastcall__ (*callback_t)(void*);

typedef struct {
	uint8_t y;
	uint8_t tile;
	uint8_t attrib;
	uint8_t x;
} tile_t;

typedef struct {
	uint8_t width, height;
	const tile_t* tiles;
} frame_t;

typedef struct {
	uint8_t anim_speed;
	int8_t next_frame_count;
	uint8_t cur_frame;
	uint8_t loop;
	uint8_t frames_num;
	const frame_t* frames;
} anim_t;

typedef struct {
  int16_t x, y;
	uint8_t status;
  anim_t* anims;
	callback_t update;
} sprite_t;

// typedef struct {
//   uint32_t x            : 13;
// 	uint32_t y            : 13;
// 	uint32_t cur_anim_id  : 4;
// 	uint32_t hflip        : 1;
// 	uint32_t vflip        : 1;
//   anim_t* anims;
// 	callback_t update;
// } sprite_t;

#define sprite_x(s)                   (((sprite_t*)s)->x)
#define sprite_y(s)                   (((sprite_t*)s)->y)
#define sprite_width(s)               (sprite_cur_anim(s)->frames[sprite_cur_anim(s)->cur_frame].width << 3)
#define sprite_height(s)              (sprite_cur_anim(s)->frames[sprite_cur_anim(s)->cur_frame].height << 3)
#define sprite_status(s)              (((sprite_t*)s)->status)
#define sprite_get_hflip(s)           (sprite_status(s) & 0x40)
#define sprite_set_hflip(s)           (sprite_status(s) |= 0x40)
#define sprite_clear_hflip(s)         (sprite_status(s) &= 0xbf)
#define sprite_reset_hflip(v, s)      ((v) ? sprite_set_hflip(s) : sprite_clear_hflip(s))
#define sprite_get_vflip(s)           (sprite_status(s) & 0x80)
#define sprite_set_vflip(s)           (sprite_status(s) |= 0x80)
#define sprite_reset_vflip(v, s)      ((v) ? sprite_set_vflip(s) : sprite_clear_vflip(s))
#define sprite_clear_vflip(s)         (sprite_status(s) &= 0x7f)
#define sprite_get_cur_anim_id(s)     (sprite_status(s) & 0x3f)
#define sprite_set_cur_anim_id(v, s)  (sprite_status(s) = ((v) & 0x3f) | (sprite_status(s) & 0xc0))
#define sprite_cur_anim(s)            (((sprite_t*)s)->anims + sprite_get_cur_anim_id(s))

typedef struct {
	uint8_t i, j;
	uint8_t rows, cols;
	uint16_t viewport_x, viewport_y;
	const uint8_t **screens;
	const uint8_t **collisions;
} level_t;

extern level_t *cur_level;

#define cur_level_getwidth() level_getwidth(cur_level)
#define cur_level_getheight() level_getheight(cur_level)

void __fastcall__ gnes_start(void);
void __fastcall__ gnes_update(void);

void __fastcall__ screen_load(uint8_t nametable, const uint8_t* screen);

#define level_getwidth(l) ((l)->cols << 8)
#define level_getheight(l) ((l)->rows * 240)

void __fastcall__ level_load(level_t* l);
const uint8_t* __fastcall__ level_getscreencur(const level_t* level);
const uint8_t* __fastcall__ level_getscreendir(uint8_t dir, const level_t* level);
uint8_t __fastcall__ level_getscreeni(const level_t* level);
uint8_t __fastcall__ level_getscreenj(const level_t* level);
const uint8_t* __fastcall__ level_setscreen(uint8_t i, uint8_t j, level_t* level);
const uint8_t* __fastcall__ level_setscreendir(uint8_t dir, level_t* level);
bool_t __fastcall__ level_hasscreendir(uint8_t dir, const level_t* level);

//uint8_t __fastcall__ screen_get_collision_info(uint16_t x, uint16_t y, const level_t* level);

void __fastcall__ sprite_init(anim_t* anims, int16_t x, int16_t y, callback_t update, sprite_t* s);
void __fastcall__ sprite_add(sprite_t* s);
void __fastcall__ sprite_remove(sprite_t* s);
void __fastcall__ sprite_setframe(uint8_t anim_id, uint8_t frame_id, bool_t run_anim, sprite_t* s);
void __fastcall__ sprite_setanim(uint8_t anim_id, uint8_t loop, sprite_t* s);
void __fastcall__ sprite_endanim(sprite_t* s);
bool_t __fastcall__ sprite_anim_finished(sprite_t* s);

#endif // _GNES_H
