/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_joypad.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 14:07:07 by niragne           #+#    #+#             */
/*   Updated: 2020/04/21 15:14:31 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gb.h"
#include "renderer.h"

void	handle_joypad(struct gb_cpu_s* gb)
{
	const Uint8 *state = SDL_GetKeyboardState(NULL);
	uint8_t		input = 0;
	uint8_t		input_high_nibble = read_8(gb, JOYP_OFFSET);

	if (gb->joypad_mode == JOYPAD_MODE_BUTTONS)
	{
		if (state[SDL_SCANCODE_BACKSPACE])
			input |= JOYP_INPUT_START;
		if (state[SDL_SCANCODE_RETURN])
			input |= JOYP_INPUT_SELECT;
		if (state[SDL_SCANCODE_Z])
			input |= JOYP_INPUT_A;
		if (state[SDL_SCANCODE_X])
			input |= JOYP_INPUT_B;
	}
	else if (gb->joypad_mode == JOYPAD_MODE_DIRECTIONS)
	{
		if (state[SDL_SCANCODE_DOWN])
			input |= JOYP_INPUT_DOWN;
		if (state[SDL_SCANCODE_UP])
			input |= JOYP_INPUT_UP;
		if (state[SDL_SCANCODE_LEFT])
			input |= JOYP_INPUT_LEFT;
		if (state[SDL_SCANCODE_RIGHT])
			input |= JOYP_INPUT_RIGHT;
	}
	input &= 0x0f;
	input = ~input;
	input = input & (input_high_nibble & 0xf0);
	printf("input in f = %x\n", input);
	write_8(gb, JOYP_OFFSET, input);
}