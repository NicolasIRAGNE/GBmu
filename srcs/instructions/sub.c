/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 13:27:30 by niragne           #+#    #+#             */
/*   Updated: 2020/04/09 17:02:31 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdint.h>

#include "gb.h"
#include "cpu.h"
#include "op.h"

void	sub(struct gb_cpu_s* gb, uint8_t value)
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

void	sub_a(struct gb_cpu_s* gb)
{
	sub(gb, gb->reg.a);
}

void	sub_b(struct gb_cpu_s* gb)
{
	sub(gb, gb->reg.b);
}

void	sub_c(struct gb_cpu_s* gb)
{
	sub(gb, gb->reg.c);
}

void	sub_d(struct gb_cpu_s* gb)
{
	sub(gb, gb->reg.d);
}

void	sub_e(struct gb_cpu_s* gb)
{
	sub(gb, gb->reg.e);
}

void	sub_h(struct gb_cpu_s* gb)
{
	sub(gb, gb->reg.h);
}

void	sub_l(struct gb_cpu_s* gb)
{
	sub(gb, gb->reg.l);
}

void	sub_a8(struct gb_cpu_s* gb)
{
	sub(gb, gb->current_instruction->args);
}

void	sub_ptr_hl(struct gb_cpu_s* gb)
{
	sub(gb, read_8(gb, gb->reg.hl));
}