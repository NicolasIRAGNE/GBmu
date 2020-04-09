/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 19:54:52 by niragne           #+#    #+#             */
/*   Updated: 2020/04/09 17:16:35 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gb.h"

void	inc_reg8(struct gb_cpu_s* gb, uint8_t* reg)
{
	if ( (((*reg & 0xf) + (1 & 0xf)) & 0x10))
		cpu_set_flag(gb, HALF_CARRY_FLAG);
	else
		cpu_unset_flag(gb, HALF_CARRY_FLAG);
	*reg = *reg + 1;
	cpu_toggle_flag(gb, ZERO_FLAG, !*reg);
	cpu_unset_flag(gb, SUBSTRACTION_FLAG);
}

void	inc_mem8(struct gb_cpu_s* gb, uint16_t addr)
{
	uint8_t	x;

	x = read_8(gb, addr);
	if ( (((x & 0xf) + (1 & 0xf)) & 0x10))
		cpu_set_flag(gb, HALF_CARRY_FLAG);
	else
		cpu_unset_flag(gb, HALF_CARRY_FLAG);
	x++;
	cpu_toggle_flag(gb, ZERO_FLAG, !x);
	cpu_unset_flag(gb, SUBSTRACTION_FLAG);
	write_8(gb, addr, x);
}

void	inc_reg16(struct gb_cpu_s* gb, uint16_t* reg)
{
	(void)gb;
	*reg = *reg + 1;
}

void	inc_a(struct gb_cpu_s* gb)
{
	inc_reg8(gb, &(gb->reg.a));
}

void	inc_b(struct gb_cpu_s* gb)
{
	inc_reg8(gb, &(gb->reg.b));
}

void	inc_c(struct gb_cpu_s* gb)
{
	inc_reg8(gb, &(gb->reg.c));
}

void	inc_d(struct gb_cpu_s* gb)
{
	inc_reg8(gb, &(gb->reg.d));
}

void	inc_e(struct gb_cpu_s* gb)
{
	inc_reg8(gb, &(gb->reg.e));
}

void	inc_h(struct gb_cpu_s* gb)
{
	inc_reg8(gb, &(gb->reg.h));
}

void	inc_l(struct gb_cpu_s* gb)
{
	inc_reg8(gb, &(gb->reg.l));
}

void	inc_hl(struct gb_cpu_s* gb)
{
	inc_reg16(gb, &(gb->reg.hl));
}

void	inc_bc(struct gb_cpu_s* gb)
{
	inc_reg16(gb, &(gb->reg.bc));
}

void	inc_de(struct gb_cpu_s* gb)
{
	inc_reg16(gb, &(gb->reg.de));
}

void	inc_sp(struct gb_cpu_s* gb)
{
	inc_reg16(gb, &(gb->reg.sp));
}

void	inc_ptr_hl(struct gb_cpu_s* gb)
{
	inc_mem8(gb, gb->reg.hl);
}