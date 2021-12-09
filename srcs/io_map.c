/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 11:22:31 by niragne           #+#    #+#             */
/*   Updated: 2021/06/04 12:20:47 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gb.h"

static void	request_lcd_on(struct gb_cpu_s* gb)
{
	gb->gpu.mode = 1;
	gb->gpu.y_coord = 0;
	gb->gpu.tick = 0;
	gb->gpu.lyc_requested = 0;
}

static void	request_lcd_off(struct gb_cpu_s* gb)
{
	(void)gb;
}

uint8_t		read_io(struct gb_cpu_s* gb, uint16_t addr)
{
	if (addr == JOYP_OFFSET)
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
	return (((uint8_t*)(gb->io_ports))[addr - 0xFF00]);	
}

void	write_io(struct gb_cpu_s* gb, uint16_t addr, uint8_t x, uint8_t lcdc)
{
	if (addr == JOYP_OFFSET)
	{
		if (x == SELECT_BUTTON_KEYS)
			gb->joypad_mode = JOYPAD_MODE_BUTTONS;
		else if (x == SELECT_DIRECTION_KEYS)
			gb->joypad_mode = JOYPAD_MODE_DIRECTIONS;
		else if (x == SELECT_NONE)
			gb->joypad_mode = JOYPAD_MODE_NONE;
	}
	else if (addr == DMA_OFFSET)
	{
		if (gb->cycle - gb->last_dma > 160)
		{
			gb->last_dma = gb->cycle;
			process_dma_transfer(gb, x);
		}
		return ;
	}
	if (addr == DIV_OFFSET)
		x = 0;
	else if (addr == IF_OFFSET)
		gb->halted = 0;
	else if (addr == 0xff50 && x == 1)
		gb->booted = 1;
	if (addr == LCDC_OFFSET && (x & LCDC_ON) && !(lcdc & LCDC_ON))
	{
		request_lcd_on(gb);
	}
	if (addr == LCDC_OFFSET && !(x & LCDC_ON) && gb->gpu.mode != GPU_MODE_VBLANK)
	{
		request_lcd_off(gb);
		// return ;
	}
	((uint8_t*)(gb->io_ports))[addr - 0xFF00] = x;
}