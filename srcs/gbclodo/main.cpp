/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 11:37:03 by niragne           #+#    #+#             */
/*   Updated: 2022/01/05 03:57:27 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <cxxopts.hpp>
#include <functional>

extern "C" {
#include "gb.h"
#include "debug.h"
#include "renderer.h"
#include "SDL.h"
#include "SDL_video.h"
#include "cpu.h"
#include "mbc.h"
#include "renderer/wrapper_c/wrapper.h"
#include "gbclodo.h"
#ifdef WITH_LIBYACC
# include "libyacc_wrapper.h"
#else
# include "fallback_debugger.h"
#endif
// #include <pthread.h>
}
#include <signal.h>

void	signal_handler(int signal)
{
    if (signal == SIGINT)
    {
	    printf("Received SIGINT\n");
	    gb_global.paused = 1;
    }
}

int		main(int ac, char** av)
{
	struct rom_s rom;
	struct gbmu_debugger_s debugger;
	struct sdl_context_s vram_viewer_context;
	struct sdl_context_s main_window_context;

#ifndef WITH_LIBYACC
	debugger.breakpoints = NULL;
	debugger.verbose_level = DEFAULT_VERBOSE;
#endif

	cxxopts::Options options(av[0], "Very wonky GameBoy emulator");

	options.add_options()
	("f,file", "Rom name", cxxopts::value<std::string>())
	("v,verbose", "Verbose output", cxxopts::value<bool>()->default_value("false"))
	("m,mode", "Mode", cxxopts::value<std::string>()->default_value("auto"))
	("h,help", "Print help");
	;

	cxxopts::ParseResult result;

	try
	{
		result = options.parse(ac, av);
	}
	catch (const cxxopts::OptionException& e)
	{
		std::cout << "error parsing options: " << e.what() << std::endl;
		return (1);
	}

	std::string filename;
	if (result.count("file") == 0)
	{
		auto u = result.unmatched();
		if (u.size() == 1)
			filename = u[0];
	}
	else
	{
		try {
			filename = result["file"].as<std::string>();
		}
		catch (const cxxopts::OptionException& e)
		{
			std::cout << "Error parsing options: " << e.what() << std::endl;
			return (1);
		}
	}
	if (filename.empty())
	{
		fprintf(stderr, "usage: %s <rom>\n", av[0]);
		return (1);
	}

	if (open_rom(filename.data(), &rom))
		return (1);
		
	debug_print_rom(&rom);

	enum gb_mode_e mode;
	auto modeopt = result["mode"].as<std::string>();
	if (modeopt == "auto")
		mode = GB_MODE_AUTO;
	else if (modeopt == "dmg")
		mode = GB_MODE_DMG;
	else if (modeopt == "cgb")
		mode = GB_MODE_CGB;
	else
	{
		fprintf(stderr, "Invalid mode: %s\n", modeopt.data());
		return (1);
	}

	if (init_cpu(&gb_global, &rom, mode))
		return (1);
	
#ifdef WITH_LIBYACC
	if ((libyacc_init_debugger(&gb_global, &debugger)) == EXIT_FAILURE)
		return 1;
#else
	debugger.breakpoints = NULL;
#endif	

	gb_global.debugger = &debugger;
	update_current_instruction(&gb_global);
	init_op_tab();
	init_ext_op_tab();
	
	if (init_sdl())
		return (1);
 #ifndef __SANITIZE_ADDRESS__
	atexit(SDL_Quit);
 #endif
	if (init_vram_viewer(&vram_viewer_context))
		return (1);
	if (init_main_window(&main_window_context))
		return (1);
	load_game(&gb_global);
	signal(SIGINT, signal_handler);

	void*	renderer = new_renderer(&gb_global);
	int window_width;
	int window_height;
	SDL_GetWindowSize(main_window_context.win, &window_width, &window_height);
	renderer_set_window_size(renderer, window_width, window_height);
	struct gbmu_wrapper_s wrapper = {&gb_global, &vram_viewer_context, &main_window_context};
	execute_loop(&wrapper, renderer);
	
	// dump_mbc(&gb_global);
	delete_renderer(renderer);
	if (gb_global.mbc.ram_size > 0)
		save_game(&gb_global);
	free(rom.ptr);
	free(gb_global.extra_ram);

	destroy_context(&main_window_context);
	// SDL_Quit();
	return (0);
}
