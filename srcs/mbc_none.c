/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbc_none.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 12:53:11 by niragne           #+#    #+#             */
/*   Updated: 2020/04/29 14:35:42 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gb.h"
#include <stdio.h>
#include <stdlib.h>

uint8_t	read_no_mbc(struct gb_cpu_s* gb, uint16_t addr)
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

void	write_no_mbc(struct gb_cpu_s* gb, uint16_t addr, uint8_t x)
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
