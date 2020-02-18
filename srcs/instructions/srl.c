/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 11:19:41 by niragne           #+#    #+#             */
/*   Updated: 2020/02/13 11:45:27 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ext_op.h"

int		srl_reg8(struct gb_cpu_s* gb, uint8_t* reg)
{
	uint16_t ret;
	ret = *reg;
	ret >>= 1;
	cpu_toggle_flag(gb, ZERO_FLAG, !ret);
	cpu_toggle_flag(gb, CARRY_FLAG, *reg & 1);
	cpu_unset_flag(gb, SUBSTRACTION_FLAG);
	*reg = (uint8_t)ret;
}

int		srl_mem8(struct gb_cpu_s* gb, uint16_t addr)
{
	uint16_t ret;
	ret = read_8(gb, addr);
	cpu_toggle_flag(gb, CARRY_FLAG, ret & 1);
	ret >>= 1;
	cpu_toggle_flag(gb, ZERO_FLAG, !ret);
	cpu_unset_flag(gb, SUBSTRACTION_FLAG);
	write_8(gb, addr, ret);
}

int		srl_a(struct gb_cpu_s* gb)
{
	srl_reg8(gb, &(gb->reg.a));
}

int		srl_b(struct gb_cpu_s* gb)
{
	srl_reg8(gb, &(gb->reg.b));
}

int		srl_c(struct gb_cpu_s* gb)
{
	srl_reg8(gb, &(gb->reg.c));
}

int		srl_d(struct gb_cpu_s* gb)
{
	srl_reg8(gb, &(gb->reg.d));
}

int		srl_e(struct gb_cpu_s* gb)
{
	srl_reg8(gb, &(gb->reg.e));
}

int		srl_h(struct gb_cpu_s* gb)
{
	srl_reg8(gb, &(gb->reg.h));
}

int		srl_l(struct gb_cpu_s* gb)
{
	srl_reg8(gb, &(gb->reg.l));
}

int		srl_hl(struct gb_cpu_s* gb)
{
	srl_mem8(gb, gb->reg.hl);
}