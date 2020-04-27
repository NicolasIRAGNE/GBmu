/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 15:18:26 by niragne           #+#    #+#             */
/*   Updated: 2020/04/27 16:45:41 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gb.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "renderer.h"

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

int		set_interrupt(struct gb_cpu_s* gb)
{
	int ret = 0;
	uint8_t interrupt_requests = read_8(gb, IF_OFFSET);
	if (interrupt_requests & INT_VBLANK_REQUEST)
	{
		if (gb->interrupt_enable_register & INT_VBLANK_REQUEST)
		{
			gb->interrupt = INT_VBLANK_ADDR;
			interrupt_requests &= ~INT_VBLANK_REQUEST;
			ret = INT_VBLANK_ADDR;
		}
	}
	else if (interrupt_requests & INT_STAT_REQUEST)
	{
		if (gb->interrupt_enable_register & INT_STAT_REQUEST)
		{
			gb->interrupt = INT_STAT_ADDR;
			interrupt_requests &= ~INT_STAT_REQUEST;
			ret = INT_STAT_ADDR;
		}
	}
	else if (interrupt_requests & INT_TIMER_REQUEST)
	{
		if (gb->interrupt_enable_register & INT_TIMER_REQUEST)
		{
			gb->interrupt = INT_TIMER_ADDR;
			interrupt_requests &= ~INT_TIMER_REQUEST;
			ret = INT_TIMER_ADDR;
		}
	}
	if (ret)
		write_8(gb, IF_OFFSET, interrupt_requests);
	return (ret);
}

void	execute_loop(struct gbmu_wrapper_s* wrapper, void* renderer)
{
	int err = 0;
	uint64_t last_sleep = 0;
	struct gb_cpu_s* gb = wrapper->gb;
	uint8_t last_line = 0;

	while(gb->running)
	{
		if (gb->ime && set_interrupt(gb))
		{
			interrupt_a16(gb, gb->interrupt);
			gb->interrupt = 0;
		}
		if (gb->paused)
			parse_command(gb);
		else if (1)
			err = handle_instruction(gb);
		if (err)
			gb->paused = 1;
		if (gb->cycle - last_sleep >= 50)
		{
			last_line = gb->gpu.y_coord;
			gpu_tick(gb);
			last_sleep = gb->cycle;
			// usleep(1);
			if (gb->gpu.y_coord != last_line)
				renderer_render(renderer);
		}
		if (wrapper->gb->gpu.y_coord == 143 && last_line != 143)
		{
			main_window_loop(wrapper, renderer);
			SDL_GL_SwapWindow(wrapper->main_context->win);
		}
	}
	if (gb->mbc.ram_size > 0)
		save_game(gb);
	free(gb->extra_ram);
}

// void*	execute_thread_entry(void* user_data)
// {
// 	execute_loop((struct gb_cpu_s*) user_data);
// 	return (NULL);
// }

int		handle_instruction(struct gb_cpu_s* gb)
{
	uint16_t tima;

	uint8_t op = update_current_instruction(gb);
	if (gb->debugger->verbose_level > 0)
			debug_print_gb(gb);
	
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

	// timer thing
	tima = read_8(gb, TIMA_OFFSET);
	tima += 1;

	if (tima > 0xff)
	{
		uint8_t interrupt_requests = read_8(gb, IF_OFFSET);
		(void)interrupt_requests;
		write_8(gb, IF_OFFSET, interrupt_requests | INT_TIMER_REQUEST);
	}
	write_8(gb, TIMA_OFFSET, tima);
	return (0);
}