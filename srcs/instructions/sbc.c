/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sbc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 10:58:13 by niragne           #+#    #+#             */
/*   Updated: 2020/03/27 10:59:20 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

int		sbc(struct gb_cpu_s* gb, uint8_t value)
{
	uint16_t ret;
	ret = gb->reg.a - value;

	if (gb->reg.f & CARRY_FLAG)
		ret--;

	if ( (((gb->reg.a & 0xf) - (value & 0xf)) & 0x10) )
		cpu_set_flag(gb, HALF_CARRY_FLAG);
	else
		cpu_unset_flag(gb, HALF_CARRY_FLAG);


	cpu_toggle_flag(gb, ZERO_FLAG, !ret);
	cpu_toggle_flag(gb, CARRY_FLAG, ret > 255);
	cpu_set_flag(gb, SUBSTRACTION_FLAG);
	gb->reg.a = (uint8_t)ret;
}


int		sbc_n(struct gb_cpu_s* gb)
{
	sbc(gb, gb->current_instruction->args);
}

int		sbc_a(struct gb_cpu_s* gb)
{
	sbc(gb, gb->reg.a);
}

int		sbc_b(struct gb_cpu_s* gb)
{
	sbc(gb, gb->reg.b);
}

int		sbc_c(struct gb_cpu_s* gb)
{
	sbc(gb, gb->reg.c);
}

int		sbc_d(struct gb_cpu_s* gb)
{
	sbc(gb, gb->reg.d);
}

int		sbc_e(struct gb_cpu_s* gb)
{
	sbc(gb, gb->reg.e);
}

int		sbc_h(struct gb_cpu_s* gb)
{
	sbc(gb, gb->reg.h);
}

int		sbc_l(struct gb_cpu_s* gb)
{
	sbc(gb, gb->reg.l);
}
