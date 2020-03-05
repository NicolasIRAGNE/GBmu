/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vram_viewer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 13:46:09 by niragne           #+#    #+#             */
/*   Updated: 2020/03/05 14:31:51 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"

int		display_vram(struct gbmu_wrapper_s* wrapper, struct tile_s* array)
{
	int i = 0;
	int index = 0;

	while (i < TILE_SIZE * TILES_COUNT)
	{
		if (print_tile(wrapper->vram_viewer_context, array + index, index, VRAM_SURFACE_WIDTH, 16))
			return (1);
		i += TILE_SIZE;
		index += 1;
	}
	return (0);
}

void	vram_viewer_loop(struct gbmu_wrapper_s* wrapper, struct tile_s* array)
{
	SDL_Event event;
   	while (SDL_PollEvent(&event)) 
	{
   		if (event.type == SDL_KEYDOWN)
		{
			if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
				wrapper->gb->running = 0;
		}
   	}
	Uint32 *pixels;
	pixels = wrapper->vram_viewer_context->surface->pixels;
	if (display_vram(wrapper, array))
	{
		printf("jette toi dans lcanal\n");
		wrapper->gb->running = 0;
	}
	wrapper->vram_viewer_context->texture = SDL_CreateTextureFromSurface(wrapper->vram_viewer_context->renderer, wrapper->vram_viewer_context->surface);
	SDL_RenderCopy(wrapper->vram_viewer_context->renderer, wrapper->vram_viewer_context->texture, NULL, NULL);
	SDL_RenderPresent(wrapper->vram_viewer_context->renderer);
	SDL_DestroyTexture(wrapper->vram_viewer_context->texture);
}
