/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sbc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 10:58:13 by niragne           #+#    #+#             */
/*   Updated: 2020/04/29 14:21:14 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

#include "op.h"
#include "cpu.h"
#include "gb.h"

void	sbc(struct gb_cpu_s* gb, uint8_t value)
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

	ret = gb->reg.a - value;
	if ( (((gb->reg.a & 0xf) - (value & 0xf)) & 0x10) || (hflag))
		cpu_set_flag(gb, HALF_CARRY_FLAG);
	else
		cpu_unset_flag(gb, HALF_CARRY_FLAG);


	cpu_toggle_flag(gb, ZERO_FLAG, !ret);
	cpu_toggle_flag(gb, CARRY_FLAG, ret > 255 || (cflag));
	cpu_set_flag(gb, SUBSTRACTION_FLAG);
	gb->reg.a = (uint8_t)ret;
}


void	sbc_n(struct gb_cpu_s* gb)
{
	sbc(gb, gb->current_instruction->args);
}

void	sbc_a(struct gb_cpu_s* gb)
{
	sbc(gb, gb->reg.a);
}

void	sbc_b(struct gb_cpu_s* gb)
{
	sbc(gb, gb->reg.b);
}

void	sbc_c(struct gb_cpu_s* gb)
{
	sbc(gb, gb->reg.c);
}

void	sbc_d(struct gb_cpu_s* gb)
{
	sbc(gb, gb->reg.d);
}

void	sbc_e(struct gb_cpu_s* gb)
{
	sbc(gb, gb->reg.e);
}

void	sbc_h(struct gb_cpu_s* gb)
{
	sbc(gb, gb->reg.h);
}

void	sbc_l(struct gb_cpu_s* gb)
{
	sbc(gb, gb->reg.l);
}

void	sbc_ptr_hl(struct gb_cpu_s* gb)
{
	sbc(gb, read_8(gb, gb->reg.hl));
}