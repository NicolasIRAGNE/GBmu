/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 17:15:16 by niragne           #+#    #+#             */
/*   Updated: 2020/02/17 14:09:26 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gb.h"

int		xor(struct gb_cpu_s* gb, uint8_t value)
{
	gb->reg.a ^= value;
	cpu_toggle_flag(gb, ZERO_FLAG, !gb->reg.a);
	cpu_unset_flag(gb, SUBSTRACTION_FLAG | CARRY_FLAG | HALF_CARRY_FLAG);
}

int		xor_a(struct gb_cpu_s* gb)
{
	xor(gb, gb->reg.a);
}

int		xor_b(struct gb_cpu_s* gb)
{
	xor(gb, gb->reg.b);
}

int		xor_c(struct gb_cpu_s* gb)
{
	xor(gb, gb->reg.c);
}

int		xor_d(struct gb_cpu_s* gb)
{
	xor(gb, gb->reg.d);
}

int		xor_e(struct gb_cpu_s* gb)
{
	xor(gb, gb->reg.e);
}

int		xor_h(struct gb_cpu_s* gb)
{
	xor(gb, gb->reg.h);
}

int		xor_l(struct gb_cpu_s* gb)
{
	xor(gb, gb->reg.l);
}

int		xor_ptr_hl(struct gb_cpu_s* gb)
{
	xor(gb, read_8(gb, gb->reg.hl));
}

int		xor_n(struct gb_cpu_s* gb)
{
	xor(gb, gb->current_instruction->args);
}