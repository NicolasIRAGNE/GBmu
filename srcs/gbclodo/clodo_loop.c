/**
 * @file clodo_loop.c
 * @author Nicolas IRAGNE (nicolas.iragne@alyce.fr)
 * @brief
 * @date 2022-01-05
 *
 * @copyright Copyright Alyce (c) 2022
 */

#include "SDL_surface.h"
#include "SDL_video.h"
#include "renderer/wrapper_c/wrapper.h"
#include "renderer.h"
#include "gb.h"
#include "input_functions.h"

extern uint32_t m_TextureData[MAIN_SURFACE_HEIGHT][MAIN_SURFACE_WIDTH];

void	handle_input(struct gbmu_wrapper_s* wrapper, void* renderer)
{
	const Uint8 *state = SDL_GetKeyboardState(NULL);
	SDL_Event event;
	SDL_PollEvent(&event);
	if (event.type == SDL_KEYDOWN)
	{
		input_functions[event.key.keysym.scancode](wrapper);
		//TODO FIXME
		check_savestate(wrapper->gb, state, event);
	}
	else if (event.type == SDL_WINDOWEVENT) {
		if (event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED) {
			renderer_set_window_size(renderer, event.window.data1, event.window.data2);
		}
	}
	else if (event.type == SDL_QUIT)
	{
		wrapper->gb->running = 0;
	}
	if (!wrapper->gb->paused)
	{
		handle_joypad(wrapper->gb, wrapper->main_context->controller, state);
	}
}

void	execute_loop(struct gbmu_wrapper_s* wrapper, void* renderer)
{
	int frame = 0;
	int ctr = 0;
	struct tile_s tiles[2][TILES_COUNT];

	while (gb_global.running)
	{
		SDL_Event event;

		if (!gb_global.paused)
			frame = cpu_step();
		if (frame == 1)
		{
			SDL_UpdateTexture(wrapper->main_context->texture, NULL, m_TextureData, MAIN_SURFACE_WIDTH * sizeof(uint32_t));
			SDL_RenderClear(wrapper->main_context->renderer);
			SDL_RenderCopy(wrapper->main_context->renderer, wrapper->main_context->texture, NULL, NULL);
			SDL_RenderPresent(wrapper->main_context->renderer);
			if (wrapper->gb->vram_viewer_running)
			{
				update_palettes(wrapper->gb);
				fill_tile_array(wrapper->gb, tiles);
				vram_viewer_loop(wrapper, tiles);
			}
		}
		if (ctr == 70000)
		{
			ctr = 0;
			handle_input(wrapper, renderer);
			// SDL_Delay(1);
		}
		ctr++;
	}
}
