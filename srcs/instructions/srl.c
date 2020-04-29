/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 11:19:41 by niragne           #+#    #+#             */
/*   Updated: 2020/04/29 14:19:36 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ext_op.h"

void	srl_reg8(struct gb_cpu_s* gb, uint8_t* reg)
{
	uint16_t ret;
	ret = *reg;
	ret >>= 1;
	cpu_toggle_flag(gb, ZERO_FLAG, !ret);
	cpu_toggle_flag(gb, CARRY_FLAG, *reg & 1);
	cpu_unset_flag(gb, SUBSTRACTION_FLAG | HALF_CARRY_FLAG);
	*reg = (uint8_t)ret;
	gb->cycle += 8;
}

void	srl_mem8(struct gb_cpu_s* gb, uint16_t addr)
{
	uint16_t ret;
	ret = read_8(gb, addr);
	cpu_toggle_flag(gb, CARRY_FLAG, ret & 1);
	ret >>= 1;
	cpu_toggle_flag(gb, ZERO_FLAG, !ret);
	cpu_unset_flag(gb, SUBSTRACTION_FLAG| HALF_CARRY_FLAG);
	write_8(gb, addr, ret);
	gb->cycle += 16;
}

void	srl_a(struct gb_cpu_s* gb)
{
	srl_reg8(gb, &(gb->reg.a));
}

void	srl_b(struct gb_cpu_s* gb)
{
	srl_reg8(gb, &(gb->reg.b));
}

void	srl_c(struct gb_cpu_s* gb)
{
	srl_reg8(gb, &(gb->reg.c));
}

void	srl_d(struct gb_cpu_s* gb)
{
	srl_reg8(gb, &(gb->reg.d));
}

void	srl_e(struct gb_cpu_s* gb)
{
	srl_reg8(gb, &(gb->reg.e));
}

void	srl_h(struct gb_cpu_s* gb)
{
	srl_reg8(gb, &(gb->reg.h));
}

void	srl_l(struct gb_cpu_s* gb)
{
	srl_reg8(gb, &(gb->reg.l));
}

void	srl_ptr_hl(struct gb_cpu_s* gb)
{
	srl_mem8(gb, gb->reg.hl);
}
