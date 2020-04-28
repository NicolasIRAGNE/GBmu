/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbc5.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 12:26:42 by niragne           #+#    #+#             */
/*   Updated: 2020/04/28 23:21:33 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gb.h"
#include <stdio.h>
#include <stdlib.h>

uint8_t	read_mbc5(struct gb_cpu_s* gb, uint16_t addr)
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
		tmp = gb->mbc.bank;
		if (tmp != 0)
		{
			if (tmp * 0x4000 + addr - 0x4000 > gb->rom_ptr->st.st_size)
			{
				dprintf(2, "fatal: attempting to read outside the cartridge at %x in bank %x. aborting...\n", addr, tmp);
				fatal(gb);
				return (0);
			}
			return (((uint8_t*)(gb->rom_ptr->ptr))[tmp * 0x4000 + addr - 0x4000]);
		}
		else
			return (((uint8_t*)(gb->rom_ptr->ptr))[addr]);
	}
	else if (addr < 0xc000)
	{
		return (((uint8_t*)(gb->extra_ram))[addr - 0xa000 + gb->mbc.ram_bank * RAM_SIZE]);		
	}
	return (0xff);
}

void	write_mbc5(struct gb_cpu_s* gb, uint16_t addr, uint8_t x)
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
	else if (addr < 0x3000)
	{
		gb->mbc.bank = (gb->mbc.bank & 0x100) | (x);
		return ;
	}
	else if (addr < 0x4000)
	{
		gb->mbc.bank = (gb->mbc.bank & 0xf) | ((x & 0x1) << 8);
		return ;
	}
	else if (addr < 0x6000)
	{
		gb->mbc.ram_bank = x & 0xf;
		printf("switching ram bank to %x\n", gb->mbc.ram_bank);
		return ;
	}
	else if (addr < 0xa000)
	{
		return ;
	}
	else if (addr < 0xc000)
	{
		if ((uint16_t)(addr - 0xa000 + gb->mbc.ram_bank * EXTRA_RAM_SIZE) > gb->mbc.ram_size)
		{
			dprintf(2, "fatal: attempting to write at %x in invalid ram bank %x. aborting...\n", addr, gb->mbc.ram_bank);
			fatal(gb);
		}
		else
			((uint8_t*)(gb->extra_ram))[addr - 0xa000 + gb->mbc.ram_bank * EXTRA_RAM_SIZE] = x;
	}
}