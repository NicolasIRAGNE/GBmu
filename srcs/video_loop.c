/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   video_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 13:27:32 by niragne           #+#    #+#             */
/*   Updated: 2020/02/23 13:10:57 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gb.h"
#include "renderer.h"

uint32_t	get_color_from_palette(uint8_t byte, uint8_t mask)
{
	// uint32_t palette[4] = 
	// {
		// 0xffffffff, 0xff0000ff, 0x00ff00ff, 0x0000ffff
	// };

	uint32_t palette[4] = 
	{
		0, 0xffffffff, 0xffffffff, 0xffffffff
	};
	
	uint32_t ret;
	uint8_t	index;

	index = byte & (0b11 << mask);
	index >>= mask;
	return (palette[index]);

}

void	create_tile(struct gbmu_wrapper_s* wrapper)
{
	int i = 0;
	int j = 0;
	int k = 0;
	uint8_t byte;

	uint32_t* pixels = wrapper->context->surface->pixels;
	byte = wrapper->gb->vram[k];
	
	while (i < 144)
	{
		while (j < 40)
		{
			uint32_t pixel;
			uint8_t mask;
			pixels[i * 160 + (j * 4) + 0] = get_color_from_palette(wrapper->gb->vram[k], 0);
			pixels[i * 160 + (j * 4) + 1] = get_color_from_palette(wrapper->gb->vram[k], 1);
			pixels[i * 160 + (j * 4) + 2] = get_color_from_palette(wrapper->gb->vram[k], 2);
			pixels[i * 160 + (j * 4) + 3] = get_color_from_palette(wrapper->gb->vram[k], 3);
			j+=1;
			k++;
		}
		j = 0;
		i++;
	}
	
}

void	video_loop(struct gbmu_wrapper_s* wrapper)
{
	wrapper->context->surface = SDL_CreateRGBSurface(0, 160, 144, 32, 0, 0, 0, 0);
	if (!wrapper->context->surface)
	{
		fprintf(stderr, "failed to create surface (%s)\n", SDL_GetError());
		return ;
	}

	wrapper->context->texture = SDL_CreateTextureFromSurface(wrapper->context->renderer, wrapper->context->surface);
	if (!wrapper->context->texture)
	{
		fprintf(stderr, "failed to create texture (%s)\n", SDL_GetError());
		return ;
	}

	while (wrapper->gb->running)
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
		pixels = wrapper->context->surface->pixels;
		create_tile(wrapper);
		wrapper->context->texture = SDL_CreateTextureFromSurface(wrapper->context->renderer, wrapper->context->surface);
		SDL_RenderClear(wrapper->context->renderer);
		SDL_RenderCopy(wrapper->context->renderer, wrapper->context->texture, NULL, NULL);
		SDL_RenderPresent(wrapper->context->renderer);
		SDL_DestroyTexture(wrapper->context->texture);
	}
}

void*	thread_entry(void* user_data)
{
	video_loop((struct gbmu_wrapper_s*) user_data);
	return (NULL);
}

