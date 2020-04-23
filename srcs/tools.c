/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 13:47:25 by niragne           #+#    #+#             */
/*   Updated: 2020/04/23 19:47:26 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gb.h"

uint32_t	get_color_from_palette(uint8_t index, uint32_t* palette)
{
	return (palette[index]);
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
