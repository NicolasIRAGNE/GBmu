/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 16:21:32 by niragne           #+#    #+#             */
/*   Updated: 2020/03/31 15:04:33 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ext_op.h"

int		swap_reg8(struct gb_cpu_s* gb, uint8_t* x)
{
	*x = ((*x & 0xf0) >> 4) | ((*x & 0x0f) << 4);
	cpu_toggle_flag(gb, ZERO_FLAG, !*x);
	cpu_unset_flag(gb, CARRY_FLAG | SUBSTRACTION_FLAG | HALF_CARRY_FLAG);
}

int		swap_mem8(struct gb_cpu_s* gb, uint16_t addr)
{
	uint8_t x = read_8(gb, addr);
	x = ((x & 0xf0) >> 4) | ((x & 0x0f) << 4);
	cpu_toggle_flag(gb, ZERO_FLAG, !x);
	cpu_unset_flag(gb, CARRY_FLAG | SUBSTRACTION_FLAG | HALF_CARRY_FLAG);
	write_8(gb, addr, x);
}

int		swap_a(struct gb_cpu_s* gb)
{
	swap_reg8(gb, &(gb->reg.a));
}

int		swap_b(struct gb_cpu_s* gb)
{
	swap_reg8(gb, &(gb->reg.b));
}

int		swap_c(struct gb_cpu_s* gb)
{
	swap_reg8(gb, &(gb->reg.c));
}

int		swap_d(struct gb_cpu_s* gb)
{
	swap_reg8(gb, &(gb->reg.d));
}

int		swap_e(struct gb_cpu_s* gb)
{
	swap_reg8(gb, &(gb->reg.e));
}

int		swap_h(struct gb_cpu_s* gb)
{
	swap_reg8(gb, &(gb->reg.h));
}

int		swap_l(struct gb_cpu_s* gb)
{
	swap_reg8(gb, &(gb->reg.l));
}

int		swap_ptr_hl(struct gb_cpu_s* gb)
{
	swap_mem8(gb, gb->reg.hl);
}
