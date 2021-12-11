/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbc2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 12:53:23 by niragne           #+#    #+#             */
/*   Updated: 2020/08/17 15:02:17 by niragne          ###   ########.fr       */
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

uint8_t	read_mbc2(struct gb_cpu_s* gb, uint16_t addr, enum memory_mode_e mode)
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
		uint8_t tmp = gb->mbc.bank;
		if (tmp != 0)
		{
			if (tmp * 0x4000 + addr - 0x4000 > gb->rom_ptr->st.st_size)
			{
				printf("waring: attempting to read outside the cartridge at %x in bank %x\n", addr, tmp);
				return (0xff);
			}
			return (((uint8_t*)(gb->rom_ptr->ptr))[tmp * 0x4000 + addr - 0x4000]);
		}
		else
			return (((uint8_t*)(gb->rom_ptr->ptr))[addr]);
	}
	else if (addr < 0xc000)
	{
		if (!gb->ram_enabled)
		{
			printf("warning: attempting to read from disabled RAM at %x\n", addr);
			return (0xff);
		}
		uint32_t index = addr - 0xa000;
		if (index >= BUILT_IN_RAM_SIZE)
		{
			printf("warning: attempting to read %x at invalid ram bank %x\n", addr, gb->mbc.ram_bank);
			return (0xff);
		}
		else
			return (((uint8_t*)(gb->extra_ram))[index]);	
	}
	return (0xff);
}

void	write_mbc2(struct gb_cpu_s* gb, uint16_t addr, uint8_t x, enum memory_mode_e mode)
{
	if (addr < 0x2000)
	{
		if (!(addr & 0x0100))
		{
			gb->ram_enabled = !gb->ram_enabled;
		}
	}
	else if (addr < 0x4000)
	{
		if (!(addr & 0x0100))
			return;
		gb->mbc.bank = (x & 0b1111);
		return ;
	}
	else if (addr < 0xc000)
	{
		if (!gb->ram_enabled)
		{
			printf("warning: attempting to write to disabled RAM at %x\n", addr);
			return ;
		}
		uint32_t index = addr - 0xa000;
		if (index >= BUILT_IN_RAM_SIZE)
		{
			printf("warning: attempting to write outside of built in RAM at %x \n", addr);				
			return ;
		}
		else
			((uint8_t*)(gb->extra_ram))[index] = x;
		return;
	}
}