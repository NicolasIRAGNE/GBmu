/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sdl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 11:56:05 by niragne           #+#    #+#             */
/*   Updated: 2020/05/02 19:56:33 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "renderer.h"
#include "input_functions.h"
#include "SDL.h"
#include "SDL_error.h"
#include "SDL_gamecontroller.h"
#include "SDL_joystick.h"
#include "SDL_render.h"
#include "SDL_surface.h"
#include "SDL_video.h"

int		init_sdl()
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK))
	{
		fprintf(stderr, "failed to initialize SDL (%s)\n", SDL_GetError());
		return (1);
	}

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
	SDL_GL_SetSwapInterval(0);
	return (0);
}

int     init_vram_viewer(struct sdl_context_s* context)
{
	if (SDL_CreateWindowAndRenderer(VRAM_WINDOW_WIDTH, VRAM_WINDOW_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL, &(context->win), &(context->renderer)))
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
	context->win = SDL_CreateWindow("GBmu", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, MAIN_WINDOW_WIDTH, MAIN_WINDOW_HEIGHT,  SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);
	if (!context->win)
	{
		fprintf(stderr, "failed to initialize create window (%s)\n", SDL_GetError());
		return (1);
	}
	context->glcontext = SDL_GL_CreateContext(context->win);
	SDL_GL_SetSwapInterval(0);
	init_input_functions();
	// context->surface = SDL_CreateRGBSurface(0, MAIN_SURFACE_WIDTH, MAIN_SURFACE_HEIGHT, 32, 0, 0, 0, 0);
	// if (!context->surface)
	// {
		// fprintf(stderr, "failed to create surface (%s)\n", SDL_GetError());
		// return (1);
	// }
	
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
	{
		context->controller = NULL;
		printf("No joystick detected.\n");
	}
	return (0);
}

void	destroy_context(struct sdl_context_s* context)
{
	if (context->controller)
		SDL_GameControllerClose(context->controller);
	SDL_GL_DeleteContext(context->glcontext);
}