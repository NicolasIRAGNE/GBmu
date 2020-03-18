/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 11:37:03 by niragne           #+#    #+#             */
/*   Updated: 2020/03/18 13:34:40 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "gb.h"
#include "renderer.h"
#include <pthread.h>
#include <signal.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

struct gb_cpu_s*	gb_global;

int		open_rom(char* name, struct rom_s* rom)
{
	struct stat st;
	int fd;
	int ret;

	ret = stat(name, &st);
	if (ret)
	{
		perror(name);
		return (ret);
	}

	fd = open(name, O_RDONLY);
	if (fd < 0)
	{
		perror(name);
		return (fd);
	}
	
	void* ptr = mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
	if (!ptr)
	{
		perror("mmap");
		return (1);
	}
	rom->ptr = ptr;

	return (0);
}

void	sigint_handler(int foo)
{
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
	debugger.breakpoints = NULL;
	
	if (ac < 2)
	{
		fprintf(stderr, "usage: %s <rom>\n", av[0]);
		return (1);
	}

	if (open_rom(av[1], &rom))
		return (1);
		
	rom.header = rom.ptr + 0x100;
	debug_print_rom(&rom);

	if (init_cpu(&gb))
		return (1);
	gb.rom_ptr = &rom;
	gb.debugger = &debugger;
	update_current_instruction(&gb);
	init_op_tab();
	init_ext_op_tab();
	
	int err;
	err = 0;

	pthread_t thread;

	if (init_sdl())
		return (1);
	if (init_vram_viewer(&vram_viewer_context))
		return (1);
	if (init_main_window(&main_window_context))
		return (1);
	// atexit(SDL_Quit);
	signal(SIGINT, sigint_handler);
	pthread_create (&thread, NULL, execute_thread_entry , &gb);
	renderer_loop(&(struct gbmu_wrapper_s){&gb, &vram_viewer_context, &main_window_context});
	pthread_join(thread, NULL);
	// SDL_DestroyWindow(context.win);
	// SDL_DestroyRenderer(context.renderer);
	// SDL_DestroyTexture(context.texture);

	return (0);
}