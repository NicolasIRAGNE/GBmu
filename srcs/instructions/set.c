/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 14:48:36 by niragne           #+#    #+#             */
/*   Updated: 2020/03/31 15:16:24 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ext_op.h"

int		set_reg8(struct gb_cpu_s* gb, int bit, uint8_t* reg)
{
	*reg |= (1 << bit);
}

int		set_mem8(struct gb_cpu_s* gb, int bit, uint16_t addr)
{
	uint8_t ret = read_8(gb, addr);
	ret |= (1 << bit);
	write_8(gb, addr, ret);
}

int		set0_ptr_hl(struct gb_cpu_s* gb)
{
	set_mem8(gb, 0, gb->reg.hl);
}

int		set1_ptr_hl(struct gb_cpu_s* gb)
{
	set_mem8(gb, 1, gb->reg.hl);
}

int		set2_ptr_hl(struct gb_cpu_s* gb)
{
	set_mem8(gb, 2, gb->reg.hl);
}

int		set3_ptr_hl(struct gb_cpu_s* gb)
{
	set_mem8(gb, 3, gb->reg.hl);
}

int		set4_ptr_hl(struct gb_cpu_s* gb)
{
	set_mem8(gb, 4, gb->reg.hl);
}

int		set5_ptr_hl(struct gb_cpu_s* gb)
{
	set_mem8(gb, 5, gb->reg.hl);
}

int		set6_ptr_hl(struct gb_cpu_s* gb)
{
	set_mem8(gb, 6, gb->reg.hl);
}

int		set7_ptr_hl(struct gb_cpu_s* gb)
{
	set_mem8(gb, 7, gb->reg.hl);
}

int		set0_b(struct gb_cpu_s* gb)
{
	set_reg8(gb, 0, &(gb->reg.b));
}

int		set0_c(struct gb_cpu_s* gb)
{
	set_reg8(gb, 0, &(gb->reg.c));
}

int		set0_d(struct gb_cpu_s* gb)
{
	set_reg8(gb, 0, &(gb->reg.d));
}

int		set0_e(struct gb_cpu_s* gb)
{
	set_reg8(gb, 0, &(gb->reg.e));
}

int		set0_h(struct gb_cpu_s* gb)
{
	set_reg8(gb, 0, &(gb->reg.h));
}

int		set0_l(struct gb_cpu_s* gb)
{
	set_reg8(gb, 0, &(gb->reg.l));
}

int		set0_a(struct gb_cpu_s* gb)
{
	set_reg8(gb, 0, &(gb->reg.a));
}

int		set1_b(struct gb_cpu_s* gb)
{
	set_reg8(gb, 1, &(gb->reg.b));
}

int		set1_c(struct gb_cpu_s* gb)
{
	set_reg8(gb, 1, &(gb->reg.c));
}

int		set1_d(struct gb_cpu_s* gb)
{
	set_reg8(gb, 1, &(gb->reg.d));
}

int		set1_e(struct gb_cpu_s* gb)
{
	set_reg8(gb, 1, &(gb->reg.e));
}

int		set1_h(struct gb_cpu_s* gb)
{
	set_reg8(gb, 1, &(gb->reg.h));
}

int		set1_l(struct gb_cpu_s* gb)
{
	set_reg8(gb, 1, &(gb->reg.l));
}

int		set1_a(struct gb_cpu_s* gb)
{
	set_reg8(gb, 1, &(gb->reg.a));
}

int		set2_b(struct gb_cpu_s* gb)
{
	set_reg8(gb, 2, &(gb->reg.b));
}

int		set2_c(struct gb_cpu_s* gb)
{
	set_reg8(gb, 2, &(gb->reg.c));
}

int		set2_d(struct gb_cpu_s* gb)
{
	set_reg8(gb, 2, &(gb->reg.d));
}

int		set2_e(struct gb_cpu_s* gb)
{
	set_reg8(gb, 2, &(gb->reg.e));
}

int		set2_h(struct gb_cpu_s* gb)
{
	set_reg8(gb, 2, &(gb->reg.h));
}

int		set2_l(struct gb_cpu_s* gb)
{
	set_reg8(gb, 2, &(gb->reg.l));
}

int		set2_a(struct gb_cpu_s* gb)
{
	set_reg8(gb, 2, &(gb->reg.a));
}

int		set3_b(struct gb_cpu_s* gb)
{
	set_reg8(gb, 3, &(gb->reg.b));
}

int		set3_c(struct gb_cpu_s* gb)
{
	set_reg8(gb, 3, &(gb->reg.c));
}

int		set3_d(struct gb_cpu_s* gb)
{
	set_reg8(gb, 3, &(gb->reg.d));
}

int		set3_e(struct gb_cpu_s* gb)
{
	set_reg8(gb, 3, &(gb->reg.e));
}

int		set3_h(struct gb_cpu_s* gb)
{
	set_reg8(gb, 3, &(gb->reg.h));
}

int		set3_l(struct gb_cpu_s* gb)
{
	set_reg8(gb, 3, &(gb->reg.l));
}

int		set3_a(struct gb_cpu_s* gb)
{
	set_reg8(gb, 3, &(gb->reg.a));
}

int		set4_b(struct gb_cpu_s* gb)
{
	set_reg8(gb, 4, &(gb->reg.b));
}

int		set4_c(struct gb_cpu_s* gb)
{
	set_reg8(gb, 4, &(gb->reg.c));
}

int		set4_d(struct gb_cpu_s* gb)
{
	set_reg8(gb, 4, &(gb->reg.d));
}

int		set4_e(struct gb_cpu_s* gb)
{
	set_reg8(gb, 4, &(gb->reg.e));
}

int		set4_h(struct gb_cpu_s* gb)
{
	set_reg8(gb, 4, &(gb->reg.h));
}

int		set4_l(struct gb_cpu_s* gb)
{
	set_reg8(gb, 4, &(gb->reg.l));
}

int		set4_a(struct gb_cpu_s* gb)
{
	set_reg8(gb, 4, &(gb->reg.a));
}

int		set5_b(struct gb_cpu_s* gb)
{
	set_reg8(gb, 5, &(gb->reg.b));
}

int		set5_c(struct gb_cpu_s* gb)
{
	set_reg8(gb, 5, &(gb->reg.c));
}

int		set5_d(struct gb_cpu_s* gb)
{
	set_reg8(gb, 5, &(gb->reg.d));
}

int		set5_e(struct gb_cpu_s* gb)
{
	set_reg8(gb, 5, &(gb->reg.e));
}

int		set5_h(struct gb_cpu_s* gb)
{
	set_reg8(gb, 5, &(gb->reg.h));
}

int		set5_l(struct gb_cpu_s* gb)
{
	set_reg8(gb, 5, &(gb->reg.l));
}

int		set5_a(struct gb_cpu_s* gb)
{
	set_reg8(gb, 5, &(gb->reg.a));
}

int		set6_b(struct gb_cpu_s* gb)
{
	set_reg8(gb, 6, &(gb->reg.b));
}

int		set6_c(struct gb_cpu_s* gb)
{
	set_reg8(gb, 6, &(gb->reg.c));
}

int		set6_d(struct gb_cpu_s* gb)
{
	set_reg8(gb, 6, &(gb->reg.d));
}

int		set6_e(struct gb_cpu_s* gb)
{
	set_reg8(gb, 6, &(gb->reg.e));
}

int		set6_h(struct gb_cpu_s* gb)
{
	set_reg8(gb, 6, &(gb->reg.h));
}

int		set6_l(struct gb_cpu_s* gb)
{
	set_reg8(gb, 6, &(gb->reg.l));
}

int		set6_a(struct gb_cpu_s* gb)
{
	set_reg8(gb, 6, &(gb->reg.a));
}

int		set7_b(struct gb_cpu_s* gb)
{
	set_reg8(gb, 7, &(gb->reg.b));
}

int		set7_c(struct gb_cpu_s* gb)
{
	set_reg8(gb, 7, &(gb->reg.c));
}

int		set7_d(struct gb_cpu_s* gb)
{
	set_reg8(gb, 7, &(gb->reg.d));
}

int		set7_e(struct gb_cpu_s* gb)
{
	set_reg8(gb, 7, &(gb->reg.e));
}

int		set7_h(struct gb_cpu_s* gb)
{
	set_reg8(gb, 7, &(gb->reg.h));
}

int		set7_l(struct gb_cpu_s* gb)
{
	set_reg8(gb, 7, &(gb->reg.l));
}

int		set7_a(struct gb_cpu_s* gb)
{
	set_reg8(gb, 7, &(gb->reg.a));
}