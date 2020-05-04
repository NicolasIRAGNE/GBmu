/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 18:57:56 by niragne           #+#    #+#             */
/*   Updated: 2020/05/04 19:00:46 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gb.h"

void	update_timer_register(struct gb_cpu_s* gb)
{
	uint8_t tac;
	tac = read_8(gb, TAC_OFFSET);
	if (!(tac & 0b100))
		return ;

	uint16_t tima = read_8(gb, TIMA_OFFSET);

	if ((tac & 0b11) == 0 && gb->cycle - gb->last_tima_increment >= TIMER_FREQ_0)
	{
		gb->last_tima_increment = gb->cycle;
		tima++;
	}
	else if ((tac & 0b11) == 1 && gb->cycle - gb->last_tima_increment >= TIMER_FREQ_1)
	{
		gb->last_tima_increment = gb->cycle;
		tima++;

	}
	else if ((tac & 0b11) == 2 && gb->cycle - gb->last_tima_increment >= TIMER_FREQ_2)
	{
		gb->last_tima_increment = gb->cycle;
		tima++;

	}
	else if ((tac & 0b11) == 3 && gb->cycle - gb->last_tima_increment >= TIMER_FREQ_3)
	{
		gb->last_tima_increment = gb->cycle;
		tima++;
	}

	if (tima > 0xff)
	{
		tima = read_8(gb, TMA_OFFSET);
		request_interrupt(gb, INT_TIMER_REQUEST);
	}
	write_8(gb, TIMA_OFFSET, tima);
}
