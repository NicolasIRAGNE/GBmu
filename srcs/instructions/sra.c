/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 15:22:52 by niragne           #+#    #+#             */
/*   Updated: 2020/04/09 17:02:04 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ext_op.h"

void	sra_reg8(struct gb_cpu_s* gb, uint8_t* reg)
{
	uint16_t ret;
	ret = *reg;
	ret = (ret & 0x80) | (ret >> 1);
	cpu_toggle_flag(gb, CARRY_FLAG, *reg & 0x1);
	cpu_toggle_flag(gb, ZERO_FLAG, !ret);
	cpu_unset_flag(gb, SUBSTRACTION_FLAG | HALF_CARRY_FLAG);
	*reg = (uint8_t)ret;
}

void	sra_mem8(struct gb_cpu_s* gb, uint16_t addr)
{
	uint16_t ret;
	uint16_t tmp;
	ret = read_8(gb, addr);
	tmp = ret;
	ret = (ret & 0x80) | (ret >> 1);
	cpu_toggle_flag(gb, CARRY_FLAG, tmp & 0x1);
	cpu_toggle_flag(gb, ZERO_FLAG, !ret);
	cpu_unset_flag(gb, SUBSTRACTION_FLAG | HALF_CARRY_FLAG);
	write_8(gb, addr, ret);
}

void	sra_a(struct gb_cpu_s* gb)
{
	sra_reg8(gb, &(gb->reg.a));
}

void	sra_b(struct gb_cpu_s* gb)
{
	sra_reg8(gb, &(gb->reg.b));
}

void	sra_c(struct gb_cpu_s* gb)
{
	sra_reg8(gb, &(gb->reg.c));
}

void	sra_d(struct gb_cpu_s* gb)
{
	sra_reg8(gb, &(gb->reg.d));
}

void	sra_e(struct gb_cpu_s* gb)
{
	sra_reg8(gb, &(gb->reg.e));
}

void	sra_h(struct gb_cpu_s* gb)
{
	sra_reg8(gb, &(gb->reg.h));
}

void	sra_l(struct gb_cpu_s* gb)
{
	sra_reg8(gb, &(gb->reg.l));
}

void	sra_ptr_hl(struct gb_cpu_s* gb)
{
	sra_mem8(gb, gb->reg.hl);
}
