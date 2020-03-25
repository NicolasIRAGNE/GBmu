/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 13:27:30 by niragne           #+#    #+#             */
/*   Updated: 2020/03/25 16:49:14 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "gb.h"

int		sub(struct gb_cpu_s* gb, uint8_t value)
{
	uint16_t ret;
	ret = gb->reg.a - value;

	if ( (((gb->reg.a & 0xf) - (value & 0xf)) & 0x10) )
		cpu_set_flag(gb, HALF_CARRY_FLAG);
	else
		cpu_unset_flag(gb, HALF_CARRY_FLAG);


	cpu_toggle_flag(gb, ZERO_FLAG, !ret);
	cpu_toggle_flag(gb, CARRY_FLAG, ret > 255);
	cpu_set_flag(gb, SUBSTRACTION_FLAG);
	gb->reg.a = (uint8_t)ret;
}

int		sub_a(struct gb_cpu_s* gb)
{
	sub(gb, gb->reg.a);
}

int		sub_b(struct gb_cpu_s* gb)
{
	sub(gb, gb->reg.b);
}

int		sub_c(struct gb_cpu_s* gb)
{
	sub(gb, gb->reg.c);
}

int		sub_d(struct gb_cpu_s* gb)
{
	sub(gb, gb->reg.d);
}

int		sub_e(struct gb_cpu_s* gb)
{
	sub(gb, gb->reg.e);
}

int		sub_h(struct gb_cpu_s* gb)
{
	sub(gb, gb->reg.h);
}

int		sub_l(struct gb_cpu_s* gb)
{
	sub(gb, gb->reg.l);
}

int		sub_a8(struct gb_cpu_s* gb)
{
	sub(gb, gb->current_instruction->args);
}

int		sbc_n(struct gb_cpu_s* gb)
{
	sub(gb, gb->current_instruction->args + ((gb->reg.f & CARRY_FLAG) != 0));
}

int		sbc_a(struct gb_cpu_s* gb)
{
	sub(gb, gb->reg.a + ((gb->reg.f & CARRY_FLAG) != 0));
}

int		sbc_b(struct gb_cpu_s* gb)
{
	sub(gb, gb->reg.b + ((gb->reg.f & CARRY_FLAG) != 0));
}

int		sbc_c(struct gb_cpu_s* gb)
{
	sub(gb, gb->reg.c + ((gb->reg.f & CARRY_FLAG) != 0));
}

int		sbc_d(struct gb_cpu_s* gb)
{
	sub(gb, gb->reg.d + ((gb->reg.f & CARRY_FLAG) != 0));
}

int		sbc_e(struct gb_cpu_s* gb)
{
	sub(gb, gb->reg.e + ((gb->reg.f & CARRY_FLAG) != 0));
}

int		sbc_h(struct gb_cpu_s* gb)
{
	sub(gb, gb->reg.h + ((gb->reg.f & CARRY_FLAG) != 0));
}

int		sbc_l(struct gb_cpu_s* gb)
{
	sub(gb, gb->reg.l + ((gb->reg.f & CARRY_FLAG) != 0));
}
