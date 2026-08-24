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

#include "SDL_gamecontroller.h"
#include "SDL_scancode.h"
#include "SDL_stdinc.h"
#include "cpu.h"
#include "renderer.h"

void handle_joypad(struct gb_cpu_s* gb, SDL_GameController* controller, const Uint8* state)
{
    struct joypad_s temp = { 0 };

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
    uint8_t ret = 0;
    if (gb->joypad_mode == JOYPAD_MODE_BUTTONS)
    {
        ret |= ((gb->joypad.a) != 0) << 0;
        ret |= ((gb->joypad.b) != 0) << 1;
        ret |= ((gb->joypad.select) != 0) << 2;
        ret |= ((gb->joypad.start) != 0) << 3;
    }
    else if (gb->joypad_mode == JOYPAD_MODE_DIRECTIONS)
    {
        ret |= ((gb->joypad.right) != 0) << 0;
        ret |= ((gb->joypad.left) != 0) << 1;
        ret |= ((gb->joypad.up) != 0) << 2;
        ret |= ((gb->joypad.down) != 0) << 3;
    }
    ret = ~ret;
    write_8(gb, JOYP_OFFSET, ret);
}