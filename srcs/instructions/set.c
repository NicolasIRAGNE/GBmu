/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 14:48:36 by niragne           #+#    #+#             */
/*   Updated: 2020/04/29 14:23:17 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

#include "ext_op.h"
#include "cpu.h"
#include "gb.h"

void	set_reg8(struct gb_cpu_s* gb, int bit, uint8_t* reg)
{
	(void)gb;
	*reg |= (1 << bit);
	gb->cycle += 2;
}

void	set_mem8(struct gb_cpu_s* gb, int bit, uint16_t addr)
{
	uint8_t ret = read_8(gb, addr);
	ret |= (1 << bit);
	write_8(gb, addr, ret);
	gb->cycle += 4;
}

void	set0_ptr_hl(struct gb_cpu_s* gb)
{
	set_mem8(gb, 0, gb->reg.hl);
}

void	set1_ptr_hl(struct gb_cpu_s* gb)
{
	set_mem8(gb, 1, gb->reg.hl);
}

void	set2_ptr_hl(struct gb_cpu_s* gb)
{
	set_mem8(gb, 2, gb->reg.hl);
}

void	set3_ptr_hl(struct gb_cpu_s* gb)
{
	set_mem8(gb, 3, gb->reg.hl);
}

void	set4_ptr_hl(struct gb_cpu_s* gb)
{
	set_mem8(gb, 4, gb->reg.hl);
}

void	set5_ptr_hl(struct gb_cpu_s* gb)
{
	set_mem8(gb, 5, gb->reg.hl);
}

void	set6_ptr_hl(struct gb_cpu_s* gb)
{
	set_mem8(gb, 6, gb->reg.hl);
}

void	set7_ptr_hl(struct gb_cpu_s* gb)
{
	set_mem8(gb, 7, gb->reg.hl);
}

void	set0_b(struct gb_cpu_s* gb)
{
	set_reg8(gb, 0, &(gb->reg.b));
}

void	set0_c(struct gb_cpu_s* gb)
{
	set_reg8(gb, 0, &(gb->reg.c));
}

void	set0_d(struct gb_cpu_s* gb)
{
	set_reg8(gb, 0, &(gb->reg.d));
}

void	set0_e(struct gb_cpu_s* gb)
{
	set_reg8(gb, 0, &(gb->reg.e));
}

void	set0_h(struct gb_cpu_s* gb)
{
	set_reg8(gb, 0, &(gb->reg.h));
}

void	set0_l(struct gb_cpu_s* gb)
{
	set_reg8(gb, 0, &(gb->reg.l));
}

void	set0_a(struct gb_cpu_s* gb)
{
	set_reg8(gb, 0, &(gb->reg.a));
}

void	set1_b(struct gb_cpu_s* gb)
{
	set_reg8(gb, 1, &(gb->reg.b));
}

void	set1_c(struct gb_cpu_s* gb)
{
	set_reg8(gb, 1, &(gb->reg.c));
}

void	set1_d(struct gb_cpu_s* gb)
{
	set_reg8(gb, 1, &(gb->reg.d));
}

void	set1_e(struct gb_cpu_s* gb)
{
	set_reg8(gb, 1, &(gb->reg.e));
}

void	set1_h(struct gb_cpu_s* gb)
{
	set_reg8(gb, 1, &(gb->reg.h));
}

void	set1_l(struct gb_cpu_s* gb)
{
	set_reg8(gb, 1, &(gb->reg.l));
}

void	set1_a(struct gb_cpu_s* gb)
{
	set_reg8(gb, 1, &(gb->reg.a));
}

void	set2_b(struct gb_cpu_s* gb)
{
	set_reg8(gb, 2, &(gb->reg.b));
}

void	set2_c(struct gb_cpu_s* gb)
{
	set_reg8(gb, 2, &(gb->reg.c));
}

void	set2_d(struct gb_cpu_s* gb)
{
	set_reg8(gb, 2, &(gb->reg.d));
}

void	set2_e(struct gb_cpu_s* gb)
{
	set_reg8(gb, 2, &(gb->reg.e));
}

void	set2_h(struct gb_cpu_s* gb)
{
	set_reg8(gb, 2, &(gb->reg.h));
}

void	set2_l(struct gb_cpu_s* gb)
{
	set_reg8(gb, 2, &(gb->reg.l));
}

void	set2_a(struct gb_cpu_s* gb)
{
	set_reg8(gb, 2, &(gb->reg.a));
}

void	set3_b(struct gb_cpu_s* gb)
{
	set_reg8(gb, 3, &(gb->reg.b));
}

void	set3_c(struct gb_cpu_s* gb)
{
	set_reg8(gb, 3, &(gb->reg.c));
}

void	set3_d(struct gb_cpu_s* gb)
{
	set_reg8(gb, 3, &(gb->reg.d));
}

void	set3_e(struct gb_cpu_s* gb)
{
	set_reg8(gb, 3, &(gb->reg.e));
}

void	set3_h(struct gb_cpu_s* gb)
{
	set_reg8(gb, 3, &(gb->reg.h));
}

void	set3_l(struct gb_cpu_s* gb)
{
	set_reg8(gb, 3, &(gb->reg.l));
}

void	set3_a(struct gb_cpu_s* gb)
{
	set_reg8(gb, 3, &(gb->reg.a));
}

void	set4_b(struct gb_cpu_s* gb)
{
	set_reg8(gb, 4, &(gb->reg.b));
}

void	set4_c(struct gb_cpu_s* gb)
{
	set_reg8(gb, 4, &(gb->reg.c));
}

void	set4_d(struct gb_cpu_s* gb)
{
	set_reg8(gb, 4, &(gb->reg.d));
}

void	set4_e(struct gb_cpu_s* gb)
{
	set_reg8(gb, 4, &(gb->reg.e));
}

void	set4_h(struct gb_cpu_s* gb)
{
	set_reg8(gb, 4, &(gb->reg.h));
}

void	set4_l(struct gb_cpu_s* gb)
{
	set_reg8(gb, 4, &(gb->reg.l));
}

void	set4_a(struct gb_cpu_s* gb)
{
	set_reg8(gb, 4, &(gb->reg.a));
}

void	set5_b(struct gb_cpu_s* gb)
{
	set_reg8(gb, 5, &(gb->reg.b));
}

void	set5_c(struct gb_cpu_s* gb)
{
	set_reg8(gb, 5, &(gb->reg.c));
}

void	set5_d(struct gb_cpu_s* gb)
{
	set_reg8(gb, 5, &(gb->reg.d));
}

void	set5_e(struct gb_cpu_s* gb)
{
	set_reg8(gb, 5, &(gb->reg.e));
}

void	set5_h(struct gb_cpu_s* gb)
{
	set_reg8(gb, 5, &(gb->reg.h));
}

void	set5_l(struct gb_cpu_s* gb)
{
	set_reg8(gb, 5, &(gb->reg.l));
}

void	set5_a(struct gb_cpu_s* gb)
{
	set_reg8(gb, 5, &(gb->reg.a));
}

void	set6_b(struct gb_cpu_s* gb)
{
	set_reg8(gb, 6, &(gb->reg.b));
}

void	set6_c(struct gb_cpu_s* gb)
{
	set_reg8(gb, 6, &(gb->reg.c));
}

void	set6_d(struct gb_cpu_s* gb)
{
	set_reg8(gb, 6, &(gb->reg.d));
}

void	set6_e(struct gb_cpu_s* gb)
{
	set_reg8(gb, 6, &(gb->reg.e));
}

void	set6_h(struct gb_cpu_s* gb)
{
	set_reg8(gb, 6, &(gb->reg.h));
}

void	set6_l(struct gb_cpu_s* gb)
{
	set_reg8(gb, 6, &(gb->reg.l));
}

void	set6_a(struct gb_cpu_s* gb)
{
	set_reg8(gb, 6, &(gb->reg.a));
}

void	set7_b(struct gb_cpu_s* gb)
{
	set_reg8(gb, 7, &(gb->reg.b));
}

void	set7_c(struct gb_cpu_s* gb)
{
	set_reg8(gb, 7, &(gb->reg.c));
}

void	set7_d(struct gb_cpu_s* gb)
{
	set_reg8(gb, 7, &(gb->reg.d));
}

void	set7_e(struct gb_cpu_s* gb)
{
	set_reg8(gb, 7, &(gb->reg.e));
}

void	set7_h(struct gb_cpu_s* gb)
{
	set_reg8(gb, 7, &(gb->reg.h));
}

void	set7_l(struct gb_cpu_s* gb)
{
	set_reg8(gb, 7, &(gb->reg.l));
}

void	set7_a(struct gb_cpu_s* gb)
{
	set_reg8(gb, 7, &(gb->reg.a));
}