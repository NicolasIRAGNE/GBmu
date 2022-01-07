/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 15:18:26 by niragne           #+#    #+#             */
/*   Updated: 2022/01/07 08:22:17 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gb.h"
#include "cpu.h"
#include "op.h"
#include "debug.h"
#ifdef WITH_LIBYACC
# include "libyacc_wrapper.h"
#else
# include "fallback_debugger.h"
#endif
#include <stdio.h>
#include <stdint.h>
#include "draw.h"

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

void	request_interrupt(struct gb_cpu_s* gb, uint8_t request)
{
	uint8_t interrupt_requests = read_8_force(gb, IF_OFFSET);
	gb->halted = 0;
	write_8(gb, IF_OFFSET, interrupt_requests | request);
}

int		set_interrupt(struct gb_cpu_s* gb)
{
	int ret = 0;
	uint8_t interrupt_requests = read_8(gb, IF_OFFSET);
	if (interrupt_requests & INT_TIMER_REQUEST && gb->interrupt_enable_register & INT_TIMER_REQUEST)
	{
		gb->interrupt = INT_TIMER_ADDR;
		interrupt_requests &= ~INT_TIMER_REQUEST;
		ret = INT_TIMER_ADDR;
	}
	else if (interrupt_requests & INT_VBLANK_REQUEST && gb->interrupt_enable_register & INT_VBLANK_REQUEST)
	{
		gb->interrupt = INT_VBLANK_ADDR;
		interrupt_requests &= ~INT_VBLANK_REQUEST;
		ret = INT_VBLANK_ADDR;
	}
	else if (interrupt_requests & INT_STAT_REQUEST && gb->interrupt_enable_register & INT_STAT_REQUEST)
	{
		gb->interrupt = INT_STAT_ADDR;
		interrupt_requests &= ~INT_STAT_REQUEST;
		ret = INT_STAT_ADDR;
	}
	else if (interrupt_requests & INT_SERIAL_REQUEST && gb->interrupt_enable_register & INT_SERIAL_REQUEST)
	{
		gb->interrupt = INT_SERIAL_ADDR;
		interrupt_requests &= ~INT_SERIAL_REQUEST;
		ret = INT_SERIAL_ADDR;
	}
	if (ret)
	{
		if (gb->ime)
			write_8_force(gb, IF_OFFSET, interrupt_requests);
	}
	return (ret);
}

// void*	execute_thread_entry(void* user_data)
// {
// 	execute_loop((struct gb_cpu_s*) user_data);
// 	return (NULL);
// }

int		handle_instruction(struct gb_cpu_s* gb)
{
	uint8_t op = update_current_instruction(gb);
	if (gb->halted)
	{
		gb->cycle += 1;

		return (0);
	}

	if (get_verbose(gb->debugger) >= 1)
			debug_print_gb(gb);

	if (find_breakpoint(gb->debugger, gb->reg.pc) && !gb->paused)
	{
		gb->paused = 1;
		debug_print_gb(gb);
		// return (0);
	}

	if (gb->current_instruction->exec)
	{
		gb->current_instruction->exec(gb);
	}
	else
	{
		debug_print_gb(gb);
		printf("fatal: illegal hardware instruction %x. aborting...\n", op);
		fatal(gb);
		return (1);
	}
	if (!gb->jmp)
		gb->reg.pc += gb->current_instruction->size + 1;
	else
		gb->jmp = 0;
	gb->cycle += gb->current_instruction->cycles;
	return (0);
}

int cpu_step()
{
    struct gb_cpu_s* gb = &gb_global;

	int err = 0;
	int res = 0;
	uint8_t y_coord_save = gb->gpu.y_coord;
	uint8_t x_coord_save = gb->gpu.x_coord;
    if (set_interrupt(gb))
    {
        // gb->halted = 0;
        if (gb->ime)
        {
            interrupt_a16(gb, gb->interrupt);
            gb->interrupt = 0;
        }
    }
    err = handle_instruction(gb);
    if (err)
	{
        gb->paused = 1;
		return (-1);
	}
	if (gb->gpu.y_coord < 144 && (gb->last_y != gb->gpu.y_coord || gb->last_x != gb->gpu.x_coord))
	{
		uint8_t lcdc = (read_8(gb, LCDC_OFFSET));
		if ((lcdc & LCDC_ON) || !gb->booted)
		{
			for (int i = gb->last_x; i < gb->gpu.x_coord; i++) {
				DrawPixel(gb->gpu.y_coord, i);
			}
		}
		gb->last_x = gb->gpu.x_coord;
		gb->last_y = gb->gpu.y_coord;
	}
    gpu_tick(gb);
    if (gb->gpu.y_coord == 144 && y_coord_save != 144)
    {
		// Frame is ready to be drawn.
		res = 1;
    }
    update_div_register(gb);
    update_timer_register(gb);
	if (gb->mbc.attr & MBC_ATTR_TIMER)
		update_rtc(gb);
	// debug_print_gb(gb);
	return (res);
}
