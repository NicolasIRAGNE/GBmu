/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 13:48:02 by niragne           #+#    #+#             */
/*   Updated: 2020/03/18 12:45:25 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"

void	fill_tile_array(struct gb_cpu_s* gb, struct tile_s* array)
{
	int i = 0;
	int index = 0; 

	while (i < TILE_SIZE * TILES_COUNT)
	{
		array[index] = create_tile(gb, i);
		i += TILE_SIZE;
		index++;
	}
}

struct tile_s	create_tile(struct gb_cpu_s* gb, uint16_t index)
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
		msb = gb->vram[index + k];
		lsb = gb->vram[index + k + 1];

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
			while (k < y)
			{
				memset_4(pixels + i * TILE_SURFACE_WIDTH * x + j * y + k * TILE_SURFACE_HEIGHT, color, x);
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

int		print_tile(struct sdl_context_s* context, struct tile_s* tile, int index, int surface_width, int tiles_per_row)
{
	SDL_Surface* tile_surface;

	tile_surface = SDL_CreateRGBSurface(0, TILE_SURFACE_WIDTH, TILE_SURFACE_HEIGHT, 32, 0, 0, 0, 0);
	if (!tile_surface)
	{
		fprintf(stderr, "failed to create tile surface (%s)\n", SDL_GetError());
		return (1);
	}
	uint32_t* pixels = tile_surface->pixels;

	resize_tile(pixels, tile, 8, 8);

	SDL_Rect pos = (SDL_Rect) {(index * TILE_SURFACE_WIDTH) % (surface_width), (index / tiles_per_row) * TILE_SURFACE_HEIGHT, TILE_SURFACE_WIDTH, TILE_SURFACE_HEIGHT};
	if (SDL_BlitSurface(tile_surface, NULL, context->surface, &pos))
	{
		fprintf(stderr, "failed to blit surface (%s)\n", SDL_GetError());
		return (1);
	}
	SDL_FreeSurface(tile_surface);
	return (0);
}