/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sdl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 11:56:05 by niragne           #+#    #+#             */
/*   Updated: 2020/04/23 16:12:48 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gb.h"
#include "renderer.h"

int		init_sdl()
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK))
	{
		fprintf(stderr, "failed to initialize SDL (%s)\n", SDL_GetError());
		return (1);
	}
	return (0);
}

int     init_vram_viewer(struct sdl_context_s* context)
{
	if (SDL_CreateWindowAndRenderer(VRAM_WINDOW_WIDTH, VRAM_WINDOW_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE, &(context->win), &(context->renderer)))
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

int     init_main_window(struct sdl_context_s* context)
{
	if (SDL_CreateWindowAndRenderer(MAIN_WINDOW_WIDTH, MAIN_WINDOW_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE, &(context->win), &(context->renderer)))
	{
		fprintf(stderr, "failed to initialize create window or renderer (%s)\n", SDL_GetError());
		return (1);
	}
	context->surface = SDL_CreateRGBSurface(0, MAIN_SURFACE_WIDTH, MAIN_SURFACE_HEIGHT, 32, 0, 0, 0, 0);
	if (!context->surface)
	{
		fprintf(stderr, "failed to create surface (%s)\n", SDL_GetError());
		return (1);
	}

	if (SDL_NumJoysticks() > 0)
	{
		if (SDL_IsGameController(0))
			context->controller = SDL_GameControllerOpen(0);
		if (!context->controller)
		{
			fprintf(stderr, "failed to load joystick (%s)\n", SDL_GetError());
		}
	}
	else
		printf("No joystick detected.\n");
    return (0);
}