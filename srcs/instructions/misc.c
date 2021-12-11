/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 17:15:01 by niragne           #+#    #+#             */
/*   Updated: 2020/04/29 16:56:33 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

#include "gb.h"
#include "cpu.h"
#include "op.h"

void	nop(struct gb_cpu_s* gb)
{
	(void)gb;
}

void	di(struct gb_cpu_s* gb)
{	
	gb->ime = 0;
}

void	ei(struct gb_cpu_s* gb)
{
	gb->ime = 1;
}

void	cpl(struct gb_cpu_s* gb)
{
	gb->reg.a = ~gb->reg.a;
	cpu_set_flag(gb, HALF_CARRY_FLAG | SUBSTRACTION_FLAG);
}

void	stop(struct gb_cpu_s* gb)
{
	(void)gb;
	gb->halted = 1;
	//TODO
}

void	halt(struct gb_cpu_s* gb)
{
	gb->halted = 1;
}

void	scf(struct gb_cpu_s* gb)
{
	cpu_unset_flag(gb, SUBSTRACTION_FLAG);
	cpu_unset_flag(gb, HALF_CARRY_FLAG);
	cpu_set_flag(gb, CARRY_FLAG);
}

void	ccf(struct gb_cpu_s* gb)
{
	cpu_unset_flag(gb, SUBSTRACTION_FLAG);
	cpu_unset_flag(gb, HALF_CARRY_FLAG);
	if (gb->reg.f & CARRY_FLAG)
		cpu_unset_flag(gb, CARRY_FLAG);
	else
		cpu_set_flag(gb, CARRY_FLAG);
}

void	daa(struct gb_cpu_s* gb)
{
	//TODO
	uint16_t ret = gb->reg.a;

	if (gb->reg.f & SUBSTRACTION_FLAG)
	{
		if (gb->reg.f & HALF_CARRY_FLAG)
			ret = (ret - 0x06) & 0xFF;
		if (gb->reg.f & CARRY_FLAG)
			ret = ret - 0x60;
	}
	else
	{
		if ((gb->reg.f & HALF_CARRY_FLAG) || ((ret & 0xF) > 9))
			ret = ret + 0x06;
		if ((gb->reg.f & CARRY_FLAG) || ret > 0x9F)
			ret = ret + 0x60;
	}

	gb->reg.a = (uint8_t) ret;
	if (ret > 255)
		cpu_set_flag(gb, CARRY_FLAG);
	cpu_unset_flag(gb, HALF_CARRY_FLAG);
	cpu_toggle_flag(gb, ZERO_FLAG, !gb->reg.a);
}