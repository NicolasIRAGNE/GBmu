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