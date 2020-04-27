/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   userscreen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 12:10:20 by niragne           #+#    #+#             */
/*   Updated: 2020/04/27 12:42:55 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"

void	display_background(struct gbmu_wrapper_s* wrapper, uint8_t lcdc, struct tile_s* array, SDL_Surface* tmp_surface)
{
	int scy_2 = read_8(wrapper->gb, SCY_OFFSET);
	int scx_2 = read_8(wrapper->gb, SCX_OFFSET);
	int wx_2 = (read_8(wrapper->gb, WX_OFFSET)) - 7;
	int wy_2 = (read_8(wrapper->gb, WY_OFFSET));
	int wx = wx_2 / 8;
	int wy = wy_2 / 8;

	int i = 0;

	while (i < 256 / TILE_SURFACE_WIDTH)
	{
		int j = 0;
		while (j < 256 / TILE_SURFACE_HEIGHT)
		{
			uint16_t tile_index;

			tile_index = wrapper->gb->vram[BGMAP1_OFFSET + i + j * 32];
			if (!(lcdc & LCDC_TILE_DATA_SELECT) && tile_index + 0x100 < 256 + 128)
				tile_index += 0x100;
			SDL_Rect pos = (SDL_Rect) {i * 8 , j * 8, TILE_SURFACE_WIDTH, TILE_SURFACE_HEIGHT};
			print_tile(wrapper->gb, tmp_surface, array + tile_index, 0, pos, TILE_TYPE_BACKGROUND);
			j++;
		}
		i++;
	}
	SDL_Rect topleft = (SDL_Rect) {0, 0, 256 - scx_2, 256 - scy_2};
	SDL_Rect topright = (SDL_Rect) {256 - scx_2, 0, scx_2, 256 - scy_2};
	SDL_Rect botleft = (SDL_Rect) {0, 256 - scy_2, 256 - scx_2, scy_2};
	SDL_Rect botright = (SDL_Rect) {256 - scx_2, 256 - scy_2, scx_2, scy_2};

	SDL_Rect src_topleft = (SDL_Rect) {scx_2, scy_2, 256 - scx_2, 256 - scy_2};
	SDL_Rect src_topright = (SDL_Rect) {0, scy_2, scx_2, 256 - scy_2};
	SDL_Rect src_botleft = (SDL_Rect) {scx_2, 0, 256 - scx_2, scy_2};
	SDL_Rect src_botright = (SDL_Rect) {0, 0, scx_2, scy_2};

	SDL_BlitSurface(tmp_surface, &src_topleft , wrapper->main_context->surface, &topleft );
	SDL_BlitSurface(tmp_surface, &src_topright, wrapper->main_context->surface, &topright);
	SDL_BlitSurface(tmp_surface, &src_botleft , wrapper->main_context->surface, &botleft );
	SDL_BlitSurface(tmp_surface, &src_botright, wrapper->main_context->surface, &botright);

	i = wx;
	while (i < USERSCREEN_WIDTH / TILE_SURFACE_WIDTH)
	{
		int j = wy;
		while (j < USERSCREEN_HEIGHT / TILE_SURFACE_HEIGHT)
		{
			uint16_t tile_index;
			if (lcdc & LCDC_WINDOW_ON)
			{
				if (lcdc & LCDC_WINDOW_SELECT)
					tile_index = wrapper->gb->vram[BGMAP2_OFFSET + (i - wx) + ((j - wy)) * 32];		
				else
					tile_index = wrapper->gb->vram[BGMAP1_OFFSET + (i - wx) + ((j - wy)) * 32];
				SDL_Rect pos = (SDL_Rect) {i * 8 + wx_2 % 8, j * 8 + wy_2 % 8, TILE_SURFACE_WIDTH, TILE_SURFACE_HEIGHT};
				if (!(lcdc & LCDC_TILE_DATA_SELECT) && tile_index + 0x100 < 256 + 128)
					tile_index += 0x100;
				print_tile(wrapper->gb, wrapper->main_context->surface, array + tile_index, 0, pos, TILE_TYPE_BACKGROUND);
			}
			j++;
		}
		i++;
	}
}

void	display_sprites(struct gbmu_wrapper_s* wrapper, uint8_t lcdc, struct tile_s* array)
{
	int i = 0;
	while (i < OAM_SIZE)
	{
		uint8_t y = 	wrapper->gb->oam[i + 0];
		uint8_t x = 	wrapper->gb->oam[i + 1];
		uint8_t tile =	wrapper->gb->oam[i + 2];
		uint8_t attr =	wrapper->gb->oam[i + 3];
		SDL_Rect pos1 = (SDL_Rect) {x - 8, y - 16,  TILE_SURFACE_WIDTH, TILE_SURFACE_HEIGHT};
		SDL_Rect pos2 = (SDL_Rect) {x - 8, y - 8,  TILE_SURFACE_WIDTH, TILE_SURFACE_HEIGHT};

		if (attr & ATTR_Y_FLIP && lcdc & LCDC_SPRITE_SIZE)
		{
			pos1 = pos2;
			pos2 = (SDL_Rect) {x - 8, y - 16,  TILE_SURFACE_WIDTH, TILE_SURFACE_HEIGHT};
		}
		print_tile(wrapper->gb, wrapper->main_context->surface, array + tile, attr, pos1, TILE_TYPE_SPRITE);		
		if (lcdc & LCDC_SPRITE_SIZE)
			print_tile(wrapper->gb, wrapper->main_context->surface, array + tile + 1, attr, pos2, TILE_TYPE_SPRITE);
		i += 4;
	}
}
