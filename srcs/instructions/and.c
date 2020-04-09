/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 12:23:21 by niragne           #+#    #+#             */
/*   Updated: 2020/04/09 16:57:55 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gb.h"

void	and(struct gb_cpu_s* gb, uint8_t value)
{
	gb->reg.a &= value;
	cpu_toggle_flag(gb, ZERO_FLAG, !gb->reg.a);
	cpu_unset_flag(gb, SUBSTRACTION_FLAG | CARRY_FLAG);
	cpu_set_flag(gb, HALF_CARRY_FLAG);
}

void	and_a(struct gb_cpu_s* gb)
{
	and(gb, gb->reg.a);
}

void	and_b(struct gb_cpu_s* gb)
{
	and(gb, gb->reg.b);
}

void	and_c(struct gb_cpu_s* gb)
{
	and(gb, gb->reg.c);
}

void	and_d(struct gb_cpu_s* gb)
{
	and(gb, gb->reg.d);
}

void	and_e(struct gb_cpu_s* gb)
{
	and(gb, gb->reg.e);
}

void	and_h(struct gb_cpu_s* gb)
{
	and(gb, gb->reg.h);
}

void	and_l(struct gb_cpu_s* gb)
{
	and(gb, gb->reg.l);
}

void	and_a8(struct gb_cpu_s* gb)
{
	and(gb, gb->current_instruction->args);
}

void	and_ptr_hl(struct gb_cpu_s* gb)
{
	and(gb, read_8(gb, gb->reg.hl));
}