/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 18:10:17 by niragne           #+#    #+#             */
/*   Updated: 2020/04/27 13:00:47 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gb.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

uint16_t	read_16(struct gb_cpu_s* gb, uint16_t a16)
{
	uint16_t ret;

	ret = read_8(gb, a16) | read_8(gb, a16 + 1) << 8;
	return (ret);
}

uint8_t	read_8(struct gb_cpu_s* gb, uint16_t a16)
{
	if (a16 < 0x8000)
	{
		return (gb->mbc.read(gb, a16));
	}
	else if (a16 < 0xa000)
	{
		return (((uint8_t*)(gb->vram))[a16 - 0x8000]);
	}
	else if (a16 < 0xc000)
	{
		return(gb->mbc.read(gb, a16));
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
	else if (a16 == 0xff04)
	{
		return (rand());	
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

void	write_8(struct gb_cpu_s* gb, uint16_t a16, uint8_t x)
{
	static uint64_t last_dma = 0;
	if (a16 < 0x8000)
	{
		gb->mbc.write(gb, a16, x);
		return ;
	}
	else if (a16 < 0xa000)
	{
		((uint8_t*)(gb->vram))[a16 - 0x8000] = x;
		return ;
	}
	else if (a16 < 0xc000)
	{
		gb->mbc.write(gb, a16, x);
		return ;
	}
	else if (a16 < 0xe000)
	{
		((uint8_t*)(gb->ram))[a16 - 0xc000] = x;
		return ;
	}
	else if (a16 == JOYP_OFFSET)
	{
		if (x == SELECT_BUTTON_KEYS)
			gb->joypad_mode = JOYPAD_MODE_BUTTONS;
		else if (x == SELECT_DIRECTION_KEYS)
			gb->joypad_mode = JOYPAD_MODE_DIRECTIONS;
		else if (x == SELECT_NONE)
		{
			gb->joypad_mode = JOYPAD_MODE_NONE;
		// gb->paused = 1;
		}
		((uint8_t*)(gb->io_ports))[a16 - 0xFF00] = (((uint8_t*)(gb->io_ports))[a16 - 0xFF00] & 0x0f) | (x & 0xf0);
		return ;
	}
	else if (a16 == DMA_OFFSET)
	{
		if (gb->cycle - last_dma > 160)
		{
			last_dma = gb->cycle;
			process_dma_transfer(gb, x);
		}
		return ;
	}
	else if (a16 >= 0xFE00 && a16 < 0xFEA0)
	{
		((uint8_t*)(gb->oam))[a16 - 0xFE00] = x;
		return ;
	}
	else if (a16 >= 0xFF00 && a16 < 0xFF80)
	{
		if (a16 == 0xff50 && x == 1)
			gb->booted = 1;
		((uint8_t*)(gb->io_ports))[a16 - 0xFF00] = x;
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

void	write_16(struct gb_cpu_s* gb, uint16_t a16, uint16_t x)
{
	write_8(gb, a16, (x & 0xff));
	write_8(gb, a16 + 1, (x & 0xff00) >> 8);
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