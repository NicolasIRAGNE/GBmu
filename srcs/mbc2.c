/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbc2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 12:53:23 by niragne           #+#    #+#             */
/*   Updated: 2020/04/25 12:53:50 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gb.h"
#include <stdio.h>

void	write_mbc2(struct gb_cpu_s* gb, uint16_t addr, uint8_t x)
{
	if (addr < 0x2000)
	{
		if (!(addr & 0x0100))
		{
			gb->ram_enabled = 1;
		}
		else
			gb->ram_enabled = 0;
	}
	else if (addr < 0x4000)
	{
		if (!(addr & 0x0100))
			return;
		gb->mbc.bank = (x & 0b1111);
		return ;
	}
}