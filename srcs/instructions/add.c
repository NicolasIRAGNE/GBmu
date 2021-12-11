/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 13:27:30 by niragne           #+#    #+#             */
/*   Updated: 2020/04/09 16:57:45 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "gb.h"

void	add(struct gb_cpu_s* gb, uint8_t value)
{
	uint16_t ret;
	ret = gb->reg.a + value;

	if ( (((gb->reg.a & 0xf) + (value & 0xf)) & 0x10) )
		cpu_set_flag(gb, HALF_CARRY_FLAG);
	else
		cpu_unset_flag(gb, HALF_CARRY_FLAG);

	cpu_toggle_flag(gb, CARRY_FLAG, ret > 255);
	cpu_unset_flag(gb, SUBSTRACTION_FLAG);
	gb->reg.a = (uint8_t)ret;
	cpu_toggle_flag(gb, ZERO_FLAG, !gb->reg.a);
}

void	add_16(struct gb_cpu_s* gb, uint16_t value)
{
	uint32_t ret;
	ret = gb->reg.hl + value;
	cpu_toggle_flag(gb, CARRY_FLAG, ret > USHRT_MAX);
	cpu_unset_flag(gb, SUBSTRACTION_FLAG);
	if ( (((gb->reg.hl & 0xfff) + (value & 0xfff)) & 0x1000) )
		cpu_set_flag(gb, HALF_CARRY_FLAG);
	else
		cpu_unset_flag(gb, HALF_CARRY_FLAG);
	gb->reg.hl = (uint16_t)ret;
}

void	add_ptr_hl(struct gb_cpu_s* gb)
{
	add(gb, read_8(gb, gb->reg.hl));	
}

void	add_a(struct gb_cpu_s* gb)
{
	add(gb, gb->reg.a);
}

void	add_b(struct gb_cpu_s* gb)
{
	add(gb, gb->reg.b);
}

void	add_c(struct gb_cpu_s* gb)
{
	add(gb, gb->reg.c);
}

void	add_d(struct gb_cpu_s* gb)
{
	add(gb, gb->reg.d);
}

void	add_e(struct gb_cpu_s* gb)
{
	add(gb, gb->reg.e);
}

void	add_h(struct gb_cpu_s* gb)
{
	add(gb, gb->reg.h);
}

void	add_l(struct gb_cpu_s* gb)
{
	add(gb, gb->reg.l);
}

void	add_a8(struct gb_cpu_s* gb)
{
	add(gb, gb->current_instruction->args);
}

void	add_bc(struct gb_cpu_s* gb)
{
	add_16(gb, gb->reg.bc);
}

void	add_de(struct gb_cpu_s* gb)
{
	add_16(gb, gb->reg.de);
}

void	add_hl(struct gb_cpu_s* gb)
{
	add_16(gb, gb->reg.hl);
}

void	add_sp(struct gb_cpu_s* gb)
{
	add_16(gb, gb->reg.sp);
}

void	add_sp_s(struct gb_cpu_s* gb)
{
	// absolutely not sure about this one
	uint32_t ret;
	int8_t value = (int8_t)(gb->current_instruction->args);

	ret = gb->reg.sp + value;
	
	cpu_toggle_flag(gb, CARRY_FLAG, ((gb->reg.sp ^ value ^ (ret & 0xFFFF)) & 0x100) == 0x100);
	cpu_toggle_flag(gb, HALF_CARRY_FLAG, ((gb->reg.sp ^ value ^ (ret & 0xFFFF)) & 0x10) == 0x10);
	
	gb->reg.sp = (uint16_t)ret;
	cpu_unset_flag(gb, ZERO_FLAG | SUBSTRACTION_FLAG);
}

