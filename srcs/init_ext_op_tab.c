/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ext_op_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 16:16:07 by niragne           #+#    #+#             */
/*   Updated: 2020/02/25 17:12:45 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ext_op.h"

struct ext_inst_s	ext_op_tab[256] = 
{	
	{0}
};

void	init_ext_op_tab()
{
	ext_op_tab[0x38] = (struct ext_inst_s) {"SRL B", 	srl_b};
	ext_op_tab[0x39] = (struct ext_inst_s) {"SRL C", 	srl_c};
	ext_op_tab[0x3a] = (struct ext_inst_s) {"SRL D", 	srl_d};
	ext_op_tab[0x3b] = (struct ext_inst_s) {"SRL E", 	srl_e};
	ext_op_tab[0x3c] = (struct ext_inst_s) {"SRL H", 	srl_h};
	ext_op_tab[0x3d] = (struct ext_inst_s) {"SRL L", 	srl_l};
	ext_op_tab[0x3e] = (struct ext_inst_s) {"SRL (HL)", srl_l};
	ext_op_tab[0x3f] = (struct ext_inst_s) {"SRL A", 	srl_a};
	ext_op_tab[0x18] = (struct ext_inst_s) {"RR B", 	rr_b};
	ext_op_tab[0x19] = (struct ext_inst_s) {"RR C", 	rr_c};
	ext_op_tab[0x1a] = (struct ext_inst_s) {"RR D", 	rr_d};
	ext_op_tab[0x1b] = (struct ext_inst_s) {"RR E", 	rr_e};
	ext_op_tab[0x1c] = (struct ext_inst_s) {"RR H", 	rr_h};
	ext_op_tab[0x1d] = (struct ext_inst_s) {"RR L", 	rr_l};
	ext_op_tab[0x1e] = (struct ext_inst_s) {"RR (HL)",	rr_hl};
	ext_op_tab[0x1f] = (struct ext_inst_s) {"RR A", 	rr_a};
	ext_op_tab[0x10] = (struct ext_inst_s) {"RL B", 	rl_b};
	ext_op_tab[0x11] = (struct ext_inst_s) {"RL C", 	rl_c};
	ext_op_tab[0x12] = (struct ext_inst_s) {"RL D", 	rl_d};
	ext_op_tab[0x13] = (struct ext_inst_s) {"RL E", 	rl_e};
	ext_op_tab[0x14] = (struct ext_inst_s) {"RL H", 	rl_h};
	ext_op_tab[0x15] = (struct ext_inst_s) {"RL L", 	rl_l};
	ext_op_tab[0x16] = (struct ext_inst_s) {"RL (HL)",	rl_hl};
	ext_op_tab[0x17] = (struct ext_inst_s) {"RL A", 	rl_a};
	ext_op_tab[0x0f] = (struct ext_inst_s) {"RRC A", 	rrc_a};
	ext_op_tab[0x7c] = (struct ext_inst_s) {"BIT 7 H", 	bit7_h};
}