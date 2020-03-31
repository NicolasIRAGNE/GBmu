/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cp.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 16:08:31 by niragne           #+#    #+#             */
/*   Updated: 2020/03/31 15:23:24 by niragne          ###   ########.fr       */
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

int	cp_a8(struct gb_cpu_s* gb)
{
	cp_reg8(gb, &(gb->reg.a), gb->current_instruction->args);	
}

int	cp_ptr_hl(struct gb_cpu_s* gb)
{
	cp_reg8(gb, &(gb->reg.a), read_8(gb, gb->reg.hl));	
}

int	cp_a(struct gb_cpu_s* gb)
{
	cp_reg8(gb, &(gb->reg.a), gb->reg.a);	
}

int	cp_b(struct gb_cpu_s* gb)
{
	cp_reg8(gb, &(gb->reg.a), gb->reg.b);	
}

int	cp_c(struct gb_cpu_s* gb)
{
	cp_reg8(gb, &(gb->reg.a), gb->reg.c);	
}

int	cp_d(struct gb_cpu_s* gb)
{
	cp_reg8(gb, &(gb->reg.a), gb->reg.d);	
}

int	cp_e(struct gb_cpu_s* gb)
{
	cp_reg8(gb, &(gb->reg.a), gb->reg.e);	
}

int	cp_h(struct gb_cpu_s* gb)
{
	cp_reg8(gb, &(gb->reg.a), gb->reg.h);	
}

int	cp_l(struct gb_cpu_s* gb)
{
	cp_reg8(gb, &(gb->reg.a), gb->reg.l);	
}