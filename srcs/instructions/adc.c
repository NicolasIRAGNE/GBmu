/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 10:55:56 by niragne           #+#    #+#             */
/*   Updated: 2020/04/09 16:57:16 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

#include "op.h"
#include "cpu.h"
#include "gb.h"

void		adc(struct gb_cpu_s* gb, uint8_t value)
{
	uint16_t ret;
	int hflag = 0;
	int cflag = 0;

	if (gb->reg.f & CARRY_FLAG)
	{
		if( (value & 0x0f) + 1 > 0x0f)
			hflag = 1;
		if (value + 1 > 0xff)
			cflag = 1;
		value++;
	}
	ret = gb->reg.a + value;
	if( ((value & 0x0f) + (gb->reg.a & 0x0f)) > 0x0f || (hflag))
		cpu_set_flag(gb, HALF_CARRY_FLAG);
	else
		cpu_unset_flag(gb, HALF_CARRY_FLAG);

	cpu_toggle_flag(gb, CARRY_FLAG, ret > 0xff || cflag);
	cpu_unset_flag(gb, SUBSTRACTION_FLAG);
	gb->reg.a = (uint8_t)ret;
	cpu_toggle_flag(gb, ZERO_FLAG, !gb->reg.a);
}

void		adc_n(struct gb_cpu_s* gb)
{
	adc(gb, gb->current_instruction->args);
}

void		adc_a(struct gb_cpu_s* gb)
{
	adc(gb, gb->reg.a);
}

void		adc_b(struct gb_cpu_s* gb)
{
	adc(gb, gb->reg.b);
}

void		adc_c(struct gb_cpu_s* gb)
{
	adc(gb, gb->reg.c);
}

void		adc_d(struct gb_cpu_s* gb)
{
	adc(gb, gb->reg.d);
}

void		adc_e(struct gb_cpu_s* gb)
{
	adc(gb, gb->reg.e);
}

void		adc_h(struct gb_cpu_s* gb)
{
	adc(gb, gb->reg.h);
}

void		adc_l(struct gb_cpu_s* gb)
{
	adc(gb, gb->reg.l);
}

void		adc_ptr_hl(struct gb_cpu_s* gb)
{
	adc(gb, read_8(gb, gb->reg.hl));
}