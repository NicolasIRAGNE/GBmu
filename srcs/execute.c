/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 15:18:26 by niragne           #+#    #+#             */
/*   Updated: 2020/06/14 13:52:33 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gb.h"
#include "SDL_surface.h"
#include "SDL_video.h"
#include "cpu.h"
#include "op.h"
#include "renderer/wrapper_c/wrapper.h"
#ifdef WITH_LIBYACC
# include "libyacc_wrapper.h"
#endif
#include <stdio.h>
#include <stdint.h>

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

void	request_interrupt(struct gb_cpu_s* gb, uint8_t request)
{
	uint8_t interrupt_requests = read_8_force(gb, IF_OFFSET);
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

void	execute_loop(struct gbmu_wrapper_s* wrapper, void* renderer)
{
	int err = 0;
	struct gb_cpu_s* gb = wrapper->gb;
	uint8_t last_line = 0;
	uint8_t	last_line_drawn = 0;
	uint8_t	last_pixel_drawn = 0;
    // SDL_Surface* tmp_surface = SDL_CreateRGBSurface(0, BGMAP_SIZE, BGMAP_SIZE, 32, 0, 0, 0, 0);
	struct tile_s tiles[TILES_COUNT];
	while (gb->running)
	{
		if (set_interrupt(gb))
		{
			if (gb->ime)
			{
				interrupt_a16(gb, gb->interrupt);
				gb->interrupt = 0;
			}
		}
		if (gb->paused)
			execute_debugger(gb);
		else
			err = handle_instruction(gb);
		if (err)
			gb->paused = 1;

		if (gb->gpu.y_coord < 144 && (last_line_drawn != gb->gpu.y_coord || last_pixel_drawn != gb->gpu.x_coord))
		{
			uint8_t lcdc = (read_8(gb, LCDC_OFFSET));
			if ((lcdc & LCDC_ON) || !gb->booted)
			{
				for (int i = last_pixel_drawn; i < gb->gpu.x_coord; i++) {
					renderer_draw_pixel(renderer, gb->gpu.y_coord, i);
				}
			}
			last_pixel_drawn = gb->gpu.x_coord;
			last_line_drawn = gb->gpu.y_coord;
		}
		last_line = gb->gpu.y_coord;
		gpu_tick(gb);
		if (wrapper->gb->gpu.y_coord == 144 && last_line != 144)
		{
			uint8_t lcdc = (read_8(gb, LCDC_OFFSET));
			if (!(lcdc & LCDC_ON) && gb->booted)
			{
				// renderer_clear(renderer);
			}
			if (wrapper->gb->vram_viewer_running)
			{
				update_palettes(wrapper->gb);
				fill_tile_array(wrapper->gb, tiles);
				vram_viewer_loop(wrapper, tiles);
			}
			// if (!gb->halted)
				renderer_render(renderer);
			SDL_GL_SwapWindow(wrapper->main_context->win);
			// renderer_clear(renderer);
			last_line_drawn = 0;
		}
		if (gb->cycle - gb->last_sleep > (70224 / 4))
		{
			// usleep(128);
			main_window_loop(wrapper, renderer);
			gb->last_sleep = gb->cycle;
		}
		update_div_register(gb);
		update_timer_register(gb);
	}
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
		gb->cycle += 4;

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
		// fatal(gb);
		// return (1);
	}
	if (!gb->jmp)
		gb->reg.pc += gb->current_instruction->size + 1;
	else
		gb->jmp = 0;
	gb->cycle += gb->current_instruction->cycles ;
	return (0);
}
