/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 10:55:56 by niragne           #+#    #+#             */
/*   Updated: 2020/03/27 10:57:21 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

int		adc(struct gb_cpu_s* gb, uint8_t value)
{
	uint16_t ret;
	ret = gb->reg.a + value;
	if (gb->reg.f & CARRY_FLAG)
		ret++;

	if ( (((gb->reg.a & 0xf) + (value & 0xf)) & 0x10) )
		cpu_set_flag(gb, HALF_CARRY_FLAG);
	else
		cpu_unset_flag(gb, HALF_CARRY_FLAG);

	cpu_toggle_flag(gb, CARRY_FLAG, ret > 255);
	cpu_unset_flag(gb, SUBSTRACTION_FLAG);
	gb->reg.a = (uint8_t)ret;
	cpu_toggle_flag(gb, ZERO_FLAG, !gb->reg.a);
}

int		adc_n(struct gb_cpu_s* gb)
{
	adc(gb, gb->current_instruction->args);
}

int		adc_a(struct gb_cpu_s* gb)
{
	adc(gb, gb->reg.a);
}

int		adc_b(struct gb_cpu_s* gb)
{
	adc(gb, gb->reg.b);
}

int		adc_c(struct gb_cpu_s* gb)
{
	adc(gb, gb->reg.c);
}

int		adc_d(struct gb_cpu_s* gb)
{
	adc(gb, gb->reg.d);
}

int		adc_e(struct gb_cpu_s* gb)
{
	adc(gb, gb->reg.e);
}

int		adc_h(struct gb_cpu_s* gb)
{
	adc(gb, gb->reg.h);
}

int		adc_l(struct gb_cpu_s* gb)
{
	adc(gb, gb->reg.l);
}
