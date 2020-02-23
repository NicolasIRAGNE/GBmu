/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 10:37:45 by niragne           #+#    #+#             */
/*   Updated: 2020/02/23 10:39:18 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H
# include "gb.h"
# include "SDL.h"

struct	sdl_context_s
{
	SDL_Window *win;
	SDL_Renderer *renderer;
    SDL_Surface *surface;
    SDL_Texture *texture;
};

void	video_loop(struct gbmu_wrapper_s* wrapper);
int     init_sdl(struct sdl_context_s* context);

#endif