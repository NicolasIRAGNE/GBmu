/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 10:40:38 by niragne           #+#    #+#             */
/*   Updated: 2020/06/11 15:07:41 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mbc.h"
#ifdef WITH_LIBYACC
# include "libyacc_wrapper.h"
#endif
#include <stdio.h>

/*
 00h  ROM ONLY                 19h  MBC5
 01h  MBC1                     1Ah  MBC5+RAM
 02h  MBC1+RAM                 1Bh  MBC5+RAM+BATTERY
 03h  MBC1+RAM+BATTERY         1Ch  MBC5+RUMBLE
 05h  MBC2                     1Dh  MBC5+RUMBLE+RAM
 06h  MBC2+BATTERY             1Eh  MBC5+RUMBLE+RAM+BATTERY
 08h  ROM+RAM                  20h  MBC6
 09h  ROM+RAM+BATTERY          22h  MBC7+SENSOR+RUMBLE+RAM+BATTERY
 0Bh  MMM01
 0Ch  MMM01+RAM
 0Dh  MMM01+RAM+BATTERY
 0Fh  MBC3+TIMER+BATTERY
 10h  MBC3+TIMER+RAM+BATTERY   FCh  POCKET CAMERA
 11h  MBC3                     FDh  BANDAI TAMA5
 12h  MBC3+RAM                 FEh  HuC3
 13h  MBC3+RAM+BATTERY         FFh  HuC1+RAM+BATTERY
 See https://gbdev.gg8.se/wiki/articles/The_Cartridge_Header
 */

struct mbc_s	mbc_array[] =
{
	{"NONE", MBC_MODE_ROM, read_no_mbc, write_no_mbc, 0, 0, 0, 0, 0, 0}, 
	{"MBC1", MBC_MODE_ROM, read_mbc1, write_mbc1, 0, 0, 0, 0, 0, 0}, 
	{"MBC2", MBC_MODE_ROM, read_mbc2, write_mbc2, 0, 0, 0, 0, BUILT_IN_RAM_SIZE, 0},
	{"MBC3", MBC_MODE_RAM, read_mbc3, write_mbc3, 0, 0, 0, 0, 0, 0}, 
	{0},
	{"MBC5", MBC_MODE_ROM, read_mbc5, write_mbc5, 0, 0, 0, 0, 0, 0}, 
};

struct mbc_s get_mbc(int index)
{
	if (mbc_array[index].name == NULL)
	{
		printf("unrecognized cartridge type. defaulting to MBC5.\n");
		return(mbc_array[5]);
	}
	return (mbc_array[index]);
}