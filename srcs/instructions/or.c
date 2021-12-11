/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   or.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 12:23:21 by niragne           #+#    #+#             */
/*   Updated: 2020/04/09 17:00:16 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

#include "gb.h"
#include "cpu.h"
#include "op.h"

void	or(struct gb_cpu_s* gb, uint8_t value)
{
	gb->reg.a |= value;
	cpu_toggle_flag(gb, ZERO_FLAG, !gb->reg.a);
	cpu_unset_flag(gb, SUBSTRACTION_FLAG | CARRY_FLAG | HALF_CARRY_FLAG);
}

void	or_a(struct gb_cpu_s* gb)
{
	or(gb, gb->reg.a);
}

void	or_b(struct gb_cpu_s* gb)
{
	or(gb, gb->reg.b);
}

void	or_c(struct gb_cpu_s* gb)
{
	or(gb, gb->reg.c);
}

void	or_d(struct gb_cpu_s* gb)
{
	or(gb, gb->reg.d);
}

void	or_e(struct gb_cpu_s* gb)
{
	or(gb, gb->reg.e);
}

void	or_h(struct gb_cpu_s* gb)
{
	or(gb, gb->reg.h);
}

void	or_l(struct gb_cpu_s* gb)
{
	or(gb, gb->reg.l);
}

void	or_n(struct gb_cpu_s* gb)
{
	or(gb, (uint8_t)gb->current_instruction->args);
}

void	or_ptr_hl(struct gb_cpu_s* gb)
{
	or(gb, read_8(gb, gb->reg.hl));
}