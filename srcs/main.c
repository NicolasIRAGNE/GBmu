/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 11:37:03 by niragne           #+#    #+#             */
/*   Updated: 2020/05/23 19:31:29 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "gb.h"
#include "renderer.h"
#include "SDL.h"
#include "SDL_video.h"
#include "cpu.h"
#include "mbc.h"
#include "renderer/wrapper_c/wrapper.h"
#ifdef WITH_LIBYACC
# include "libyacc_wrapper.h"
#endif
// #include <pthread.h>
#include <signal.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

struct gb_cpu_s*	gb_global;

void	sigint_handler(int foo)
{
	(void)foo;
	printf("Received SIGINT\n");
	gb_global->paused = 1;
}

int		main(int ac, char** av)
{
	struct rom_s rom;
	struct gb_cpu_s gb;
	struct gbmu_debugger_s debugger;
	struct sdl_context_s vram_viewer_context;
	struct sdl_context_s main_window_context;
	gb_global = &gb;
#ifndef WITH_LIBYACC
	debugger.breakpoints = NULL;
	debugger.verbose_level = DEFAULT_VERBOSE;
#endif

	if (ac < 2)
	{
		fprintf(stderr, "usage: %s <rom>\n", av[0]);
		return (1);
	}

	if (open_rom(av[1], &rom))
		return (1);
		
	rom.header = (uint8_t*)rom.ptr + 0x100;
	debug_print_rom(&rom);

	if (init_cpu(&gb, &rom))
		return (1);
	
#ifdef WITH_LIBYACC
	if ((libyacc_init_debugger(&gb, &debugger)) == EXIT_FAILURE)
		return 1;
#else
	debugger.breakpoints = NULL;
#endif	

	gb.debugger = &debugger;
	update_current_instruction(&gb);
	init_op_tab();
	init_ext_op_tab();
	
	if (init_sdl())
		return (1);
 #ifndef __SANITIZE_ADDRESS__
	atexit(SDL_Quit);
 #endif
	// if (init_vram_viewer(&vram_viewer_context))
		// return (1);
	if (init_main_window(&main_window_context))
		return (1);
	load_game(&gb);
	signal(SIGINT, sigint_handler);

	void*	renderer = new_renderer(&gb);
	renderer_init(renderer);
	int window_width;
	int window_height;
	SDL_GetWindowSize(main_window_context.win, &window_width, &window_height);
	renderer_set_window_size(renderer, window_width, window_height);
	execute_loop(&(struct gbmu_wrapper_s){&gb, &vram_viewer_context, &main_window_context}, renderer);
	delete_renderer(renderer);
	if (gb.mbc.ram_size > 0)
		save_game(&gb);
	free(rom.ptr);
	free(gb.extra_ram);

	destroy_context(&main_window_context);
	// SDL_Quit();
	return (0);
}
