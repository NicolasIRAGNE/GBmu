/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_window_loop.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 14:11:30 by niragne           #+#    #+#             */
/*   Updated: 2020/04/09 17:58:45 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"

int		display_test(struct gbmu_wrapper_s* wrapper, struct tile_s* array)
{
	int i = 0;
	int index = 0;
	uint8_t	lcdc;

	while (i < BGMAP_SIZE)
	{
		lcdc = read_8(wrapper->gb, LCDC_OFFSET);
		(void)lcdc;
		SDL_Rect pos = (SDL_Rect) {(index * TILE_SURFACE_WIDTH) % (MAIN_SURFACE_WIDTH), (index / 32) * TILE_SURFACE_HEIGHT, TILE_SURFACE_WIDTH, TILE_SURFACE_HEIGHT};
		print_tile(wrapper->main_context, array + wrapper->gb->vram[BGMAP1_OFFSET + i], index, pos);
		i++;
		index++;
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
				wrapper->gb->paused = 1;
		}
   	}
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