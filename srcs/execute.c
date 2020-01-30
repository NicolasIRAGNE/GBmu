/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 15:18:26 by niragne           #+#    #+#             */
/*   Updated: 2020/01/30 17:18:44 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gb.h"
#include <stdio.h>
#include <stdlib.h>


int		handle_instruction(struct gb_cpu_s* gb)
{
	uint16_t pc = gb->reg.pc;
	uint8_t* ptr = gb->rom_ptr->ptr;
	uint8_t op = ptr[pc];
	gb->current_instruction = op_tab + op;
	printf("CURRENT PC: %hx\n", gb->reg.pc);
	if (gb->current_instruction->exec)
	{
		printf("CURRENT INSTRUCTION : %s\n", gb->current_instruction->name);
		gb->current_instruction->exec(gb);
	}
	else
	{
		printf("OPCODE %0x NOT IMPLEMENTED\n", op);
		exit(1);
	}
	
}