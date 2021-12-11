/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbc_none.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 12:53:11 by niragne           #+#    #+#             */
/*   Updated: 2020/08/17 15:06:25 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdint.h>

#include "gb.h"
#include "cpu.h"
#include "mbc.h"

uint8_t	read_no_mbc(struct gb_cpu_s* gb, uint16_t addr, enum memory_mode_e mode)
{
	if (addr < 0x100 && !gb->booted)
	{
		return (((uint8_t*)(gb->boot_rom))[addr]);
	}
	else if (addr < 0x8000)
	{
		return (((uint8_t*)(gb->rom_ptr->ptr))[addr]);
	}
	else if (addr < 0xc000)
	{
		printf("WARNING: READING FROM EXTRA RAM AT %x\n", addr);
		return (0xff);
	}
	return (0xff);
}

void	write_no_mbc(struct gb_cpu_s* gb, uint16_t addr, uint8_t x, enum memory_mode_e mode)
{
	(void)gb;
	if (addr < 0x2000)
	{
		return ;
	}
	else if (addr < 0x4000)
	{
		return ;
	}
	else if (addr < 0x6000)
	{
		return ;
	}
	else if (addr < 0x8000)
	{
		return ;
	}
	else if (addr < 0xc000)
	{
		printf("WARNING: WRITING %x TO EXTRA RAM AT INDEX %x\n", x, addr);
		return;
	}
}
