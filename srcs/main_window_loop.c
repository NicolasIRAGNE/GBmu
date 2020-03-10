/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_window_loop.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 14:11:30 by niragne           #+#    #+#             */
/*   Updated: 2020/03/10 14:08:18 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"

int		display_test(struct gbmu_wrapper_s* wrapper, struct tile_s* array)
{
	int i = 0;
	int index = 0;

	while (i < TILE_SIZE * 20 * 18)
	{
		if (print_tile(wrapper->main_context, array + index, index, MAIN_SURFACE_WIDTH, 20))
		{
			printf("kesta %d\n", i);
			return (1);
		}
		i += TILE_SIZE;
		index += 1;
	}
	return (0);
}

void	main_window_loop(struct gbmu_wrapper_s* wrapper, struct tile_s* array)
{
	SDL_Event event;
   	while (SDL_PollEvent(&event)) 
	{
   		if (event.type == SDL_KEYDOWN)
		{
			if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
				wrapper->gb->running = 0;
			if (event.key.keysym.scancode == SDL_SCANCODE_SPACE)
				wrapper->gb->paused = !wrapper->gb->paused ;
		}
   	}
	Uint32 *pixels;
	pixels = wrapper->main_context->surface->pixels;
	if (display_test(wrapper, array))
	{
		printf("jette toi dans lcanal\n");
		wrapper->gb->running = 0;
	}
	wrapper->main_context->texture = SDL_CreateTextureFromSurface(wrapper->main_context->renderer, wrapper->main_context->surface);
	SDL_RenderCopy(wrapper->main_context->renderer, wrapper->main_context->texture, NULL, NULL);
	SDL_RenderPresent(wrapper->main_context->renderer);
	SDL_DestroyTexture(wrapper->main_context->texture);
}