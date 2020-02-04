/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_op_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 16:16:07 by niragne           #+#    #+#             */
/*   Updated: 2020/02/04 17:17:42 by niragne          ###   ########.fr       */
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
	op_tab[0x06] = (struct inst_s) {"LD B A8",		0x06, 1, 1, ld_b_a8};
	op_tab[0x0e] = (struct inst_s) {"LD C A8",		0x0e, 1, 1, ld_c_a8};
	op_tab[0x21] = (struct inst_s) {"LD HL A16",	0x21, 1, 2, ld_hl_a16};
	op_tab[0x31] = (struct inst_s) {"LD SP A16",	0x31, 1, 2, ld_sp_a16};
	op_tab[0x3e] = (struct inst_s) {"LD A A8",		0x3e, 1, 1, ld_a_a8};
	op_tab[0xc3] = (struct inst_s) {"JP A16",		0xc3, 1, 2, jp_a16};
	op_tab[0xaf] = (struct inst_s) {"XOR A",		0xaf, 1, 0, xor_a};
	op_tab[0xf3] = (struct inst_s) {"DI",			0xf3, 1, 0, di};
	op_tab[0xfb] = (struct inst_s) {"EI",			0xfb, 1, 0, ei};
}