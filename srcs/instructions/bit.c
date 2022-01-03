/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 16:56:55 by niragne           #+#    #+#             */
/*   Updated: 2020/04/29 14:23:51 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

#include "ext_op.h"
#include "cpu.h"
#include "gb.h"

void	bit_reg8(struct gb_cpu_s* gb, int bit, uint8_t reg)
{
	cpu_toggle_flag(gb, ZERO_FLAG, !(reg & (1 << bit)));
	cpu_set_flag(gb, HALF_CARRY_FLAG);
	cpu_unset_flag(gb, SUBSTRACTION_FLAG);
	gb->cycle += 2;
}

void	bit0_ptr_hl(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 0, read_8(gb, gb->reg.hl));
	gb->cycle += 1;
}

void	bit1_ptr_hl(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 1, read_8(gb, gb->reg.hl));
	gb->cycle += 1;
}

void	bit2_ptr_hl(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 2, read_8(gb, gb->reg.hl));
	gb->cycle += 1;
}

void	bit3_ptr_hl(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 3, read_8(gb, gb->reg.hl));
	gb->cycle += 1;
}

void	bit4_ptr_hl(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 4, read_8(gb, gb->reg.hl));
	gb->cycle += 1;
}

void	bit5_ptr_hl(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 5, read_8(gb, gb->reg.hl));
	gb->cycle += 1;
}

void	bit6_ptr_hl(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 6, read_8(gb, gb->reg.hl));
	gb->cycle += 1;
}

void	bit7_ptr_hl(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 7, read_8(gb, gb->reg.hl));
	gb->cycle += 2;
}

void	bit0_b(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 0, gb->reg.b);
}

void	bit0_c(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 0, gb->reg.c);
}

void	bit0_d(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 0, gb->reg.d);
}

void	bit0_e(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 0, gb->reg.e);
}

void	bit0_h(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 0, gb->reg.h);
}

void	bit0_l(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 0, gb->reg.l);
}

void	bit0_a(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 0, gb->reg.a);
}

void	bit1_b(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 1, gb->reg.b);
}

void	bit1_c(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 1, gb->reg.c);
}

void	bit1_d(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 1, gb->reg.d);
}

void	bit1_e(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 1, gb->reg.e);
}

void	bit1_h(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 1, gb->reg.h);
}

void	bit1_l(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 1, gb->reg.l);
}

void	bit1_a(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 1, gb->reg.a);
}

void	bit2_b(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 2, gb->reg.b);
}

void	bit2_c(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 2, gb->reg.c);
}

void	bit2_d(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 2, gb->reg.d);
}

void	bit2_e(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 2, gb->reg.e);
}

void	bit2_h(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 2, gb->reg.h);
}

void	bit2_l(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 2, gb->reg.l);
}

void	bit2_a(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 2, gb->reg.a);
}

void	bit3_b(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 3, gb->reg.b);
}

void	bit3_c(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 3, gb->reg.c);
}

void	bit3_d(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 3, gb->reg.d);
}

void	bit3_e(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 3, gb->reg.e);
}

void	bit3_h(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 3, gb->reg.h);
}

void	bit3_l(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 3, gb->reg.l);
}

void	bit3_a(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 3, gb->reg.a);
}

void	bit4_b(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 4, gb->reg.b);
}

void	bit4_c(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 4, gb->reg.c);
}

void	bit4_d(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 4, gb->reg.d);
}

void	bit4_e(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 4, gb->reg.e);
}

void	bit4_h(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 4, gb->reg.h);
}

void	bit4_l(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 4, gb->reg.l);
}

void	bit4_a(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 4, gb->reg.a);
}

void	bit5_b(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 5, gb->reg.b);
}

void	bit5_c(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 5, gb->reg.c);
}

void	bit5_d(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 5, gb->reg.d);
}

void	bit5_e(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 5, gb->reg.e);
}

void	bit5_h(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 5, gb->reg.h);
}

void	bit5_l(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 5, gb->reg.l);
}

void	bit5_a(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 5, gb->reg.a);
}

void	bit6_b(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 6, gb->reg.b);
}

void	bit6_c(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 6, gb->reg.c);
}

void	bit6_d(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 6, gb->reg.d);
}

void	bit6_e(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 6, gb->reg.e);
}

void	bit6_h(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 6, gb->reg.h);
}

void	bit6_l(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 6, gb->reg.l);
}

void	bit6_a(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 6, gb->reg.a);
}

void	bit7_b(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 7, gb->reg.b);
}

void	bit7_c(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 7, gb->reg.c);
}

void	bit7_d(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 7, gb->reg.d);
}

void	bit7_e(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 7, gb->reg.e);
}

void	bit7_h(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 7, gb->reg.h);
}

void	bit7_l(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 7, gb->reg.l);
}

void	bit7_a(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 7, gb->reg.a);
}