/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbc3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 12:53:11 by niragne           #+#    #+#             */
/*   Updated: 2020/08/17 15:02:25 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdint.h>
#include <sys/stat.h>

#include "gb.h"
#include "mbc.h"
#include "cpu.h"
#include "rom.h"
#ifdef WITH_LIBYACC
# include "libyacc_wrapper.h"
#else
# include "fallback_debugger.h"
#endif

# define CYCLES_PER_SECOND	4000000
# define CYCLES_PER_MINUTE	(uint64_t)((CYCLES_PER_SECOND * 60))
# define CYCLES_PER_HOUR	(uint64_t)((CYCLES_PER_MINUTE * 60))
# define CYCLES_PER_DAY		(uint64_t)((CYCLES_PER_HOUR * 24))

void	update_rtc(struct gb_cpu_s* gb)
{
	gb->rtc.clocks += (gb->cycle - gb->rtc.last_cycle);
	gb->rtc.last_cycle = gb->cycle;
	
	while (gb->rtc.clocks >= CYCLES_PER_SECOND)
	{
		gb->rtc.sec += 1;
		if (gb->rtc.sec == 60)
		{
			gb->rtc.sec = 0;
			gb->rtc.min += 1;
		}
		if (gb->rtc.min == 60)
		{
			gb->rtc.min = 0;
			gb->rtc.hour += 1;
		}
		if (gb->rtc.hour == 24)
		{
			gb->rtc.hour = 0;
			gb->rtc.dayl += 1;
		}
		gb->rtc.clocks -= CYCLES_PER_SECOND;
	}
}

void	latch_rtc_registers(struct gb_cpu_s* gb)
{
	gb->rtc.rtc[0] = gb->rtc.sec;
	gb->rtc.rtc[1] = gb->rtc.min;
	gb->rtc.rtc[2] = gb->rtc.hour;
	gb->rtc.rtc[3] = gb->rtc.dayl;
	gb->rtc.last_latch = gb->cycle;
	printf("Latching RTC with: %x %x %x %x\n", gb->rtc.rtc[0], gb->rtc.rtc[1], gb->rtc.rtc[2], gb->rtc.rtc[3]);
}

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
		tmp = gb->mbc.bank % gb->mbc.max_rom_banks;
		if (tmp)
		{
			if (tmp * 0x4000 + addr - 0x4000 >= gb->rom_ptr->st.st_size)
			{
				printf("fatal: attempting to read outside the cartridge at %x in bank %x. aborting...\n", tmp * 0x4000 + addr - 0x4000, tmp);
				printf("fatal: cartridge size is %x\n", gb->rom_ptr->st.st_size);
				printf("banks: %x\n", gb->mbc.max_rom_banks);

				fatal(gb);
				return (0);
			}
			return (((uint8_t*)(gb->rom_ptr->ptr))[tmp * 0x4000 + addr - 0x4000]);
		}
		else
			return (((uint8_t*)(gb->rom_ptr->ptr))[addr % 0x4000]);
	}
	else if (addr < 0xc000)
	{
		// printf("WARNING: READING FROM EXTRA RAM\n");
		if (gb->mbc.mode == MBC_MODE_RAM)
			return (((uint8_t*)(gb->extra_ram))[addr - 0xa000 + gb->mbc.ram_bank * EXTRA_RAM_SIZE]);		
		else if (gb->mbc.mode == MBC_MODE_RTC)
			return (gb->rtc.rtc[gb->mbc.rtc]);
	}
	return (0xff);
}

void	write_mbc3(struct gb_cpu_s* gb, uint16_t addr, uint8_t x, enum memory_mode_e mode)
{
	if (addr < 0x2000)
	{
		if (x == 0x0a)
		{
			if (get_verbose(gb->debugger) >= 1)
				printf("RAM ENABLED (%4x)\n", addr);
			gb->ram_enabled = 1;
		}
		else if (x == 0x00)
		{
			if (get_verbose(gb->debugger) >= 1)
				printf("RAM DISABLED (%4x)\n", addr);
			gb->ram_enabled = 0;
		}
		return ;
	}
	else if (addr < 0x4000)
	{
		if ((x & 0b1111111) == 0)
			gb->mbc.bank = 1;
		else
			gb->mbc.bank = x & 0b1111111;
		// printf("MBC BANK SELECTED: %x\n", gb->mbc.bank);
		return ;
	}
	else if (addr < 0x6000)
	{
		// printf("mapping %x\n", x);
		if (x <= 0x03)
		{
			// printf("MBC RAM BANK SELECTED: %x\n", x);
			gb->mbc.ram_bank = x;
			gb->mbc.mode = MBC_MODE_RAM;
		}		
		else if (x >= 0x8 && x <= 0xC)
		{
			gb->mbc.rtc = x - 0x8;
			gb->mbc.mode = MBC_MODE_RTC;
		}
		return ;
	}
	else if (addr < 0x8000)
	{
		if (gb->rtc.last_write == 0x00 && x == 0x01)
		{
			latch_rtc_registers(gb);
		}
		gb->rtc.last_write = x;
		return ;
	}
	else if (addr < 0xa000)
	{
		return ;
	}
	else if (addr < 0xc000)
	{
		if (!gb->ram_enabled && mode == MEM_SYSTEM)
		{
			printf("warning: attempting to write to disabled RAM / RTC\n");
			return ;
		}
		if (gb->mbc.mode == MBC_MODE_RTC)
		{
			gb->rtc.rtc[gb->mbc.rtc] = x;
		}
		else 
		{
			if ((uint16_t)(addr - 0xa000 + gb->mbc.ram_bank * EXTRA_RAM_SIZE) >= gb->mbc.ram_size)
				printf("warning: attempting to write at %x in invalid ram bank %x\n", addr, gb->mbc.ram_bank);
			else
				((uint8_t*)(gb->extra_ram))[addr - 0xa000 + gb->mbc.ram_bank * EXTRA_RAM_SIZE] = x;
		}
		return ;
	}
}
