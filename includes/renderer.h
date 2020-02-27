/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 10:37:45 by niragne           #+#    #+#             */
/*   Updated: 2020/02/27 11:42:42 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H
# include "gb.h"
# include "SDL.h"

# define VRAM_WINDOW_WIDTH 512
# define VRAM_WINDOW_HEIGHT 512
# define VRAM_SURFACE_WIDTH 512 
# define VRAM_SURFACE_HEIGHT 512


struct	sdl_context_s
{
	SDL_Window *win;
	SDL_Renderer *renderer;
    SDL_Surface *surface;
    SDL_Texture *texture;
};

struct 	tile_s
{
	uint16_t pixels[8];
};


void	video_loop(struct gbmu_wrapper_s* wrapper);
int     init_vram_viewer(struct sdl_context_s* context);

#endif