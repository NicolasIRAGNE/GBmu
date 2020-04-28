/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbc1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 12:53:11 by niragne           #+#    #+#             */
/*   Updated: 2020/04/28 13:06:59 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gb.h"
#include <stdio.h>
#include <stdlib.h>

uint8_t	read_mbc1(struct gb_cpu_s* gb, uint16_t addr)
{
	if (addr < 0x100 && !gb->booted)
	{
		return (((uint8_t*)(gb->boot_rom))[addr]);
	}
	else if (addr < 0x4000)
	{
		return (((uint8_t*)(gb->rom_ptr->ptr))[addr]);
	}
	else if (addr < 0x8000)
	{
		uint8_t tmp;
		if (gb->mbc.mode == MBC_MODE_RAM)
			tmp = gb->mbc.bank & 0b11111;
		else
			tmp = gb->mbc.bank;
		if (tmp != 0)
		{
			if (tmp * 0x4000 + addr - 0x4000 > gb->rom_ptr->st.st_size)
			{
				dprintf(2, "fatal: attempting to read outside the cartridge at %x in bank %x. aborting...\n", addr, tmp);
				abort();
				if (gb->mbc.ram_size > 0)
					save_game(gb);
				return (0);
			}
			return (((uint8_t*)(gb->rom_ptr->ptr))[tmp * 0x4000 + addr - 0x4000]);
		}
		else
			return (((uint8_t*)(gb->rom_ptr->ptr))[addr]);
	}
	else if (addr < 0xc000)
	{
		// printf("WARNING: READING FROM EXTRA RAM\n");
		if (gb->mbc.mode == MBC_MODE_RAM)
			return (((uint8_t*)(gb->extra_ram))[addr - 0xa000 + gb->mbc.ram_bank * EXTRA_RAM_SIZE]);		
		else
			return (((uint8_t*)(gb->extra_ram))[addr - 0xa000]);
	}
	return (0xff);
}

void	write_mbc1(struct gb_cpu_s* gb, uint16_t addr, uint8_t x)
{
	if (addr < 0x2000)
	{
		if (x == 0x0a)
		{
			if (gb->debugger->verbose_level >= 1)
				printf("RAM ENABLED (%4x)\n", addr);
			gb->ram_enabled = 1;
		}
		else
		{
			if (gb->debugger->verbose_level >= 1)
				printf("RAM DISABLED (%4x)\n", addr);
			gb->ram_enabled = 0;
		}
		return ;
	}
	else if (addr < 0x4000)
	{
		gb->mbc.bank = (gb->mbc.bank & 0b1100000) | (x & 0b11111);
		return ;
	}
	else if (addr < 0x6000)
	{
		gb->mbc.bank = (gb->mbc.bank & 0b11111) | (x & 0b1100000);
		gb->mbc.ram_bank = (x & 0b1100000) >> 5;
		if (gb->mbc.bank == 0x20 || gb->mbc.bank == 0x40 || gb->mbc.bank == 0x60)
			gb->mbc.bank += 1;
		return ;
	}
	else if (addr < 0x8000)
	{
		if (x == 0)
			gb->mbc.mode = MBC_MODE_ROM;
		else if (x == 1)
			gb->mbc.mode = MBC_MODE_RAM;
		printf("SWITCHING MBC MODE %x \n", gb->mbc.mode);
		return ;
	}
	else if (addr < 0xc000)
	{
		// printf("WARNING: READING FROM EXTRA RAM\n");
		if (gb->mbc.mode == MBC_MODE_RAM)
			((uint8_t*)(gb->extra_ram))[addr - 0xa000 + gb->mbc.ram_bank * EXTRA_RAM_SIZE] = x;		
		else
			((uint8_t*)(gb->extra_ram))[addr - 0xa000] = x;
		return;
	}
}
