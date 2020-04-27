/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_window_loop.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 14:11:30 by niragne           #+#    #+#             */
/*   Updated: 2020/04/27 16:17:17 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"

int		display_test(struct gbmu_wrapper_s* wrapper, struct tile_s* array, SDL_Surface* tmp_surface)
{
	uint8_t lcdc = (read_8(wrapper->gb, LCDC_OFFSET)) ;

	update_palettes(wrapper->gb);

	display_background(wrapper, lcdc, array, tmp_surface);
	display_sprites(wrapper, lcdc, array);
	return (0);
}

void	main_window_loop(struct gbmu_wrapper_s* wrapper, void* renderer)
{
	SDL_Event event;

   	while (SDL_PollEvent(&event)) 
	{
   		if (event.type == SDL_KEYDOWN)
		{
			if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
				wrapper->gb->running = 0;
			if (event.key.keysym.scancode == SDL_SCANCODE_SPACE)
				wrapper->gb->paused = 1;
		}
   	}
	if (!wrapper->gb->paused)
		handle_joypad(wrapper->gb, wrapper->main_context->controller);
}