/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 18:10:17 by niragne           #+#    #+#             */
/*   Updated: 2020/04/21 15:30:04 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gb.h"
#include <stdio.h>
#include <stdlib.h>

uint16_t	read_16(struct gb_cpu_s* gb, uint16_t a16)
{
	uint16_t ret;

	ret = read_8(gb, a16) | read_8(gb, a16 + 1) << 8;
	return (ret);
}

uint8_t	read_8(struct gb_cpu_s* gb, uint16_t a16)
{
	if (a16 < 0x100 && !gb->booted)
	{
		return (((uint8_t*)(gb->boot_rom))[a16]);
	}
	else if (a16 < 0x4000)
	{
		return (((uint8_t*)(gb->rom_ptr->ptr))[a16]);
	}
	else if (a16 < 0x8000)
	{
		if (gb->mbc.mode == MBC_MODE_ROM && gb->mbc.bank != 0 && gb->rom_ptr->header->type != 0)
		{
			if (gb->mbc.bank * 0x4000 + a16 - 0x4000 > gb->rom_ptr->st.st_size)
			{
				debug_print_gb(gb);
				dprintf(2, "fatal: attempting to read outside the cartridge at %x in bank %x. aborting...\n", a16, gb->mbc.bank);
				abort();
				return (0);
			}
			return (((uint8_t*)(gb->rom_ptr->ptr))[gb->mbc.bank * 0x4000 + a16 - 0x4000]);
		}
		else
			return (((uint8_t*)(gb->rom_ptr->ptr))[a16]);
	}
	else if (a16 < 0xa000)
	{
		return (((uint8_t*)(gb->vram))[a16 - 0x8000]);
	}
	else if (a16 < 0xc000)
	{
		printf("WARNING: READING FROM EXTRA RAM\n");
		return (((uint8_t*)(gb->extra_ram))[a16 - 0xa000]);
	}
	else if (a16 < 0xe000)
	{
		return (((uint8_t*)(gb->ram))[a16 - 0xc000]);		
	}
	else if (a16 >= 0xFF00 && a16 < 0xFF80)
	{
		return (((uint8_t*)(gb->io_ports))[a16 - 0xFF00]);		
	}
	else if (a16 >= 0xFF80 && a16 < 0xFFFF)
	{
		return (((uint8_t*)(gb->hram))[a16 - 0xFF80]);		
	}
	else if (a16 == 0xFFFF)
	{
		return (gb->interrupt_enable_register);
	}
	else
	{
		printf("WARNING: READING FROM UNIMPLEMENTED ZONE %4x\n", a16);
		return (0);
	}
}

void	write_8(struct gb_cpu_s* gb, uint16_t a16, uint8_t x)
{
	if (a16 < 0x2000)
	{
		if (x == 0x0a)
		{
			if (gb->debugger->verbose_level >= 1)
				printf("RAM ENABLED (%4x)\n", a16);
			gb->ram_enabled = 1;
		}
		else
		{
			if (gb->debugger->verbose_level >= 1)
				printf("RAM DISABLED (%4x)\n", a16);
			gb->ram_enabled = 0;
		}
		return ;
	}
	else if (a16 < 0x4000)
	{
		uint8_t tmp = x & 0b1100000;
		gb->mbc.bank = tmp | (x & 0b11111);
		if (gb->debugger->verbose_level >= 1)
			printf("SWITCHING BANK LOWER BITS %x \n", gb->mbc.bank);
		return ;
	}
	else if (a16 < 0x6000)
	{
		if (gb->mbc.mode == MBC_MODE_ROM)
		{
			uint8_t tmp = x & 0b0011111;
			gb->mbc.bank = tmp | (x & 0b1100000);
			if (gb->debugger->verbose_level >= 1)
				printf("SWITCHING BANK UPPER BITS %x \n", gb->mbc.bank);
		}
		return ;
	}
	else if (a16 < 0x8000)
	{
		if (x == 0)
			gb->mbc.mode = MBC_MODE_ROM;
		else if (x == 1)
			gb->mbc.mode = MBC_MODE_RAM;
		printf("SWITCHING MBC MODE %x \n", gb->mbc.mode);
		return ;
	}
	else if (a16 < 0xa000)
	{
		((uint8_t*)(gb->vram))[a16 - 0x8000] = x;
		return ;
	}
	else if (a16 < 0xc000)
	{
		// printf("WARNING: WRITING TO EXTRA RAM\n");
		((uint8_t*)(gb->extra_ram))[a16 - 0xa000] = x;
		return ;
	}
	else if (a16 < 0xe000)
	{
		((uint8_t*)(gb->ram))[a16 - 0xc000] = x;
		return ;
	}
	else if (a16 == JOYP_OFFSET)
	{
		if (x == SELECT_BUTTON_KEYS)
			gb->joypad_mode = JOYPAD_MODE_BUTTONS;
		else if (x == SELECT_DIRECTION_KEYS)
			gb->joypad_mode = JOYPAD_MODE_DIRECTIONS;
		else if (x == SELECT_NONE)
		{
			gb->joypad_mode = JOYPAD_MODE_NONE;
		gb->paused = 1;
		}
		return ;
	}
	else if (a16 >= 0xFF00 && a16 < 0xFF80)
	{
		if (a16 == 0xff50 && x == 1)
			gb->booted = 1;
		((uint8_t*)(gb->io_ports))[a16 - 0xFF00] = x;
		return ;
	}
	else if (a16 >= 0xFF80 && a16 < 0xFFFF)
	{
		((uint8_t*)(gb->hram))[a16 - 0xFF80] = x;
		return ;
	}
	else if (a16 == 0xFFFF)
	{
		gb->interrupt_enable_register = x;
		return ;
	}
	else
	{
		// printf("WARNING: WRITING TO UNIMPLEMENTED ZONE %4x\n", a16);
		return ;
	}	
}

void	write_16(struct gb_cpu_s* gb, uint16_t a16, uint16_t x)
{
	write_8(gb, a16, (x & 0xff));
	write_8(gb, a16 + 1, (x & 0xff00) >> 8);
}
