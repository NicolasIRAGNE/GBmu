/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   res.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 14:48:36 by niragne           #+#    #+#             */
/*   Updated: 2020/03/31 15:15:50 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ext_op.h"

int		res_reg8(struct gb_cpu_s* gb, int bit, uint8_t* reg)
{
	*reg &= ~(1 << bit);
}

int		res_mem8(struct gb_cpu_s* gb, int bit, uint16_t addr)
{
	uint8_t ret = read_8(gb, addr);
	ret &= ~(1 << bit);
	write_8(gb, addr, ret);
}

int		res0_ptr_hl(struct gb_cpu_s* gb)
{
	res_mem8(gb, 0, gb->reg.hl);
}

int		res1_ptr_hl(struct gb_cpu_s* gb)
{
	res_mem8(gb, 1, gb->reg.hl);
}

int		res2_ptr_hl(struct gb_cpu_s* gb)
{
	res_mem8(gb, 2, gb->reg.hl);
}

int		res3_ptr_hl(struct gb_cpu_s* gb)
{
	res_mem8(gb, 3, gb->reg.hl);
}

int		res4_ptr_hl(struct gb_cpu_s* gb)
{
	res_mem8(gb, 4, gb->reg.hl);
}

int		res5_ptr_hl(struct gb_cpu_s* gb)
{
	res_mem8(gb, 5, gb->reg.hl);
}

int		res6_ptr_hl(struct gb_cpu_s* gb)
{
	res_mem8(gb, 6, gb->reg.hl);
}

int		res7_ptr_hl(struct gb_cpu_s* gb)
{
	res_mem8(gb, 7, gb->reg.hl);
}

int		res0_b(struct gb_cpu_s* gb)
{
	res_reg8(gb, 0, &(gb->reg.b));
}

int		res0_c(struct gb_cpu_s* gb)
{
	res_reg8(gb, 0, &(gb->reg.c));
}

int		res0_d(struct gb_cpu_s* gb)
{
	res_reg8(gb, 0, &(gb->reg.d));
}

int		res0_e(struct gb_cpu_s* gb)
{
	res_reg8(gb, 0, &(gb->reg.e));
}

int		res0_h(struct gb_cpu_s* gb)
{
	res_reg8(gb, 0, &(gb->reg.h));
}

int		res0_l(struct gb_cpu_s* gb)
{
	res_reg8(gb, 0, &(gb->reg.l));
}

int		res0_a(struct gb_cpu_s* gb)
{
	res_reg8(gb, 0, &(gb->reg.a));
}

int		res1_b(struct gb_cpu_s* gb)
{
	res_reg8(gb, 1, &(gb->reg.b));
}

int		res1_c(struct gb_cpu_s* gb)
{
	res_reg8(gb, 1, &(gb->reg.c));
}

int		res1_d(struct gb_cpu_s* gb)
{
	res_reg8(gb, 1, &(gb->reg.d));
}

int		res1_e(struct gb_cpu_s* gb)
{
	res_reg8(gb, 1, &(gb->reg.e));
}

int		res1_h(struct gb_cpu_s* gb)
{
	res_reg8(gb, 1, &(gb->reg.h));
}

int		res1_l(struct gb_cpu_s* gb)
{
	res_reg8(gb, 1, &(gb->reg.l));
}

int		res1_a(struct gb_cpu_s* gb)
{
	res_reg8(gb, 1, &(gb->reg.a));
}

int		res2_b(struct gb_cpu_s* gb)
{
	res_reg8(gb, 2, &(gb->reg.b));
}

int		res2_c(struct gb_cpu_s* gb)
{
	res_reg8(gb, 2, &(gb->reg.c));
}

int		res2_d(struct gb_cpu_s* gb)
{
	res_reg8(gb, 2, &(gb->reg.d));
}

int		res2_e(struct gb_cpu_s* gb)
{
	res_reg8(gb, 2, &(gb->reg.e));
}

int		res2_h(struct gb_cpu_s* gb)
{
	res_reg8(gb, 2, &(gb->reg.h));
}

int		res2_l(struct gb_cpu_s* gb)
{
	res_reg8(gb, 2, &(gb->reg.l));
}

int		res2_a(struct gb_cpu_s* gb)
{
	res_reg8(gb, 2, &(gb->reg.a));
}

int		res3_b(struct gb_cpu_s* gb)
{
	res_reg8(gb, 3, &(gb->reg.b));
}

int		res3_c(struct gb_cpu_s* gb)
{
	res_reg8(gb, 3, &(gb->reg.c));
}

int		res3_d(struct gb_cpu_s* gb)
{
	res_reg8(gb, 3, &(gb->reg.d));
}

int		res3_e(struct gb_cpu_s* gb)
{
	res_reg8(gb, 3, &(gb->reg.e));
}

int		res3_h(struct gb_cpu_s* gb)
{
	res_reg8(gb, 3, &(gb->reg.h));
}

int		res3_l(struct gb_cpu_s* gb)
{
	res_reg8(gb, 3, &(gb->reg.l));
}

int		res3_a(struct gb_cpu_s* gb)
{
	res_reg8(gb, 3, &(gb->reg.a));
}

int		res4_b(struct gb_cpu_s* gb)
{
	res_reg8(gb, 4, &(gb->reg.b));
}

int		res4_c(struct gb_cpu_s* gb)
{
	res_reg8(gb, 4, &(gb->reg.c));
}

int		res4_d(struct gb_cpu_s* gb)
{
	res_reg8(gb, 4, &(gb->reg.d));
}

int		res4_e(struct gb_cpu_s* gb)
{
	res_reg8(gb, 4, &(gb->reg.e));
}

int		res4_h(struct gb_cpu_s* gb)
{
	res_reg8(gb, 4, &(gb->reg.h));
}

int		res4_l(struct gb_cpu_s* gb)
{
	res_reg8(gb, 4, &(gb->reg.l));
}

int		res4_a(struct gb_cpu_s* gb)
{
	res_reg8(gb, 4, &(gb->reg.a));
}

int		res5_b(struct gb_cpu_s* gb)
{
	res_reg8(gb, 5, &(gb->reg.b));
}

int		res5_c(struct gb_cpu_s* gb)
{
	res_reg8(gb, 5, &(gb->reg.c));
}

int		res5_d(struct gb_cpu_s* gb)
{
	res_reg8(gb, 5, &(gb->reg.d));
}

int		res5_e(struct gb_cpu_s* gb)
{
	res_reg8(gb, 5, &(gb->reg.e));
}

int		res5_h(struct gb_cpu_s* gb)
{
	res_reg8(gb, 5, &(gb->reg.h));
}

int		res5_l(struct gb_cpu_s* gb)
{
	res_reg8(gb, 5, &(gb->reg.l));
}

int		res5_a(struct gb_cpu_s* gb)
{
	res_reg8(gb, 5, &(gb->reg.a));
}

int		res6_b(struct gb_cpu_s* gb)
{
	res_reg8(gb, 6, &(gb->reg.b));
}

int		res6_c(struct gb_cpu_s* gb)
{
	res_reg8(gb, 6, &(gb->reg.c));
}

int		res6_d(struct gb_cpu_s* gb)
{
	res_reg8(gb, 6, &(gb->reg.d));
}

int		res6_e(struct gb_cpu_s* gb)
{
	res_reg8(gb, 6, &(gb->reg.e));
}

int		res6_h(struct gb_cpu_s* gb)
{
	res_reg8(gb, 6, &(gb->reg.h));
}

int		res6_l(struct gb_cpu_s* gb)
{
	res_reg8(gb, 6, &(gb->reg.l));
}

int		res6_a(struct gb_cpu_s* gb)
{
	res_reg8(gb, 6, &(gb->reg.a));
}

int		res7_b(struct gb_cpu_s* gb)
{
	res_reg8(gb, 7, &(gb->reg.b));
}

int		res7_c(struct gb_cpu_s* gb)
{
	res_reg8(gb, 7, &(gb->reg.c));
}

int		res7_d(struct gb_cpu_s* gb)
{
	res_reg8(gb, 7, &(gb->reg.d));
}

int		res7_e(struct gb_cpu_s* gb)
{
	res_reg8(gb, 7, &(gb->reg.e));
}

int		res7_h(struct gb_cpu_s* gb)
{
	res_reg8(gb, 7, &(gb->reg.h));
}

int		res7_l(struct gb_cpu_s* gb)
{
	res_reg8(gb, 7, &(gb->reg.l));
}

int		res7_a(struct gb_cpu_s* gb)
{
	res_reg8(gb, 7, &(gb->reg.a));
}