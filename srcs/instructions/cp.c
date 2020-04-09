/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cp.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 16:08:31 by niragne           #+#    #+#             */
/*   Updated: 2020/04/09 16:58:54 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gb.h"

void	cp_reg8(struct gb_cpu_s* gb, uint8_t* reg, uint8_t x)
{
	uint16_t ret;
	ret = *reg - x;
	cpu_toggle_flag(gb, ZERO_FLAG, !ret);
	cpu_toggle_flag(gb, CARRY_FLAG, ret > 255);
	cpu_set_flag(gb, SUBSTRACTION_FLAG);

	if ( (((*reg & 0xf) - (x & 0xf)) & 0x10))
		cpu_set_flag(gb, HALF_CARRY_FLAG);
	else
		cpu_unset_flag(gb, HALF_CARRY_FLAG);

}

void	cp_a8(struct gb_cpu_s* gb)
{
	cp_reg8(gb, &(gb->reg.a), gb->current_instruction->args);	
}

void	cp_ptr_hl(struct gb_cpu_s* gb)
{
	cp_reg8(gb, &(gb->reg.a), read_8(gb, gb->reg.hl));	
}

void	cp_a(struct gb_cpu_s* gb)
{
	cp_reg8(gb, &(gb->reg.a), gb->reg.a);	
}

void	cp_b(struct gb_cpu_s* gb)
{
	cp_reg8(gb, &(gb->reg.a), gb->reg.b);	
}

void	cp_c(struct gb_cpu_s* gb)
{
	cp_reg8(gb, &(gb->reg.a), gb->reg.c);	
}

void	cp_d(struct gb_cpu_s* gb)
{
	cp_reg8(gb, &(gb->reg.a), gb->reg.d);	
}

void	cp_e(struct gb_cpu_s* gb)
{
	cp_reg8(gb, &(gb->reg.a), gb->reg.e);	
}

void	cp_h(struct gb_cpu_s* gb)
{
	cp_reg8(gb, &(gb->reg.a), gb->reg.h);	
}

void	cp_l(struct gb_cpu_s* gb)
{
	cp_reg8(gb, &(gb->reg.a), gb->reg.l);	
}