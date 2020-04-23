/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 13:47:25 by niragne           #+#    #+#             */
/*   Updated: 2020/04/23 13:01:09 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gb.h"

uint32_t	get_color_from_palette(uint8_t index, enum tile_type_e type)
{
	uint32_t sprite_palette[4] = 
	{
		0x00000000, 0x111111ff, 0x333333ff, 0x999999ff
	};

	uint32_t bg_palette[4] = 
	{
		0x111111ff, 0x333333ff, 0x555555ff, 0xaaaaaaff
	};

	if (type == TILE_TYPE_SPRITE)
		return (sprite_palette[index]);
	else
		return (bg_palette[index]);
}

void	memset_4(uint32_t* ptr, uint32_t c, size_t n)
{
	size_t i = 0;

	while (i < n)
	{
		ptr[i] = c;
		i += 1;
	}
}
