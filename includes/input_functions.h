/**
 * @file input_functions.h
 * @author Nicolas IRAGNE (nicolas.iragne@alyce.fr)
 * @date 2021-12-10
 */

#pragma once

void	init_input_functions(void);

extern void	(*input_functions[SDL_NUM_SCANCODES])(struct gbmu_wrapper_s* wrapper);
