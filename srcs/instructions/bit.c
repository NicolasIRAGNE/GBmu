/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 16:56:55 by niragne           #+#    #+#             */
/*   Updated: 2020/03/05 14:49:10 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ext_op.h"

int		bit_reg8(struct gb_cpu_s* gb, int bit, uint8_t reg)
{
	cpu_toggle_flag(gb, ZERO_FLAG, !(reg & (1 << bit)));
	cpu_set_flag(gb, HALF_CARRY_FLAG);
	cpu_unset_flag(gb, SUBSTRACTION_FLAG);
}

int		bit7_b(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 7, gb->reg.b);
}

int		bit7_c(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 7, gb->reg.c);
}

int		bit7_d(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 7, gb->reg.d);
}

int		bit7_e(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 7, gb->reg.e);
}

int		bit7_h(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 7, gb->reg.h);
}

int		bit7_l(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 7, gb->reg.l);
}

int		bit7_a(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 7, gb->reg.a);
}