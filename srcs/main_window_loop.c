/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_window_loop.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 14:11:30 by niragne           #+#    #+#             */
/*   Updated: 2020/05/12 12:27:49 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdint.h>

#include "renderer.h"
#include "input_functions.h"
#include "SDL_events.h"
#include "SDL_keyboard.h"
#include "SDL_stdinc.h"
#include "SDL_surface.h"
#include "SDL_video.h"
#include "cpu.h"
#include "gb.h"
#ifdef WITH_HWACCEL
# include "renderer/wrapper_c/wrapper.h"
#endif

int		display_test(struct gbmu_wrapper_s* wrapper, struct tile_s* array, SDL_Surface* tmp_surface)
{
	uint8_t lcdc = (read_8(wrapper->gb, LCDC_OFFSET)) ;

	update_palettes(wrapper->gb);

	display_background(wrapper, lcdc, array, tmp_surface);
	display_sprites(wrapper, lcdc, array);
	return (0);
}

void	main_window_loop(struct gbmu_wrapper_s* wrapper)
{
	SDL_Event event;
	const Uint8 *state = SDL_GetKeyboardState(NULL);

	// printf("main_window_loop\n");
		while (SDL_PollEvent(&event)) 
		{
   			if (event.type == SDL_KEYDOWN)
			{
				input_functions[event.key.keysym.scancode](wrapper);
				//TODO FIXME
				check_savestate(wrapper->gb, state, event);
			}
			// else if (event.type == SDL_WINDOWEVENT) {
			// 	if (event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED) {
			// 		renderer_set_window_size(wrapper->renderer, event.window.data1, event.window.data2);
			// 	}
			// }
			else if (event.type == SDL_QUIT)
			{
				wrapper->gb->running = 0;
			}
   		}
		if (!wrapper->gb->paused)
		{
			handle_joypad(wrapper->gb, wrapper->main_context->controller, state);
		}
	    SDL_SetRenderDrawColor( wrapper->main_context->renderer, 255, 0, 0, 255 );
		SDL_RenderClear( wrapper->main_context->renderer );
    	SDL_RenderPresent(wrapper->main_context->renderer);
}
