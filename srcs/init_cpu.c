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

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <sys/stat.h>

#include "gb.h"
#include "cpu.h"
#include "mbc.h"
#include "dmg_boot_rom.h"
#include "rom.h"

struct gb_cpu_s	gb_global;

int		open_rom(char* name, struct rom_s* rom)
{
	int ret;

	ret = stat(name, &rom->st);
	if (ret)
	{
		perror(name);
		return (ret);
	}
	
	FILE* f = fopen(name, "rb");
	if (f == NULL)
	{
		perror(name);
		return (1);
	}
	
	uint8_t* buf = malloc(rom->st.st_size);
	if (!buf)
	{
		perror("malloc");
		fclose(f);
		return (1);
	}
	size_t rd = fread(buf, rom->st.st_size, 1, f) * rom->st.st_size;
	if (rd != rom->st.st_size)
	{
		perror(name);
		fclose(f);
		free(buf);
		return (1);
	}
	fclose(f);
	rom->ptr = buf;
	rom->header = (struct rom_hdr_s*)((uint8_t*)rom->ptr + 0x100);
	return (0);
}

int		init_boot_rom(struct gb_cpu_s* gb)
{
#ifdef DMG_BOOT_ROM
    FILE* f = fopen(DMG_BOOT_ROM, "rb");

	if (f == NULL)
	{
		perror("fatal: could not open "DMG_BOOT_ROM);
		return (1);
	}
	gb->boot_rom = malloc(DMG_BOOT_ROM_SIZE);
	if (!gb->boot_rom)
	{
		perror("malloc:");
		fclose(f);
		return (1);
	}
	size_t rd = fread(gb->boot_rom, DMG_BOOT_ROM_SIZE, 1, f) * DMG_BOOT_ROM_SIZE;
	if (rd == 0)
	{
		perror("fatal: could read from "DMG_BOOT_ROM);
		fclose(f);
		return (1);
	}
	if (rd != DMG_BOOT_ROM_SIZE)
		fprintf(stderr, "WARNING : read %zu bytes from boot rom (expected %d). boot behavior is unexpected.\n", rd, DMG_BOOT_ROM_SIZE);
	fclose(f);
	return (0);
#else
	gb->boot_rom = DMG_ROM;
	return (0);
#endif
}

void init_registers(struct registers_s* reg, int booted, enum gb_mode_e mode)
{
    switch (mode)
    {
    case GB_MODE_DMG:
        if (booted)
        {
            reg->af = 0x01B0;
            reg->bc = 0x0013;
            reg->de = 0x00D8;
            reg->hl = 0x014D;
            reg->sp = 0xFFFE;
            reg->pc = 0x0100;
        }
        else
        {
            reg->af = 0x0000;
            reg->bc = 0x0000;
            reg->de = 0x0000;
            reg->hl = 0x0000;
            reg->pc = 0x0000;
            reg->sp = 0x0000;
        }
        break;
	
	case GB_MODE_CGB:
		reg->af = 0x1180;
		reg->bc = 0x0000;
		reg->de = 0xFF56;
		reg->hl = 0x000D;
    	reg->sp = 0xFFFE;
		reg->pc = 0x0100;
		break;

    default:
		printf("error: unknown GB mode %d!\n", mode);
        break;
    }
}

int		init_cpu_dmg(struct gb_cpu_s* gb, struct rom_s* rom)
{
	if (gb->booted == 0)
	{
		if (init_boot_rom(gb))
			return (1);
	}
	gb->rom_ptr = rom;
	gb->running = 1;
	gb->vram_viewer_running = 1;
	gb->draw_background = 1;
	gb->draw_sprites = 1;
	gb->draw_window = 1;
	gb->debug_palette = 0;
	gb->current_instruction = NULL;
	gb->ime = 0;
	gb->wram_bank = 1;
	gb->paused = 0;
	// gb->interrupt_enable_register |= INT_VBLANK_REQUEST;
	// gb->interrupt_enable_register |= INT_TIMER_REQUEST;
	// gb->interrupt_enable_register |= INT_STAT_REQUEST;
	init_mbc(gb);
	gb->mbc.bank = 1;
	write_8_force(gb, LCDC_OFFSET, read_8_force(gb, LCDC_OFFSET) | LCDC_ON);
	if (gb->mbc.ram_size)
	{
		gb->extra_ram = malloc(gb->mbc.ram_size);
		if (!gb->extra_ram)
		{
			perror("malloc");
			return (1);
		}
		memset(gb->extra_ram, 0, gb->mbc.ram_size);
	}
	return (0);
}

static int		init_cpu_cgb(struct gb_cpu_s* gb, struct rom_s* rom)
{
	if (gb->booted == 0)
	{
		printf("warning: CGB boot rom is not supported by the current version of GBmu.\n");
		gb->booted = 1;
	}
	gb->rom_ptr = rom;
	gb->draw_background = 1;
	gb->draw_sprites = 1;
	gb->draw_window = 1;
	gb->running = 1;
	gb->vram_viewer_running = 1;
	gb->paused = 0;
	gb->current_instruction = NULL;
	gb->ime = 0;
	gb->wram_bank = 1;
	// gb->interrupt_enable_register |= INT_VBLANK_REQUEST;
	// gb->interrupt_enable_register |= INT_TIMER_REQUEST;
	// gb->interrupt_enable_register |= INT_STAT_REQUEST;
	init_mbc(gb);
	gb->mbc.bank = 1;
	gb->paused = 0;
	write_8(gb, LCDC_OFFSET, read_8(gb, LCDC_OFFSET) | LCDC_ON);
	if (gb->mbc.ram_size)
	{
		gb->extra_ram = malloc(gb->mbc.ram_size);
		if (!gb->extra_ram)
		{
			perror("malloc");
			return (1);
		}
		memset(gb->extra_ram, 0, gb->mbc.ram_size);
	}
	return (0);
}

int		init_cpu(struct gb_cpu_s* gb, struct rom_s* rom, enum gb_mode_e mode)
{
	memset(gb, 0, sizeof(*gb));
	if (mode == GB_MODE_AUTO)
	{
		if (rom->header->title[15] == 0x80 || rom->header->title[15] == 0xC0)
			mode = GB_MODE_CGB;
		else
			mode = GB_MODE_DMG;
	}
	gb->mode = mode;
	gb->booted = 1;
	init_registers(&gb->reg, gb->booted, gb->mode);
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
		switch (gb->rom_ptr->header->rom_size)
		{
		case 0:
			gb->mbc.max_rom_banks = 0;
			gb->mbc.rom_size = 0x8000;
			break;
		case 1:
			gb->mbc.max_rom_banks = 4;
			gb->mbc.rom_size = 0x10000;
			break;
		case 2:
			gb->mbc.max_rom_banks = 8;
			gb->mbc.rom_size = 0x20000;
			break;
		case 3:
			gb->mbc.max_rom_banks = 16;
			gb->mbc.rom_size = 0x40000;
			break;
		case 4:
			gb->mbc.max_rom_banks = 32;
			gb->mbc.rom_size = 0x80000;
			break;
		case 5:
			gb->mbc.max_rom_banks = 64;
			gb->mbc.rom_size = 0x100000;
			break;
		case 6:
			gb->mbc.max_rom_banks = 128;
			gb->mbc.rom_size = 0x200000;
			break;
		case 7:
			gb->mbc.max_rom_banks = 256;
			gb->mbc.rom_size = 0x400000;
			break;
		case 8:
			gb->mbc.max_rom_banks = 512;
			gb->mbc.rom_size = 0x800000;
			break;
		case 52:
			gb->mbc.max_rom_banks = 72;
			gb->mbc.rom_size = 0x280000;
			break;

		}
		
		
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