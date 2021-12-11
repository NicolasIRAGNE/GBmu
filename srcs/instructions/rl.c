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

#include <stdint.h>

#include "ext_op.h"
#include "cpu.h"
#include "gb.h"
#include "op.h"

void	rl_reg8(struct gb_cpu_s* gb, uint8_t* reg)
{
	uint16_t ret;
	ret = *reg;
	ret <<= 1;
	if (gb->reg.f & CARRY_FLAG)
		ret += 0x1;
	cpu_toggle_flag(gb, CARRY_FLAG, *reg & 0x80);
	cpu_toggle_flag(gb, ZERO_FLAG, !(uint8_t)ret);
	cpu_unset_flag(gb, SUBSTRACTION_FLAG | HALF_CARRY_FLAG);
	*reg = (uint8_t)ret;
}

void	rl_mem8(struct gb_cpu_s* gb, uint16_t addr)
{
	uint16_t ret;
	uint16_t tmp;
	ret = read_8(gb, addr);
	tmp = ret;
	ret <<= 1;
	if (gb->reg.f & CARRY_FLAG)
		ret += 0x1;
	cpu_toggle_flag(gb, CARRY_FLAG, tmp & 0x80);
	cpu_toggle_flag(gb, ZERO_FLAG, !(uint8_t)ret);
	cpu_unset_flag(gb, SUBSTRACTION_FLAG | HALF_CARRY_FLAG);
	write_8(gb, addr, ret);
}

void	rl_a(struct gb_cpu_s* gb)
{
	rl_reg8(gb, &(gb->reg.a));
}

void	rla(struct gb_cpu_s* gb)
{
	uint16_t ret;
	ret = gb->reg.a;
	ret <<= 1;
	if (gb->reg.f & CARRY_FLAG)
		ret += 0x1;
	cpu_toggle_flag(gb, CARRY_FLAG, gb->reg.a & 0x80);
	cpu_unset_flag(gb, ZERO_FLAG | SUBSTRACTION_FLAG | HALF_CARRY_FLAG);
	gb->reg.a = (uint8_t)ret;
}

void	rl_b(struct gb_cpu_s* gb)
{
	rl_reg8(gb, &(gb->reg.b));
}

void	rl_c(struct gb_cpu_s* gb)
{
	rl_reg8(gb, &(gb->reg.c));
}

void	rl_d(struct gb_cpu_s* gb)
{
	rl_reg8(gb, &(gb->reg.d));
}

void	rl_e(struct gb_cpu_s* gb)
{
	rl_reg8(gb, &(gb->reg.e));
}

void	rl_h(struct gb_cpu_s* gb)
{
	rl_reg8(gb, &(gb->reg.h));
}

void	rl_l(struct gb_cpu_s* gb)
{
	rl_reg8(gb, &(gb->reg.l));
}

void	rl_ptr_hl(struct gb_cpu_s* gb)
{
	rl_mem8(gb, gb->reg.hl);
}
