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

#include <stdint.h>

#include "gb.h"
#include "cpu.h"

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

void print_binary(unsigned char c)
{
 unsigned char i1 = (1 << (sizeof(c)*8-1));
 for(; i1; i1 >>= 1)
      printf("%d",(c&i1)!=0);
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
	if (addr == DMA_OFFSET)
	{
		if (gb->cycle - gb->last_dma > 160)
		{
			gb->last_dma = gb->cycle;
			process_dma_transfer(gb, x);
		}
		return ;
	}
	if (addr == DIV_OFFSET)
	{
		x = 0;
	}
	if (addr == IF_OFFSET)
	{
		gb->halted = 0;
	}
	if (addr == VBK_OFFSET && gb->mode == GB_MODE_CGB)
	{
		gb->vram_bank = x & 0x01;
	}
	if (addr == SVBK_OFFSET && gb->mode == GB_MODE_CGB)
	{
		gb->wram_bank = x & 0b111;
	}
	if (addr == KEY1_OFFSET && gb->mode == GB_MODE_CGB)
	{
		x = (gb->current_speed_mode << 7) | (x & 1);
	}
	if (addr == 0xff50 && x == 1)
	{
		gb->booted = 1;
	}
	if (addr == LCDC_OFFSET && (x & LCDC_ON) && !(lcdc & LCDC_ON))
	{
		request_lcd_on(gb);
	}
	if (addr == LCDC_OFFSET && !(x & LCDC_ON) && gb->gpu.mode != GPU_MODE_VBLANK)
	{
		request_lcd_off(gb);
		// return ;
	}
	if (addr == SERIAL_DATA_OFFSET)
	{
		printf("%c", x);
	}
	if (addr == LCDC_OFFSET)
	{
		// printf("Setting LCDC to ");
		// print_binary(x);
		// printf(" (changed:"); 
		// print_binary(x ^ ((uint8_t*)(gb->io_ports))[addr - 0xFF00]);
		// printf(")\n");
	}
	((uint8_t*)(gb->io_ports))[addr - 0xFF00] = x;
}