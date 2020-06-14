/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cpu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 15:30:05 by niragne           #+#    #+#             */
/*   Updated: 2020/06/14 17:27:18 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gb.h"
#include <strings.h>
#include <stdlib.h>
#include <stdio.h>

#define DEFAULT_GB_MODE	GB_MODE_DMG

int		init_boot_rom(struct gb_cpu_s* gb)
{
	int fd;
	int rd;

	fd = open(DMG_BOOT_ROM, O_RDONLY);
	if (fd < 0)
	{
		perror("fatal: could not open "DMG_BOOT_ROM);
		return (1);
	}
	gb->boot_rom = malloc(DMG_BOOT_ROM_SIZE);
	rd = read(fd, gb->boot_rom, DMG_BOOT_ROM_SIZE);
	if (rd < 0)
	{
		perror("fatal: could read from "DMG_BOOT_ROM);
		return (1);
	}
	if (rd != DMG_BOOT_ROM_SIZE)
		fprintf(stderr, "WARNING : read %d bytes from boot rom (expected %d). boot behavior is unexpected.\n", rd, DMG_BOOT_ROM_SIZE);
	close(fd);
	return (0);
}

static int		init_cpu_dmg(struct gb_cpu_s* gb, struct rom_s* rom)
{
	if (init_boot_rom(gb))
		return (1);
	gb->rom_ptr = rom;
	gb->reg.sp = 0xFFFE;
	gb->reg.af = 0x0000;
	gb->reg.de = 0;
	gb->reg.hl = 0;
	gb->reg.pc = 0x00;
	gb->booted = (gb->reg.pc) >= 0x100;
	gb->running = 1;
	gb->vram_viewer_running = 1;
	gb->paused = 0;
	gb->current_instruction = NULL;
	gb->ime = 1;
	gb->div_freq = DEFAULT_DIV_FREQ;
	// gb->interrupt_enable_register |= INT_VBLANK_REQUEST;
	// gb->interrupt_enable_register |= INT_TIMER_REQUEST;
	// gb->interrupt_enable_register |= INT_STAT_REQUEST;
	init_mbc(gb);
	if (gb->mbc.ram_size)
		gb->extra_ram = malloc(gb->mbc.ram_size);
	return (0);
}

static int		init_cpu_cgb(struct gb_cpu_s* gb, struct rom_s* rom)
{
	gb->rom_ptr = rom;
	gb->reg.sp = 0xFFFE;
	gb->reg.af = 0x1100;
	gb->reg.de = 0;
	gb->reg.hl = 0;
	gb->reg.pc = 0x100;
	gb->booted = (gb->reg.pc) >= 0x100;
	gb->running = 1;
	gb->vram_viewer_running = 1;
	gb->paused = 0;
	gb->current_instruction = NULL;
	gb->ime = 1;
	gb->div_freq = DEFAULT_DIV_FREQ;
	// gb->interrupt_enable_register |= INT_VBLANK_REQUEST;
	// gb->interrupt_enable_register |= INT_TIMER_REQUEST;
	// gb->interrupt_enable_register |= INT_STAT_REQUEST;
	init_mbc(gb);
	if (gb->mbc.ram_size)
		gb->extra_ram = malloc(gb->mbc.ram_size);
	return (0);
}

int		init_cpu(struct gb_cpu_s* gb, struct rom_s* rom)
{
	bzero(gb, sizeof(*gb));
	gb->mode = DEFAULT_GB_MODE;
	if (gb->mode == GB_MODE_DMG)
	{
		return (init_cpu_dmg(gb, rom));
	}
	else if (gb->mode == GB_MODE_CGB)
	{
		return (init_cpu_cgb(gb, rom));
	}
	else
	{
		fprintf(stderr, "fatal : unrecognized hardware type\n");
		return (1);
	}
}

int		init_mbc(struct gb_cpu_s* gb)
{
	uint8_t		mbc_array[0xff] = {};
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