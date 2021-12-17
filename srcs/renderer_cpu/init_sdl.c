/**
 * @file init_sdl.c
 * @author Nicolas IRAGNE (nicolas.iragne@alyce.fr)
 * @brief 
 * @date 2021-12-17
 * 
 * @copyright Copyright Alyce (c) 2021
 */

#include "SDL.h"
#include "renderer.h"

int		init_sdl()
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK | SDL_INIT_EVENTS))
    {
        fprintf(stderr, "failed to initialize SDL (%s)\n", SDL_GetError());
        return (1);
    }

    return (0);
}

int init_vram_viewer(struct sdl_context_s* context)
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

int init_main_window(struct sdl_context_s* context)
{
     if (SDL_CreateWindowAndRenderer(MAIN_WINDOW_WIDTH, MAIN_WINDOW_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE, &(context->win), &(context->renderer)))
    {
        fprintf(stderr, "failed to initialize create window or renderer(%s)\n", SDL_GetError());
        return (1);
    }
    init_input_functions();
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
	{
		context->controller = NULL;
		printf("No joystick detected.\n");
	}
	return (0);
}

void    destroy_context(struct sdl_context_s* context)
{
    SDL_DestroyWindow(context->win);
    SDL_DestroyRenderer(context->renderer);
    SDL_FreeSurface(context->surface);
    SDL_DestroyTexture(context->texture);
    SDL_DestroyRenderer(context->renderer);
    SDL_DestroyWindow(context->win);
    SDL_Quit();
}