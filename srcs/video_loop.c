/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   video_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 13:27:32 by niragne           #+#    #+#             */
/*   Updated: 2020/02/23 21:47:59 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gb.h"
#include "renderer.h"

uint32_t	get_color_from_palette(uint8_t byte, uint8_t mask)
{
	uint32_t palette[4] = 
	{
		0x00000000, 0xff0000ff, 0x00ff00ff, 0x0000ffff
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
	uint8_t msb_tmp;
	uint8_t lsb;
	uint8_t lsb_tmp;
	uint16_t test;

	while (i < 8)
	{
		msb = wrapper->gb->vram[index + k];
		lsb = wrapper->gb->vram[index + k + 1];

		// msb = 0b01101010;
		// lsb = 0b01011010;

		msb_tmp = ((msb & 0b10) >> 1)
				| ((msb & 0b1000) >> 2)
				| ((msb & 0b100000) >> 3)
				| ((msb & 0b10000000) >> 4);
		
		lsb_tmp = ((lsb & 0b10) >> 1)
				| ((lsb & 0b1000) >> 2)
				| ((lsb & 0b100000) >> 3)
				| ((lsb & 0b10000000) >> 4);
		
		
		test = ((msb_tmp << 4) | lsb_tmp) << 8;

		msb_tmp = ((msb & 0b1) >> 0)
				| ((msb & 0b100) >> 1)
				| ((msb & 0b10000) >> 2)
				| ((msb & 0b1000000) >> 3);
		
		lsb_tmp = ((lsb & 0b1) >> 0)
				| ((lsb & 0b100) >> 1)
				| ((lsb & 0b10000) >> 2)
				| ((lsb & 0b1000000) >> 3);
		
		test |= ((msb_tmp << 4) | lsb_tmp);

		k += 2;
		ret.pixels[i] = test;
		i++;
	}
	return (ret);
}

void	print_tile(struct gbmu_wrapper_s* wrapper, struct tile_s* tile, int index)
{
	uint32_t* pixels = wrapper->context->surface->pixels;

	int i = 0;
	int j = 0;

	printf("TILE AT %x\n", index);
	printf("%x\n", tile->pixels[0]);
	printf("%x\n", tile->pixels[1]);
	printf("%x\n", tile->pixels[2]);
	printf("%x\n", tile->pixels[3]);
	printf("%x\n", tile->pixels[4]);
	printf("%x\n", tile->pixels[5]);
	printf("%x\n", tile->pixels[6]);
	printf("%x\n\n", tile->pixels[7]);

	while (i < 8)
	{
		while (j < 16)
		{
			pixels[index + i * 160 + j + 0] = get_color_from_palette((tile->pixels[i] & 0xff00) >> 8, 0);			pixels[index + i * 160 + j + 0] = get_color_from_palette((tile->pixels[i] & 0xff00) >> 8, 0);
			pixels[index + i * 160 + j + 1] = get_color_from_palette((tile->pixels[i] & 0xff00) >> 8, 1);			pixels[index + i * 160 + j + 1] = get_color_from_palette((tile->pixels[i] & 0xff00) >> 8, 1);
			pixels[index + i * 160 + j + 2] = get_color_from_palette((tile->pixels[i] & 0xff00) >> 8, 2);			pixels[index + i * 160 + j + 2] = get_color_from_palette((tile->pixels[i] & 0xff00) >> 8, 2);
			pixels[index + i * 160 + j + 3] = get_color_from_palette((tile->pixels[i] & 0xff00) >> 8, 3);			pixels[index + i * 160 + j + 3] = get_color_from_palette((tile->pixels[i] & 0xff00) >> 8, 3);
			pixels[index + i * 160 + j + 4] = get_color_from_palette(tile->pixels[i] & 0xff, 0);
			pixels[index + i * 160 + j + 5] = get_color_from_palette(tile->pixels[i] & 0xff, 1);
			pixels[index + i * 160 + j + 6] = get_color_from_palette(tile->pixels[i] & 0xff, 2);
			pixels[index + i * 160 + j + 7] = get_color_from_palette(tile->pixels[i] & 0xff, 3);
			
			j += 8;
		}
		j = 0;
		i++;
	}
}

void	display_vram(struct gbmu_wrapper_s* wrapper)
{
	int i = 0;

	while (i < VRAM_SIZE)
	{
		struct tile_s current_tile = create_tile(wrapper, i);
		print_tile(wrapper, &current_tile, i);
		i += 16;
	}
}

void	video_loop(struct gbmu_wrapper_s* wrapper)
{
	wrapper->context->surface = SDL_CreateRGBSurface(0, 256, 256, 32, 0, 0, 0, 0);
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
		display_vram(wrapper);
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

