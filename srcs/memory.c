/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 18:10:17 by niragne           #+#    #+#             */
/*   Updated: 2020/02/24 09:25:15 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gb.h"
#include <stdio.h>

uint16_t	read_16(struct gb_cpu_s* gb, uint16_t a16)
{
	uint16_t ret;

	ret = read_8(gb, a16) | read_8(gb, a16 + 1) << 8;
	return (ret);
}

uint8_t	read_8(struct gb_cpu_s* gb, uint16_t a16)
{
	if (a16 < 0x8000)
	{
		return (((uint8_t*)(gb->rom_ptr->ptr))[a16]);
	}
	else if (a16 < 0xa000)
	{
		return (((uint8_t*)(gb->vram))[a16 - 0x8000]);
	}
	else if (a16 < 0xc000)
	{
		printf("WARNING: READING FROM EXTRA RAM\n");
		return (0);
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
	if (a16 < 0x8000)
	{
		printf("WARNING: TRYING TO WRITE TO ROM AT %x\n", a16);
		return ;
	}
	else if (a16 < 0xa000)
	{
		// if (a16 < 0x97FF)
			// gb->paused = 1;
		((uint8_t*)(gb->vram))[a16 - 0x8000] = x;
		return ;
	}
	else if (a16 < 0xc000)
	{
		printf("WARNING: WRITING TO EXTRA RAM\n");
		return ;
	}
	else if (a16 < 0xe000)
	{
		((uint8_t*)(gb->ram))[a16 - 0xc000] = x;
		return ;
	}
	else if (a16 >= 0xFF00 && a16 < 0xFF80)
	{
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
		printf("WARNING: WRITING TO UNIMPLEMENTED ZONE %4x\n", a16);
		return ;
	}	
}

void	write_16(struct gb_cpu_s* gb, uint16_t a16, uint16_t x)
{
	write_8(gb, a16, (x & 0xff));
	write_8(gb, a16 + 1, (x & 0xff00) >> 8);
}
