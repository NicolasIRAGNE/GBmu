/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 15:18:26 by niragne           #+#    #+#             */
/*   Updated: 2020/03/24 16:28:56 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gb.h"
#include <stdio.h>
#include <stdlib.h>

uint8_t	update_current_instruction(struct gb_cpu_s* gb)
{
	uint16_t pc = gb->reg.pc;
	uint8_t op = read_8(gb, pc);
	gb->current_instruction = op_tab + op;
	if (gb->current_instruction->size == 1)
		gb->current_instruction->args = read_8(gb, pc + 1);
	else if (gb->current_instruction->size == 2)
		gb->current_instruction->args = read_16(gb, pc + 1);
	return (op);
}

void	execute_loop(struct gb_cpu_s* gb)
{
	int err = 0;

	while(gb->running)
	{
		if (gb->interrupt)
		{
			interrupt_a16(gb, gb->interrupt);
			gb->interrupt = 0;
		}
		if (gb->paused)
			parse_command(gb);
		else if (1)
			err = handle_instruction(gb);
		gpu_tick(gb);

		if (err)
			gb->paused = 1;
	}
}

void*	execute_thread_entry(void* user_data)
{
	execute_loop((struct gb_cpu_s*) user_data);
	return (NULL);
}

int		handle_instruction(struct gb_cpu_s* gb)
{
	uint8_t op;
	op = update_current_instruction(gb);
	// debug_print_gb(gb);

	if (find_breakpoint(gb->debugger->breakpoints, gb->reg.pc) && !gb->paused)
	{
		gb->paused = 1;
		return (0);
	}

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
	gb->cycle += gb->current_instruction->cycles;
	return (0);
}