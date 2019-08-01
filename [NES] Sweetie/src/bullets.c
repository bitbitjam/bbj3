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

#include "bullets.h"
#include <string.h>

#pragma warn(const-comparison, off)

#define BULLETS_BITMASK_SIZE ((BULLETS_MAX >> 3) + ((BULLETS_MAX & 0x7) != 0))

static bullet_t _bullets[BULLETS_MAX];
static uint8_t _bullets_bitmask[BULLETS_BITMASK_SIZE];

bool_t __fastcall__ bullet_update(void*);

const tile_t BULLET_1_F1[] = {
	{  0, 0xd0, 0, 0 }, {  0, 0xd1, 0, 8 },
  {  8, 0xe0, 0, 0 }, {  8, 0xe1, 0, 8 }
};

const tile_t BULLET_1_F2[] = {
	{  0, 0xd2, 0, 0 }, {  0, 0xd3, 0, 8 },
  {  8, 0xe2, 0, 0 }, {  8, 0xe3, 0, 8 }
};

const tile_t BULLET_1_F3[] = {
	{  0, 0xd4, 0, 0 }, {  0, 0xd5, 0, 8 },
  {  8, 0xe4, 0, 0 }, {  8, 0xe5, 0, 8 }
};

const tile_t BULLET_2_F1[] = {
	{  0, 0xd6, 0, 0 }, {  0, 0xd7, 0, 8 },
  {  8, 0xe6, 0, 0 }, {  8, 0xe7, 0, 8 }
};

const tile_t BULLET_2_F2[] = {
	{  0, 0xd8, 0, 0 }, {  0, 0xd9, 0, 8 },
  {  8, 0xe8, 0, 0 }, {  8, 0xe9, 0, 8 }
};

const tile_t BULLET_2_F3[] = {
	{  0, 0xda, 0, 0 }, {  0, 0xdb, 0, 8 },
  {  8, 0xea, 0, 0 }, {  8, 0xeb, 0, 8 }
};

const frame_t BULLETS_FRAMES[][BULLET_FRAMES_NUM] = {
	{ { 2, 2, BULLET_1_F1 }, { 2, 2, BULLET_1_F2 }, { 2, 2, BULLET_1_F3 } },
	{ { 2, 2, BULLET_2_F1 }, { 2, 2, BULLET_2_F2 }, { 2, 2, BULLET_2_F3 } }
};

const anim_t BULLETS_ANIMS_PROTO[] = {
	{ 1, 0, 0, TRUE, BULLET_FRAMES_NUM, BULLETS_FRAMES[0] },
	{ 1, 0, 0, TRUE, BULLET_FRAMES_NUM, BULLETS_FRAMES[1] }
};

void __fastcall__ bullets_init(void)
{
uint8_t i;

	memset(_bullets_bitmask, 0, BULLETS_BITMASK_SIZE);
	if(BULLETS_MAX & 0x7) {
		for(i = (BULLETS_MAX & 0x7); i < 8; ++i)
			_bullets_bitmask[BULLETS_BITMASK_SIZE - 1] |= (0x1 << i);
	}
}

int8_t __fastcall__ bullet_add(uint8_t bullet_type, int8_t speed, uint16_t x, uint16_t y)
{
bullet_t *b;
uint8_t bitmask;
int8_t i, j, bid;

	for(i = 0; i < BULLETS_BITMASK_SIZE; ++i) {
		if(~_bullets_bitmask[i])
			break;
	}

	if(i == BULLETS_BITMASK_SIZE)
		return -1;

	bitmask = ~_bullets_bitmask[i];
	for(j = 0; j < 7; ++j) {
		if(bitmask & (0x1 << j))
			break;
	}
	_bullets_bitmask[i] |= (0x1 << j);

	bid = (i << 3) + j;
	b = _bullets + bid;
	b->speed = speed;
	b->anim = BULLETS_ANIMS_PROTO[bullet_type];
	sprite_init(&(b->anim), x, y, bullet_update, (sprite_t*)b);
	sprite_setanim(0, TRUE, (sprite_t*)b);
	sprite_reset_hflip(speed < 0, (sprite_t*)b);
	sprite_add((sprite_t*)b);
	return bid;
};

void __fastcall__ bullet_remove(int8_t bid)
{
	_bullets_bitmask[bid >> 3] &= ~(0x1 << (bid & 0x7));
	sprite_remove((sprite_t*)(_bullets + bid));
}

bool_t __fastcall__ bullet_update(void* b)
{
int8_t bid;

	if((((bullet_t*)b)->speed < 0 && ((sprite_t*)b)->x <= -((bullet_t*)b)->speed)
  	|| ((sprite_t*)b)->x + ((bullet_t*)b)->speed + 16 >= cur_level_getwidth()) {
		bid = ((bullet_t*)b) - _bullets;
		_bullets_bitmask[bid >> 3] &= ~(0x1 << (bid & 0x7));
		return TRUE;
	}
	// 	|| ...)
	// 		sprite_remove((sprite_t*)b);
	// else
	// 	((sprite_t*)b)->x += ((bullet_t*)b)->speed;

	((sprite_t*)b)->x += ((bullet_t*)b)->speed;
	return FALSE;
}

int8_t __fastcall__ bullet_first(void)
{
uint8_t bitmask;
int8_t i, j, bid;

	for(i = 0; i < BULLETS_BITMASK_SIZE; ++i) {
		if(_bullets_bitmask[i])
			break;
	}

	if(i == BULLETS_BITMASK_SIZE)
		return -1;

	bitmask = _bullets_bitmask[i];
	for(j = 0; j < 7; ++j) {
		if(bitmask & (0x1 << j))
			break;
	}

	bid = (i << 3) + j;
	return (bid >= BULLETS_MAX ? -1 : bid);
}

int8_t __fastcall__ bullet_next(int8_t bid)
{
uint8_t bitmask;
int8_t i = (bid >> 3), j = (bid & 0x7) + 1;

	if(j == 8) {
		i++;
		j = 0;
	}

	while(i < BULLETS_BITMASK_SIZE) {
		bitmask = _bullets_bitmask[i];
		while(j < 8) {
			if(bitmask & (0x1 << j)) {
				bid = (i << 3) + j;
				return (bid >= BULLETS_MAX ? -1 : bid);
			}
			++j;
		}
		++i;
		j = 0;
	}

	return -1;
}

bullet_t* __fastcall__ bullet_get(int8_t bid)
{
	return _bullets + bid;
}
