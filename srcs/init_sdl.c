/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sdl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 11:56:05 by niragne           #+#    #+#             */
/*   Updated: 2020/02/27 09:13:01 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gb.h"
#include "renderer.h"

int     init_vram_viewer(struct sdl_context_s* context)
{
	
    if (SDL_Init(SDL_INIT_VIDEO))
	{
		fprintf(stderr, "failed to initialize SDL (%s)\n", SDL_GetError());
		return (1);
	}
    
	if (SDL_CreateWindowAndRenderer(VRAM_WINDOW_WIDTH, VRAM_WINDOW_HEIGHT, SDL_WINDOW_SHOWN, &(context->win), &(context->renderer)))
	{
		fprintf(stderr, "failed to initialize create window or renderer(%s)\n", SDL_GetError());
		return (1);
	}
    context->surface = SDL_CreateRGBSurface(0, VRAM_SURFACE_WIDTH, VRAM_SURFACE_HEIGHT, 32, 0, 0, 0, 0);
	if (!context->surface)
	{
		fprintf(stderr, "failed to create surface (%s)\n", SDL_GetError());
		return (1);
	}
    return (0);
}