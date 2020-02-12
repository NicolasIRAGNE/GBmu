/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 12:23:21 by niragne           #+#    #+#             */
/*   Updated: 2020/02/12 12:57:24 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gb.h"

int		and(struct gb_cpu_s* gb, uint8_t value)
{
	gb->reg.a &= value;
	cpu_toggle_flag(gb, ZERO_FLAG, !gb->reg.a);
	cpu_unset_flag(gb, SUBSTRACTION_FLAG | CARRY_FLAG);
	cpu_set_flag(gb, HALF_CARRY_FLAG);
}

int		and_a(struct gb_cpu_s* gb)
{
	and(gb, gb->reg.a);
}

int		and_b(struct gb_cpu_s* gb)
{
	and(gb, gb->reg.b);
}

int		and_c(struct gb_cpu_s* gb)
{
	and(gb, gb->reg.c);
}

int		and_d(struct gb_cpu_s* gb)
{
	and(gb, gb->reg.d);
}

int		and_e(struct gb_cpu_s* gb)
{
	and(gb, gb->reg.e);
}

int		and_h(struct gb_cpu_s* gb)
{
	and(gb, gb->reg.h);
}

int		and_l(struct gb_cpu_s* gb)
{
	and(gb, gb->reg.l);
}

int		and_a8(struct gb_cpu_s* gb)
{
	and(gb, gb->current_instruction->args);
}
