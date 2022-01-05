/**
 * @file gbclodo.h
 * @author Nicolas IRAGNE (nicolas.iragne@alyce.fr)
 * @brief 
 * @date 2022-01-05
 * 
 * @copyright Copyright Alyce (c) 2022
 */

#pragma once
#include "gb.h"

/**
 * @brief The current execution loop used by the program. This function is not a good piece of code and should be rewritten.
 * 
 * @param wrapper @copydoc struct gbmu_wrapper_s* wrapper
 * @param renderer @copydoc struct gbmu_renderer_s* renderer
 */
void	execute_loop(struct gbmu_wrapper_s* wrapper, void* renderer);