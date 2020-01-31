/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_op_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 16:16:07 by niragne           #+#    #+#             */
/*   Updated: 2020/01/31 11:26:26 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

struct inst_s	op_tab[256] = 
{	
	{0}
};

void	init_op_tab()
{
	op_tab[0x00] = (struct inst_s) {"NOP",		0x00, 1, 0, nop};
	op_tab[0xc3] = (struct inst_s) {"JP A16",	0xc3, 1, 2, jp_a16};
	op_tab[0xaf] = (struct inst_s) {"XOR A",	0xaf, 1, 0, xor_a};
}