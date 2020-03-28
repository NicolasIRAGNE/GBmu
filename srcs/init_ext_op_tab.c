/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ext_op_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 16:16:07 by niragne           #+#    #+#             */
/*   Updated: 2020/03/28 13:16:15 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ext_op.h"

struct ext_inst_s	ext_op_tab[256] = 
{	
	{0}
};

void	init_ext_op_tab()
{
	ext_op_tab[0x00] = (struct ext_inst_s) {"RLC B", 	rlc_b};
	ext_op_tab[0x01] = (struct ext_inst_s) {"RLC C", 	rlc_c};
	ext_op_tab[0x02] = (struct ext_inst_s) {"RLC D", 	rlc_d};
	ext_op_tab[0x03] = (struct ext_inst_s) {"RLC E", 	rlc_e};
	ext_op_tab[0x04] = (struct ext_inst_s) {"RLC H", 	rlc_h};
	ext_op_tab[0x05] = (struct ext_inst_s) {"RLC L", 	rlc_l};
	ext_op_tab[0x06] = (struct ext_inst_s) {"RLC (HL)", rlc_ptr_hl};
	ext_op_tab[0x07] = (struct ext_inst_s) {"RLC A", 	rlc_a};

	ext_op_tab[0x08] = (struct ext_inst_s) {"RRC B", 	rrc_b};
	ext_op_tab[0x09] = (struct ext_inst_s) {"RRC C", 	rrc_c};
	ext_op_tab[0x0a] = (struct ext_inst_s) {"RRC D", 	rrc_d};
	ext_op_tab[0x0b] = (struct ext_inst_s) {"RRC E", 	rrc_e};
	ext_op_tab[0x0c] = (struct ext_inst_s) {"RRC H", 	rrc_h};
	ext_op_tab[0x0d] = (struct ext_inst_s) {"RRC L", 	rrc_l};
	ext_op_tab[0x0e] = (struct ext_inst_s) {"RRC (HL)", rrc_ptr_hl};
	ext_op_tab[0x0f] = (struct ext_inst_s) {"RRC A", 	rrc_a};

	ext_op_tab[0x10] = (struct ext_inst_s) {"RL B", 	rl_b};
	ext_op_tab[0x11] = (struct ext_inst_s) {"RL C", 	rl_c};
	ext_op_tab[0x12] = (struct ext_inst_s) {"RL D", 	rl_d};
	ext_op_tab[0x13] = (struct ext_inst_s) {"RL E", 	rl_e};
	ext_op_tab[0x14] = (struct ext_inst_s) {"RL H", 	rl_h};
	ext_op_tab[0x15] = (struct ext_inst_s) {"RL L", 	rl_l};
	ext_op_tab[0x16] = (struct ext_inst_s) {"RL (HL)",	rl_ptr_hl};
	ext_op_tab[0x17] = (struct ext_inst_s) {"RL A", 	rl_a};

	ext_op_tab[0x18] = (struct ext_inst_s) {"RR B", 	rr_b};
	ext_op_tab[0x19] = (struct ext_inst_s) {"RR C", 	rr_c};
	ext_op_tab[0x1a] = (struct ext_inst_s) {"RR D", 	rr_d};
	ext_op_tab[0x1b] = (struct ext_inst_s) {"RR E", 	rr_e};
	ext_op_tab[0x1c] = (struct ext_inst_s) {"RR H", 	rr_h};
	ext_op_tab[0x1d] = (struct ext_inst_s) {"RR L", 	rr_l};
	ext_op_tab[0x1e] = (struct ext_inst_s) {"RR (HL)",	rr_ptr_hl};
	ext_op_tab[0x1f] = (struct ext_inst_s) {"RR A", 	rr_a};

	ext_op_tab[0x38] = (struct ext_inst_s) {"SRL B", 	srl_b};
	ext_op_tab[0x39] = (struct ext_inst_s) {"SRL C", 	srl_c};
	ext_op_tab[0x3a] = (struct ext_inst_s) {"SRL D", 	srl_d};
	ext_op_tab[0x3b] = (struct ext_inst_s) {"SRL E", 	srl_e};
	ext_op_tab[0x3c] = (struct ext_inst_s) {"SRL H", 	srl_h};
	ext_op_tab[0x3d] = (struct ext_inst_s) {"SRL L", 	srl_l};
	ext_op_tab[0x3e] = (struct ext_inst_s) {"SRL (HL)", srl_ptr_hl};
	ext_op_tab[0x3f] = (struct ext_inst_s) {"SRL A", 	srl_a};
	ext_op_tab[0x78] = (struct ext_inst_s) {"BIT 7 B", 	bit7_b};
	ext_op_tab[0x79] = (struct ext_inst_s) {"BIT 7 C", 	bit7_c};
	ext_op_tab[0x7a] = (struct ext_inst_s) {"BIT 7 D", 	bit7_d};
	ext_op_tab[0x7b] = (struct ext_inst_s) {"BIT 7 E", 	bit7_e};
	ext_op_tab[0x7c] = (struct ext_inst_s) {"BIT 7 H", 	bit7_h};
	ext_op_tab[0x7d] = (struct ext_inst_s) {"BIT 7 L", 	bit7_l};
	ext_op_tab[0x7e] = (struct ext_inst_s) {"BIT 7 (HL)", 	bit7_ptr_hl};
	ext_op_tab[0x7f] = (struct ext_inst_s) {"BIT 7 A", 	bit7_a};
	ext_op_tab[0x68] = (struct ext_inst_s) {"BIT 5 B", 	bit5_b};
	ext_op_tab[0x69] = (struct ext_inst_s) {"BIT 5 C", 	bit5_c};
	ext_op_tab[0x6a] = (struct ext_inst_s) {"BIT 5 D", 	bit5_d};
	ext_op_tab[0x6b] = (struct ext_inst_s) {"BIT 5 E", 	bit5_e};
	ext_op_tab[0x6c] = (struct ext_inst_s) {"BIT 5 H", 	bit5_h};
	ext_op_tab[0x6d] = (struct ext_inst_s) {"BIT 5 L", 	bit5_l};
	ext_op_tab[0x6e] = (struct ext_inst_s) {"BIT 5 (HL)", 	bit5_ptr_hl};
	ext_op_tab[0x6f] = (struct ext_inst_s) {"BIT 5 A", 	bit5_a};
	ext_op_tab[0x58] = (struct ext_inst_s) {"BIT 3 B", 	bit3_b};
	ext_op_tab[0x59] = (struct ext_inst_s) {"BIT 3 C", 	bit3_c};
	ext_op_tab[0x5a] = (struct ext_inst_s) {"BIT 3 D", 	bit3_d};
	ext_op_tab[0x5b] = (struct ext_inst_s) {"BIT 3 E", 	bit3_e};
	ext_op_tab[0x5c] = (struct ext_inst_s) {"BIT 3 H", 	bit3_h};
	ext_op_tab[0x5d] = (struct ext_inst_s) {"BIT 3 L", 	bit3_l};
	ext_op_tab[0x5e] = (struct ext_inst_s) {"BIT 3 (HL)", 	bit3_ptr_hl};
	ext_op_tab[0x5f] = (struct ext_inst_s) {"BIT 3 A", 	bit3_a};
	ext_op_tab[0x48] = (struct ext_inst_s) {"BIT 1 B", 	bit1_b};
	ext_op_tab[0x49] = (struct ext_inst_s) {"BIT 1 C", 	bit1_c};
	ext_op_tab[0x4a] = (struct ext_inst_s) {"BIT 1 D", 	bit1_d};
	ext_op_tab[0x4b] = (struct ext_inst_s) {"BIT 1 E", 	bit1_e};
	ext_op_tab[0x4c] = (struct ext_inst_s) {"BIT 1 H", 	bit1_h};
	ext_op_tab[0x4d] = (struct ext_inst_s) {"BIT 1 L", 	bit1_l};
	ext_op_tab[0x4e] = (struct ext_inst_s) {"BIT 1 (HL)", 	bit1_ptr_hl};
	ext_op_tab[0x4f] = (struct ext_inst_s) {"BIT 1 A", 	bit1_a};

	ext_op_tab[0x40] = (struct ext_inst_s) {"BIT 0 B", 	bit0_b};
	ext_op_tab[0x41] = (struct ext_inst_s) {"BIT 0 C", 	bit0_c};
	ext_op_tab[0x42] = (struct ext_inst_s) {"BIT 0 D", 	bit0_d};
	ext_op_tab[0x43] = (struct ext_inst_s) {"BIT 0 E", 	bit0_e};
	ext_op_tab[0x44] = (struct ext_inst_s) {"BIT 0 H", 	bit0_h};
	ext_op_tab[0x45] = (struct ext_inst_s) {"BIT 0 L", 	bit0_l};
	ext_op_tab[0x46] = (struct ext_inst_s) {"BIT 0 (HL)", 	bit0_ptr_hl};
	ext_op_tab[0x47] = (struct ext_inst_s) {"BIT 0 A", 	bit0_a};

	ext_op_tab[0x50] = (struct ext_inst_s) {"BIT 2 B", 	bit2_b};
	ext_op_tab[0x51] = (struct ext_inst_s) {"BIT 2 C", 	bit2_c};
	ext_op_tab[0x52] = (struct ext_inst_s) {"BIT 2 D", 	bit2_d};
	ext_op_tab[0x53] = (struct ext_inst_s) {"BIT 2 E", 	bit2_e};
	ext_op_tab[0x54] = (struct ext_inst_s) {"BIT 2 H", 	bit2_h};
	ext_op_tab[0x55] = (struct ext_inst_s) {"BIT 2 L", 	bit2_l};
	ext_op_tab[0x56] = (struct ext_inst_s) {"BIT 2 (HL)", 	bit2_ptr_hl};
	ext_op_tab[0x57] = (struct ext_inst_s) {"BIT 2 A", 	bit2_a};

	ext_op_tab[0x60] = (struct ext_inst_s) {"BIT 4 B", 	bit4_b};
	ext_op_tab[0x61] = (struct ext_inst_s) {"BIT 4 C", 	bit4_c};
	ext_op_tab[0x62] = (struct ext_inst_s) {"BIT 4 D", 	bit4_d};
	ext_op_tab[0x63] = (struct ext_inst_s) {"BIT 4 E", 	bit4_e};
	ext_op_tab[0x64] = (struct ext_inst_s) {"BIT 4 H", 	bit4_h};
	ext_op_tab[0x65] = (struct ext_inst_s) {"BIT 4 L", 	bit4_l};
	ext_op_tab[0x66] = (struct ext_inst_s) {"BIT 4 (HL)", 	bit4_ptr_hl};
	ext_op_tab[0x67] = (struct ext_inst_s) {"BIT 4 A", 	bit4_a};

	ext_op_tab[0x70] = (struct ext_inst_s) {"BIT 6 B", 	bit6_b};
	ext_op_tab[0x71] = (struct ext_inst_s) {"BIT 6 C", 	bit6_c};
	ext_op_tab[0x72] = (struct ext_inst_s) {"BIT 6 D", 	bit6_d};
	ext_op_tab[0x73] = (struct ext_inst_s) {"BIT 6 E", 	bit6_e};
	ext_op_tab[0x74] = (struct ext_inst_s) {"BIT 6 H", 	bit6_h};
	ext_op_tab[0x75] = (struct ext_inst_s) {"BIT 6 L", 	bit6_l};
	ext_op_tab[0x76] = (struct ext_inst_s) {"BIT 6 (HL)", 	bit6_ptr_hl};
	ext_op_tab[0x77] = (struct ext_inst_s) {"BIT 6 A", 	bit6_a};

	ext_op_tab[0x87] = (struct ext_inst_s) {"RES 0 A", 	res0_a};
	ext_op_tab[0x37] = (struct ext_inst_s) {"SWAP  A", 	swap_a};
}