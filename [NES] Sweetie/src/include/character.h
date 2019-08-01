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

#ifndef _CHARACTER_H
#define _CHARACTER_H

#include "gnes.h"

enum {
  CHARACTER_WALK  = 0x01,
  CHARACTER_MASH  = 0x02,
  CHARACTER_SHOT  = 0x04,
  CHARACTER_JUMP  = 0x08,
  CHARACTER_ROLL  = 0x10,
  CHARACTER_IDLE  = 0x20,
};

typedef struct {
  sprite_t super;
  uint8_t features;

  // Walk
  uint8_t walk_anim;
  int8_t walk_speed;

  // Mash
  uint8_t mash_anim;
} lite_character_t;

#define lite_character_features(c)          (((lite_character_t*)c)->features)
#define lite_character_setfeatures(f, c)    (lite_character_features(c) |= f)
#define lite_character_clearfeatures(f, c)  (lite_character_features(c) &= ~f)
#define lite_character_hasfeatures(f, c)    (lite_character_features(c) & f)
#define lite_character_walk_anim(c)         (((lite_character_t*)(c))->walk_anim)
#define lite_character_walk_speed(c)        (((lite_character_t*)(c))->walk_speed)
#define lite_character_mash_anim(c)         (((lite_character_t*)(c))->mash_anim)
#define lite_character_mashing(c)           (lite_character_get_cur_anim_id(c) == lite_character_mash_anim(c))

#define lite_character_x(c)                                      sprite_x(c)
#define lite_character_y(c)                                      sprite_y(c)
#define lite_character_get_hflip(c)                              sprite_get_hflip(c)
#define lite_character_set_hflip(c)                              sprite_set_hflip(c)
#define lite_character_clear_hflip(c)                            sprite_clear_hflip(c)
#define lite_character_reset_hflip(v, c)                         sprite_reset_hflip(v, c)
#define lite_character_get_vflip(c)                              sprite_get_vflip(c)
#define lite_character_set_vflip(c)                              sprite_set_vflip(c)
#define lite_character_clear_vflip(c)                            sprite_clear_vflip(c)
#define lite_character_reset_vflip(v, c)                         sprite_reset_vflip(v, c)
#define lite_character_get_cur_anim_id(c)                        sprite_get_cur_anim_id(c)
#define lite_character_set_cur_anim_id(v, c)                     sprite_set_cur_anim_id(v, c)
#define lite_character_cur_anim(c)                               sprite_cur_anim(c)
#define lite_character_width(c)                                  sprite_width((sprite_t*)c)
#define lite_character_height(c)                                 sprite_height((sprite_t*)c)
#define lite_character_add(c)                                    sprite_add((sprite_t*)c)
#define lite_character_remove(c)                                 sprite_remove((sprite_t*)c)
#define lite_character_setframe(anim_id, frame_id, run_anim, c)  sprite_setframe(anim_id, frame_id, run_anim, (sprite_t*)c)
#define lite_character_setanim(anim_id, loop, c)                 sprite_setanim(anim_id, loop, (sprite_t*)c)
#define lite_character_endanim(c)                                sprite_endanim((sprite_t*)c)
#define lite_character_anim_finished(c)                          sprite_anim_finished((sprite_t*)c)

void __fastcall__ lite_character_init(anim_t* anims, uint16_t x, uint16_t y, lite_character_t* c);
bool_t __fastcall__ lite_character_update(void* c);

void __fastcall__ lite_character_setwalk(uint8_t walk_anim, lite_character_t* c);
void __fastcall__ lite_character_setmash(uint8_t mash_anim, lite_character_t* c);
void __fastcall__ lite_character_mash(lite_character_t* c);

typedef struct {
  lite_character_t super;

  // Shot
  uint8_t shot_anim;
  uint8_t bullet_id;
  uint8_t bullet_speed;

  // Jump
  uint8_t jump_anim;
  uint8_t jump_load_time;
  uint8_t jump_asc_time;
  uint8_t jump_time;
  uint8_t jump_height;
  int16_t jump_y0;

  // Roll
  uint8_t roll_anim;

  // Idle
  uint8_t idle_anim;
} character_t;

#define character_features(c)            lite_character_features(c)
#define character_setfeatures(f, c)      lite_character_setfeatures(f, (lite_character_t*)(c))
#define character_clearfeatures(f, c)    lite_character_clearfeatures(f, (lite_character_t*)(c))
#define character_hasfeatures(f, c)      lite_character_hasfeatures(f, (lite_character_t*)(c))

#define character_setwalk(walk_anim, c)  lite_character_setwalk(walk_anim, (lite_character_t*)(c))
#define character_walk_anim(c)           lite_character_walk_anim((lite_character_t*)(c))
#define character_walk_speed(c)          lite_character_walk_speed((lite_character_t*)(c))

#define character_setmash(mash_anim, c)  lite_character_setmash(mash_anim, (lite_character_t*)(c))
#define character_mash_anim(c)           lite_character_mash_anim((lite_character_t*)(c))
#define character_mash(c)                lite_character_mash((lite_character_t*)(c))
#define character_mashing(c)             lite_character_mashing((lite_character_t*)(c))

#define character_shot_anim(c)           (((character_t*)c)->shot_anim)
#define character_bullet_id(c)           (((character_t*)c)->bullet_id)
#define character_bullet_speed(c)        (((character_t*)c)->bullet_speed)
#define character_shooting(c)            (sprite_get_cur_anim_id(c) == character_shot_anim(c) && !character_anim_finished(c))

#define character_jump_anim(c)           (((character_t*)c)->jump_anim)
#define character_jump_load_time(c)      (((character_t*)c)->jump_load_time)
#define character_jump_asc_time(c)       (((character_t*)c)->jump_asc_time)
#define character_jump_time(c)           (((character_t*)c)->jump_time)
#define character_jump_height(c)         (((character_t*)c)->jump_height)
#define character_jump_y0(c)             (((character_t*)c)->jump_y0)
#define character_jumping(c)             (character_jump_time(c) != 0)

#define character_roll_anim(c)           (((character_t*)c)->roll_anim)
#define character_rolling(c)             (sprite_get_cur_anim_id(c) == character_roll_anim(c) && !character_anim_finished(c))

#define character_idle_anim(c)           (((character_t*)c)->idle_anim)

// Sprite wrappers
#define character_x(c)                                      lite_character_x((lite_character_t*)(c))
#define character_y(c)                                      lite_character_y((lite_character_t*)(c))
#define character_get_hflip(c)                              lite_character_get_hflip((lite_character_t*)(c))
#define character_set_hflip(c)                              lite_character_set_hflip((lite_character_t*)(c))
#define character_clear_hflip(c)                            lite_character_clear_hflip((lite_character_t*)(c))
#define character_reset_hflip(v, c)                         lite_character_reset_hflip(v, (lite_character_t*)(c))
#define character_get_vflip(c)                              lite_character_get_vflip((lite_character_t*)(c))
#define character_set_vflip(c)                              lite_character_set_vflip((lite_character_t*)(c))
#define character_clear_vflip(c)                            lite_character_clear_vflip((lite_character_t*)(c))
#define character_reset_vflip(v, c)                         lite_character_reset_vflip(v, (lite_character_t*)(c))
#define character_get_cur_anim_id(c)                        lite_character_get_cur_anim_id((lite_character_t*)(c))
#define character_set_cur_anim_id(v, c)                     lite_character_set_cur_anim_id(v, (lite_character_t*)(c))
#define character_cur_anim(c)                               lite_character_cur_anim((lite_character_t*)(c))
#define character_width(c)                                  lite_character_width((lite_character_t*)(c))
#define character_height(c)                                 lite_character_height((lite_character_t*)(c))
#define character_add(c)                                    lite_character_add((lite_character_t*)(c))
#define character_remove(c)                                 lite_character_remove((lite_character_t*)(c))
#define character_setframe(anim_id, frame_id, run_anim, c)  lite_character_setframe(anim_id, frame_id, run_anim, (lite_character_t*)(c))
#define character_setanim(anim_id, loop, c)                 lite_character_setanim(anim_id, loop, (lite_character_t*)(c))
#define character_endanim(c)                                lite_character_endanim((lite_character_t*)(c))
#define character_anim_finished(c)                          lite_character_anim_finished((lite_character_t*)(c))

void __fastcall__ character_init(anim_t* anims, uint16_t x, uint16_t y, character_t* c);
bool_t __fastcall__ character_update(void* c);

void __fastcall__ character_setshot(uint8_t shot_anim, character_t* c);
void __fastcall__ character_setjump(uint8_t jump_anim, uint8_t jump_load_time, uint8_t jump_asc_time, uint8_t jump_height, character_t* character);
void __fastcall__ character_setroll(uint8_t roll_anim, character_t* c);
void __fastcall__ character_setidle(uint8_t idle_anim, character_t* c);

void __fastcall__ character_shot_start(uint8_t bullet_id, uint8_t bullet_speed, character_t* c);
void __fastcall__ character_shot_stop(character_t* c);

void __fastcall__ character_jump_start(character_t* c);
void __fastcall__ character_jump_stop(character_t* c);

void __fastcall__ character_roll(character_t* c);

#endif // _CHARACTER_H
