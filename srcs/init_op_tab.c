/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_op_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 16:16:07 by niragne           #+#    #+#             */
/*   Updated: 2020/02/11 14:50:32 by niragne          ###   ########.fr       */
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
	op_tab[0x02] = (struct inst_s) {"LD (BC) A",	1, 0, ld_ptr_bc_a};
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
	op_tab[0x51] = (struct inst_s) {"LD D C",		1, 0, ld_dc};
	op_tab[0x47] = (struct inst_s) {"LD B A",		1, 0, ld_ba};
	op_tab[0x78] = (struct inst_s) {"LD A B",		1, 0, ld_ab};
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
	op_tab[0x3e] = (struct inst_s) {"LD A A8",		1, 1, ld_a_a8};
	op_tab[0x4e] = (struct inst_s) {"LD C (HL)",	1, 1, ld_c_hl};
	op_tab[0xc3] = (struct inst_s) {"JP A16",		1, 2, jp_a16};
	op_tab[0xc9] = (struct inst_s) {"RET",			1, 0, ret};
	op_tab[0xca] = (struct inst_s) {"JP Z A16",		1, 2, jp_z_a16};
	op_tab[0x20] = (struct inst_s) {"JR NZ A8",		1, 1, jr_nz_a8};
	op_tab[0x28] = (struct inst_s) {"JR Z A8",		1, 1, jr_z_a8};
	op_tab[0x38] = (struct inst_s) {"JR C A8",		1, 1, jr_c_a8};
	op_tab[0xaf] = (struct inst_s) {"XOR A",		1, 0, xor_a};
	op_tab[0xcd] = (struct inst_s) {"CALL A16",		1, 2, call_a16};
	op_tab[0xe0] = (struct inst_s) {"LDH (n) A",	1, 1, ldh_a8_a};
	op_tab[0xf0] = (struct inst_s) {"LDH A (n)",	1, 1, ldh_a_a8};
	op_tab[0xf3] = (struct inst_s) {"DI",			1, 0, di};
	op_tab[0xfb] = (struct inst_s) {"EI",			1, 0, ei};
	op_tab[0xfe] = (struct inst_s) {"CP n",			1, 1, cp_a8};
	op_tab[0x2a] = (struct inst_s) {"LDI A (HL)",	1, 0, ldi_a_ptr_hl};
}