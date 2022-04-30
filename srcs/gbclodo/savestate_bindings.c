/**
 * @file savestate_bindings.c
 * @author Nicolas IRAGNE (nicolas.iragne@alyce.fr)
 * @brief 
 * @date 2022-04-30
 * 
 * @copyright Copyright Alyce (c) 2022
 */

#include "SDL_events.h"
#include "SDL_keyboard.h"
#include "SDL_scancode.h"
#include "SDL_stdinc.h"
#include "gb.h"

void	check_savestate(struct gb_cpu_s* gb, const Uint8* state, SDL_Event event)
{
	Uint8 slots[] = 
	{
		SDL_SCANCODE_1,
		SDL_SCANCODE_2,
		SDL_SCANCODE_3,
		SDL_SCANCODE_4,
		SDL_SCANCODE_5,
		SDL_SCANCODE_6,
		SDL_SCANCODE_7,
		SDL_SCANCODE_8,
		SDL_SCANCODE_9,
	};

	for (size_t i = 0; i < sizeof(slots); i++)
	{
		if (event.key.keysym.scancode == slots[i])
		{
			if (state[SDL_SCANCODE_LSHIFT])
				loadstate(gb, i + 1);
			else
				savestate(gb, i + 1);
			return ;
		}
	}
}