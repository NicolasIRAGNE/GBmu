/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_op_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 16:16:07 by niragne           #+#    #+#             */
/*   Updated: 2020/03/31 15:21:01 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

struct inst_s	op_tab[256] = 
{	
	{0}
};

void	init_op_tab()
{
	op_tab[0x00] = (struct inst_s) {"NOP",			4, 0, nop};
	op_tab[0x01] = (struct inst_s) {"LD BC A16",	1, 2, ld_bc_a16};
	op_tab[0x02] = (struct inst_s) {"LD (BC) A",	1, 0, ld_ptr_bc_a};
	op_tab[0x03] = (struct inst_s) {"INC BC",		8, 0, inc_bc};
	op_tab[0x04] = (struct inst_s) {"INC B",		4, 0, inc_b};
	op_tab[0x05] = (struct inst_s) {"DEC B",		4, 0, dec_b};
	op_tab[0x06] = (struct inst_s) {"LD B A8",		8, 1, ld_b_a8};
	op_tab[0x07] = (struct inst_s) {"RLC A",		8, 0, rlca};
	op_tab[0x08] = (struct inst_s) {"LD (nn) SP",	20, 2, ld_ptr_nn_sp};
	op_tab[0x09] = (struct inst_s) {"ADD BC",		8, 0, add_bc};
	op_tab[0x0a] = (struct inst_s) {"LD A (BC)",	8, 0, ld_a_ptr_bc};
	op_tab[0x0b] = (struct inst_s) {"DEC BC",		8, 0, dec_bc};
	op_tab[0x0c] = (struct inst_s) {"INC C",		4, 0, inc_c};
	op_tab[0x0d] = (struct inst_s) {"DEC C",		4, 0, dec_c};
	op_tab[0x0e] = (struct inst_s) {"LD C A8",		8, 1, ld_c_a8};
	op_tab[0x0f] = (struct inst_s) {"RRC A",		8, 0, rrca};
	op_tab[0x10] = (struct inst_s) {"STOP",			4, 0, stop};
	op_tab[0x11] = (struct inst_s) {"LD DE A16",	12, 2, ld_de_a16};
	op_tab[0x12] = (struct inst_s) {"LD (DE) A",	8, 0, ld_ptr_de_a};
	op_tab[0x13] = (struct inst_s) {"INC DE",		8, 0, inc_de};
	op_tab[0x14] = (struct inst_s) {"INC D",		4, 0, inc_d};
	op_tab[0x15] = (struct inst_s) {"DEC D",		4, 0, dec_d};
	op_tab[0x16] = (struct inst_s) {"LD D A8",		8, 1, ld_d_a8};
	op_tab[0x17] = (struct inst_s) {"RL A",			8, 0, rla};
	op_tab[0x18] = (struct inst_s) {"JR A8",		12, 1, jr_a8};
	op_tab[0x19] = (struct inst_s) {"ADD DE",		8, 0, add_de};
	op_tab[0x1a] = (struct inst_s) {"LD A (DE)",	8, 0, ld_a_ptr_de};
	op_tab[0x1b] = (struct inst_s) {"DEC DE",		8, 0, dec_de};
	op_tab[0x1c] = (struct inst_s) {"INC E",		4, 0, inc_e};
	op_tab[0x1d] = (struct inst_s) {"DEC E",		4, 0, dec_e};
	op_tab[0x1e] = (struct inst_s) {"LD E A8",		8, 1, ld_e_a8};
	op_tab[0x1f] = (struct inst_s) {"RR A",			8, 0, rra};
	op_tab[0x20] = (struct inst_s) {"JR NZ A8",		8, 1, jr_nz_a8};
	op_tab[0x21] = (struct inst_s) {"LD HL A16",	12, 2, ld_hl_a16};
	op_tab[0x22] = (struct inst_s) {"LDI (HL) A",	8, 0, ldi_hl_a};
	op_tab[0x23] = (struct inst_s) {"INC HL",		8, 0, inc_hl};
	op_tab[0x24] = (struct inst_s) {"INC H",		4, 0, inc_h};
	op_tab[0x25] = (struct inst_s) {"DEC H",		4, 0, dec_h};
	op_tab[0x26] = (struct inst_s) {"LD H A8",		8, 1, ld_h_a8};
	op_tab[0x27] = (struct inst_s) {"DAA",			4, 0, daa};
	op_tab[0x28] = (struct inst_s) {"JR Z A8",		8, 1, jr_z_a8};
	op_tab[0x29] = (struct inst_s) {"ADD HL",		8, 0, add_hl};
	op_tab[0x2a] = (struct inst_s) {"LDI A (HL)",	8, 0, ldi_a_ptr_hl};
	op_tab[0x2b] = (struct inst_s) {"DEC HL",		8, 0, dec_hl};
	op_tab[0x2c] = (struct inst_s) {"INC L",		4, 0, inc_l};
	op_tab[0x2d] = (struct inst_s) {"DEC L",		4, 0, dec_l};
	op_tab[0x2e] = (struct inst_s) {"LD L A8",		8, 1, ld_l_a8};
	op_tab[0x2f] = (struct inst_s) {"CPL",			4, 0, cpl};
	op_tab[0x30] = (struct inst_s) {"JR NC A8",		8, 1, jr_nc_a8};
	op_tab[0x31] = (struct inst_s) {"LD SP A16",	12, 2, ld_sp_a16};
	op_tab[0x32] = (struct inst_s) {"LDD (HL) A",	8, 0, ldd_hl_a};
	op_tab[0x33] = (struct inst_s) {"INC SP",		8, 0, inc_sp};
	op_tab[0x34] = (struct inst_s) {"INC (HL)",		12, 0, inc_ptr_hl};
	op_tab[0x35] = (struct inst_s) {"DEC (HL)",		12, 0, dec_ptr_hl};
	op_tab[0x36] = (struct inst_s) {"LD (HL) n",	8, 1, ld_ptr_hl_n};
	op_tab[0x37] = (struct inst_s) {"SCF",			4, 0, scf};
	op_tab[0x38] = (struct inst_s) {"JR C A8",		8, 1, jr_c_a8};
	op_tab[0x39] = (struct inst_s) {"ADD SP",		8, 0, add_sp};
	op_tab[0x3a] = (struct inst_s) {"LDD A (HL)",	8, 0, ldd_a_ptr_hl};
	op_tab[0x3b] = (struct inst_s) {"DEC SP",		8, 0, dec_sp};
	op_tab[0x3c] = (struct inst_s) {"INC A",		4, 0, inc_a};
	op_tab[0x3d] = (struct inst_s) {"DEC A",		4, 0, dec_a};
	op_tab[0x3e] = (struct inst_s) {"LD A A8",		8, 1, ld_a_a8};
	op_tab[0x3f] = (struct inst_s) {"CCF",			4, 0, ccf};
	op_tab[0x40] = (struct inst_s) {"LD B B",		4, 0, ld_b_b};
	op_tab[0x41] = (struct inst_s) {"LD B C",		4, 0, ld_b_c};
	op_tab[0x42] = (struct inst_s) {"LD B D",		4, 0, ld_b_d};
	op_tab[0x43] = (struct inst_s) {"LD B E",		4, 0, ld_b_e};
	op_tab[0x44] = (struct inst_s) {"LD B H",		4, 0, ld_b_h};
	op_tab[0x45] = (struct inst_s) {"LD B L",		4, 0, ld_b_l};
	op_tab[0x46] = (struct inst_s) {"LD B (HL)",	8, 0, ld_b_ptr_hl};
	op_tab[0x47] = (struct inst_s) {"LD B A",		4, 0, ld_b_a};
	op_tab[0x48] = (struct inst_s) {"LD C B",		4, 0, ld_c_b};
	op_tab[0x49] = (struct inst_s) {"LD C C",		4, 0, ld_c_c};
	op_tab[0x4a] = (struct inst_s) {"LD C D",		4, 0, ld_c_d};
	op_tab[0x4b] = (struct inst_s) {"LD C E",		4, 0, ld_c_e};
	op_tab[0x4c] = (struct inst_s) {"LD C H",		4, 0, ld_c_h};
	op_tab[0x4d] = (struct inst_s) {"LD C L",		4, 0, ld_c_l};
	op_tab[0x4e] = (struct inst_s) {"LD C (HL)",	8, 0, ld_c_ptr_hl};
	op_tab[0x4f] = (struct inst_s) {"LD C A",		4, 0, ld_c_a};
	op_tab[0x50] = (struct inst_s) {"LD D B",		4, 0, ld_d_b};
	op_tab[0x51] = (struct inst_s) {"LD D C",		4, 0, ld_d_c};
	op_tab[0x52] = (struct inst_s) {"LD D D",		4, 0, ld_d_d};
	op_tab[0x53] = (struct inst_s) {"LD D E",		4, 0, ld_d_e};
	op_tab[0x54] = (struct inst_s) {"LD D H",		4, 0, ld_d_h};
	op_tab[0x55] = (struct inst_s) {"LD D L",		4, 0, ld_d_l};
	op_tab[0x56] = (struct inst_s) {"LD D (HL)",	8, 0, ld_d_ptr_hl};
	op_tab[0x57] = (struct inst_s) {"LD D A",		4, 0, ld_d_a};
	op_tab[0x58] = (struct inst_s) {"LD E B",		4, 0, ld_e_b};
	op_tab[0x59] = (struct inst_s) {"LD E C",		4, 0, ld_e_c};
	op_tab[0x5a] = (struct inst_s) {"LD E D",		4, 0, ld_e_d};
	op_tab[0x5b] = (struct inst_s) {"LD E E",		4, 0, ld_e_e};
	op_tab[0x5c] = (struct inst_s) {"LD E H",		4, 0, ld_e_h};
	op_tab[0x5d] = (struct inst_s) {"LD E L",		4, 0, ld_e_l};
	op_tab[0x5e] = (struct inst_s) {"LD E (HL)",	8, 0, ld_e_ptr_hl};
	op_tab[0x5f] = (struct inst_s) {"LD E A",		4, 0, ld_e_a};
	op_tab[0x60] = (struct inst_s) {"LD H B",		4, 0, ld_h_b};
	op_tab[0x61] = (struct inst_s) {"LD H C",		4, 0, ld_h_c};
	op_tab[0x62] = (struct inst_s) {"LD H D",		4, 0, ld_h_d};
	op_tab[0x63] = (struct inst_s) {"LD H E",		4, 0, ld_h_e};
	op_tab[0x64] = (struct inst_s) {"LD H H",		4, 0, ld_h_h};
	op_tab[0x65] = (struct inst_s) {"LD H L",		4, 0, ld_h_l};
	op_tab[0x66] = (struct inst_s) {"LD H (HL)",	8, 0, ld_h_ptr_hl};
	op_tab[0x67] = (struct inst_s) {"LD H A",		4, 0, ld_h_a};
	op_tab[0x68] = (struct inst_s) {"LD L B",		4, 0, ld_l_b};
	op_tab[0x69] = (struct inst_s) {"LD L C",		4, 0, ld_l_c};
	op_tab[0x6a] = (struct inst_s) {"LD L D",		4, 0, ld_l_d};
	op_tab[0x6b] = (struct inst_s) {"LD L E",		4, 0, ld_l_e};
	op_tab[0x6c] = (struct inst_s) {"LD L H",		4, 0, ld_l_h};
	op_tab[0x6d] = (struct inst_s) {"LD L L",		4, 0, ld_l_l};
	op_tab[0x6e] = (struct inst_s) {"LD L (HL)",	8, 0, ld_l_ptr_hl};
	op_tab[0x6f] = (struct inst_s) {"LD L A",		4, 0, ld_l_a};
	op_tab[0x70] = (struct inst_s) {"LD (HL) B",	8, 0, ld_ptr_hl_b};
	op_tab[0x71] = (struct inst_s) {"LD (HL) C",	8, 0, ld_ptr_hl_c};
	op_tab[0x72] = (struct inst_s) {"LD (HL) D",	8, 0, ld_ptr_hl_d};
	op_tab[0x73] = (struct inst_s) {"LD (HL) E",	8, 0, ld_ptr_hl_e};
	op_tab[0x74] = (struct inst_s) {"LD (HL) H",	8, 0, ld_ptr_hl_h};
	op_tab[0x75] = (struct inst_s) {"LD (HL) L",	8, 0, ld_ptr_hl_l};
	op_tab[0x76] = (struct inst_s) {"HALT",			4, 0, halt};
	op_tab[0x77] = (struct inst_s) {"LD (HL) A",	8, 0, ld_ptr_hl_a};
	op_tab[0x78] = (struct inst_s) {"LD A B",		4, 0, ld_a_b};
	op_tab[0x79] = (struct inst_s) {"LD A C",		4, 0, ld_a_c};
	op_tab[0x7a] = (struct inst_s) {"LD A D",		4, 0, ld_a_d};
	op_tab[0x7b] = (struct inst_s) {"LD A E",		4, 0, ld_a_e};
	op_tab[0x7c] = (struct inst_s) {"LD A H",		4, 0, ld_a_h};
	op_tab[0x7d] = (struct inst_s) {"LD A L",		4, 0, ld_a_l};
	op_tab[0x7e] = (struct inst_s) {"LD A (HL)",	8, 0, ld_a_ptr_hl};
	op_tab[0x7f] = (struct inst_s) {"LD A A",		4, 0, ld_a_a};
	op_tab[0x80] = (struct inst_s) {"ADD A B",		4, 0, add_b};
	op_tab[0x81] = (struct inst_s) {"ADD A C",		4, 0, add_c};
	op_tab[0x82] = (struct inst_s) {"ADD A D",		4, 0, add_d};
	op_tab[0x83] = (struct inst_s) {"ADD A E",		4, 0, add_e};
	op_tab[0x84] = (struct inst_s) {"ADD A H",		4, 0, add_h};
	op_tab[0x85] = (struct inst_s) {"ADD A L",		4, 0, add_l};
	op_tab[0x86] = (struct inst_s) {"ADD (HL)",		8, 0, add_ptr_hl};
	op_tab[0x87] = (struct inst_s) {"ADD A A",		4, 0, add_a};
	op_tab[0x88] = (struct inst_s) {"ADC B",		4, 0, adc_b};
	op_tab[0x89] = (struct inst_s) {"ADC C",		4, 0, adc_c};
	op_tab[0x8a] = (struct inst_s) {"ADC D",		4, 0, adc_d};
	op_tab[0x8b] = (struct inst_s) {"ADC E",		4, 0, adc_e};
	op_tab[0x8c] = (struct inst_s) {"ADC H",		4, 0, adc_h};
	op_tab[0x8d] = (struct inst_s) {"ADC L",		4, 0, adc_l};
	op_tab[0x8e] = (struct inst_s) {"ADC (HL)",		8, 0, adc_ptr_hl};
	op_tab[0x8f] = (struct inst_s) {"ADC A",		4, 0, adc_a};
	op_tab[0x90] = (struct inst_s) {"SUB A B",		4, 0, sub_b};
	op_tab[0x91] = (struct inst_s) {"SUB A C",		4, 0, sub_c};
	op_tab[0x92] = (struct inst_s) {"SUB A D",		4, 0, sub_d};
	op_tab[0x93] = (struct inst_s) {"SUB A E",		4, 0, sub_e};
	op_tab[0x94] = (struct inst_s) {"SUB A H",		4, 0, sub_h};
	op_tab[0x95] = (struct inst_s) {"SUB A L",		4, 0, sub_l};
	op_tab[0x96] = (struct inst_s) {"SUB (HL)",		8, 0, sub_ptr_hl};
	op_tab[0x97] = (struct inst_s) {"SUB A A",		4, 0, sub_a};
	op_tab[0x98] = (struct inst_s) {"SBC B",		4, 0, sbc_b};
	op_tab[0x99] = (struct inst_s) {"SBC C",		4, 0, sbc_c};
	op_tab[0x9a] = (struct inst_s) {"SBC D",		4, 0, sbc_d};
	op_tab[0x9b] = (struct inst_s) {"SBC E",		4, 0, sbc_e};
	op_tab[0x9c] = (struct inst_s) {"SBC H",		4, 0, sbc_h};
	op_tab[0x9d] = (struct inst_s) {"SBC L",		4, 0, sbc_l};
	op_tab[0x9e] = (struct inst_s) {"SBC (HL)",		8, 0, sbc_ptr_hl};
	op_tab[0x9f] = (struct inst_s) {"SBC A",		4, 0, sbc_a};
	op_tab[0xa0] = (struct inst_s) {"AND B",		4, 0, and_b};
	op_tab[0xa1] = (struct inst_s) {"AND C",		4, 0, and_c};
	op_tab[0xa2] = (struct inst_s) {"AND D",		4, 0, and_d};
	op_tab[0xa3] = (struct inst_s) {"AND E",		4, 0, and_e};
	op_tab[0xa4] = (struct inst_s) {"AND H",		4, 0, and_h};
	op_tab[0xa5] = (struct inst_s) {"AND L",		4, 0, and_l};
	op_tab[0xa6] = (struct inst_s) {"AND (HL)",		8, 0, and_ptr_hl};
	op_tab[0xa7] = (struct inst_s) {"AND A",		4, 0, and_a};
	op_tab[0xa8] = (struct inst_s) {"XOR B",		4, 0, xor_b};
	op_tab[0xa9] = (struct inst_s) {"XOR C",		4, 0, xor_c};
	op_tab[0xaa] = (struct inst_s) {"XOR D",		4, 0, xor_d};
	op_tab[0xab] = (struct inst_s) {"XOR E",		4, 0, xor_e};
	op_tab[0xac] = (struct inst_s) {"XOR H",		4, 0, xor_h};
	op_tab[0xad] = (struct inst_s) {"XOR L",		4, 0, xor_l};
	op_tab[0xae] = (struct inst_s) {"XOR (HL)",		8, 0, xor_ptr_hl};
	op_tab[0xaf] = (struct inst_s) {"XOR A",		4, 0, xor_a};
	op_tab[0xb0] = (struct inst_s) {"OR B",			4, 0, or_b};
	op_tab[0xb1] = (struct inst_s) {"OR C",			4, 0, or_c};
	op_tab[0xb2] = (struct inst_s) {"OR D",			4, 0, or_d};
	op_tab[0xb3] = (struct inst_s) {"OR E",			4, 0, or_e};
	op_tab[0xb4] = (struct inst_s) {"OR H",			4, 0, or_h};
	op_tab[0xb5] = (struct inst_s) {"OR L",			4, 0, or_l};
	op_tab[0xb6] = (struct inst_s) {"OR (HL)",		8, 0, or_ptr_hl};
	op_tab[0xb7] = (struct inst_s) {"OR A",			4, 0, or_a};
	op_tab[0xb8] = (struct inst_s) {"CP B",			4, 0, cp_b};
	op_tab[0xb9] = (struct inst_s) {"CP C",			4, 0, cp_c};
	op_tab[0xba] = (struct inst_s) {"CP D",			4, 0, cp_d};
	op_tab[0xbb] = (struct inst_s) {"CP E",			4, 0, cp_e};
	op_tab[0xbc] = (struct inst_s) {"CP H",			4, 0, cp_h};
	op_tab[0xbd] = (struct inst_s) {"CP L",			4, 0, cp_l};
	op_tab[0xbe] = (struct inst_s) {"CP (HL)",		8, 0, cp_ptr_hl};
	op_tab[0xbf] = (struct inst_s) {"CP A",			4, 0, cp_a};
	op_tab[0xc0] = (struct inst_s) {"RET NZ",		8, 0, ret_nz};
	op_tab[0xc1] = (struct inst_s) {"POP BC",		12, 0, pop_bc};
	op_tab[0xc2] = (struct inst_s) {"JP NZ A16",	12, 2, jp_nz_a16};
	op_tab[0xc3] = (struct inst_s) {"JP A16",		16, 2, jp_a16};
	op_tab[0xc4] = (struct inst_s) {"CALL NZ A16",	12, 2, call_nz_a16};
	op_tab[0xc5] = (struct inst_s) {"PUSH BC",		16, 0, push_bc};
	op_tab[0xc6] = (struct inst_s) {"ADD A A8",		8, 1, add_a8};
	op_tab[0xc7] = (struct inst_s) {"RST 0",		16, 0, rst_0};
	op_tab[0xc8] = (struct inst_s) {"RET Z",		8, 0, ret_z};
	op_tab[0xc9] = (struct inst_s) {"RET",			16, 0, ret};
	op_tab[0xca] = (struct inst_s) {"JP Z A16",		12, 2, jp_z_a16};
	op_tab[0xcb] = (struct inst_s) {"CB N",			1, 1, cb_n};
	op_tab[0xcc] = (struct inst_s) {"CALL Z A16",	12, 2, call_z_a16};
	op_tab[0xcd] = (struct inst_s) {"CALL A16",		24, 2, call_a16};
	op_tab[0xce] = (struct inst_s) {"ADC N",		8, 1, adc_n};
	op_tab[0xcf] = (struct inst_s) {"RST 8",		16, 0, rst_8};
	op_tab[0xd0] = (struct inst_s) {"RET NC",		8, 0, ret_nc};
	op_tab[0xd1] = (struct inst_s) {"POP DE",		12, 0, pop_de};
	op_tab[0xd2] = (struct inst_s) {"JP NC A16",	16, 2, jp_nc_a16};
	op_tab[0xd4] = (struct inst_s) {"CALL NZ A16",	12, 2, call_nc_a16};
	op_tab[0xd5] = (struct inst_s) {"PUSH DE",		16, 0, push_de};
	op_tab[0xd6] = (struct inst_s) {"SUB A A8",		8, 1, sub_a8};
	op_tab[0xd7] = (struct inst_s) {"RST 10",		16, 0, rst_10};
	op_tab[0xd8] = (struct inst_s) {"RET C",		8, 0, ret_c};
	op_tab[0xd9] = (struct inst_s) {"RETI",			16, 0, reti};
	op_tab[0xda] = (struct inst_s) {"JP C A16",		16, 2, jp_c_a16};
	op_tab[0xdc] = (struct inst_s) {"CALL Z A16",	12, 2, call_c_a16};
	op_tab[0xde] = (struct inst_s) {"SBC N",		8, 1, sbc_n};
	op_tab[0xdf] = (struct inst_s) {"RST 18",		16, 0, rst_18};
	op_tab[0xe0] = (struct inst_s) {"LDH (n) A",	12, 1, ldh_a8_a};
	op_tab[0xe1] = (struct inst_s) {"POP HL",		12, 0, pop_hl};
	op_tab[0xe2] = (struct inst_s) {"LDH (C) A",	8, 0, ldh_ptr_c_a};
	op_tab[0xe5] = (struct inst_s) {"PUSH HL",		16, 0, push_hl};
	op_tab[0xe6] = (struct inst_s) {"AND A8",		8, 1, and_a8};
	op_tab[0xe7] = (struct inst_s) {"RST 20",		16, 0, rst_20};
	op_tab[0xe8] = (struct inst_s) {"ADD SP, s",	16, 1, add_sp_s};
	op_tab[0xe9] = (struct inst_s) {"JP HL",		4, 0, jp_hl};
	op_tab[0xea] = (struct inst_s) {"LD (NN) A",	16, 2, ld_nn_a};
	op_tab[0xee] = (struct inst_s) {"XOR N",		8, 1, xor_n};
	op_tab[0xef] = (struct inst_s) {"RST 28",		16, 0, rst_28};
	op_tab[0xf0] = (struct inst_s) {"LDH A (n)",	12, 1, ldh_a_ptr_n};
	op_tab[0xf1] = (struct inst_s) {"POP AF",		12, 0, pop_af};
	op_tab[0xf2] = (struct inst_s) {"LDH A (C)",	8, 0, ldh_a_ptr_c};
	op_tab[0xf3] = (struct inst_s) {"DI",			4, 0, di};
	op_tab[0xf5] = (struct inst_s) {"PUSH AF",		16, 0, push_af};
	op_tab[0xf6] = (struct inst_s) {"OR N",			8, 1, or_n};
	op_tab[0xf7] = (struct inst_s) {"RST 30",		16, 0, rst_30};
	op_tab[0xf8] = (struct inst_s) {"LDHL SP, s",	12, 1, ld_hl_sp_s};
	op_tab[0xf9] = (struct inst_s) {"LD SP HL",		8, 0, ld_sp_hl};
	op_tab[0xfa] = (struct inst_s) {"LD A (A16)",	16, 2, ld_a_ptr_a16};
	op_tab[0xfb] = (struct inst_s) {"EI",			4, 0, ei};
	op_tab[0xfe] = (struct inst_s) {"CP n",			8, 1, cp_a8};
	op_tab[0xff] = (struct inst_s) {"RST 38",		16, 0, rst_38};
}