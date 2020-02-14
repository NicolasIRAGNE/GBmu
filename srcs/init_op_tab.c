/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_op_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 16:16:07 by niragne           #+#    #+#             */
/*   Updated: 2020/02/14 15:38:29 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

struct inst_s	op_tab[256] = 
{	
	{0}
};

void	init_op_tab()
{
	op_tab[0x00] = (struct inst_s) {"NOP",			1, 0, nop};
	op_tab[0x01] = (struct inst_s) {"LD BC A16",	1, 2, ld_bc_a16};
	op_tab[0x02] = (struct inst_s) {"LD (BC) A",	1, 0, ld_ptr_bc_a};
	op_tab[0x03] = (struct inst_s) {"INC BC",		1, 0, inc_bc};
	op_tab[0x3d] = (struct inst_s) {"DEC A",		1, 0, dec_a};
	op_tab[0x05] = (struct inst_s) {"DEC B",		1, 0, dec_b};
	op_tab[0x0d] = (struct inst_s) {"DEC C",		1, 0, dec_c};
	op_tab[0x15] = (struct inst_s) {"DEC D",		1, 0, dec_d};
	op_tab[0x1d] = (struct inst_s) {"DEC E",		1, 0, dec_e};
	op_tab[0x25] = (struct inst_s) {"DEC H",		1, 0, dec_h};
	op_tab[0x2d] = (struct inst_s) {"DEC L",		1, 0, dec_l};
	op_tab[0x3c] = (struct inst_s) {"INC A",		1, 0, inc_a};
	op_tab[0x04] = (struct inst_s) {"INC B",		1, 0, inc_b};
	op_tab[0x0c] = (struct inst_s) {"INC C",		1, 0, inc_c};
	op_tab[0x14] = (struct inst_s) {"INC D",		1, 0, inc_d};
	op_tab[0x12] = (struct inst_s) {"LD (DE) A",	1, 0, ld_ptr_de_a};
	op_tab[0x1c] = (struct inst_s) {"INC E",		1, 0, inc_e};
	op_tab[0x24] = (struct inst_s) {"INC H",		1, 0, inc_h};
	op_tab[0x2c] = (struct inst_s) {"INC L",		1, 0, inc_l};
	op_tab[0x03] = (struct inst_s) {"INC BC",		1, 0, inc_bc};
	op_tab[0x13] = (struct inst_s) {"INC DE",		1, 0, inc_de};
	op_tab[0x23] = (struct inst_s) {"INC HL",		1, 0, inc_hl};
	op_tab[0x33] = (struct inst_s) {"INC SP",		1, 0, inc_sp};
	op_tab[0x0b] = (struct inst_s) {"DEC BC",		1, 0, dec_bc};
	op_tab[0x1b] = (struct inst_s) {"DEC DE",		1, 0, dec_de};
	op_tab[0x2b] = (struct inst_s) {"DEC HL",		1, 0, dec_hl};
	op_tab[0x3b] = (struct inst_s) {"DEC SP",		1, 0, dec_sp};
	op_tab[0xc6] = (struct inst_s) {"ADD A A8",		1, 1, add_a8};
	op_tab[0xce] = (struct inst_s) {"ADC N",		1, 1, adc_n};
	op_tab[0x80] = (struct inst_s) {"ADD A B",		1, 0, add_b};
	op_tab[0x81] = (struct inst_s) {"ADD A C",		1, 0, add_c};
	op_tab[0x82] = (struct inst_s) {"ADD A D",		1, 0, add_d};
	op_tab[0x83] = (struct inst_s) {"ADD A E",		1, 0, add_e};
	op_tab[0x84] = (struct inst_s) {"ADD A H",		1, 0, add_h};
	op_tab[0x85] = (struct inst_s) {"ADD A L",		1, 0, add_l};
	op_tab[0x87] = (struct inst_s) {"ADD A A",		1, 0, add_a};
	op_tab[0xd6] = (struct inst_s) {"SUB A A8",		1, 1, sub_a8};
	op_tab[0x90] = (struct inst_s) {"SUB A B",		1, 0, sub_b};
	op_tab[0x91] = (struct inst_s) {"SUB A C",		1, 0, sub_c};
	op_tab[0x92] = (struct inst_s) {"SUB A D",		1, 0, sub_d};
	op_tab[0x93] = (struct inst_s) {"SUB A E",		1, 0, sub_e};
	op_tab[0x94] = (struct inst_s) {"SUB A H",		1, 0, sub_h};
	op_tab[0x95] = (struct inst_s) {"SUB A L",		1, 0, sub_l};
	op_tab[0x97] = (struct inst_s) {"SUB A A",		1, 0, sub_a};
	op_tab[0x51] = (struct inst_s) {"LD D C",		1, 0, ld_d_c};
	op_tab[0x4f] = (struct inst_s) {"LD C A",		1, 0, ld_c_a};
	op_tab[0x70] = (struct inst_s) {"LD (HL) B",	1, 0, ld_ptr_hl_b};
	op_tab[0x71] = (struct inst_s) {"LD (HL) C",	1, 0, ld_ptr_hl_c};
	op_tab[0x72] = (struct inst_s) {"LD (HL) D",	1, 0, ld_ptr_hl_d};
	op_tab[0x73] = (struct inst_s) {"LD (HL) E",	1, 0, ld_ptr_hl_e};
	op_tab[0x74] = (struct inst_s) {"LD (HL) H",	1, 0, ld_ptr_hl_h};
	op_tab[0x75] = (struct inst_s) {"LD (HL) L",	1, 0, ld_ptr_hl_l};
	op_tab[0x78] = (struct inst_s) {"LD A B",		1, 0, ld_a_b};
	op_tab[0x79] = (struct inst_s) {"LD A C",		1, 0, ld_a_c};
	op_tab[0x7a] = (struct inst_s) {"LD A D",		1, 0, ld_a_d};
	op_tab[0x7b] = (struct inst_s) {"LD A E",		1, 0, ld_a_e};
	op_tab[0x7c] = (struct inst_s) {"LD A H",		1, 0, ld_a_h};
	op_tab[0x7d] = (struct inst_s) {"LD A L",		1, 0, ld_a_l};
	op_tab[0x57] = (struct inst_s) {"LD D A",		1, 0, ld_d_a};
	op_tab[0x47] = (struct inst_s) {"LD B A",		1, 0, ld_b_a};
	op_tab[0x5f] = (struct inst_s) {"LD E A",		1, 0, ld_e_a};
	op_tab[0x06] = (struct inst_s) {"LD B A8",		1, 1, ld_b_a8};
	op_tab[0x0e] = (struct inst_s) {"LD C A8",		1, 1, ld_c_a8};
	op_tab[0x16] = (struct inst_s) {"LD D A8",		1, 1, ld_d_a8};
	op_tab[0x1e] = (struct inst_s) {"LD E A8",		1, 1, ld_e_a8};
	op_tab[0x26] = (struct inst_s) {"LD H A8",		1, 1, ld_h_a8};
	op_tab[0x2e] = (struct inst_s) {"LD L A8",		1, 1, ld_l_a8};
	op_tab[0x11] = (struct inst_s) {"LD DE A16",	1, 2, ld_de_a16};
	op_tab[0x21] = (struct inst_s) {"LD HL A16",	1, 2, ld_hl_a16};
	op_tab[0x31] = (struct inst_s) {"LD SP A16",	1, 2, ld_sp_a16};
	op_tab[0x32] = (struct inst_s) {"LDD (HL) A",	1, 0, ldd_hl_a};
	op_tab[0x77] = (struct inst_s) {"LD (HL) A",	1, 0, ld_ptr_hl_a};
	op_tab[0x22] = (struct inst_s) {"LDI (HL) A",	1, 0, ldi_hl_a};
	op_tab[0x3e] = (struct inst_s) {"LD A A8",		1, 1, ld_a_a8};
	op_tab[0xfa] = (struct inst_s) {"LD A (A16)",	1, 2, ld_a_ptr_a16};
	op_tab[0x1a] = (struct inst_s) {"LD A (DE)",	1, 0, ld_a_ptr_de};
	op_tab[0x7e] = (struct inst_s) {"LD A (HL)",	1, 0, ld_a_ptr_hl};
	op_tab[0x46] = (struct inst_s) {"LD B (HL)",	1, 0, ld_b_ptr_hl};
	op_tab[0x4e] = (struct inst_s) {"LD C (HL)",	1, 0, ld_c_ptr_hl};
	op_tab[0x56] = (struct inst_s) {"LD D (HL)",	1, 0, ld_d_ptr_hl};
	op_tab[0x66] = (struct inst_s) {"LD H (HL)",	1, 0, ld_h_ptr_hl};
	op_tab[0xc3] = (struct inst_s) {"JP A16",		1, 2, jp_a16};
	op_tab[0xc9] = (struct inst_s) {"RET",			1, 0, ret};
	op_tab[0xc0] = (struct inst_s) {"RET NZ",		1, 0, ret_nz};
	op_tab[0xc8] = (struct inst_s) {"RET Z",		1, 0, ret_z};
	op_tab[0xd0] = (struct inst_s) {"RET NC",		1, 0, ret_nc};
	op_tab[0xd8] = (struct inst_s) {"RET C",		1, 0, ret_c};
	op_tab[0xca] = (struct inst_s) {"JP Z A16",		1, 2, jp_z_a16};
	op_tab[0x20] = (struct inst_s) {"JR NZ A8",		1, 1, jr_nz_a8};
	op_tab[0x18] = (struct inst_s) {"JR A8",		1, 1, jr_a8};
	op_tab[0x28] = (struct inst_s) {"JR Z A8",		1, 1, jr_z_a8};
	op_tab[0x38] = (struct inst_s) {"JR C A8",		1, 1, jr_c_a8};
	op_tab[0x30] = (struct inst_s) {"JR NC A8",		1, 1, jr_nc_a8};
	op_tab[0xaf] = (struct inst_s) {"XOR A",		1, 0, xor_a};
	op_tab[0xa8] = (struct inst_s) {"XOR B",		1, 0, xor_b};
	op_tab[0xa9] = (struct inst_s) {"XOR C",		1, 0, xor_c};
	op_tab[0xaa] = (struct inst_s) {"XOR D",		1, 0, xor_d};
	op_tab[0xab] = (struct inst_s) {"XOR E",		1, 0, xor_e};
	op_tab[0xac] = (struct inst_s) {"XOR H",		1, 0, xor_h};
	op_tab[0xad] = (struct inst_s) {"XOR L",		1, 0, xor_l};
	op_tab[0xae] = (struct inst_s) {"XOR (HL)",		1, 0, xor_ptr_hl};
	op_tab[0xee] = (struct inst_s) {"XOR N",		1, 1, xor_n};
	op_tab[0xb7] = (struct inst_s) {"OR A",			1, 0, or_a};
	op_tab[0xb0] = (struct inst_s) {"OR B",			1, 0, or_b};
	op_tab[0xb1] = (struct inst_s) {"OR C",			1, 0, or_c};
	op_tab[0xb2] = (struct inst_s) {"OR D",			1, 0, or_d};
	op_tab[0xb3] = (struct inst_s) {"OR E",			1, 0, or_e};
	op_tab[0xb4] = (struct inst_s) {"OR H",			1, 0, or_h};
	op_tab[0xb5] = (struct inst_s) {"OR L",			1, 0, or_l};
	op_tab[0xe6] = (struct inst_s) {"AND A8",		1, 1, and_a8};
	op_tab[0xcd] = (struct inst_s) {"CALL A16",		1, 2, call_a16};
	op_tab[0xc4] = (struct inst_s) {"CALL NZ A16",	1, 2, call_nz_a16};
	op_tab[0xe0] = (struct inst_s) {"LDH (n) A",	1, 1, ldh_a8_a};
	op_tab[0xf0] = (struct inst_s) {"LDH A (n)",	1, 1, ldh_a_a8};
	op_tab[0xf3] = (struct inst_s) {"DI",			1, 0, di};
	op_tab[0xfb] = (struct inst_s) {"EI",			1, 0, ei};
	op_tab[0xfe] = (struct inst_s) {"CP n",			1, 1, cp_a8};
	op_tab[0x2a] = (struct inst_s) {"LDI A (HL)",	1, 0, ldi_a_ptr_hl};
	op_tab[0xea] = (struct inst_s) {"LD (NN) A",	1, 2, ld_nn_a};
	op_tab[0xe5] = (struct inst_s) {"PUSH HL",		1, 0, push_hl};
	op_tab[0xf5] = (struct inst_s) {"PUSH AF",		1, 0, push_af};
	op_tab[0xc5] = (struct inst_s) {"PUSH BC",		1, 0, push_bc};
	op_tab[0xd5] = (struct inst_s) {"PUSH DE",		1, 0, push_de};
	op_tab[0xe1] = (struct inst_s) {"POP HL",		1, 0, pop_hl};
	op_tab[0xf1] = (struct inst_s) {"POP AF",		1, 0, pop_af};
	op_tab[0xc1] = (struct inst_s) {"POP BC",		1, 0, pop_bc};
	op_tab[0xd1] = (struct inst_s) {"POP DE",		1, 0, pop_de};
	op_tab[0xcb] = (struct inst_s) {"CB N",			1, 1, cb_n};
	op_tab[0x1f] = (struct inst_s) {"RR A",			1, 0, rr_a};
}