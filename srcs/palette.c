/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 18:55:57 by niragne           #+#    #+#             */
/*   Updated: 2020/04/29 09:07:07 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

#include "gb.h"
#include "cpu.h"

void	update_palettes(struct gb_cpu_s* gb)
{
	// I have absolutely no idea why this works 
	uint32_t monochrome_palette[4] = 
	{
		0xccccccff, 0x888888ff, 0x555555ff, 0x111111ff
	};	
	uint8_t bgp;
	if (gb->mode == GB_MODE_DMG)
		bgp = read_8(gb, BGP_OFFSET);
	else
		bgp = 0xdc;
	gb->bg_palettes[0][0] = monochrome_palette[(bgp & 0b00000011) >> 0];
	gb->bg_palettes[0][2] = monochrome_palette[(bgp & 0b00001100) >> 2];
	gb->bg_palettes[0][1] = monochrome_palette[(bgp & 0b00110000) >> 4];
	gb->bg_palettes[0][3] = monochrome_palette[(bgp & 0b11000000) >> 6];

	uint8_t obp0 = read_8(gb, OBP0_OFFSET);
	gb->obj_palettes[0][0] = 0;
	gb->obj_palettes[0][2] = monochrome_palette[(obp0 & 0b00001100) >> 2];
	gb->obj_palettes[0][1] = monochrome_palette[(obp0 & 0b00110000) >> 4];
	gb->obj_palettes[0][3] = monochrome_palette[(obp0 & 0b11000000) >> 6];

	uint8_t obp1 = read_8(gb, OBP1_OFFSET);
	gb->obj_palettes[1][0] = 0;
	gb->obj_palettes[1][2] = monochrome_palette[(obp1 & 0b00001100) >> 2];
	gb->obj_palettes[1][1] = monochrome_palette[(obp1 & 0b00110000) >> 4];
	gb->obj_palettes[1][3] = monochrome_palette[(obp1 & 0b11000000) >> 6];
}