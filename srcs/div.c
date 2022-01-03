/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   div.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 18:59:04 by niragne           #+#    #+#             */
/*   Updated: 2020/05/04 19:23:15 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

#include "gb.h"
#include "cpu.h"

void	update_div_register(struct gb_cpu_s* gb)
{
	uint64_t freq;
	if (gb->current_speed_mode)
		freq = 4194304 / DOUBLE_DIV_FREQ;
	else
		freq = 4194304 / DEFAULT_DIV_FREQ;
	if (gb->cycle - gb->last_div_increment >= freq)
	{
		gb->last_div_increment = gb->cycle;
		uint8_t div = read_8(gb, DIV_OFFSET);
		div++;
		write_8_force(gb, DIV_OFFSET, div);
	}
}
