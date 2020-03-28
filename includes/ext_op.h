/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ext_op.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 11:04:14 by niragne           #+#    #+#             */
/*   Updated: 2020/03/28 13:13:04 by niragne          ###   ########.fr       */
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

int		res0_a(struct gb_cpu_s* gb);

int		swap_a(struct gb_cpu_s* gb);


#endif