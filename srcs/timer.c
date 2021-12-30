/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 18:57:56 by niragne           #+#    #+#             */
/*   Updated: 2020/05/09 14:24:01 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

#include "gb.h"
#include "cpu.h"

uint64_t	freqs[] =
{
	TIMER_FREQ_0,
	TIMER_FREQ_0,
	TIMER_FREQ_2,
	TIMER_FREQ_3,
};

void	update_timer_register(struct gb_cpu_s* gb)
{
	uint8_t tac;
	tac = read_8(gb, TAC_OFFSET);
	if (!(tac & TAC_ENABLE))
	{
		gb->tima.last_cycle = gb->cycle;
		return ;
	}

	gb->tima.clocks += (gb->cycle - gb->tima.last_cycle);
	gb->tima.last_cycle = gb->cycle;
	gb->tima.freq = freqs[tac & TAC_FREQ];
	uint16_t tima = read_8(gb, TIMA_OFFSET);

	while (gb->tima.clocks >= gb->tima.freq)
	{
		tima = read_8(gb, TIMA_OFFSET);
		gb->tima.clocks -= gb->tima.freq;
		if (tima >= 0xff)
		{
			tima = read_8(gb, TMA_OFFSET);
			request_interrupt(gb, INT_TIMER_REQUEST);
		}
		else
			tima++;
	}
	write_8(gb, TIMA_OFFSET, tima);
}
