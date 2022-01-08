/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 13:47:25 by niragne           #+#    #+#             */
/*   Updated: 2022/01/07 14:51:46 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include "gb.h"
#include "cpu.h"

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

int		clamp(int val, int min, int max)
{
	if (val < min)
		return (min);
	if (val > max)
		return (max);
	return (val);
}

void	copy_registers(void* dst)
{
	memcpy(dst, &gb_global.reg, sizeof(struct registers_s));
}
