/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vram_viewer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 13:46:09 by niragne           #+#    #+#             */
/*   Updated: 2020/04/24 12:09:35 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "renderer.h"
#include "SDL_rect.h"
#include "SDL_render.h"
#include "SDL_surface.h"
#include "cpu.h"
#include "gb.h"

int print_palette(struct gbmu_wrapper_s* wrapper, SDL_Surface *surface, uint16_t* palette, SDL_Rect pos)
{
	// Print the palette, which is stored as RGB555
	for (int i = 0; i < 4; i++)
	{
		uint16_t color = palette[i];
		uint8_t b = (color >> 10) & 0x1f;
		uint8_t g = (color >> 5) & 0x1f;
		uint8_t r = color & 0x1f;
		r = (r << 3) | (r >> 2);
		g = (g << 3) | (g >> 2);
		b = (b << 3) | (b >> 2);
		SDL_Surface* surf = SDL_CreateRGBSurface(0, 6, 6, 32, 0, 0, 0, 0);
		SDL_FillRect(surf, NULL, SDL_MapRGB(surf->format, r, g, b));
		if (SDL_BlitSurface(surf, NULL, surface, &pos) != 0)
		{
			SDL_Log("SDL_BlitSurface failed: %s", SDL_GetError());
			return -1;
		}
		SDL_FreeSurface(surf);
		pos.x += 6;
	}
	return (0);
}

int display_vram(struct gbmu_wrapper_s* wrapper, struct tile_s array[2][TILES_COUNT])
{
    int i = 0;
    int index = 0;

    uint8_t bank = 0;
    while (bank < 2)
    {
        while (i < TILE_SIZE * TILES_COUNT)
        {
            // SDL_Rect pos = (SDL_Rect) { (index * TILE_SURFACE_WIDTH) % (VRAM_SURFACE_WIDTH / 2) + (bank * VRAM_SURFACE_WIDTH / 2), (index / 16) * TILE_SURFACE_HEIGHT, TILE_SURFACE_WIDTH, TILE_SURFACE_HEIGHT };
			SDL_Rect pos = (SDL_Rect) { (index * TILE_SURFACE_WIDTH) % (VRAM_SURFACE_WIDTH / 2) + (bank * VRAM_SURFACE_WIDTH / 2), (index / 16) * TILE_SURFACE_HEIGHT, TILE_SURFACE_WIDTH, TILE_SURFACE_HEIGHT };

            if (print_tile(wrapper->gb, wrapper->vram_viewer_context->surface, array[bank] + index, 0, pos, TILE_TYPE_BACKGROUND))
                return (1);
            i += TILE_SIZE;
            index += 1;
        }
		bank += 1;
		i = 0;
		index = 0;
    }

	// Print palettes in the bottom
    if (wrapper->gb->mode == GB_MODE_CGB)
    {
        for (i = 0; i < CRAM_SIZE / 8; i++)
        {
            // Bg palette
            SDL_Rect pos = (SDL_Rect) { 0, VRAM_SURFACE_HEIGHT - 64 + i * 6, 6, 6 };
            uint16_t* palette = (uint16_t*)wrapper->gb->cgb_bg_palettes + i * 4;
            if (print_palette(wrapper, wrapper->vram_viewer_context->surface, palette, pos))
                return (1);
            // Sprite palette
            pos = (SDL_Rect) { 72, VRAM_SURFACE_HEIGHT - 64 + i * 6, 6, 6 };
            palette = (uint16_t*)wrapper->gb->cgb_obj_palettes + i * 4;
            if (print_palette(wrapper, wrapper->vram_viewer_context->surface, palette, pos))
                return (1);
        }
    }

    return (0);
}

void	vram_viewer_loop(struct gbmu_wrapper_s* wrapper, struct tile_s array[2][TILES_COUNT])
{
   	// while (SDL_PollEvent(&event)) 
	// {
   		// if (event.type == SDL_KEYDOWN)
		// {
			// if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
			// {
				// SDL_DestroyWindow(wrapper->vram_viewer_context->win);
				// wrapper->gb->vram_viewer_running = 0;
			// }
		// }
   	// }
	// SDL_FillRect(wrapper->vram_viewer_context->surface, NULL, 0);
	if (display_vram(wrapper, array))
	{
		printf("jette toi dans lcanal\n");
		wrapper->gb->vram_viewer_running = 0;
	}
	wrapper->vram_viewer_context->texture = SDL_CreateTextureFromSurface(wrapper->vram_viewer_context->renderer, wrapper->vram_viewer_context->surface);
	if (wrapper->vram_viewer_context->texture == NULL)
	{
		printf("jette toi dans lcanal\n");
		wrapper->gb->vram_viewer_running = 0;
	}
	SDL_RenderCopy(wrapper->vram_viewer_context->renderer, wrapper->vram_viewer_context->texture, NULL, NULL);
	SDL_RenderPresent(wrapper->vram_viewer_context->renderer);
	SDL_DestroyTexture(wrapper->vram_viewer_context->texture);
}
