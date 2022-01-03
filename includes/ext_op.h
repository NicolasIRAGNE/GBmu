/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ext_op.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 11:04:14 by niragne           #+#    #+#             */
/*   Updated: 2020/04/09 17:03:45 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXT_OP_H
# define EXT_OP_H

# include "gb.h"
# include "cpu.h"

struct ext_inst_s
{
	char*	name;
	void	(*exec)(struct gb_cpu_s*);
};

extern struct ext_inst_s ext_op_tab[256];

void	srl_a(struct gb_cpu_s* gb);
void	srl_b(struct gb_cpu_s* gb);
void	srl_c(struct gb_cpu_s* gb);
void	srl_d(struct gb_cpu_s* gb);
void	srl_e(struct gb_cpu_s* gb);
void	srl_h(struct gb_cpu_s* gb);
void	srl_l(struct gb_cpu_s* gb);
void	srl_ptr_hl(struct gb_cpu_s* gb);

void	rr_a(struct gb_cpu_s* gb);
void	rr_b(struct gb_cpu_s* gb);
void	rr_c(struct gb_cpu_s* gb);
void	rr_d(struct gb_cpu_s* gb);
void	rr_e(struct gb_cpu_s* gb);
void	rr_h(struct gb_cpu_s* gb);
void	rr_l(struct gb_cpu_s* gb);
void	rr_ptr_hl(struct gb_cpu_s* gb);

void	rl_a(struct gb_cpu_s* gb);
void	rl_b(struct gb_cpu_s* gb);
void	rl_c(struct gb_cpu_s* gb);
void	rl_d(struct gb_cpu_s* gb);
void	rl_e(struct gb_cpu_s* gb);
void	rl_h(struct gb_cpu_s* gb);
void	rl_l(struct gb_cpu_s* gb);
void	rl_ptr_hl(struct gb_cpu_s* gb);

void	sla_a(struct gb_cpu_s* gb);
void	sla_b(struct gb_cpu_s* gb);
void	sla_c(struct gb_cpu_s* gb);
void	sla_d(struct gb_cpu_s* gb);
void	sla_e(struct gb_cpu_s* gb);
void	sla_h(struct gb_cpu_s* gb);
void	sla_l(struct gb_cpu_s* gb);
void	sla_ptr_hl(struct gb_cpu_s* gb);

void	sra_a(struct gb_cpu_s* gb);
void	sra_b(struct gb_cpu_s* gb);
void	sra_c(struct gb_cpu_s* gb);
void	sra_d(struct gb_cpu_s* gb);
void	sra_e(struct gb_cpu_s* gb);
void	sra_h(struct gb_cpu_s* gb);
void	sra_l(struct gb_cpu_s* gb);
void	sra_ptr_hl(struct gb_cpu_s* gb);

void	swap_a(struct gb_cpu_s* gb);
void	swap_b(struct gb_cpu_s* gb);
void	swap_c(struct gb_cpu_s* gb);
void	swap_d(struct gb_cpu_s* gb);
void	swap_e(struct gb_cpu_s* gb);
void	swap_h(struct gb_cpu_s* gb);
void	swap_l(struct gb_cpu_s* gb);
void	swap_ptr_hl(struct gb_cpu_s* gb);

void	rrc_a(struct gb_cpu_s* gb);

void	rlc_a(struct gb_cpu_s* gb);
void	rlc_b(struct gb_cpu_s* gb);
void	rlc_c(struct gb_cpu_s* gb);
void	rlc_d(struct gb_cpu_s* gb);
void	rlc_e(struct gb_cpu_s* gb);
void	rlc_h(struct gb_cpu_s* gb);
void	rlc_l(struct gb_cpu_s* gb);
void	rlc_ptr_hl(struct gb_cpu_s* gb);

void	rrc_a(struct gb_cpu_s* gb);
void	rrc_b(struct gb_cpu_s* gb);
void	rrc_c(struct gb_cpu_s* gb);
void	rrc_d(struct gb_cpu_s* gb);
void	rrc_e(struct gb_cpu_s* gb);
void	rrc_h(struct gb_cpu_s* gb);
void	rrc_l(struct gb_cpu_s* gb);
void	rrc_ptr_hl(struct gb_cpu_s* gb);

void	bit0_ptr_hl(struct gb_cpu_s* gb);
void	bit1_ptr_hl(struct gb_cpu_s* gb);
void	bit2_ptr_hl(struct gb_cpu_s* gb);
void	bit3_ptr_hl(struct gb_cpu_s* gb);
void	bit4_ptr_hl(struct gb_cpu_s* gb);
void	bit5_ptr_hl(struct gb_cpu_s* gb);
void	bit6_ptr_hl(struct gb_cpu_s* gb);
void	bit7_ptr_hl(struct gb_cpu_s* gb);
void	bit0_b(struct gb_cpu_s* gb);
void	bit0_c(struct gb_cpu_s* gb);
void	bit0_d(struct gb_cpu_s* gb);
void	bit0_e(struct gb_cpu_s* gb);
void	bit0_h(struct gb_cpu_s* gb);
void	bit0_l(struct gb_cpu_s* gb);
void	bit0_a(struct gb_cpu_s* gb);
void	bit1_b(struct gb_cpu_s* gb);
void	bit1_c(struct gb_cpu_s* gb);
void	bit1_d(struct gb_cpu_s* gb);
void	bit1_e(struct gb_cpu_s* gb);
void	bit1_h(struct gb_cpu_s* gb);
void	bit1_l(struct gb_cpu_s* gb);
void	bit1_a(struct gb_cpu_s* gb);
void	bit2_b(struct gb_cpu_s* gb);
void	bit2_c(struct gb_cpu_s* gb);
void	bit2_d(struct gb_cpu_s* gb);
void	bit2_e(struct gb_cpu_s* gb);
void	bit2_h(struct gb_cpu_s* gb);
void	bit2_l(struct gb_cpu_s* gb);
void	bit2_a(struct gb_cpu_s* gb);
void	bit3_b(struct gb_cpu_s* gb);
void	bit3_c(struct gb_cpu_s* gb);
void	bit3_d(struct gb_cpu_s* gb);
void	bit3_e(struct gb_cpu_s* gb);
void	bit3_h(struct gb_cpu_s* gb);
void	bit3_l(struct gb_cpu_s* gb);
void	bit3_a(struct gb_cpu_s* gb);
void	bit4_b(struct gb_cpu_s* gb);
void	bit4_c(struct gb_cpu_s* gb);
void	bit4_d(struct gb_cpu_s* gb);
void	bit4_e(struct gb_cpu_s* gb);
void	bit4_h(struct gb_cpu_s* gb);
void	bit4_l(struct gb_cpu_s* gb);
void	bit4_a(struct gb_cpu_s* gb);
void	bit5_b(struct gb_cpu_s* gb);
void	bit5_c(struct gb_cpu_s* gb);
void	bit5_d(struct gb_cpu_s* gb);
void	bit5_e(struct gb_cpu_s* gb);
void	bit5_h(struct gb_cpu_s* gb);
void	bit5_l(struct gb_cpu_s* gb);
void	bit5_a(struct gb_cpu_s* gb);
void	bit6_b(struct gb_cpu_s* gb);
void	bit6_c(struct gb_cpu_s* gb);
void	bit6_d(struct gb_cpu_s* gb);
void	bit6_e(struct gb_cpu_s* gb);
void	bit6_h(struct gb_cpu_s* gb);
void	bit6_l(struct gb_cpu_s* gb);
void	bit6_a(struct gb_cpu_s* gb);
void	bit7_b(struct gb_cpu_s* gb);
void	bit7_c(struct gb_cpu_s* gb);
void	bit7_d(struct gb_cpu_s* gb);
void	bit7_e(struct gb_cpu_s* gb);
void	bit7_h(struct gb_cpu_s* gb);
void	bit7_l(struct gb_cpu_s* gb);
void	bit7_a(struct gb_cpu_s* gb);


void	res0_ptr_hl(struct gb_cpu_s* gb);
void	res1_ptr_hl(struct gb_cpu_s* gb);
void	res2_ptr_hl(struct gb_cpu_s* gb);
void	res3_ptr_hl(struct gb_cpu_s* gb);
void	res4_ptr_hl(struct gb_cpu_s* gb);
void	res5_ptr_hl(struct gb_cpu_s* gb);
void	res6_ptr_hl(struct gb_cpu_s* gb);
void	res7_ptr_hl(struct gb_cpu_s* gb);
void	res0_b(struct gb_cpu_s* gb);
void	res0_c(struct gb_cpu_s* gb);
void	res0_d(struct gb_cpu_s* gb);
void	res0_e(struct gb_cpu_s* gb);
void	res0_h(struct gb_cpu_s* gb);
void	res0_l(struct gb_cpu_s* gb);
void	res0_a(struct gb_cpu_s* gb);
void	res1_b(struct gb_cpu_s* gb);
void	res1_c(struct gb_cpu_s* gb);
void	res1_d(struct gb_cpu_s* gb);
void	res1_e(struct gb_cpu_s* gb);
void	res1_h(struct gb_cpu_s* gb);
void	res1_l(struct gb_cpu_s* gb);
void	res1_a(struct gb_cpu_s* gb);
void	res2_b(struct gb_cpu_s* gb);
void	res2_c(struct gb_cpu_s* gb);
void	res2_d(struct gb_cpu_s* gb);
void	res2_e(struct gb_cpu_s* gb);
void	res2_h(struct gb_cpu_s* gb);
void	res2_l(struct gb_cpu_s* gb);
void	res2_a(struct gb_cpu_s* gb);
void	res3_b(struct gb_cpu_s* gb);
void	res3_c(struct gb_cpu_s* gb);
void	res3_d(struct gb_cpu_s* gb);
void	res3_e(struct gb_cpu_s* gb);
void	res3_h(struct gb_cpu_s* gb);
void	res3_l(struct gb_cpu_s* gb);
void	res3_a(struct gb_cpu_s* gb);
void	res4_b(struct gb_cpu_s* gb);
void	res4_c(struct gb_cpu_s* gb);
void	res4_d(struct gb_cpu_s* gb);
void	res4_e(struct gb_cpu_s* gb);
void	res4_h(struct gb_cpu_s* gb);
void	res4_l(struct gb_cpu_s* gb);
void	res4_a(struct gb_cpu_s* gb);
void	res5_b(struct gb_cpu_s* gb);
void	res5_c(struct gb_cpu_s* gb);
void	res5_d(struct gb_cpu_s* gb);
void	res5_e(struct gb_cpu_s* gb);
void	res5_h(struct gb_cpu_s* gb);
void	res5_l(struct gb_cpu_s* gb);
void	res5_a(struct gb_cpu_s* gb);
void	res6_b(struct gb_cpu_s* gb);
void	res6_c(struct gb_cpu_s* gb);
void	res6_d(struct gb_cpu_s* gb);
void	res6_e(struct gb_cpu_s* gb);
void	res6_h(struct gb_cpu_s* gb);
void	res6_l(struct gb_cpu_s* gb);
void	res6_a(struct gb_cpu_s* gb);
void	res7_b(struct gb_cpu_s* gb);
void	res7_c(struct gb_cpu_s* gb);
void	res7_d(struct gb_cpu_s* gb);
void	res7_e(struct gb_cpu_s* gb);
void	res7_h(struct gb_cpu_s* gb);
void	res7_l(struct gb_cpu_s* gb);
void	res7_a(struct gb_cpu_s* gb);

void	set0_ptr_hl(struct gb_cpu_s* gb);
void	set1_ptr_hl(struct gb_cpu_s* gb);
void	set2_ptr_hl(struct gb_cpu_s* gb);
void	set3_ptr_hl(struct gb_cpu_s* gb);
void	set4_ptr_hl(struct gb_cpu_s* gb);
void	set5_ptr_hl(struct gb_cpu_s* gb);
void	set6_ptr_hl(struct gb_cpu_s* gb);
void	set7_ptr_hl(struct gb_cpu_s* gb);
void	set0_b(struct gb_cpu_s* gb);
void	set0_c(struct gb_cpu_s* gb);
void	set0_d(struct gb_cpu_s* gb);
void	set0_e(struct gb_cpu_s* gb);
void	set0_h(struct gb_cpu_s* gb);
void	set0_l(struct gb_cpu_s* gb);
void	set0_a(struct gb_cpu_s* gb);
void	set1_b(struct gb_cpu_s* gb);
void	set1_c(struct gb_cpu_s* gb);
void	set1_d(struct gb_cpu_s* gb);
void	set1_e(struct gb_cpu_s* gb);
void	set1_h(struct gb_cpu_s* gb);
void	set1_l(struct gb_cpu_s* gb);
void	set1_a(struct gb_cpu_s* gb);
void	set2_b(struct gb_cpu_s* gb);
void	set2_c(struct gb_cpu_s* gb);
void	set2_d(struct gb_cpu_s* gb);
void	set2_e(struct gb_cpu_s* gb);
void	set2_h(struct gb_cpu_s* gb);
void	set2_l(struct gb_cpu_s* gb);
void	set2_a(struct gb_cpu_s* gb);
void	set3_b(struct gb_cpu_s* gb);
void	set3_c(struct gb_cpu_s* gb);
void	set3_d(struct gb_cpu_s* gb);
void	set3_e(struct gb_cpu_s* gb);
void	set3_h(struct gb_cpu_s* gb);
void	set3_l(struct gb_cpu_s* gb);
void	set3_a(struct gb_cpu_s* gb);
void	set4_b(struct gb_cpu_s* gb);
void	set4_c(struct gb_cpu_s* gb);
void	set4_d(struct gb_cpu_s* gb);
void	set4_e(struct gb_cpu_s* gb);
void	set4_h(struct gb_cpu_s* gb);
void	set4_l(struct gb_cpu_s* gb);
void	set4_a(struct gb_cpu_s* gb);
void	set5_b(struct gb_cpu_s* gb);
void	set5_c(struct gb_cpu_s* gb);
void	set5_d(struct gb_cpu_s* gb);
void	set5_e(struct gb_cpu_s* gb);
void	set5_h(struct gb_cpu_s* gb);
void	set5_l(struct gb_cpu_s* gb);
void	set5_a(struct gb_cpu_s* gb);
void	set6_b(struct gb_cpu_s* gb);
void	set6_c(struct gb_cpu_s* gb);
void	set6_d(struct gb_cpu_s* gb);
void	set6_e(struct gb_cpu_s* gb);
void	set6_h(struct gb_cpu_s* gb);
void	set6_l(struct gb_cpu_s* gb);
void	set6_a(struct gb_cpu_s* gb);
void	set7_b(struct gb_cpu_s* gb);
void	set7_c(struct gb_cpu_s* gb);
void	set7_d(struct gb_cpu_s* gb);
void	set7_e(struct gb_cpu_s* gb);
void	set7_h(struct gb_cpu_s* gb);
void	set7_l(struct gb_cpu_s* gb);
void	set7_a(struct gb_cpu_s* gb);


#endif