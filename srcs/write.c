/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 18:10:17 by niragne           #+#    #+#             */
/*   Updated: 2020/06/14 13:51:39 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

#include "gb.h"
#include "cpu.h"
#include "mbc.h"

static void	write_8_internal(struct gb_cpu_s* gb, uint16_t a16, uint8_t x, enum memory_mode_e mode)
{
	uint8_t lcdc = read_8(gb, LCDC_OFFSET);
	if (a16 < 0x8000)
	{
		gb->mbc.write(gb, a16, x, mode);
		return ;
	}
	else if (a16 < 0xa000)
	{
		if (mode == MEM_SYSTEM && gb->gpu.mode == GPU_MODE_VRAM && (lcdc & LCDC_ON))
			return;
		gb->vram_updated[gb->vram_bank] = 1;
		gb->vram[gb->vram_bank][a16 - 0x8000] = x;
		return ;
	}
	else if (a16 < 0xc000)
	{
		gb->mbc.write(gb, a16, x, mode);
		return ;
	}
	else if (a16 < 0xe000)
	{
		((uint8_t*)(gb->ram))[a16 - 0xc000] = x;
		return ;
	}
	else if (a16 >= 0xFE00 && a16 < 0xFEA0)
	{
		if (mode != MEM_SYSTEM || gb->gpu.mode == GPU_MODE_HBLANK || gb->gpu.mode == GPU_MODE_VBLANK || !(lcdc && LCDC_ON))
		{
			((uint8_t*)(gb->oam))[a16 - 0xFE00] = x;
		}
		return ;
	}
	else if (a16 >= 0xFF00 && a16 < 0xFF80)
	{
		write_io(gb, a16, x, lcdc);
		return ;
	}
	else if (a16 >= 0xFF80 && a16 < 0xFFFF)
	{
		((uint8_t*)(gb->hram))[a16 - 0xFF80] = x;
		return ;
	}
	else if (a16 == 0xFFFF)
	{
		gb->interrupt_enable_register = x;
		return ;
	}
	else
	{
		// printf("WARNING: WRITING TO UNIMPLEMENTED ZONE %4x\n", a16);
		return ;
	}	
}

void	process_dma_transfer(struct gb_cpu_s* gb, uint8_t a8)
{
	int i = 0;

	while (i < OAM_SIZE)
	{
		uint8_t x = read_8(gb, ((a8 << 8) | i));
		write_8(gb, 0xFE00 | i, x);
		i++;
	}
}

void	write_8(struct gb_cpu_s* gb, uint16_t a16, uint8_t x)
{
	write_8_internal(gb, a16, x, MEM_SYSTEM);
}

void	write_8_debug(struct gb_cpu_s* gb, uint16_t a16, uint8_t x)
{
	write_8_internal(gb, a16, x, MEM_DEBUGGER);
}

void	write_8_force(struct gb_cpu_s* gb, uint16_t a16, uint8_t x)
{
	write_8_internal(gb, a16, x, MEM_FORCE);
}

void	write_16(struct gb_cpu_s* gb, uint16_t a16, uint16_t x)
{
	write_8(gb, a16, (x & 0xff));
	write_8(gb, a16 + 1, (x & 0xff00) >> 8);
}

void	write_16_debug(struct gb_cpu_s* gb, uint16_t a16, uint16_t x)
{
	write_8_debug(gb, a16, (x & 0xff));
	write_8_debug(gb, a16 + 1, (x & 0xff00) >> 8);
}

void	write_16_force(struct gb_cpu_s* gb, uint16_t a16, uint16_t x)
{
	write_8_force(gb, a16, (x & 0xff));
	write_8_force(gb, a16 + 1, (x & 0xff00) >> 8);
}