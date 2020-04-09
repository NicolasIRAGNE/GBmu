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

void	rr_reg8(struct gb_cpu_s* gb, uint8_t* reg)
{
	uint16_t ret;
	ret = *reg;
	ret >>= 1;
	if (gb->reg.f & CARRY_FLAG)
		ret |= 0x80;
	cpu_toggle_flag(gb, CARRY_FLAG, *reg & 1);
	cpu_toggle_flag(gb, ZERO_FLAG, !ret);	
	cpu_unset_flag(gb, SUBSTRACTION_FLAG | HALF_CARRY_FLAG);
	*reg = (uint8_t)ret;
}

void	rr_mem8(struct gb_cpu_s* gb, uint16_t addr)
{
	uint16_t ret;
	uint16_t tmp;
	ret = read_8(gb, addr);
	tmp = ret;
	ret >>= 1;
	if (gb->reg.f & CARRY_FLAG)
		ret |= 0x80;
	cpu_toggle_flag(gb, CARRY_FLAG, tmp & 1);
	cpu_toggle_flag(gb, ZERO_FLAG, !ret);	
	cpu_unset_flag(gb, SUBSTRACTION_FLAG | HALF_CARRY_FLAG);
	write_8(gb, addr, ret);
}

void	rra(struct gb_cpu_s* gb)
{
	uint16_t ret;
	ret = gb->reg.a;
	ret >>= 1;
	if (gb->reg.f & CARRY_FLAG)
		ret |= 0x80;
	cpu_toggle_flag(gb, CARRY_FLAG, gb->reg.a & 1);
	cpu_unset_flag(gb, ZERO_FLAG | SUBSTRACTION_FLAG | HALF_CARRY_FLAG);
	gb->reg.a = (uint8_t)ret;
}

void	rr_a(struct gb_cpu_s* gb)
{
	rr_reg8(gb, &(gb->reg.a));
}

void	rr_b(struct gb_cpu_s* gb)
{
	rr_reg8(gb, &(gb->reg.b));
}

void	rr_c(struct gb_cpu_s* gb)
{
	rr_reg8(gb, &(gb->reg.c));
}

void	rr_d(struct gb_cpu_s* gb)
{
	rr_reg8(gb, &(gb->reg.d));
}

void	rr_e(struct gb_cpu_s* gb)
{
	rr_reg8(gb, &(gb->reg.e));
}

void	rr_h(struct gb_cpu_s* gb)
{
	rr_reg8(gb, &(gb->reg.h));
}

void	rr_l(struct gb_cpu_s* gb)
{
	rr_reg8(gb, &(gb->reg.l));
}

void	rr_ptr_hl(struct gb_cpu_s* gb)
{
	rr_mem8(gb, gb->reg.hl);
}
