/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 13:48:02 by niragne           #+#    #+#             */
/*   Updated: 2020/04/23 12:57:18 by niragne          ###   ########.fr       */
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
	uint16_t offset = 0;
	uint8_t msb;
	uint16_t msb_tmp;
	uint8_t lsb;
	uint16_t lsb_tmp;
	uint16_t test;

	if (index + 4096 < 0x17FF)
		offset += 0; // Why 4096 and not 2048 ? No idea

	while (i < 8)
	{
		msb = gb->vram[index + offset + k];
		lsb = gb->vram[index + offset + k + 1];

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
	/*
	** This function takes an 8*8 tile and makes it x times wider and y times taller.
	** This function is also useless because I am a moron and SDL does it by default.
	** But I am leaving it in since I spent way too much time on it.
	*/
	int i = 0;
	int j = 0;
	int k = 0;

	while (i < 8)
	{
		while (j < 8)
		{
			uint32_t color = get_color_from_palette(tile->index[i][j], TILE_TYPE_BACKGROUND);
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

void	flip_tile(uint32_t* pixels, struct tile_s* tile, int x, int y, enum tile_type_e type)
{
	int i = 0;
	int j = 0;
	
	while (i < 8)
	{
		while (j < 8)
		{
			uint32_t color = get_color_from_palette(tile->index[i][j], type);
			int line = i;
			int column = j;
			if (x)
				line = (TILE_SURFACE_WIDTH - i - 1);
			if (y)
				column = (TILE_SURFACE_HEIGHT - j - 1);
			pixels[line * TILE_SURFACE_WIDTH + column] =  color;
			j++;
		}
		// printf("\n");
		j = 0;
		i++;
	}
		// printf("\n");
}

int		print_tile(struct sdl_context_s* context, struct tile_s* tile, int attr, SDL_Rect pos, enum tile_type_e type)
{
	SDL_Surface* tile_surface;

	tile_surface = SDL_CreateRGBSurfaceWithFormat(0, TILE_SURFACE_WIDTH, TILE_SURFACE_HEIGHT, 32, SDL_PIXELFORMAT_RGBA8888);

	if (!tile_surface)
	{
		fprintf(stderr, "failed to create tile surface (%s)\n", SDL_GetError());
		return (1);
	}
	SDL_SetSurfaceBlendMode(tile_surface, SDL_BLENDMODE_BLEND);
	uint32_t* pixels = tile_surface->pixels;

	flip_tile(pixels, tile, attr & 0x40, attr & 0x20, type);

	if (SDL_BlitSurface(tile_surface, NULL, context->surface, &pos))
	{
		fprintf(stderr, "failed to blit surface (%s)\n", SDL_GetError());
		return (1);
	}
	SDL_FreeSurface(tile_surface);
	return (0);
}