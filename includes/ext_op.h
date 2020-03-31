/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ext_op.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 11:04:14 by niragne           #+#    #+#             */
/*   Updated: 2020/03/31 15:16:50 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXT_OP_H
# define EXT_OP_H

# include "gb.h"

struct ext_inst_s
{
	char*	name;
	int		(*exec)(struct gb_cpu_s*);
};

extern struct ext_inst_s ext_op_tab[256];

int		srl_a(struct gb_cpu_s* gb);
int		srl_b(struct gb_cpu_s* gb);
int		srl_c(struct gb_cpu_s* gb);
int		srl_d(struct gb_cpu_s* gb);
int		srl_e(struct gb_cpu_s* gb);
int		srl_h(struct gb_cpu_s* gb);
int		srl_l(struct gb_cpu_s* gb);
int		srl_ptr_hl(struct gb_cpu_s* gb);

int		rr_a(struct gb_cpu_s* gb);
int		rr_b(struct gb_cpu_s* gb);
int		rr_c(struct gb_cpu_s* gb);
int		rr_d(struct gb_cpu_s* gb);
int		rr_e(struct gb_cpu_s* gb);
int		rr_h(struct gb_cpu_s* gb);
int		rr_l(struct gb_cpu_s* gb);
int		rr_ptr_hl(struct gb_cpu_s* gb);

int		rl_a(struct gb_cpu_s* gb);
int		rl_b(struct gb_cpu_s* gb);
int		rl_c(struct gb_cpu_s* gb);
int		rl_d(struct gb_cpu_s* gb);
int		rl_e(struct gb_cpu_s* gb);
int		rl_h(struct gb_cpu_s* gb);
int		rl_l(struct gb_cpu_s* gb);
int		rl_ptr_hl(struct gb_cpu_s* gb);

int		sla_a(struct gb_cpu_s* gb);
int		sla_b(struct gb_cpu_s* gb);
int		sla_c(struct gb_cpu_s* gb);
int		sla_d(struct gb_cpu_s* gb);
int		sla_e(struct gb_cpu_s* gb);
int		sla_h(struct gb_cpu_s* gb);
int		sla_l(struct gb_cpu_s* gb);
int		sla_ptr_hl(struct gb_cpu_s* gb);

int		sra_a(struct gb_cpu_s* gb);
int		sra_b(struct gb_cpu_s* gb);
int		sra_c(struct gb_cpu_s* gb);
int		sra_d(struct gb_cpu_s* gb);
int		sra_e(struct gb_cpu_s* gb);
int		sra_h(struct gb_cpu_s* gb);
int		sra_l(struct gb_cpu_s* gb);
int		sra_ptr_hl(struct gb_cpu_s* gb);

int		swap_a(struct gb_cpu_s* gb);
int		swap_b(struct gb_cpu_s* gb);
int		swap_c(struct gb_cpu_s* gb);
int		swap_d(struct gb_cpu_s* gb);
int		swap_e(struct gb_cpu_s* gb);
int		swap_h(struct gb_cpu_s* gb);
int		swap_l(struct gb_cpu_s* gb);
int		swap_ptr_hl(struct gb_cpu_s* gb);

int		rrc_a(struct gb_cpu_s* gb);

int		rlc_a(struct gb_cpu_s* gb);
int		rlc_b(struct gb_cpu_s* gb);
int		rlc_c(struct gb_cpu_s* gb);
int		rlc_d(struct gb_cpu_s* gb);
int		rlc_e(struct gb_cpu_s* gb);
int		rlc_h(struct gb_cpu_s* gb);
int		rlc_l(struct gb_cpu_s* gb);
int		rlc_ptr_hl(struct gb_cpu_s* gb);

int		rrc_a(struct gb_cpu_s* gb);
int		rrc_b(struct gb_cpu_s* gb);
int		rrc_c(struct gb_cpu_s* gb);
int		rrc_d(struct gb_cpu_s* gb);
int		rrc_e(struct gb_cpu_s* gb);
int		rrc_h(struct gb_cpu_s* gb);
int		rrc_l(struct gb_cpu_s* gb);
int		rrc_ptr_hl(struct gb_cpu_s* gb);

int		bit0_ptr_hl(struct gb_cpu_s* gb);
int		bit1_ptr_hl(struct gb_cpu_s* gb);
int		bit2_ptr_hl(struct gb_cpu_s* gb);
int		bit3_ptr_hl(struct gb_cpu_s* gb);
int		bit4_ptr_hl(struct gb_cpu_s* gb);
int		bit5_ptr_hl(struct gb_cpu_s* gb);
int		bit6_ptr_hl(struct gb_cpu_s* gb);
int		bit7_ptr_hl(struct gb_cpu_s* gb);
int		bit0_b(struct gb_cpu_s* gb);
int		bit0_c(struct gb_cpu_s* gb);
int		bit0_d(struct gb_cpu_s* gb);
int		bit0_e(struct gb_cpu_s* gb);
int		bit0_h(struct gb_cpu_s* gb);
int		bit0_l(struct gb_cpu_s* gb);
int		bit0_a(struct gb_cpu_s* gb);
int		bit1_b(struct gb_cpu_s* gb);
int		bit1_c(struct gb_cpu_s* gb);
int		bit1_d(struct gb_cpu_s* gb);
int		bit1_e(struct gb_cpu_s* gb);
int		bit1_h(struct gb_cpu_s* gb);
int		bit1_l(struct gb_cpu_s* gb);
int		bit1_a(struct gb_cpu_s* gb);
int		bit2_b(struct gb_cpu_s* gb);
int		bit2_c(struct gb_cpu_s* gb);
int		bit2_d(struct gb_cpu_s* gb);
int		bit2_e(struct gb_cpu_s* gb);
int		bit2_h(struct gb_cpu_s* gb);
int		bit2_l(struct gb_cpu_s* gb);
int		bit2_a(struct gb_cpu_s* gb);
int		bit3_b(struct gb_cpu_s* gb);
int		bit3_c(struct gb_cpu_s* gb);
int		bit3_d(struct gb_cpu_s* gb);
int		bit3_e(struct gb_cpu_s* gb);
int		bit3_h(struct gb_cpu_s* gb);
int		bit3_l(struct gb_cpu_s* gb);
int		bit3_a(struct gb_cpu_s* gb);
int		bit4_b(struct gb_cpu_s* gb);
int		bit4_c(struct gb_cpu_s* gb);
int		bit4_d(struct gb_cpu_s* gb);
int		bit4_e(struct gb_cpu_s* gb);
int		bit4_h(struct gb_cpu_s* gb);
int		bit4_l(struct gb_cpu_s* gb);
int		bit4_a(struct gb_cpu_s* gb);
int		bit5_b(struct gb_cpu_s* gb);
int		bit5_c(struct gb_cpu_s* gb);
int		bit5_d(struct gb_cpu_s* gb);
int		bit5_e(struct gb_cpu_s* gb);
int		bit5_h(struct gb_cpu_s* gb);
int		bit5_l(struct gb_cpu_s* gb);
int		bit5_a(struct gb_cpu_s* gb);
int		bit6_b(struct gb_cpu_s* gb);
int		bit6_c(struct gb_cpu_s* gb);
int		bit6_d(struct gb_cpu_s* gb);
int		bit6_e(struct gb_cpu_s* gb);
int		bit6_h(struct gb_cpu_s* gb);
int		bit6_l(struct gb_cpu_s* gb);
int		bit6_a(struct gb_cpu_s* gb);
int		bit7_b(struct gb_cpu_s* gb);
int		bit7_c(struct gb_cpu_s* gb);
int		bit7_d(struct gb_cpu_s* gb);
int		bit7_e(struct gb_cpu_s* gb);
int		bit7_h(struct gb_cpu_s* gb);
int		bit7_l(struct gb_cpu_s* gb);
int		bit7_a(struct gb_cpu_s* gb);


int		res0_ptr_hl(struct gb_cpu_s* gb);
int		res1_ptr_hl(struct gb_cpu_s* gb);
int		res2_ptr_hl(struct gb_cpu_s* gb);
int		res3_ptr_hl(struct gb_cpu_s* gb);
int		res4_ptr_hl(struct gb_cpu_s* gb);
int		res5_ptr_hl(struct gb_cpu_s* gb);
int		res6_ptr_hl(struct gb_cpu_s* gb);
int		res7_ptr_hl(struct gb_cpu_s* gb);
int		res0_b(struct gb_cpu_s* gb);
int		res0_c(struct gb_cpu_s* gb);
int		res0_d(struct gb_cpu_s* gb);
int		res0_e(struct gb_cpu_s* gb);
int		res0_h(struct gb_cpu_s* gb);
int		res0_l(struct gb_cpu_s* gb);
int		res0_a(struct gb_cpu_s* gb);
int		res1_b(struct gb_cpu_s* gb);
int		res1_c(struct gb_cpu_s* gb);
int		res1_d(struct gb_cpu_s* gb);
int		res1_e(struct gb_cpu_s* gb);
int		res1_h(struct gb_cpu_s* gb);
int		res1_l(struct gb_cpu_s* gb);
int		res1_a(struct gb_cpu_s* gb);
int		res2_b(struct gb_cpu_s* gb);
int		res2_c(struct gb_cpu_s* gb);
int		res2_d(struct gb_cpu_s* gb);
int		res2_e(struct gb_cpu_s* gb);
int		res2_h(struct gb_cpu_s* gb);
int		res2_l(struct gb_cpu_s* gb);
int		res2_a(struct gb_cpu_s* gb);
int		res3_b(struct gb_cpu_s* gb);
int		res3_c(struct gb_cpu_s* gb);
int		res3_d(struct gb_cpu_s* gb);
int		res3_e(struct gb_cpu_s* gb);
int		res3_h(struct gb_cpu_s* gb);
int		res3_l(struct gb_cpu_s* gb);
int		res3_a(struct gb_cpu_s* gb);
int		res4_b(struct gb_cpu_s* gb);
int		res4_c(struct gb_cpu_s* gb);
int		res4_d(struct gb_cpu_s* gb);
int		res4_e(struct gb_cpu_s* gb);
int		res4_h(struct gb_cpu_s* gb);
int		res4_l(struct gb_cpu_s* gb);
int		res4_a(struct gb_cpu_s* gb);
int		res5_b(struct gb_cpu_s* gb);
int		res5_c(struct gb_cpu_s* gb);
int		res5_d(struct gb_cpu_s* gb);
int		res5_e(struct gb_cpu_s* gb);
int		res5_h(struct gb_cpu_s* gb);
int		res5_l(struct gb_cpu_s* gb);
int		res5_a(struct gb_cpu_s* gb);
int		res6_b(struct gb_cpu_s* gb);
int		res6_c(struct gb_cpu_s* gb);
int		res6_d(struct gb_cpu_s* gb);
int		res6_e(struct gb_cpu_s* gb);
int		res6_h(struct gb_cpu_s* gb);
int		res6_l(struct gb_cpu_s* gb);
int		res6_a(struct gb_cpu_s* gb);
int		res7_b(struct gb_cpu_s* gb);
int		res7_c(struct gb_cpu_s* gb);
int		res7_d(struct gb_cpu_s* gb);
int		res7_e(struct gb_cpu_s* gb);
int		res7_h(struct gb_cpu_s* gb);
int		res7_l(struct gb_cpu_s* gb);
int		res7_a(struct gb_cpu_s* gb);

int		set0_ptr_hl(struct gb_cpu_s* gb);
int		set1_ptr_hl(struct gb_cpu_s* gb);
int		set2_ptr_hl(struct gb_cpu_s* gb);
int		set3_ptr_hl(struct gb_cpu_s* gb);
int		set4_ptr_hl(struct gb_cpu_s* gb);
int		set5_ptr_hl(struct gb_cpu_s* gb);
int		set6_ptr_hl(struct gb_cpu_s* gb);
int		set7_ptr_hl(struct gb_cpu_s* gb);
int		set0_b(struct gb_cpu_s* gb);
int		set0_c(struct gb_cpu_s* gb);
int		set0_d(struct gb_cpu_s* gb);
int		set0_e(struct gb_cpu_s* gb);
int		set0_h(struct gb_cpu_s* gb);
int		set0_l(struct gb_cpu_s* gb);
int		set0_a(struct gb_cpu_s* gb);
int		set1_b(struct gb_cpu_s* gb);
int		set1_c(struct gb_cpu_s* gb);
int		set1_d(struct gb_cpu_s* gb);
int		set1_e(struct gb_cpu_s* gb);
int		set1_h(struct gb_cpu_s* gb);
int		set1_l(struct gb_cpu_s* gb);
int		set1_a(struct gb_cpu_s* gb);
int		set2_b(struct gb_cpu_s* gb);
int		set2_c(struct gb_cpu_s* gb);
int		set2_d(struct gb_cpu_s* gb);
int		set2_e(struct gb_cpu_s* gb);
int		set2_h(struct gb_cpu_s* gb);
int		set2_l(struct gb_cpu_s* gb);
int		set2_a(struct gb_cpu_s* gb);
int		set3_b(struct gb_cpu_s* gb);
int		set3_c(struct gb_cpu_s* gb);
int		set3_d(struct gb_cpu_s* gb);
int		set3_e(struct gb_cpu_s* gb);
int		set3_h(struct gb_cpu_s* gb);
int		set3_l(struct gb_cpu_s* gb);
int		set3_a(struct gb_cpu_s* gb);
int		set4_b(struct gb_cpu_s* gb);
int		set4_c(struct gb_cpu_s* gb);
int		set4_d(struct gb_cpu_s* gb);
int		set4_e(struct gb_cpu_s* gb);
int		set4_h(struct gb_cpu_s* gb);
int		set4_l(struct gb_cpu_s* gb);
int		set4_a(struct gb_cpu_s* gb);
int		set5_b(struct gb_cpu_s* gb);
int		set5_c(struct gb_cpu_s* gb);
int		set5_d(struct gb_cpu_s* gb);
int		set5_e(struct gb_cpu_s* gb);
int		set5_h(struct gb_cpu_s* gb);
int		set5_l(struct gb_cpu_s* gb);
int		set5_a(struct gb_cpu_s* gb);
int		set6_b(struct gb_cpu_s* gb);
int		set6_c(struct gb_cpu_s* gb);
int		set6_d(struct gb_cpu_s* gb);
int		set6_e(struct gb_cpu_s* gb);
int		set6_h(struct gb_cpu_s* gb);
int		set6_l(struct gb_cpu_s* gb);
int		set6_a(struct gb_cpu_s* gb);
int		set7_b(struct gb_cpu_s* gb);
int		set7_c(struct gb_cpu_s* gb);
int		set7_d(struct gb_cpu_s* gb);
int		set7_e(struct gb_cpu_s* gb);
int		set7_h(struct gb_cpu_s* gb);
int		set7_l(struct gb_cpu_s* gb);
int		set7_a(struct gb_cpu_s* gb);


#endif