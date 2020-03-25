/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 13:27:30 by niragne           #+#    #+#             */
/*   Updated: 2020/03/25 16:21:42 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "gb.h"

int		add(struct gb_cpu_s* gb, uint8_t value)
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

int		add_16(struct gb_cpu_s* gb, uint16_t value)
{
	uint32_t ret;
	ret = gb->reg.hl + value;
	cpu_toggle_flag(gb, CARRY_FLAG, ret > USHRT_MAX);
	cpu_unset_flag(gb, SUBSTRACTION_FLAG);
	if ( (((gb->reg.hl & 0xf00) + (value & 0xf00)) & 0x1000) )
		cpu_set_flag(gb, HALF_CARRY_FLAG);
	else
		cpu_unset_flag(gb, HALF_CARRY_FLAG);
	gb->reg.hl = (uint16_t)ret;
}

int		add_ptr_hl(struct gb_cpu_s* gb)
{
	add(gb, read_8(gb, gb->reg.hl));	
}

int		add_a(struct gb_cpu_s* gb)
{
	add(gb, gb->reg.a);
}

int		add_b(struct gb_cpu_s* gb)
{
	add(gb, gb->reg.b);
}

int		add_c(struct gb_cpu_s* gb)
{
	add(gb, gb->reg.c);
}

int		add_d(struct gb_cpu_s* gb)
{
	add(gb, gb->reg.d);
}

int		add_e(struct gb_cpu_s* gb)
{
	add(gb, gb->reg.e);
}

int		add_h(struct gb_cpu_s* gb)
{
	add(gb, gb->reg.h);
}

int		add_l(struct gb_cpu_s* gb)
{
	add(gb, gb->reg.l);
}

int		add_a8(struct gb_cpu_s* gb)
{
	add(gb, gb->current_instruction->args);
}

int		add_bc(struct gb_cpu_s* gb)
{
	add_16(gb, gb->reg.bc);
}

int		add_de(struct gb_cpu_s* gb)
{
	add_16(gb, gb->reg.de);
}

int		add_hl(struct gb_cpu_s* gb)
{
	add_16(gb, gb->reg.hl);
}

int		add_sp(struct gb_cpu_s* gb)
{
	add_16(gb, gb->reg.sp);
}

int		adc_n(struct gb_cpu_s* gb)
{
	add(gb, gb->current_instruction->args + ((gb->reg.f & CARRY_FLAG) != 0));
}

int		adc_a(struct gb_cpu_s* gb)
{
	add(gb, gb->reg.a + ((gb->reg.f & CARRY_FLAG) != 0));
}

int		adc_b(struct gb_cpu_s* gb)
{
	add(gb, gb->reg.b + ((gb->reg.f & CARRY_FLAG) != 0));
}

int		adc_c(struct gb_cpu_s* gb)
{
	add(gb, gb->reg.c + ((gb->reg.f & CARRY_FLAG) != 0));
}

int		adc_d(struct gb_cpu_s* gb)
{
	add(gb, gb->reg.d + ((gb->reg.f & CARRY_FLAG) != 0));
}

int		adc_e(struct gb_cpu_s* gb)
{
	add(gb, gb->reg.e + ((gb->reg.f & CARRY_FLAG) != 0));
}

int		adc_h(struct gb_cpu_s* gb)
{
	add(gb, gb->reg.h + ((gb->reg.f & CARRY_FLAG) != 0));
}

int		adc_l(struct gb_cpu_s* gb)
{
	add(gb, gb->reg.l + ((gb->reg.f & CARRY_FLAG) != 0));
}
