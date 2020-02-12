/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   or.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 12:23:21 by niragne           #+#    #+#             */
/*   Updated: 2020/02/12 12:40:54 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gb.h"

int		or(struct gb_cpu_s* gb, uint8_t value)
{
	gb->reg.a |= value;
	cpu_toggle_flag(gb, ZERO_FLAG, !gb->reg.a);
	cpu_unset_flag(gb, SUBSTRACTION_FLAG | CARRY_FLAG | HALF_CARRY_FLAG);
}

int		or_a(struct gb_cpu_s* gb)
{
	or(gb, gb->reg.a);
}

int		or_b(struct gb_cpu_s* gb)
{
	or(gb, gb->reg.b);
}

int		or_c(struct gb_cpu_s* gb)
{
	or(gb, gb->reg.c);
}

int		or_d(struct gb_cpu_s* gb)
{
	or(gb, gb->reg.d);
}

int		or_e(struct gb_cpu_s* gb)
{
	or(gb, gb->reg.e);
}

int		or_h(struct gb_cpu_s* gb)
{
	or(gb, gb->reg.h);
}

int		or_l(struct gb_cpu_s* gb)
{
	or(gb, gb->reg.l);
}
