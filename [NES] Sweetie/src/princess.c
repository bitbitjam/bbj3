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

#include "princess.h"

const tile_t PRINCESS_IDLE1[] = {
	{  0, 0x40, 0, 0 }, {  0, 0x41, 0, 8 },
  {  8, 0x50, 0, 0 }, {  8, 0x51, 0, 8 },
  { 16, 0x60, 0, 0 }, { 16, 0x61, 0, 8 },
  { 24, 0x70, 0, 0 }, { 24, 0x71, 0, 8 }
};

const tile_t PRINCESS_IDLE2[] = {
	{  0, 0x42, 0, 0 }, {  0, 0x43, 0, 8 },
  {  8, 0x52, 0, 0 }, {  8, 0x53, 0, 8 },
  { 16, 0x62, 0, 0 }, { 16, 0x63, 0, 8 },
  { 24, 0x72, 0, 0 }, { 24, 0x73, 0, 8 }
};

const frame_t PRINCESS_IDLE_FRAMES[] = {
	{ 2, 4, PRINCESS_IDLE1 },
	{ 2, 4, PRINCESS_IDLE2 }
};

const tile_t PRINCESS_WALK1[] = {
	{  0, 0x44, 0, 0 }, {  0, 0x45, 0, 8 },
  {  8, 0x54, 0, 0 }, {  8, 0x55, 0, 8 },
  { 16, 0x64, 0, 0 }, { 16, 0x65, 0, 8 },
  { 24, 0x74, 0, 0 }, { 24, 0x75, 0, 8 }
};

const tile_t PRINCESS_WALK2[] = {
	{  0, 0x46, 0, 0 }, {  0, 0x47, 0, 8 },
  {  8, 0x56, 0, 0 }, {  8, 0x57, 0, 8 },
  { 16, 0x66, 0, 0 }, { 16, 0x67, 0, 8 },
  { 24, 0x76, 0, 0 }, { 24, 0x77, 0, 8 }
};

const frame_t PRINCESS_WALK_FRAMES[] = {
	{ 2, 4, PRINCESS_WALK1 },
	{ 2, 4, PRINCESS_WALK2 }
};

const tile_t PRINCESS_JUMP1[] = {
	{  9, 0x0a, 0, 0 }, {  9, 0x0b, 0, 8 },
	{ 17, 0x1a, 0, 0 }, { 17, 0x1b, 0, 8 },
	{ 25, 0x2a, 0, 0 }, { 25, 0x2b, 0, 8 }
};

const tile_t PRINCESS_JUMP2[] = {
	{  1, 0x0c, 0, 0 }, {  1, 0x0d, 0, 8 },
	{  9, 0x1c, 0, 0 }, {  9, 0x1d, 0, 8 },
	{ 17, 0x2c, 0, 0 }, { 17, 0x2d, 0, 8 },
	{ 25, 0x3c, 0, 0 }, { 25, 0x3d, 0, 8 },
};

const tile_t PRINCESS_JUMP3[] = {
	{  0, 0x0e, 0, 0 }, {  0, 0x0f, 0, 8 },
	{  8, 0x1e, 0, 0 }, {  8, 0x1f, 0, 8 },
	{ 16, 0x2e, 0, 0 }, { 16, 0x2f, 0, 8 },
	{ 24, 0x3e, 0, 0 }, { 24, 0x3f, 0, 8 },
};

const frame_t PRINCESS_JUMP_FRAMES[] = {
	{ 2, 3, PRINCESS_JUMP1 },
	{ 2, 4, PRINCESS_JUMP2 },
	{ 2, 4, PRINCESS_JUMP3 }
};

const tile_t PRINCESS_SHOT1[] = {
	{  0, 0x4c, 0, 0 }, {  0, 0x4d, 0, 8 },
  {  8, 0x5c, 0, 0 }, {  8, 0x5d, 0, 8 },
  { 16, 0x6c, 0, 0 }, { 16, 0x6d, 0, 8 },
  { 24, 0x7c, 0, 0 }, { 24, 0x7d, 0, 8 }
};

const tile_t PRINCESS_SHOT2[] = {
	{  0, 0x4e, 0, 0 }, {  0, 0x4f, 0, 8 },
  {  8, 0x5e, 0, 0 }, {  8, 0x5f, 0, 8 },
  { 16, 0x6e, 0, 0 }, { 16, 0x6f, 0, 8 },
  { 24, 0x7e, 0, 0 }, { 24, 0x7f, 0, 8 }
};

const frame_t PRINCESS_SHOT_FRAMES[] = {
	{ 2, 4, PRINCESS_SHOT1 },
	{ 2, 4, PRINCESS_SHOT2 }
};

const tile_t PRINCESS_ROLL1[] = {
  { 16, 0x98, 0, 0 }, { 16, 0x99, 0, 8 },
  { 24, 0xa8, 0, 0 }, { 24, 0xa9, 0, 8 }
};

const tile_t PRINCESS_ROLL2[] = {
  {  8, 0xaa, 0, 0 }, {  8, 0xab, 0, 8 },
  { 16, 0xba, 0, 0 }, { 16, 0xbb, 0, 8 },
  { 24, 0xca, 0, 0 }, { 24, 0xcb, 0, 8 }
};

const tile_t PRINCESS_ROLL3[] = {
  { 16, 0xb8, 0, 0 }, { 16, 0xb9, 0, 8 },
  { 24, 0xc8, 0, 0 }, { 24, 0xc9, 0, 8 }
};

const frame_t PRINCESS_ROLL_FRAMES[] = {
	{ 2, 2, PRINCESS_ROLL1 },
	{ 2, 3, PRINCESS_ROLL2 },
	{ 2, 2, PRINCESS_ROLL3 }
};

const tile_t PRINCESS_MASH1[] = {
	{  0, 0x48, 0, 0 }, {  0, 0x49, 0, 8 },
  {  8, 0x58, 0, 0 }, {  8, 0x59, 0, 8 },
  { 16, 0x68, 0, 0 }, { 16, 0x69, 0, 8 },
  { 24, 0x78, 0, 0 }, { 24, 0x79, 0, 8 }
};

const tile_t PRINCESS_MASH2[] = {
	{  0, 0x4a, 0, 0 }, {  0, 0x4b, 0, 8 },
  {  8, 0x5a, 0, 0 }, {  8, 0x5b, 0, 8 },
  { 16, 0x6a, 0, 0 }, { 16, 0x6b, 0, 8 },
  { 24, 0x7a, 0, 0 }, { 24, 0x7b, 0, 8 }
};

const tile_t PRINCESS_MASH3[] = {
  {  8, 0x08, 0, 0 }, {  8, 0x09, 0, 8 },
  { 16, 0x18, 0, 0 }, { 16, 0x19, 0, 8 },
  { 24, 0x28, 0, 0 }, { 24, 0x29, 0, 8 }
};

const tile_t PRINCESS_MASH4[] = {
  { 24, 0x38, 0, 0 }, { 24, 0x39, 0, 8 }
};

const frame_t PRINCESS_MASH_FRAMES[] = {
	{ 2, 4, PRINCESS_MASH1 },
	{ 2, 4, PRINCESS_MASH2 },
	{ 2, 3, PRINCESS_MASH3 },
	{ 2, 1, PRINCESS_MASH4 }
};
