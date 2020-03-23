/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 17:15:01 by niragne           #+#    #+#             */
/*   Updated: 2020/03/23 16:58:41 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gb.h"

int		nop(struct gb_cpu_s* gb)
{
	
}

int		di(struct gb_cpu_s* gb)
{
	gb->ime = 0;
}

int		ei(struct gb_cpu_s* gb)
{
	gb->ime = 1;
}

int		cpl(struct gb_cpu_s* gb)
{
	gb->reg.a = ~gb->reg.a;
	cpu_set_flag(gb, HALF_CARRY_FLAG | SUBSTRACTION_FLAG);
}

int		stop(struct gb_cpu_s* gb)
{
	//TODO
}

int		halt(struct gb_cpu_s* gb)
{
	gb->halted = 1;
}

int		daa(struct gb_cpu_s* gb)
{
	//TODO
	uint8_t tmp;
	uint8_t tmp2;

	tmp = gb->reg.a % 10;
	tmp2 = gb->reg.a / 10;

	// gb->reg.a = (tmp2 << 4) | tmp;
}