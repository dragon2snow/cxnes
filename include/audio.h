/*
  cxNES - NES/Famicom Emulator
  Copyright (C) 2011-2015 Ryan Jackson

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation.; either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License along
  with this program; if not, write to the Free Software Foundation, Inc.,
  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#ifndef __AUDIO_H__
#define __AUDIO_H__

#include "emu.h"

int audio_init(struct emu *emu);
int audio_shutdown(void);
int audio_fill_buffer(uint32_t cycles);
void audio_add_delta(unsigned time, int delta);
int audio_buffer_check(void);
void audio_pause(int);
int audio_apply_config(struct emu *emu);
void audio_mute(int);

#endif				/* __AUDIO_H__ */