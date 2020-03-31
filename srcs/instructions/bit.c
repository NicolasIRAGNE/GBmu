/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 16:56:55 by niragne           #+#    #+#             */
/*   Updated: 2020/03/31 15:07:46 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ext_op.h"

int		bit_reg8(struct gb_cpu_s* gb, int bit, uint8_t reg)
{
	cpu_toggle_flag(gb, ZERO_FLAG, !(reg & (1 << bit)));
	cpu_set_flag(gb, HALF_CARRY_FLAG);
	cpu_unset_flag(gb, SUBSTRACTION_FLAG);
}

int		bit0_ptr_hl(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 0, read_8(gb, gb->reg.hl));
}

int		bit1_ptr_hl(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 1, read_8(gb, gb->reg.hl));
}

int		bit2_ptr_hl(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 2, read_8(gb, gb->reg.hl));
}

int		bit3_ptr_hl(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 3, read_8(gb, gb->reg.hl));
}

int		bit4_ptr_hl(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 4, read_8(gb, gb->reg.hl));
}

int		bit5_ptr_hl(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 5, read_8(gb, gb->reg.hl));
}

int		bit6_ptr_hl(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 6, read_8(gb, gb->reg.hl));
}

int		bit7_ptr_hl(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 7, read_8(gb, gb->reg.hl));
}


int		bit0_b(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 0, gb->reg.b);
}

int		bit0_c(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 0, gb->reg.c);
}

int		bit0_d(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 0, gb->reg.d);
}

int		bit0_e(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 0, gb->reg.e);
}

int		bit0_h(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 0, gb->reg.h);
}

int		bit0_l(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 0, gb->reg.l);
}

int		bit0_a(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 0, gb->reg.a);
}

int		bit1_b(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 1, gb->reg.b);
}

int		bit1_c(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 1, gb->reg.c);
}

int		bit1_d(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 1, gb->reg.d);
}

int		bit1_e(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 1, gb->reg.e);
}

int		bit1_h(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 1, gb->reg.h);
}

int		bit1_l(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 1, gb->reg.l);
}

int		bit1_a(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 1, gb->reg.a);
}

int		bit2_b(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 2, gb->reg.b);
}

int		bit2_c(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 2, gb->reg.c);
}

int		bit2_d(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 2, gb->reg.d);
}

int		bit2_e(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 2, gb->reg.e);
}

int		bit2_h(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 2, gb->reg.h);
}

int		bit2_l(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 2, gb->reg.l);
}

int		bit2_a(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 2, gb->reg.a);
}

int		bit3_b(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 3, gb->reg.b);
}

int		bit3_c(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 3, gb->reg.c);
}

int		bit3_d(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 3, gb->reg.d);
}

int		bit3_e(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 3, gb->reg.e);
}

int		bit3_h(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 3, gb->reg.h);
}

int		bit3_l(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 3, gb->reg.l);
}

int		bit3_a(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 3, gb->reg.a);
}

int		bit4_b(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 4, gb->reg.b);
}

int		bit4_c(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 4, gb->reg.c);
}

int		bit4_d(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 4, gb->reg.d);
}

int		bit4_e(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 4, gb->reg.e);
}

int		bit4_h(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 4, gb->reg.h);
}

int		bit4_l(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 4, gb->reg.l);
}

int		bit4_a(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 4, gb->reg.a);
}

int		bit5_b(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 5, gb->reg.b);
}

int		bit5_c(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 5, gb->reg.c);
}

int		bit5_d(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 5, gb->reg.d);
}

int		bit5_e(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 5, gb->reg.e);
}

int		bit5_h(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 5, gb->reg.h);
}

int		bit5_l(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 5, gb->reg.l);
}

int		bit5_a(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 5, gb->reg.a);
}

int		bit6_b(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 6, gb->reg.b);
}

int		bit6_c(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 6, gb->reg.c);
}

int		bit6_d(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 6, gb->reg.d);
}

int		bit6_e(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 6, gb->reg.e);
}

int		bit6_h(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 6, gb->reg.h);
}

int		bit6_l(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 6, gb->reg.l);
}

int		bit6_a(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 6, gb->reg.a);
}

int		bit7_b(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 7, gb->reg.b);
}

int		bit7_c(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 7, gb->reg.c);
}

int		bit7_d(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 7, gb->reg.d);
}

int		bit7_e(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 7, gb->reg.e);
}

int		bit7_h(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 7, gb->reg.h);
}

int		bit7_l(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 7, gb->reg.l);
}

int		bit7_a(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 7, gb->reg.a);
}