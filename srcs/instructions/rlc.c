/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rlc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 12:54:59 by niragne           #+#    #+#             */
/*   Updated: 2020/03/31 15:01:37 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ext_op.h"

int		rlc_reg8(struct gb_cpu_s* gb, uint8_t* reg)
{
	uint16_t ret;
	ret = *reg;
	ret <<= 1;
	if (*reg & 0x80)
		ret += 1;
	cpu_toggle_flag(gb, CARRY_FLAG, *reg & 0x80);
	cpu_toggle_flag(gb, ZERO_FLAG, !(uint8_t)ret);
	cpu_unset_flag(gb, HALF_CARRY_FLAG | SUBSTRACTION_FLAG);
	*reg = (uint8_t)ret;
}

int		rlc_mem8(struct gb_cpu_s* gb, uint16_t addr)
{
	uint16_t ret;
	uint16_t tmp;
	ret = read_8(gb, addr);
	tmp = ret;
	ret <<= 1;
	if (tmp & 0x80)
		ret += 1;
	cpu_toggle_flag(gb, CARRY_FLAG, tmp & 0x80);
	cpu_toggle_flag(gb, ZERO_FLAG, !(uint8_t)ret);
	cpu_unset_flag(gb, HALF_CARRY_FLAG | SUBSTRACTION_FLAG);
	write_8(gb, addr, ret);
}

int		rlc_b(struct gb_cpu_s* gb)
{
	rlc_reg8(gb, &(gb->reg.b));
}

int		rlc_c(struct gb_cpu_s* gb)
{
	rlc_reg8(gb, &(gb->reg.c));
}

int		rlc_d(struct gb_cpu_s* gb)
{
	rlc_reg8(gb, &(gb->reg.d));
}

int		rlc_e(struct gb_cpu_s* gb)
{
	rlc_reg8(gb, &(gb->reg.e));
}

int		rlc_h(struct gb_cpu_s* gb)
{
	rlc_reg8(gb, &(gb->reg.h));
}

int		rlc_l(struct gb_cpu_s* gb)
{
	rlc_reg8(gb, &(gb->reg.l));
}

int		rlc_ptr_hl(struct gb_cpu_s* gb)
{
	rlc_mem8(gb, gb->reg.hl);
}

int		rlc_a(struct gb_cpu_s* gb)
{
	rlc_reg8(gb, &(gb->reg.a));
}

int		rlca(struct gb_cpu_s* gb)
{
	uint16_t ret;
	ret = gb->reg.a;
	ret <<= 1;
	if (gb->reg.a & 0x80)
		ret += 1;
	cpu_toggle_flag(gb, CARRY_FLAG, gb->reg.a & 0x80);
	cpu_unset_flag(gb, ZERO_FLAG | HALF_CARRY_FLAG | SUBSTRACTION_FLAG);
	gb->reg.a = (uint8_t)ret;
}