/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cpu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 15:30:05 by niragne           #+#    #+#             */
/*   Updated: 2020/05/09 13:28:11 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gb.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int		init_boot_rom(struct gb_cpu_s* gb)
{

    FILE* f = fopen(BOOT_ROM, "rb");

	if (f == NULL)
	{
		perror("fatal: could not open "BOOT_ROM);
		return (1);
	}
	size_t rd = fread(gb->boot_rom, BOOT_ROM_SIZE, 1, f) * BOOT_ROM_SIZE;
	if (rd == 0)
	{
		perror("fatal: could read from "BOOT_ROM);
		fclose(f);
		return (1);
	}
	if (rd != BOOT_ROM_SIZE)
		fprintf(stderr, "WARNING : read %zu bytes from boot rom (expected %d). boot behavior is unexpected.\n", rd, BOOT_ROM_SIZE);
	fclose(f);
	return (0);
}

int		init_cpu(struct gb_cpu_s* gb, struct rom_s* rom)
{
	memset(gb, 0, sizeof(*gb));
	if (init_boot_rom(gb))
		return (1);
	gb->rom_ptr = rom;
	gb->reg.sp = 0xFFFE;
	gb->reg.af = 0;
	gb->reg.de = 0;
	gb->reg.hl = 0;
	gb->reg.pc = 0x100;
	gb->booted = (gb->reg.pc) >= 0x100;
	gb->running = 1;
	gb->vram_viewer_running = 1;
	gb->draw_background = 1;
	gb->draw_sprites = 1;
	gb->draw_window = 1;
	gb->paused = 0;
	gb->current_instruction = NULL;
	gb->ime = 1;
	gb->div_freq = DEFAULT_DIV_FREQ;
	gb->interrupt_enable_register |= INT_VBLANK_REQUEST;
	gb->interrupt_enable_register |= INT_TIMER_REQUEST;
	gb->interrupt_enable_register |= INT_STAT_REQUEST;
	init_mbc(gb);
	gb->extra_ram = malloc(gb->mbc.ram_size);
	write_8(gb, LCDC_OFFSET, read_8(gb, LCDC_OFFSET) | LCDC_ON);
	return (0);
}

int		init_mbc(struct gb_cpu_s* gb)
{
	uint8_t		mbc_array[0xff] = {0};
	mbc_array[0x00] = 0;
	mbc_array[0x01] = 1;
	mbc_array[0x02] = 1;
	mbc_array[0x03] = 1;

	mbc_array[0x05] = 2;
	mbc_array[0x06] = 2;

	mbc_array[0x0f] = 3;
	mbc_array[0x10] = 3;
	mbc_array[0x11] = 3;
	mbc_array[0x12] = 3;
	mbc_array[0x13] = 3;
	
	mbc_array[0x19] = 5;
	mbc_array[0x1a] = 5;
	mbc_array[0x1b] = 5;
	mbc_array[0x1c] = 5;
	mbc_array[0x1d] = 5;
	mbc_array[0x1e] = 5;

	gb->mbc = get_mbc(mbc_array[gb->rom_ptr->header->type]);

	if (gb->rom_ptr->header->rom_size <= 0x8)
	{
		gb->mbc.rom_size = 0x8000 << gb->rom_ptr->header->rom_size;
	}

	if (gb->mbc.ram_size != 0)
		return (0);

	if (gb->rom_ptr->header->ram_size == 0x01)
	{
		gb->mbc.ram_size = 0x400;
	}
	else if (gb->rom_ptr->header->ram_size == 0x02)
	{
		gb->mbc.ram_size = EXTRA_RAM_SIZE;
	}
	else if (gb->rom_ptr->header->ram_size == 0x03)
	{
		gb->mbc.ram_size = EXTRA_RAM_SIZE * 4;
	}
	else if (gb->rom_ptr->header->ram_size == 0x04)
	{
		gb->mbc.ram_size = EXTRA_RAM_SIZE * 16;
	}
	else if (gb->rom_ptr->header->ram_size == 0x05)
	{
		gb->mbc.ram_size = EXTRA_RAM_SIZE * 8;
	}
	else
	{
		gb->mbc.ram_size = 0;
	}
	return(0);
}