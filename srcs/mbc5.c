/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbc5.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 12:26:42 by niragne           #+#    #+#             */
/*   Updated: 2020/08/17 15:02:35 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdint.h>
#include <sys/stat.h>

#include "gb.h"
#include "mbc.h"
#include "cpu.h"
#ifdef WITH_LIBYACC
# include "libyacc_wrapper.h"
#endif

uint8_t	read_mbc5(struct gb_cpu_s* gb, uint16_t addr, enum memory_mode_e mode)
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
		tmp = gb->mbc.bank % gb->mbc.max_rom_banks;
		if (tmp)
		{
			if (tmp * 0x4000 + addr - 0x4000 >= gb->rom_ptr->st.st_size)
			{
				printf("fatal: attempting to read outside the cartridge at %x in bank %x. aborting...\n", tmp * 0x4000 + addr - 0x4000, tmp);
				printf("fatal: cartridge size is %x\n", gb->rom_ptr->st.st_size);
				printf("banks: %x\n", gb->mbc.max_rom_banks);

				// fatal(gb);
				return (0);
			}
			return (((uint8_t*)(gb->rom_ptr->ptr))[tmp * 0x4000 + addr - 0x4000]);
		}
		else
			return (((uint8_t*)(gb->rom_ptr->ptr))[addr % 0x4000]);
	}
	else if (addr < 0xc000)
	{
		if (!gb->ram_enabled)
		{
			printf("warning: attempting to read from disabled RAM\n");
			return (0xff);
		}
		uint32_t index;
		index = addr - 0xa000 + (gb->mbc.ram_bank * EXTRA_RAM_SIZE);
		if (index >= gb->mbc.ram_size)
		{
			printf("warning: attempting to read %x at invalid ram bank %x\n", addr, gb->mbc.ram_bank);				
			return (0xff);
		}
		else
			return (((uint8_t*)(gb->extra_ram))[index]);	
	}
	return (0xff);
}

void	write_mbc5(struct gb_cpu_s* gb, uint16_t addr, uint8_t x, enum memory_mode_e mode)
{
	if (addr < 0x2000)
	{
		if (x == 0x0a)
		{
			// if (get_verbose(gb->debugger) >= 1)
				printf("RAM ENABLED (%4x)\n", addr);
			gb->ram_enabled = 1;
		}
		else
		{
			// if (get_verbose(gb->debugger) >= 1)
				printf("RAM DISABLED (%4x)\n", addr);
			gb->ram_enabled = 0;
		}
		return ;
	}
	else if (addr < 0x3000)
	{
		gb->mbc.bank &= ~0xFF;
		gb->mbc.bank |= x;
		// gb->mbc.bank = (gb->mbc.bank & 0x100) | (x & 0x0f);
		printf("1. Switched to bank %x (wrote %x to %x)\n", gb->mbc.bank, x, addr);
		return ;
	}
	else if (addr < 0x4000)
	{
		if (x & 0x01)
		{
			gb->mbc.bank = (gb->mbc.bank | 0x100);
		}
		else
		{
			gb->mbc.bank &= ~0x100;
		}
		printf("2. Switched to bank %x (wrote %x to %x)\n", gb->mbc.bank, x, addr);
		return ;
	}
	else if (addr < 0x6000)
	{
		gb->mbc.ram_bank = gb->mbc.ram_bank & 0xf0 | (x & 0xf);
		// gb->mbc.ram_bank &= (gb->mbc.ram_size / 0x2000) - 1;
		printf("switching ram bank to %x\n", gb->mbc.ram_bank);
		return ;
	}
	else if (addr < 0xa000)
	{
		return ;
	}
	else if (addr < 0xc000)
	{
		if (!gb->ram_enabled)
		{
			printf("warning: attempting to write to disabled RAM\n");
			return ;
		}
		if ((uint16_t)(addr - 0xa000 + gb->mbc.ram_bank * EXTRA_RAM_SIZE) >= gb->mbc.ram_size)
			printf("warning: attempting to write at %x in invalid ram bank %x\n", addr, gb->mbc.ram_bank);
		else
			((uint8_t*)(gb->extra_ram))[addr - 0xa000 + gb->mbc.ram_bank * EXTRA_RAM_SIZE] = x;
	}
}
