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

#ifndef _LEVELS_H
#define _LEVELS_H
#include "gnes.h"

#include "level1/level1_00x00.h"
//#include "level1/level1_00x00_collision.h"
#include "level1/level1_00x01.h"
//#include "level1/level1_00x01_collision.h"

const uint8_t* level1_screens[] = { level1_00x00, level1_00x01 };
//const uint8_t* level1_collisions[] = { level1_00x00_collision, level1_00x01_collision };

level_t level1[] = { { 0, 0, 1, 2, 0, 0, level1_screens, 0 } };

#endif // _LEVELS_H
