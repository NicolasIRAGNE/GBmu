/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sla.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 15:22:52 by niragne           #+#    #+#             */
/*   Updated: 2020/03/30 16:56:49 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ext_op.h"

int		sla_reg8(struct gb_cpu_s* gb, uint8_t* reg)
{
	uint16_t ret;
	ret = *reg;
	ret <<= 1;
	cpu_toggle_flag(gb, CARRY_FLAG, *reg & 0x80);
	cpu_toggle_flag(gb, ZERO_FLAG, !(uint8_t)ret);
	cpu_unset_flag(gb, SUBSTRACTION_FLAG | HALF_CARRY_FLAG);
	*reg = (uint8_t)ret;
}

int		sla_mem8(struct gb_cpu_s* gb, uint16_t addr)
{
	uint16_t ret;
	uint16_t tmp;
	ret = read_8(gb, addr);
	tmp = ret;
	ret <<= 1;
	cpu_toggle_flag(gb, CARRY_FLAG, tmp & 0x80);
	cpu_toggle_flag(gb, ZERO_FLAG, !(uint8_t)ret);
	cpu_unset_flag(gb, SUBSTRACTION_FLAG | HALF_CARRY_FLAG);
	write_8(gb, addr, ret);
}

int		sla_a(struct gb_cpu_s* gb)
{
	sla_reg8(gb, &(gb->reg.a));
}

int		sla_b(struct gb_cpu_s* gb)
{
	sla_reg8(gb, &(gb->reg.b));
}

int		sla_c(struct gb_cpu_s* gb)
{
	sla_reg8(gb, &(gb->reg.c));
}

int		sla_d(struct gb_cpu_s* gb)
{
	sla_reg8(gb, &(gb->reg.d));
}

int		sla_e(struct gb_cpu_s* gb)
{
	sla_reg8(gb, &(gb->reg.e));
}

int		sla_h(struct gb_cpu_s* gb)
{
	sla_reg8(gb, &(gb->reg.h));
}

int		sla_l(struct gb_cpu_s* gb)
{
	sla_reg8(gb, &(gb->reg.l));
}

int		sla_ptr_hl(struct gb_cpu_s* gb)
{
	sla_mem8(gb, gb->reg.hl);
}
