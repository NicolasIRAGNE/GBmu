/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 11:37:03 by niragne           #+#    #+#             */
/*   Updated: 2020/04/30 11:05:57 by niragne          ###   ########.fr       */
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
	int fd;
	int ret;

	ret = stat(name, &rom->st);
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
	
	uint8_t* buf = malloc(rom->st.st_size);
	if (!buf)
	{
		perror("malloc");
		return (1);
	}
	int rd = read(fd, buf, rom->st.st_size);
	if (rd < 0 || rd != rom->st.st_size)
	{
		perror(name);
		return (1);
	}
	rom->ptr = buf;
	return (0);
}

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
	debugger.breakpoints = NULL;
	debugger.verbose_level = DEFAULT_VERBOSE;
	
	if (ac < 2)
	{
		fprintf(stderr, "usage: %s <rom>\n", av[0]);
		return (1);
	}

	if (open_rom(av[1], &rom))
		return (1);
		
	rom.header = rom.ptr + 0x100;
	debug_print_rom(&rom);

	if (init_cpu(&gb, &rom))
		return (1);
	gb.debugger = &debugger;
	update_current_instruction(&gb);
	init_op_tab();
	init_ext_op_tab();
	
	if (init_sdl())
		return (1);
	if (init_vram_viewer(&vram_viewer_context))
		return (1);
	if (init_main_window(&main_window_context))
		return (1);
	load_game(&gb);
	signal(SIGINT, sigint_handler);

	void*	renderer = new_renderer(&gb);
	renderer_init(renderer);
	execute_loop(&(struct gbmu_wrapper_s){&gb, &vram_viewer_context, &main_window_context}, renderer);
	delete_renderer(renderer);
	destroy_context(&main_window_context);
	if (gb.mbc.ram_size > 0)
		save_game(&gb);
	free(rom.ptr);
	free(gb.extra_ram);
	return (0);
}