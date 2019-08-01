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

#include "alien.h"

const tile_t ALIEN_WALK1[] = {
	{  0, 0x02, 3, 0 }, {  0, 0x03, 3, 8 },
  {  8, 0x12, 3, 0 }, {  8, 0x13, 3, 8 },
  { 16, 0x22, 3, 0 }, { 16, 0x23, 3, 8 },
  { 24, 0x32, 3, 0 }, { 24, 0x33, 3, 8 }
};

const tile_t ALIEN_WALK2[] = {
  {  0, 0x04, 3, 0 }, {  0, 0x05, 3, 8 },
  {  8, 0x14, 3, 0 }, {  8, 0x15, 3, 8 },
  { 16, 0x24, 3, 0 }, { 16, 0x25, 3, 8 },
  { 24, 0x34, 3, 0 }, { 24, 0x35, 3, 8 }
};

const frame_t ALIEN_WALK_FRAMES[] = {
	{ 2, 4, ALIEN_WALK1 },
	{ 2, 4, ALIEN_WALK2 }
};

const tile_t ALIEN_MASH1[] = {
	{  0, 0x06, 3, 0 }, {  0, 0x07, 3, 8 },
  {  8, 0x16, 3, 0 }, {  8, 0x17, 3, 8 },
  { 16, 0x26, 3, 0 }, { 16, 0x27, 3, 8 },
  { 24, 0x36, 3, 0 }, { 24, 0x37, 3, 8 }
};

const tile_t ALIEN_MASH2[] = {
  { 24, 0x30, 3, 0 }, { 24, 0x31, 3, 8 }
};

const frame_t ALIEN_MASH_FRAMES[] = {
	{ 2, 4, ALIEN_MASH1 },
	{ 2, 1, ALIEN_MASH2 }
};
