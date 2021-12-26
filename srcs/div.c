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
	if (gb->halted)
		return ;
	if (gb->cycle - gb->last_div_increment >= DEFAULT_DIV_FREQ)
	{
		gb->last_div_increment = gb->cycle;
		uint8_t div = read_8(gb, DIV_OFFSET);
		div++;
		gb->io_ports[0x04] = div;
	}
}
