/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 14:47:16 by niragne           #+#    #+#             */
/*   Updated: 2021/06/04 12:18:29 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

#include "gb.h"
#include "cpu.h"
#include "mbc.h"

#define IGNORE_LOCKS 1


/**
 * @brief This function reads a byte from the gameboy RAM. It needs to be an interface for both the DMG and the CGB.
 * On the DMG, there is only one RAM bank of size 0x2000 bytes. On the CGB, there are 8 banks of size 0x1000 bytes.
 * The memory is mapped as follows:
 * - 0xC000 - 0xCFFF is always mapped to the first bank of the RAM.
 * - 0xD000 - 0xDFFF is dynamically mapped to an arbitrary bank of the RAM.
 * @param gb The GB to read from
 * @param a16 The absolute address to read from
 * @return uint8_t Value read from the cpu.
 */
static uint8_t	read_from_ram(struct gb_cpu_s* gb, uint16_t a16)
{
	if (a16 < 0xD000)
	{
		return (gb->ram[0][a16 - 0xC000]);
	}
	else
	{
		return (gb->ram[gb->wram_bank][a16 - 0xD000]);
	}
}

static uint8_t	read_8_internal(struct gb_cpu_s* gb, uint16_t a16, enum memory_mode_e mode)
{
	if (a16 < 0x8000)
	{
		return (gb->mbc.read(gb, a16, mode));
	}
	else if (a16 < 0xa000)
	{
		#ifndef IGNORE_LOCKS
		uint8_t lcdc = read_8_force(gb, LCDC_OFFSET);
		if (mode == MEM_SYSTEM && gb->gpu.mode == GPU_MODE_VRAM && (lcdc & LCDC_ON))
			return (0xff);
		#endif
		return (((uint8_t*)(gb->vram[gb->vram_bank]))[a16 - 0x8000]);
	}
	else if (a16 < 0xc000)
	{
		return(gb->mbc.read(gb, a16, mode));
	}
	else if (a16 < 0xe000)
	{
		return(read_from_ram(gb, a16));
	}
	else if (a16 < 0xFE00)
	{
		printf("warning: reading from echo RAM at address 0x%x\n", a16);
		return(read_from_ram(gb, a16 - 0x2000));
	}
	else if (a16 == JOYP_OFFSET)
	{
		uint8_t ret = 0;
		if (gb->joypad_mode == JOYPAD_MODE_BUTTONS)
		{
			ret |= ((gb->joypad.a) != 0) << 0;
			ret |= ((gb->joypad.b) != 0) << 1;
			ret |= ((gb->joypad.select) != 0) << 2;
			ret |= ((gb->joypad.start) != 0) << 3;
		}
		else if (gb->joypad_mode == JOYPAD_MODE_DIRECTIONS)
		{
			ret |= ((gb->joypad.right) != 0) << 0;
			ret |= ((gb->joypad.left) != 0) << 1;
			ret |= ((gb->joypad.up) != 0) << 2;
			ret |= ((gb->joypad.down) != 0) << 3;
		}
		ret = ~ret;
		return (ret);
	}
	else if (a16 < 0xFEA0)
	{
		#ifndef IGNORE_LOCKS
		uint8_t lcdc = read_8_force(gb, LCDC_OFFSET);
		if (mode != MEM_SYSTEM || gb->gpu.mode == GPU_MODE_HBLANK || gb->gpu.mode == GPU_MODE_VBLANK || !(lcdc & LCDC_ON))
		#endif
			return (((uint8_t*)(gb->oam))[a16 - 0xFE00]);
		return (0xff);
	}
	else if (a16 >= 0xFF00 && a16 < 0xFF80)
	{
		return (((uint8_t*)(gb->io_ports))[a16 - 0xFF00]);		
	}
	else if (a16 >= 0xFF80 && a16 < 0xFFFF)
	{
		return (((uint8_t*)(gb->hram))[a16 - 0xFF80]);		
	}
	else if (a16 == 0xFFFF)
	{
		return (gb->interrupt_enable_register);
	}
	else
	{
		printf("WARNING: READING FROM UNIMPLEMENTED ZONE %4x\n", a16);
		return (0xff);
	}
}

uint8_t	read_8(struct gb_cpu_s* gb, uint16_t a16)
{
	return (read_8_internal(gb, a16, MEM_SYSTEM));
}

uint8_t	read_8_debug(struct gb_cpu_s* gb, uint16_t a16)
{
	return (read_8_internal(gb, a16, MEM_DEBUGGER));
}

uint8_t	read_8_force(struct gb_cpu_s* gb, uint16_t a16)
{
	return (read_8_internal(gb, a16, MEM_FORCE));
}

uint16_t	read_16(struct gb_cpu_s* gb, uint16_t a16)
{
	uint16_t ret;

	ret = read_8(gb, a16) | read_8(gb, a16 + 1) << 8;
	return (ret);
}

uint16_t	read_16_debug(struct gb_cpu_s* gb, uint16_t a16)
{
	uint16_t ret;

	ret = read_8_debug(gb, a16) | read_8_debug(gb, a16 + 1) << 8;
	return (ret);
}

uint16_t	read_16_force(struct gb_cpu_s* gb, uint16_t a16)
{
	uint16_t ret;

	ret = read_8_force(gb, a16) | read_8_force(gb, a16 + 1) << 8;
	return (ret);
}

