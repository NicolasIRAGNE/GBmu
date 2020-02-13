/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 11:10:03 by niragne           #+#    #+#             */
/*   Updated: 2020/02/13 11:19:33 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include <stdio.h>

int		cb_n(struct gb_cpu_s* gb)
{
	uint8_t op = gb->current_instruction->args;
	struct ext_inst_s* inst;

	inst = ext_op_tab + op;
	if (inst->exec)
	{
		inst->exec(gb);
	}
	else
	{
		printf("EXTENDED OPCODE %x NOT IMPLEMENTED\n", op);
		gb->running = 0;
	}
	
}
