/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   res.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 14:48:36 by niragne           #+#    #+#             */
/*   Updated: 2020/04/29 14:23:00 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

#include "ext_op.h"
#include "cpu.h"
#include "gb.h"

void	res_reg8(struct gb_cpu_s* gb, int bit, uint8_t* reg)
{
	(void)gb;
	*reg &= ~(1 << bit);
	gb->cycle += 8;
}

void	res_mem8(struct gb_cpu_s* gb, int bit, uint16_t addr)
{
	uint8_t ret = read_8(gb, addr);
	ret &= ~(1 << bit);
	write_8(gb, addr, ret);
	gb->cycle += 16;
}

void	res0_ptr_hl(struct gb_cpu_s* gb)
{
	res_mem8(gb, 0, gb->reg.hl);
}

void	res1_ptr_hl(struct gb_cpu_s* gb)
{
	res_mem8(gb, 1, gb->reg.hl);
}

void	res2_ptr_hl(struct gb_cpu_s* gb)
{
	res_mem8(gb, 2, gb->reg.hl);
}

void	res3_ptr_hl(struct gb_cpu_s* gb)
{
	res_mem8(gb, 3, gb->reg.hl);
}

void	res4_ptr_hl(struct gb_cpu_s* gb)
{
	res_mem8(gb, 4, gb->reg.hl);
}

void	res5_ptr_hl(struct gb_cpu_s* gb)
{
	res_mem8(gb, 5, gb->reg.hl);
}

void	res6_ptr_hl(struct gb_cpu_s* gb)
{
	res_mem8(gb, 6, gb->reg.hl);
}

void	res7_ptr_hl(struct gb_cpu_s* gb)
{
	res_mem8(gb, 7, gb->reg.hl);
}

void	res0_b(struct gb_cpu_s* gb)
{
	res_reg8(gb, 0, &(gb->reg.b));
}

void	res0_c(struct gb_cpu_s* gb)
{
	res_reg8(gb, 0, &(gb->reg.c));
}

void	res0_d(struct gb_cpu_s* gb)
{
	res_reg8(gb, 0, &(gb->reg.d));
}

void	res0_e(struct gb_cpu_s* gb)
{
	res_reg8(gb, 0, &(gb->reg.e));
}

void	res0_h(struct gb_cpu_s* gb)
{
	res_reg8(gb, 0, &(gb->reg.h));
}

void	res0_l(struct gb_cpu_s* gb)
{
	res_reg8(gb, 0, &(gb->reg.l));
}

void	res0_a(struct gb_cpu_s* gb)
{
	res_reg8(gb, 0, &(gb->reg.a));
}

void	res1_b(struct gb_cpu_s* gb)
{
	res_reg8(gb, 1, &(gb->reg.b));
}

void	res1_c(struct gb_cpu_s* gb)
{
	res_reg8(gb, 1, &(gb->reg.c));
}

void	res1_d(struct gb_cpu_s* gb)
{
	res_reg8(gb, 1, &(gb->reg.d));
}

void	res1_e(struct gb_cpu_s* gb)
{
	res_reg8(gb, 1, &(gb->reg.e));
}

void	res1_h(struct gb_cpu_s* gb)
{
	res_reg8(gb, 1, &(gb->reg.h));
}

void	res1_l(struct gb_cpu_s* gb)
{
	res_reg8(gb, 1, &(gb->reg.l));
}

void	res1_a(struct gb_cpu_s* gb)
{
	res_reg8(gb, 1, &(gb->reg.a));
}

void	res2_b(struct gb_cpu_s* gb)
{
	res_reg8(gb, 2, &(gb->reg.b));
}

void	res2_c(struct gb_cpu_s* gb)
{
	res_reg8(gb, 2, &(gb->reg.c));
}

void	res2_d(struct gb_cpu_s* gb)
{
	res_reg8(gb, 2, &(gb->reg.d));
}

void	res2_e(struct gb_cpu_s* gb)
{
	res_reg8(gb, 2, &(gb->reg.e));
}

void	res2_h(struct gb_cpu_s* gb)
{
	res_reg8(gb, 2, &(gb->reg.h));
}

void	res2_l(struct gb_cpu_s* gb)
{
	res_reg8(gb, 2, &(gb->reg.l));
}

void	res2_a(struct gb_cpu_s* gb)
{
	res_reg8(gb, 2, &(gb->reg.a));
}

void	res3_b(struct gb_cpu_s* gb)
{
	res_reg8(gb, 3, &(gb->reg.b));
}

void	res3_c(struct gb_cpu_s* gb)
{
	res_reg8(gb, 3, &(gb->reg.c));
}

void	res3_d(struct gb_cpu_s* gb)
{
	res_reg8(gb, 3, &(gb->reg.d));
}

void	res3_e(struct gb_cpu_s* gb)
{
	res_reg8(gb, 3, &(gb->reg.e));
}

void	res3_h(struct gb_cpu_s* gb)
{
	res_reg8(gb, 3, &(gb->reg.h));
}

void	res3_l(struct gb_cpu_s* gb)
{
	res_reg8(gb, 3, &(gb->reg.l));
}

void	res3_a(struct gb_cpu_s* gb)
{
	res_reg8(gb, 3, &(gb->reg.a));
}

void	res4_b(struct gb_cpu_s* gb)
{
	res_reg8(gb, 4, &(gb->reg.b));
}

void	res4_c(struct gb_cpu_s* gb)
{
	res_reg8(gb, 4, &(gb->reg.c));
}

void	res4_d(struct gb_cpu_s* gb)
{
	res_reg8(gb, 4, &(gb->reg.d));
}

void	res4_e(struct gb_cpu_s* gb)
{
	res_reg8(gb, 4, &(gb->reg.e));
}

void	res4_h(struct gb_cpu_s* gb)
{
	res_reg8(gb, 4, &(gb->reg.h));
}

void	res4_l(struct gb_cpu_s* gb)
{
	res_reg8(gb, 4, &(gb->reg.l));
}

void	res4_a(struct gb_cpu_s* gb)
{
	res_reg8(gb, 4, &(gb->reg.a));
}

void	res5_b(struct gb_cpu_s* gb)
{
	res_reg8(gb, 5, &(gb->reg.b));
}

void	res5_c(struct gb_cpu_s* gb)
{
	res_reg8(gb, 5, &(gb->reg.c));
}

void	res5_d(struct gb_cpu_s* gb)
{
	res_reg8(gb, 5, &(gb->reg.d));
}

void	res5_e(struct gb_cpu_s* gb)
{
	res_reg8(gb, 5, &(gb->reg.e));
}

void	res5_h(struct gb_cpu_s* gb)
{
	res_reg8(gb, 5, &(gb->reg.h));
}

void	res5_l(struct gb_cpu_s* gb)
{
	res_reg8(gb, 5, &(gb->reg.l));
}

void	res5_a(struct gb_cpu_s* gb)
{
	res_reg8(gb, 5, &(gb->reg.a));
}

void	res6_b(struct gb_cpu_s* gb)
{
	res_reg8(gb, 6, &(gb->reg.b));
}

void	res6_c(struct gb_cpu_s* gb)
{
	res_reg8(gb, 6, &(gb->reg.c));
}

void	res6_d(struct gb_cpu_s* gb)
{
	res_reg8(gb, 6, &(gb->reg.d));
}

void	res6_e(struct gb_cpu_s* gb)
{
	res_reg8(gb, 6, &(gb->reg.e));
}

void	res6_h(struct gb_cpu_s* gb)
{
	res_reg8(gb, 6, &(gb->reg.h));
}

void	res6_l(struct gb_cpu_s* gb)
{
	res_reg8(gb, 6, &(gb->reg.l));
}

void	res6_a(struct gb_cpu_s* gb)
{
	res_reg8(gb, 6, &(gb->reg.a));
}

void	res7_b(struct gb_cpu_s* gb)
{
	res_reg8(gb, 7, &(gb->reg.b));
}

void	res7_c(struct gb_cpu_s* gb)
{
	res_reg8(gb, 7, &(gb->reg.c));
}

void	res7_d(struct gb_cpu_s* gb)
{
	res_reg8(gb, 7, &(gb->reg.d));
}

void	res7_e(struct gb_cpu_s* gb)
{
	res_reg8(gb, 7, &(gb->reg.e));
}

void	res7_h(struct gb_cpu_s* gb)
{
	res_reg8(gb, 7, &(gb->reg.h));
}

void	res7_l(struct gb_cpu_s* gb)
{
	res_reg8(gb, 7, &(gb->reg.l));
}

void	res7_a(struct gb_cpu_s* gb)
{
	res_reg8(gb, 7, &(gb->reg.a));
}