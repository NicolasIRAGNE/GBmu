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
	if (addr == VBK_OFFSET && gb->mode == GB_MODE_CGB)
	{
		return (gb->vram_bank & 0xfe);
	}
	if (addr == BCPD_OFFSET && gb->mode == GB_MODE_CGB)
	{
		return (gb->cgb_bg_palettes[gb->bg_palette_index]);
	}
	if (addr == OCPD_OFFSET && gb->mode == GB_MODE_CGB)
	{
		return (gb->cgb_obj_palettes[gb->obj_palette_index]);
	}
	return (((uint8_t*)(gb->io_ports))[addr - 0xFF00]);	
}

void print_binary(unsigned char c)
{
 unsigned char i1 = (1 << (sizeof(c)*8-1));
 for(; i1; i1 >>= 1)
      printf("%d",(c&i1)!=0);
}

void	write_io(struct gb_cpu_s* gb, uint16_t addr, uint8_t x, uint8_t lcdc, enum memory_mode_e mode)
{
	if (mode == MEM_FORCE)
			goto _end;
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
		if (gb->cycle - gb->last_dma > 0) //FIXME: this should be *something else* than 0
		{
			gb->last_dma = gb->cycle;
			process_dma_transfer(gb, x);
		}
		return ;
	}
	if (addr == HDMA5_OFFSET)
	{
		if (gb->mode != GB_MODE_CGB)
			return;
		if (gb->cycle - gb->last_hdma > 0) //FIXME: this should be *something else* than 0
		{
			gb->last_hdma = gb->cycle;
			process_hdma_transfer(gb, x);
		}
		return;
	}
	if (addr == DIV_OFFSET)
	{
		x = 0;
	}
	if (addr == IF_OFFSET && mode != MEM_SYSTEM)
	{
		gb->halted = 0;
	}
	if (addr == VBK_OFFSET && gb->mode == GB_MODE_CGB)
	{
		printf("Switching to VRAM bank %d\n", x );
		gb->vram_bank = x & 0x01;
	}
	if (addr == SVBK_OFFSET && gb->mode == GB_MODE_CGB)
	{
		if (x == 0)
			x = 1;
		printf("Switching to WRAM bank %d\n", x & 0b111);
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
	if (addr == BCPS_OFFSET && gb->mode == GB_MODE_CGB)
	{
		gb->bcpd_auto_increment = (x & 0x80) != 0;
		gb->bg_palette_index = x & 0b111111;
	}
	if (addr == BCPD_OFFSET && gb->mode == GB_MODE_CGB)
	{
		gb->cgb_bg_palettes[gb->bg_palette_index] = x;
		if (gb->bcpd_auto_increment)
			gb->bg_palette_index = (gb->bg_palette_index + 1) & 0b111111;
	}
	if (addr == OCPS_OFFSET && gb->mode == GB_MODE_CGB)
	{
		gb->ocpd_auto_increment = (x & 0x80) != 0;
		gb->obj_palette_index = x & 0b111111;
	}
	if (addr == OCPD_OFFSET && gb->mode == GB_MODE_CGB)
	{
		gb->cgb_obj_palettes[gb->obj_palette_index] = x;
		if (gb->ocpd_auto_increment)
			gb->obj_palette_index = (gb->obj_palette_index + 1) & 0b111111;
	}
_end:
	((uint8_t*)(gb->io_ports))[addr - 0xFF00] = x;
}