/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 15:18:26 by niragne           #+#    #+#             */
/*   Updated: 2020/02/04 16:43:45 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gb.h"
#include <stdio.h>
#include <stdlib.h>

uint8_t	update_current_instruction(struct gb_cpu_s* gb)
{
	uint16_t pc = gb->reg.pc;
	uint8_t* ptr = gb->rom_ptr->ptr;
	uint8_t op = ptr[pc];
	gb->current_instruction = op_tab + op;
	if (gb->current_instruction->size == 1)
		gb->current_instruction->args = ptr[pc + 1];
	else if (gb->current_instruction->size == 2)
		gb->current_instruction->args = ptr[pc + 1] | (ptr[pc + 2] << 8);
	return (op);
}

int		handle_instruction(struct gb_cpu_s* gb)
{
	uint8_t op;
	op = update_current_instruction(gb);
	debug_print_gb(gb);
	if (gb->current_instruction->exec)
	{
		gb->current_instruction->exec(gb);
	}
	else
	{
		printf("OPCODE %0x NOT IMPLEMENTED\n", op);
		return(1);
	}
	if (!gb->jmp)
		gb->reg.pc += gb->current_instruction->size + 1;
	else
		gb->jmp = 0;

	return (0);
}