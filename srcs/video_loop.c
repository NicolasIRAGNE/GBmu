/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   video_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 13:27:32 by niragne           #+#    #+#             */
/*   Updated: 2020/03/04 15:17:23 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gb.h"
#include "renderer.h"

uint32_t	get_color_from_palette(uint8_t index)
{
	uint32_t palette[4] = 
	{
		0x00000000, 0xff444444, 0xff999999, 0xffffffff
	};
	return (palette[index]);
}

struct tile_s	create_tile(struct gbmu_wrapper_s* wrapper, uint16_t index)
{
	struct tile_s ret;
	
	int i = 0;
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
		// test = 0xb00b;

		k += 2;
		ret.pixels_raw[i] = test;
		int j = 0;
		while (j < 8)
		{
			ret.index[i][7] = (test & (0b11 << 0)) >> 0;
			ret.index[i][6] = (test & (0b11 << 2)) >> 2;
			ret.index[i][5] = (test & (0b11 << 4)) >> 4;
			ret.index[i][4] = (test & (0b11 << 6)) >> 6;
			
			ret.index[i][3] = (((test & 0xff00) >> 8) & (0b11 << 0)) >> 0;
			ret.index[i][2] = (((test & 0xff00) >> 8) & (0b11 << 2)) >> 2;
			ret.index[i][1] = (((test & 0xff00) >> 8) & (0b11 << 4)) >> 4;
			ret.index[i][0] = (((test & 0xff00) >> 8) & (0b11 << 6)) >> 6;

			// ret.index[i][0] = 3;
			// ret.index[i][1] = 2;
			// ret.index[i][2] = 1;
			// ret.index[i][3] = 0;
			
			// ret.index[i][4] = 0;
			// ret.index[i][5] = 1;
			// ret.index[i][6] = 2;
			// ret.index[i][7] = 3;
			j++;
		}
		i++;
	}
	return (ret);
}

void	memset_4(uint32_t* ptr, uint32_t c, size_t n)
{
	int i = 0;

	while (i < n)
	{
		ptr[i] = c;
		i += 1;
	}
}

void	resize_tile(uint32_t* pixels, struct tile_s* tile, int x, int y)
{
	int i = 0;
	int j = 0;
	int k = 0;

	while (i < 8)
	{
		while (j < 8)
		{
			uint32_t color = get_color_from_palette(tile->index[i][j]);
			// printf("%d ", tile->index[i][j]);
			while (k < 8)
			{
				memset_4(pixels + i * 512 + j * 8 + k * 64, color, 8);
				k++;

			}
			k = 0;
			j++;
		}
		// printf("\n");
		j = 0;
		i++;
	}
		// printf("\n");
}

void	print_tile(struct gbmu_wrapper_s* wrapper, struct tile_s* tile, int index)
{
	SDL_Surface* tile_surface;

	tile_surface = SDL_CreateRGBSurface(0, TILE_SURFACE_WIDTH, TILE_SURFACE_HEIGHT, 32, 0, 0, 0, 0);
	if (!tile_surface)
	{
		fprintf(stderr, "failed to create tile surface (%s)\n", SDL_GetError());
		return ;
	}
	uint32_t* pixels = tile_surface->pixels;

	resize_tile(pixels, tile, TILE_SURFACE_WIDTH, TILE_SURFACE_HEIGHT);

	SDL_Rect pos = (SDL_Rect) {(index * TILE_SURFACE_WIDTH) % (VRAM_SURFACE_WIDTH), (index / 16) * TILE_SURFACE_HEIGHT, TILE_SURFACE_WIDTH, TILE_SURFACE_HEIGHT};
	if (SDL_BlitSurface(tile_surface, NULL, wrapper->vram_viewer_context->surface, &pos))
		fprintf(stderr, "failed to blit surface (%s)\n", SDL_GetError());
	SDL_FreeSurface(tile_surface);
}

void	display_vram(struct gbmu_wrapper_s* wrapper)
{
	int i = 0;
	int index = 0;

	while (i < 16 * 384)
	{
		struct tile_s current_tile = create_tile(wrapper, i);
		print_tile(wrapper, &current_tile, index);
		i += 0x10;
		index += 1;
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

