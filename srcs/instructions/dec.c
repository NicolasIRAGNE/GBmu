/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dec.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 20:05:58 by niragne           #+#    #+#             */
/*   Updated: 2020/04/09 17:16:41 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

#include "gb.h"
#include "cpu.h"
#include "op.h"

void	dec_reg8(struct gb_cpu_s* gb, uint8_t* reg)
{	
	if ( (((*reg & 0xf) - (1 & 0xf)) & 0x10))
		cpu_set_flag(gb, HALF_CARRY_FLAG);
	else
		cpu_unset_flag(gb, HALF_CARRY_FLAG);
	*reg = *reg - 1;
	cpu_toggle_flag(gb, ZERO_FLAG, !*reg);
	cpu_set_flag(gb, SUBSTRACTION_FLAG);
}

void	dec_mem8(struct gb_cpu_s* gb, uint16_t addr)
{
	uint8_t	x;

	x = read_8(gb, addr);
	if ( (((x & 0xf) - (1 & 0xf)) & 0x10))
		cpu_set_flag(gb, HALF_CARRY_FLAG);
	else
		cpu_unset_flag(gb, HALF_CARRY_FLAG);
	x--;
	cpu_toggle_flag(gb, ZERO_FLAG, !x);
	cpu_set_flag(gb, SUBSTRACTION_FLAG);
	write_8(gb, addr, x);
}

void	dec_reg16(struct gb_cpu_s* gb, uint16_t* reg)
{
	(void)gb;
	*reg = *reg - 1;
}

void	dec_a(struct gb_cpu_s* gb)
{
	dec_reg8(gb, &(gb->reg.a));
}

void	dec_b(struct gb_cpu_s* gb)
{
	dec_reg8(gb, &(gb->reg.b));
}

void	dec_c(struct gb_cpu_s* gb)
{
	dec_reg8(gb, &(gb->reg.c));
}

void	dec_d(struct gb_cpu_s* gb)
{
	dec_reg8(gb, &(gb->reg.d));
}

void	dec_e(struct gb_cpu_s* gb)
{
	dec_reg8(gb, &(gb->reg.e));
}

void	dec_h(struct gb_cpu_s* gb)
{
	dec_reg8(gb, &(gb->reg.h));
}

void	dec_l(struct gb_cpu_s* gb)
{
	dec_reg8(gb, &(gb->reg.l));
}

void	dec_hl(struct gb_cpu_s* gb)
{
	dec_reg16(gb, &(gb->reg.hl));
}

void	dec_bc(struct gb_cpu_s* gb)
{
	dec_reg16(gb, &(gb->reg.bc));
}

void	dec_de(struct gb_cpu_s* gb)
{
	dec_reg16(gb, &(gb->reg.de));
}

void	dec_sp(struct gb_cpu_s* gb)
{
	dec_reg16(gb, &(gb->reg.sp));
}

void	dec_ptr_hl(struct gb_cpu_s* gb)
{
	dec_mem8(gb, gb->reg.hl);
}