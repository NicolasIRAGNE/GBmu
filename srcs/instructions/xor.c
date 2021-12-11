/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 17:15:16 by niragne           #+#    #+#             */
/*   Updated: 2020/04/09 17:03:03 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

#include "gb.h"
#include "cpu.h"
#include "op.h"

void	xor(struct gb_cpu_s* gb, uint8_t value)
{
	gb->reg.a ^= value;
	cpu_toggle_flag(gb, ZERO_FLAG, !gb->reg.a);
	cpu_unset_flag(gb, SUBSTRACTION_FLAG | CARRY_FLAG | HALF_CARRY_FLAG);
}

void	xor_a(struct gb_cpu_s* gb)
{
	xor(gb, gb->reg.a);
}

void	xor_b(struct gb_cpu_s* gb)
{
	xor(gb, gb->reg.b);
}

void	xor_c(struct gb_cpu_s* gb)
{
	xor(gb, gb->reg.c);
}

void	xor_d(struct gb_cpu_s* gb)
{
	xor(gb, gb->reg.d);
}

void	xor_e(struct gb_cpu_s* gb)
{
	xor(gb, gb->reg.e);
}

void	xor_h(struct gb_cpu_s* gb)
{
	xor(gb, gb->reg.h);
}

void	xor_l(struct gb_cpu_s* gb)
{
	xor(gb, gb->reg.l);
}

void	xor_ptr_hl(struct gb_cpu_s* gb)
{
	xor(gb, read_8(gb, gb->reg.hl));
}

void	xor_n(struct gb_cpu_s* gb)
{
	xor(gb, gb->current_instruction->args);
}