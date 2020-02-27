/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   video_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 13:27:32 by niragne           #+#    #+#             */
/*   Updated: 2020/02/27 13:08:38 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gb.h"
#include "renderer.h"

uint32_t	get_color_from_palette(uint8_t byte, uint8_t mask)
{
	uint32_t palette[4] = 
	{
		0x0000000, 0xff0000ff, 0x00ff00ff, 0x0000ffff
	};

	// uint32_t palette[4] = 
	// {
		// 0, 0xffffffff, 0xffffffff, 0xffffffff
	// };
	
	uint32_t ret;
	uint8_t	index;

	index = byte & (0b11 << mask);
	index >>= mask;
	return (palette[index]);

}

struct tile_s	create_tile(struct gbmu_wrapper_s* wrapper, uint16_t index)
{
	struct tile_s ret;
	
	int i = 0;
	int j = 0;
	int k = 0;
	uint8_t msb;
	uint16_t msb_tmp;
	uint8_t lsb;
	uint16_t lsb_tmp;
	uint16_t test;

	while (i < 8)
	{
		msb = wrapper->gb->vram[index + k];
		lsb = wrapper->gb->vram[index + k + 1];

		msb_tmp = ((msb & 0b00000001) << 1)
				| ((msb & 0b00000010) << 2)
				| ((msb & 0b00000100) << 3)
				| ((msb & 0b00001000) << 4)
				| ((msb & 0b00010000) << 5)
				| ((msb & 0b00100000) << 6)
				| ((msb & 0b01000000) << 7)
				| ((msb & 0b10000000) << 8);
		
		lsb_tmp = ((lsb & 0b00000001) << 0)
				| ((lsb & 0b00000010) << 1)
				| ((lsb & 0b00000100) << 2)
				| ((lsb & 0b00001000) << 3)
				| ((lsb & 0b00010000) << 4)
				| ((lsb & 0b00100000) << 5)
				| ((lsb & 0b01000000) << 6)
				| ((lsb & 0b10000000) << 7);

		
		test = msb_tmp | lsb_tmp;

		k += 2;
		ret.pixels[i] = test;
		i++;
	}
	return (ret);
}

void	resize_tile(uint32_t* pixels, struct tile_s* tile, int x, int y)
{
	int i = 0;
	int j = 0;
	while (i < 8)
	{
		int index = 0;
		int k = 0;
		while (k < x)
		{
			pixels[(i + j) * 64 + index++] = get_color_from_palette((tile->pixels[i] & 0xff00) >> 8, 3);
			k++;
		}
		k = 0;
		while (k < x)
		{
			pixels[(i + j) * 64 + index++] = get_color_from_palette((tile->pixels[i] & 0xff00) >> 8, 2);
			k++;
		}
		k = 0;
		while (k < x)
		{
			pixels[(i + j) * 64 + index++] = get_color_from_palette((tile->pixels[i] & 0xff00) >> 8, 1);
			k++;
		}
		k = 0;
		while (k < x)
		{
			pixels[(i + j) * 64 + index++] = get_color_from_palette((tile->pixels[i] & 0xff00) >> 8, 0);
			k++;
		}
		k = 0;
		while (k < x)
		{
			pixels[(i + j) * 64 + index++] = get_color_from_palette((tile->pixels[i] & 0xff), 3);
			k++;
		}
		k = 0;
		while (k < x)
		{
			pixels[(i + j) * 64 + index++] = get_color_from_palette((tile->pixels[i] & 0xff), 2);
			k++;
		}
		k = 0;
		while (k < x)
		{
			pixels[(i + j) * 64 + index++] = get_color_from_palette((tile->pixels[i] & 0xff), 1);
			k++;
		}
		k = 0;
		while (k < x)
		{
			pixels[(i + j) * 64 + index++] = get_color_from_palette((tile->pixels[i] & 0xff), 0);
			k++;
		}
		index = 0;
		j = 0;
		i++;
	}
}

void	print_tile(struct gbmu_wrapper_s* wrapper, struct tile_s* tile, int index)
{
	SDL_Surface* tile_surface;

	tile_surface = SDL_CreateRGBSurface(0, 64, 64, 32, 0, 0, 0, 0);
	if (!tile_surface)
	{
		fprintf(stderr, "failed to create tile surface (%s)\n", SDL_GetError());
		return ;
	}
	uint32_t* pixels = tile_surface->pixels;

	resize_tile(pixels, tile, 2, 2);

	SDL_Rect pos = (SDL_Rect) {(index * 16) % (VRAM_SURFACE_WIDTH / 2), (index * 16 / 256) * 16, 64, 64};
	if (SDL_BlitSurface(tile_surface, NULL, wrapper->vram_viewer_context->surface, &pos))
		fprintf(stderr, "failed to blit surface (%s)\n", SDL_GetError());
	SDL_FreeSurface(tile_surface);
}

void	display_vram(struct gbmu_wrapper_s* wrapper)
{
	int i = 0x00;
	int index = 0;

	while (i < 0x17ff)
	{
		struct tile_s current_tile = create_tile(wrapper, i);
		print_tile(wrapper, &current_tile, index);
		i += 16;
		index = i / 16;
	}
}

void	video_loop(struct gbmu_wrapper_s* wrapper)
{
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
		pixels = wrapper->vram_viewer_context->surface->pixels;
		display_vram(wrapper);
		wrapper->vram_viewer_context->texture = SDL_CreateTextureFromSurface(wrapper->vram_viewer_context->renderer, wrapper->vram_viewer_context->surface);
		SDL_RenderCopy(wrapper->vram_viewer_context->renderer, wrapper->vram_viewer_context->texture, NULL, NULL);
		SDL_RenderPresent(wrapper->vram_viewer_context->renderer);
		SDL_DestroyTexture(wrapper->vram_viewer_context->texture);
	}
}

void*	thread_entry(void* user_data)
{
	video_loop((struct gbmu_wrapper_s*) user_data);
	return (NULL);
}

