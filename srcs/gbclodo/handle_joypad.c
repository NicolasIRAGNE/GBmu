/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_joypad.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 14:07:07 by niragne           #+#    #+#             */
/*   Updated: 2020/04/28 22:46:02 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"
#include "SDL_gamecontroller.h"
#include "SDL_scancode.h"
#include "SDL_stdinc.h"
#include "cpu.h"

void	handle_joypad(struct gb_cpu_s* gb, SDL_GameController* controller, const Uint8* state)
{
	struct joypad_s temp = {0};

	if (controller)
	{
		temp.start = SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_START);
		temp.select = SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_BACK);
		temp.a = SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_A);
		temp.b = SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_X);
		temp.down = SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_DOWN);
		temp.up = SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_UP);
		temp.left = SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_LEFT);
		temp.right = SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_RIGHT);

	}
	gb->joypad.start = (state[SDL_SCANCODE_BACKSPACE] != 0) || temp.start;
	gb->joypad.select = (state[SDL_SCANCODE_RETURN] != 0) || temp.select;
	gb->joypad.a = (state[SDL_SCANCODE_Z] != 0) || temp.a;
	gb->joypad.b = (state[SDL_SCANCODE_X] != 0) || temp.b;
	gb->joypad.down = (state[SDL_SCANCODE_DOWN] != 0) || temp.down;
	gb->joypad.up = (state[SDL_SCANCODE_UP] != 0) || temp.up;
	gb->joypad.left = (state[SDL_SCANCODE_LEFT] != 0) || temp.left;
	gb->joypad.right = (state[SDL_SCANCODE_RIGHT] != 0) || temp.right;
}