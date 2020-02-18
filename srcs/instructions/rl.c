/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 11:19:41 by niragne           #+#    #+#             */
/*   Updated: 2020/02/13 11:41:02 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ext_op.h"

int		rl_reg8(struct gb_cpu_s* gb, uint8_t* reg)
{
	uint16_t ret;
	ret = *reg;
	ret <<= 1;
	if (gb->reg.f & CARRY_FLAG)
		ret |= 0x1;
	cpu_toggle_flag(gb, ZERO_FLAG, !ret);
	cpu_toggle_flag(gb, CARRY_FLAG, *reg & 0x80);
	cpu_unset_flag(gb, SUBSTRACTION_FLAG);
	*reg = (uint8_t)ret;
}

int		rl_mem8(struct gb_cpu_s* gb, uint16_t addr)
{
	uint16_t ret;
	uint16_t tmp;
	ret = read_8(gb, addr);
	tmp = ret;
	ret <<= 1;
	if (gb->reg.f & CARRY_FLAG)
		ret |= 0x1;
	cpu_toggle_flag(gb, ZERO_FLAG, !ret);
	cpu_toggle_flag(gb, CARRY_FLAG, tmp & 0x80);
	cpu_unset_flag(gb, SUBSTRACTION_FLAG);
	write_8(gb, addr, ret);
}

int		rlc_reg8(struct gb_cpu_s* gb, uint8_t* reg)
{
	uint16_t ret;
	ret = *reg;
	ret <<= 1;
	if (*reg & 0x80)
		ret |= 1;
	cpu_toggle_flag(gb, ZERO_FLAG, !ret);
	cpu_toggle_flag(gb, CARRY_FLAG, *reg & 80);
	cpu_unset_flag(gb, SUBSTRACTION_FLAG);
	*reg = (uint8_t)ret;
}

int		rl_a(struct gb_cpu_s* gb)
{
	rl_reg8(gb, &(gb->reg.a));
}

int		rl_b(struct gb_cpu_s* gb)
{
	rl_reg8(gb, &(gb->reg.b));
}

int		rl_c(struct gb_cpu_s* gb)
{
	rl_reg8(gb, &(gb->reg.c));
}

int		rl_d(struct gb_cpu_s* gb)
{
	rl_reg8(gb, &(gb->reg.d));
}

int		rl_e(struct gb_cpu_s* gb)
{
	rl_reg8(gb, &(gb->reg.e));
}

int		rl_h(struct gb_cpu_s* gb)
{
	rl_reg8(gb, &(gb->reg.h));
}

int		rl_l(struct gb_cpu_s* gb)
{
	rl_reg8(gb, &(gb->reg.l));
}

int		rl_hl(struct gb_cpu_s* gb)
{
	rl_mem8(gb, gb->reg.hl);
}

int		rlc_a(struct gb_cpu_s* gb)
{
	rlc_reg8(gb, &(gb->reg.a));
}