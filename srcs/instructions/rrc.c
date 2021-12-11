/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 12:54:59 by niragne           #+#    #+#             */
/*   Updated: 2020/04/29 14:18:58 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

#include "ext_op.h"
#include "cpu.h"
#include "gb.h"
#include "op.h"

void	rrc_reg8(struct gb_cpu_s* gb, uint8_t* reg)
{
	uint16_t ret;
	ret = *reg;
	ret >>= 1;
	if (*reg & 1)
		ret |= 0x80;
	cpu_toggle_flag(gb, CARRY_FLAG, *reg & 1);
	cpu_toggle_flag(gb, ZERO_FLAG, !(uint8_t)ret);
	cpu_unset_flag(gb, HALF_CARRY_FLAG | SUBSTRACTION_FLAG);
	*reg = (uint8_t)ret;
	gb->cycle += 8;
}

void	rrc_mem8(struct gb_cpu_s* gb, uint16_t addr)
{
	uint16_t ret;
	uint16_t tmp;
	ret = read_8(gb, addr);
	tmp = ret;
	ret >>= 1;
	if (tmp & 1)
		ret |= 0x80;
	cpu_toggle_flag(gb, CARRY_FLAG, tmp & 0x1);
	cpu_toggle_flag(gb, ZERO_FLAG, !(uint8_t)ret);
	cpu_unset_flag(gb, HALF_CARRY_FLAG | SUBSTRACTION_FLAG );
	write_8(gb, addr, ret);
	gb->cycle += 16;
}

void	rrc_b(struct gb_cpu_s* gb)
{
	rrc_reg8(gb, &(gb->reg.b));
}

void	rrc_c(struct gb_cpu_s* gb)
{
	rrc_reg8(gb, &(gb->reg.c));
}

void	rrc_d(struct gb_cpu_s* gb)
{
	rrc_reg8(gb, &(gb->reg.d));
}

void	rrc_e(struct gb_cpu_s* gb)
{
	rrc_reg8(gb, &(gb->reg.e));
}

void	rrc_h(struct gb_cpu_s* gb)
{
	rrc_reg8(gb, &(gb->reg.h));
}

void	rrc_l(struct gb_cpu_s* gb)
{
	rrc_reg8(gb, &(gb->reg.l));
}

void	rrc_ptr_hl(struct gb_cpu_s* gb)
{
	rrc_mem8(gb, gb->reg.hl);
}

void	rrc_a(struct gb_cpu_s* gb)
{
	rrc_reg8(gb, &(gb->reg.a));
}

void	rrca(struct gb_cpu_s* gb)
{
	uint16_t ret;
	ret = gb->reg.a;
	ret >>= 1;
	if (gb->reg.a & 1)
		ret |= 0x80;
	cpu_toggle_flag(gb, CARRY_FLAG, gb->reg.a & 1);
	cpu_unset_flag(gb, ZERO_FLAG | HALF_CARRY_FLAG | SUBSTRACTION_FLAG);
	gb->reg.a = (uint8_t)ret;
	gb->cycle += 4;
}