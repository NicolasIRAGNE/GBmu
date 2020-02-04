/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_op_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 16:16:07 by niragne           #+#    #+#             */
/*   Updated: 2020/02/04 20:13:32 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

struct inst_s	op_tab[256] = 
{	
	{0}
};

void	init_op_tab()
{
	op_tab[0x00] = (struct inst_s) {"NOP",			0x00, 1, 0, nop};
	op_tab[0x3d] = (struct inst_s) {"DEC A",		0x3d, 1, 0, dec_a};
	op_tab[0x05] = (struct inst_s) {"DEC B",		0x05, 1, 0, dec_b};
	op_tab[0x0d] = (struct inst_s) {"DEC C",		0x0d, 1, 0, dec_c};
	op_tab[0x15] = (struct inst_s) {"DEC D",		0x15, 1, 0, dec_d};
	op_tab[0x1d] = (struct inst_s) {"DEC E",		0x1d, 1, 0, dec_e};
	op_tab[0x25] = (struct inst_s) {"DEC H",		0x25, 1, 0, dec_h};
	op_tab[0x2d] = (struct inst_s) {"DEC L",		0x2d, 1, 0, dec_l};
	op_tab[0x3c] = (struct inst_s) {"INC A",		0x3c, 1, 0, inc_a};
	op_tab[0x04] = (struct inst_s) {"INC B",		0x04, 1, 0, inc_b};
	op_tab[0x0c] = (struct inst_s) {"INC C",		0x0c, 1, 0, inc_c};
	op_tab[0x14] = (struct inst_s) {"INC D",		0x14, 1, 0, inc_d};
	op_tab[0x1c] = (struct inst_s) {"INC E",		0x1c, 1, 0, inc_e};
	op_tab[0x24] = (struct inst_s) {"INC H",		0x24, 1, 0, inc_h};
	op_tab[0x2c] = (struct inst_s) {"INC L",		0x2c, 1, 0, inc_l};
	op_tab[0x06] = (struct inst_s) {"LD B A8",		0x06, 1, 1, ld_b_a8};
	op_tab[0x0e] = (struct inst_s) {"LD C A8",		0x0e, 1, 1, ld_c_a8};
	op_tab[0x21] = (struct inst_s) {"LD HL A16",	0x21, 1, 2, ld_hl_a16};
	op_tab[0x31] = (struct inst_s) {"LD SP A16",	0x31, 1, 2, ld_sp_a16};
	op_tab[0x32] = (struct inst_s) {"LDD (HL) A",	0x3e, 1, 0, ldd_hl_a};
	op_tab[0x3e] = (struct inst_s) {"LD A A8",		0x3e, 1, 1, ld_a_a8};
	op_tab[0x4e] = (struct inst_s) {"LD C (HL)",	0x4e, 1, 1, ld_c_hl};
	op_tab[0xc3] = (struct inst_s) {"JP A16",		0xc3, 1, 2, jp_a16};
	op_tab[0xaf] = (struct inst_s) {"XOR A",		0xaf, 1, 0, xor_a};
	op_tab[0xcd] = (struct inst_s) {"CALL A16",		0xaf, 1, 1, call_a16};
	op_tab[0xe0] = (struct inst_s) {"LDH (n) A",	0xe0, 1, 1, ldh_a8_a};
	op_tab[0xf0] = (struct inst_s) {"LDH A (n)",	0xf0, 1, 1, ldh_a_a8};
	op_tab[0xf3] = (struct inst_s) {"DI",			0xf3, 1, 0, di};
	op_tab[0xfb] = (struct inst_s) {"EI",			0xfb, 1, 0, ei};
}