/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   video_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 13:27:32 by niragne           #+#    #+#             */
/*   Updated: 2020/02/21 14:02:51 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gb.h"
#include "SDL.h"

void	video_loop(struct gbmu_wrapper_s* wrapper)
{
	wrapper->context->surface = SDL_LoadBMP("sample.bmp");
	if (!wrapper->context->surface)
	{
		fprintf(stderr, "failed to create surface (%s)\n", SDL_GetError());
		return ;
	}

	wrapper->context->texture = SDL_CreateTextureFromSurface(wrapper->context->renderer, wrapper->context->surface);
	if (!wrapper->context->texture)
	{
		fprintf(stderr, "failed to create texture (%s)\n", SDL_GetError());
		return ;
	}

	SDL_FreeSurface(wrapper->context->surface);

	while (wrapper->gb->running)
	{
		SDL_Event event;
    	while (SDL_PollEvent(&event)) 
		{
    		if (event.type == SDL_KEYDOWN)
			{
				if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
					wrapper->gb->running = 0;
			}
    	}
		SDL_RenderClear(wrapper->context->renderer);
		SDL_RenderCopy(wrapper->context->renderer, wrapper->context->texture, NULL, NULL);
		SDL_RenderPresent(wrapper->context->renderer);
	}
}

void*	thread_entry(void* user_data)
{
	video_loop((struct gbmu_wrapper_s*) user_data);
	return (NULL);
}

