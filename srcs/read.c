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

static uint8_t	read_8_internal(struct gb_cpu_s* gb, uint16_t a16, enum memory_mode_e mode)
{
	if (a16 < 0x8000)
	{
		return (gb->mbc.read(gb, a16, mode));
	}
	else if (a16 < 0xa000)
	{
		uint8_t lcdc = read_8(gb, LCDC_OFFSET);
		if (mode != MEM_SYSTEM || gb->gpu.mode != GPU_MODE_VRAM || !(lcdc & LCDC_ON))
			return (((uint8_t*)(gb->vram))[a16 - 0x8000]);
		else
			return (0xff);
	}
	else if (a16 < 0xc000)
	{
		return(gb->mbc.read(gb, a16, mode));
	}
	else if (a16 < 0xe000)
	{
		return (((uint8_t*)(gb->ram))[a16 - 0xc000]);		
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
	else if (a16 >= 0xFE00 && a16 < 0xFEA0)
	{
		uint8_t lcdc = read_8(gb, LCDC_OFFSET);
		if (mode != MEM_SYSTEM || gb->gpu.mode == GPU_MODE_HBLANK || gb->gpu.mode == GPU_MODE_VBLANK || !(lcdc & LCDC_ON))
			return (((uint8_t*)(gb->oam))[a16 - 0xFE00]);
		else
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
		// printf("WARNING: READING FROM UNIMPLEMENTED ZONE %4x\n", a16);
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

