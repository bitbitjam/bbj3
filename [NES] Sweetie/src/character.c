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

#include "character.h"
#include "bullets.h"

void __fastcall__ lite_character_init(anim_t* anims, uint16_t x, uint16_t y, lite_character_t* c)
{
  sprite_init(anims, x, y, lite_character_update, (sprite_t*)c);
  lite_character_features(c) = 0;
}

void __fastcall__ lite_character_setwalk(uint8_t walk_anim, lite_character_t* c)
{
  lite_character_setfeatures(CHARACTER_WALK, c);
  lite_character_walk_anim(c) = walk_anim;
  lite_character_walk_speed(c) = 0;
}

void __fastcall__ lite_character_setmash(uint8_t mash_anim, lite_character_t* c)
{
  lite_character_setfeatures(CHARACTER_MASH, c);
  lite_character_mash_anim(c) = mash_anim;
}

void __fastcall__ lite_character_mash(lite_character_t* c)
{
  lite_character_setanim(lite_character_mash_anim(c), FALSE, c);
}

void __fastcall__ character_init(anim_t* anims, uint16_t x, uint16_t y, character_t* c)
{
  sprite_init(anims, x, y, character_update, (sprite_t*)c);
  character_features(c) = 0;
}

void __fastcall__ character_setshot(uint8_t shot_anim, character_t* c)
{
  character_setfeatures(CHARACTER_SHOT, c);
  character_shot_anim(c) = shot_anim;
}

void __fastcall__ character_shot_start(uint8_t bullet_id, uint8_t bullet_speed, character_t* c)
{
  if(!character_shooting(c)
    && (!character_hasfeatures(CHARACTER_JUMP, c) || !character_jumping(c))
    && (!character_hasfeatures(CHARACTER_ROLL, c) || !character_rolling(c))) {
      character_setanim(character_shot_anim(c), TRUE, c);
      character_bullet_id(c) = bullet_id;
      character_bullet_speed(c) = bullet_speed;
  }
}

void __fastcall__ character_shot_stop(character_t* c)
{
  if(character_shooting(c))
    character_endanim(c);
}

void __fastcall__ character_setjump(uint8_t jump_anim, uint8_t jump_load_time, uint8_t jump_asc_time, uint8_t jump_height, character_t* c)
{
  character_setfeatures(CHARACTER_JUMP, c);
  character_jump_anim(c) = jump_anim;
  character_jump_load_time(c) = jump_load_time;
  character_jump_asc_time(c) = jump_asc_time;
  character_jump_height(c) = jump_height;
  character_jump_time(c) = 0;
}

void __fastcall__ character_jump_start(character_t* c)
{
  if(!character_jumping(c)) {
    character_jump_time(c) = 1;
    character_jump_y0(c) = character_y(c);
    character_setframe(character_jump_anim(c), 0, FALSE, c);
  }
}

void __fastcall__ character_jump_stop(character_t* c)
{
  if(character_jumping(c) && character_jump_time(c) < character_jump_load_time(c) + character_jump_asc_time(c)) {
    character_jump_time(c) = character_jump_asc_time(c) + character_jump_load_time(c) + 1;
    character_setframe(character_jump_anim(c), 2, FALSE, c);
  }
}

void __fastcall__ character_setroll(uint8_t roll_anim, character_t* c)
{
  character_setfeatures(CHARACTER_ROLL, c);
  character_roll_anim(c) = roll_anim;
}

void __fastcall__ character_roll(character_t* c)
{
  if(!character_rolling(c)
    && (!character_hasfeatures(CHARACTER_JUMP, c) || !character_jumping(c))
    && (!character_hasfeatures(CHARACTER_SHOT, c) || !character_shooting(c))) {
      character_setanim(character_roll_anim(c), FALSE, c);
  }
}

void __fastcall__ character_setidle(uint8_t idle_anim, character_t* c)
{
  character_setfeatures(CHARACTER_IDLE, c);
  c->idle_anim = idle_anim;
}

bool_t __fastcall__ lite_character_update(void* c)
{
  if(lite_character_hasfeatures(CHARACTER_MASH, c) && lite_character_mashing(c))
    return FALSE;

  if(lite_character_hasfeatures(CHARACTER_WALK, c) && lite_character_walk_speed(c) != 0) {
      lite_character_reset_hflip(lite_character_walk_speed(c) < 0, c);
      lite_character_x(c) += lite_character_walk_speed(c);
  }

  return FALSE;
}

bool_t __fastcall__ character_update(void* c)
{
uint8_t status = CHARACTER_IDLE;
int16_t t, t2;
anim_t* shot_anim;

  if(character_hasfeatures(CHARACTER_MASH, c) && character_mashing(c))
    return FALSE;

  if(character_hasfeatures(CHARACTER_SHOT, c) && character_shooting(c)) {
    if(character_walk_speed(c) != 0)
      character_reset_hflip(character_walk_speed(c) < 0, c);

    shot_anim = character_cur_anim(c);
    if(shot_anim->cur_frame == shot_anim->frames_num - 1 && shot_anim->next_frame_count == shot_anim->anim_speed) {
      bullet_add(character_bullet_id(c), character_bullet_speed(c) * (character_get_hflip(c) ? -1 : 1), character_x(c), character_y(c));
    }
    return FALSE;
  }

  if(character_hasfeatures(CHARACTER_WALK, c)
    && (character_walk_speed(c) < 0 && character_x(c) >= -character_walk_speed(c) + 3) || (character_walk_speed(c) > 0 && character_x(c) + character_walk_speed(c) + character_width(c) < cur_level_getwidth())) {
      character_reset_hflip(character_walk_speed(c) < 0, c);
      character_x(c) += character_walk_speed(c);

      if(character_hasfeatures(CHARACTER_ROLL, c) && character_rolling(c))
        status = CHARACTER_ROLL;
      else
        status = CHARACTER_WALK;
  }

  if(character_hasfeatures(CHARACTER_JUMP, c) && character_jumping(c)) {
    status = CHARACTER_JUMP;

    if(character_jump_time(c) > character_jump_load_time(c)) {
      if(character_jump_time(c) == character_jump_load_time(c) + 1)
        character_setframe(character_jump_anim(c), 1, FALSE, c);

      t2 = (int16_t)character_jump_asc_time(c);
      t = (character_jump_time(c) - character_jump_load_time(c) - 1) - t2;

      if(t < 0) {
        character_y(c) = character_jump_y0(c) + ((int16_t)character_jump_height(c) * t / t2 * t / t2) - character_jump_height(c);
        ++character_jump_time(c);
      }
      else {
        if(t == 0)
          character_setframe(character_jump_anim(c), 2, FALSE, c);

        character_y(c) += ((t << GRAVITY_EXP) / t2 * t / t2);

        if(character_y(c) >= character_jump_y0(c)) {
          character_jump_time(c) = 0;
          character_y(c) = character_jump_y0(c);
          character_setframe(character_jump_anim(c), 2, TRUE, c);
        }
        else
          ++character_jump_time(c);
      }
    }
    else
      ++character_jump_time(c);
  }

  if(character_hasfeatures(CHARACTER_IDLE, c) && (status & CHARACTER_IDLE) && character_get_cur_anim_id(c) != character_idle_anim(c))
    character_setanim(character_idle_anim(c), TRUE, c);
  else if(character_hasfeatures(CHARACTER_WALK, c) && (status & CHARACTER_WALK) && character_get_cur_anim_id(c) != character_walk_anim(c))
    character_setanim(character_walk_anim(c), TRUE, c);

  return FALSE;
}
