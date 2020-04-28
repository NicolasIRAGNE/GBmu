/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbc3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 12:53:11 by niragne           #+#    #+#             */
/*   Updated: 2020/04/28 23:31:13 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gb.h"
#include <stdio.h>
#include <stdlib.h>

uint8_t	read_mbc3(struct gb_cpu_s* gb, uint16_t addr)
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
		{
			tmp = gb->mbc.bank;
			if (tmp * 0x4000 + addr - 0x4000 > gb->rom_ptr->st.st_size)
			{
				dprintf(2, "fatal: attempting to read outside the cartridge at %x in bank %x. aborting...\n", addr, tmp);
				fatal(gb);
				return (0);
			}
			return (((uint8_t*)(gb->rom_ptr->ptr))[tmp * 0x4000 + addr - 0x4000]);
		}
		else if (gb->mbc.mode == MBC_MODE_RTC)
		{
			printf("banane\n");
			return(0xff);
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

void	write_mbc3(struct gb_cpu_s* gb, uint16_t addr, uint8_t x)
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
		if (x == 0)
			gb->mbc.bank = 1;
		else
			gb->mbc.bank = x & 0b1111111;
		return ;
	}
	else if (addr < 0x6000)
	{
		printf("mapping %x\n", x);
		if (x <= 0x03)
		{
			gb->mbc.ram_bank = x;
			gb->mbc.mode = MBC_MODE_RAM;
		}		
		else if (x >= 0x8 && x <= 0xC)
		{
			gb->mbc.rtc = x;
			// gb->mbc.mode = MBC_MODE_RTC; //Disabled until proper implementation of RTC registers
		}
		return ;
	}
	else if (addr < 0x8000)
	{
		return ;
	}
}
