/**
 * @file input_functions.c
 * @author Nicolas IRAGNE (nicolas.iragne@alyce.fr)
 * @brief Functions to add to the main input function pointer array.
 * @date 2021-12-10
 */

#include "gb.h"
#include "SDL_scancode.h"
#include "cpu.h"

void	key_escape(struct gbmu_wrapper_s* wrapper)
{
	wrapper->gb->running = 0;
}

void	key_space(struct gbmu_wrapper_s* wrapper)
{
	wrapper->gb->paused = !wrapper->gb->paused;
}

void	key_c(struct gbmu_wrapper_s* wrapper)
{
	wrapper->gb->debug_palette = !wrapper->gb->debug_palette;
}

void	key_unused(struct gbmu_wrapper_s* wrapper)
{
	(void)wrapper;
}

void    key_numpad_1(struct gbmu_wrapper_s* wrapper)
{
    wrapper->gb->draw_background = !wrapper->gb->draw_background;
}

void    key_numpad_2(struct gbmu_wrapper_s* wrapper)
{
    wrapper->gb->draw_sprites = !wrapper->gb->draw_sprites;
}

void    key_numpad_3(struct gbmu_wrapper_s* wrapper)
{
    wrapper->gb->draw_window = !wrapper->gb->draw_window;
}

void	(*input_functions[SDL_NUM_SCANCODES])(struct gbmu_wrapper_s* wrapper);

void	init_input_functions(void)
{
	int i;

	i = 0;
	while (i < SDL_NUM_SCANCODES)
	{
		input_functions[i] = &key_unused;
		i++;
	}
	input_functions[SDL_SCANCODE_ESCAPE] = &key_escape;
	input_functions[SDL_SCANCODE_SPACE] = &key_space;
	input_functions[SDL_SCANCODE_C] = &key_c;
	input_functions[SDL_SCANCODE_KP_1] = &key_numpad_1;
	input_functions[SDL_SCANCODE_KP_2] = &key_numpad_2;
	input_functions[SDL_SCANCODE_KP_3] = &key_numpad_3;
}
