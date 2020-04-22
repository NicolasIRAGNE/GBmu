/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_joypad.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 14:07:07 by niragne           #+#    #+#             */
/*   Updated: 2020/04/22 14:28:11 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gb.h"
#include "renderer.h"

void	handle_joypad(struct gb_cpu_s* gb)
{
	const Uint8 *state = SDL_GetKeyboardState(NULL);

	gb->joypad.start = (state[SDL_SCANCODE_BACKSPACE] != 0);
	gb->joypad.select = (state[SDL_SCANCODE_RETURN] != 0);
	gb->joypad.a = (state[SDL_SCANCODE_Z] != 0);
	gb->joypad.b = (state[SDL_SCANCODE_X] != 0);
	gb->joypad.down = (state[SDL_SCANCODE_DOWN] != 0);
	gb->joypad.up = (state[SDL_SCANCODE_UP] != 0);
	gb->joypad.left = (state[SDL_SCANCODE_LEFT] != 0);
	gb->joypad.right = (state[SDL_SCANCODE_RIGHT] != 0);
}