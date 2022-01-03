/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 16:21:32 by niragne           #+#    #+#             */
/*   Updated: 2020/04/29 14:21:37 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

#include "ext_op.h"
#include "cpu.h"
#include "gb.h"

void	swap_reg8(struct gb_cpu_s* gb, uint8_t* x)
{
	*x = ((*x & 0xf0) >> 4) | ((*x & 0x0f) << 4);
	cpu_toggle_flag(gb, ZERO_FLAG, !*x);
	cpu_unset_flag(gb, CARRY_FLAG | SUBSTRACTION_FLAG | HALF_CARRY_FLAG);
	gb->cycle += 2;
}

void	swap_mem8(struct gb_cpu_s* gb, uint16_t addr)
{
	uint8_t x = read_8(gb, addr);
	x = ((x & 0xf0) >> 4) | ((x & 0x0f) << 4);
	cpu_toggle_flag(gb, ZERO_FLAG, !x);
	cpu_unset_flag(gb, CARRY_FLAG | SUBSTRACTION_FLAG | HALF_CARRY_FLAG);
	write_8(gb, addr, x);
	gb->cycle += 4;
}

void	swap_a(struct gb_cpu_s* gb)
{
	swap_reg8(gb, &(gb->reg.a));
}

void	swap_b(struct gb_cpu_s* gb)
{
	swap_reg8(gb, &(gb->reg.b));
}

void	swap_c(struct gb_cpu_s* gb)
{
	swap_reg8(gb, &(gb->reg.c));
}

void	swap_d(struct gb_cpu_s* gb)
{
	swap_reg8(gb, &(gb->reg.d));
}

void	swap_e(struct gb_cpu_s* gb)
{
	swap_reg8(gb, &(gb->reg.e));
}

void	swap_h(struct gb_cpu_s* gb)
{
	swap_reg8(gb, &(gb->reg.h));
}

void	swap_l(struct gb_cpu_s* gb)
{
	swap_reg8(gb, &(gb->reg.l));
}

void	swap_ptr_hl(struct gb_cpu_s* gb)
{
	swap_mem8(gb, gb->reg.hl);
}
