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

#include "board_private.h"

static CPU_WRITE_HANDLER(axrom_write_handler)
{
	update_prg_bank(emu->board, 1, (value & 0x0f));
	standard_mirroring_handler(emu, 0, value, cycles);
}

static struct board_write_handler axrom_write_handlers[] = {
	{axrom_write_handler, 0x8000, SIZE_32K, 0},
	{NULL},
};

struct board_info board_axrom = {
	.board_type = BOARD_TYPE_AxROM,
	.name = "AxROM",
	.mirroring_values = std_mirroring_01,
	.mirroring_shift = 4,
	.init_prg = std_prg_32k,
	.init_chr0 = std_chr_8k,
	.write_handlers = axrom_write_handlers,
	.max_prg_rom_size = SIZE_512K,
	.max_chr_rom_size = SIZE_8K,
	.max_wram_size = {SIZE_8K, 0},
	.flags = BOARD_INFO_FLAG_MIRROR_M,
};
