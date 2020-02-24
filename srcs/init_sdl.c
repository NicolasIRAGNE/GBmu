/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sdl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 11:56:05 by niragne           #+#    #+#             */
/*   Updated: 2020/02/24 09:42:39 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gb.h"
#include "renderer.h"

int     init_sdl(struct sdl_context_s* context)
{
    if (SDL_Init(SDL_INIT_VIDEO))
	{
		fprintf(stderr, "failed to initialize SDL (%s)\n", SDL_GetError());
		return (1);
	}
    
	if (SDL_CreateWindowAndRenderer(127, 256, SDL_WINDOW_SHOWN, &(context->win), &(context->renderer)))
	{
		fprintf(stderr, "failed to initialize create window or renderer(%s)\n", SDL_GetError());
		return (1);
	}
    
    return (0);
}