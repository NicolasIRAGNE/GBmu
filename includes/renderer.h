/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 10:37:45 by niragne           #+#    #+#             */
/*   Updated: 2020/03/22 13:27:58 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H
# include "gb.h"
# include "cpu.h"
# include "SDL.h"

# define VRAM_WINDOW_WIDTH 256
# define VRAM_WINDOW_HEIGHT 512
# define VRAM_SURFACE_WIDTH 1024
# define VRAM_SURFACE_HEIGHT 2048

# define MAIN_WINDOW_WIDTH (256 * 2)
# define MAIN_WINDOW_HEIGHT (256 * 2)


# define TILE_SURFACE_WIDTH		64
# define TILE_SURFACE_HEIGHT	64

# define MAIN_SURFACE_WIDTH (256 * 8)
# define MAIN_SURFACE_HEIGHT (256 * 8)

# define TILE_SIZE				16
# define TILES_COUNT ((VRAM_TILE_BANK_SIZE + 1) / TILE_SIZE)

struct	sdl_context_s
{
	SDL_Window *win;
	SDL_Renderer *renderer;
    SDL_Surface *surface;
    SDL_Texture *texture;
};

struct 	tile_s
{
	uint16_t	pixels_raw[8];
	uint8_t		index[8][8];
	SDL_Surface	*surface;
};


void	vram_viewer_loop(struct gbmu_wrapper_s* wrapper, struct tile_s* array);
int     init_vram_viewer(struct sdl_context_s* context);
int     init_main_window(struct sdl_context_s* context);
int     init_sdl();
void	renderer_loop(struct gbmu_wrapper_s* wrapper);
uint32_t	get_color_from_palette(uint8_t index);
struct tile_s	create_tile(struct gb_cpu_s* gb, uint16_t index);
uint32_t	get_color_from_palette(uint8_t index);
int		print_tile(struct sdl_context_s* context, struct tile_s* tile, int index, SDL_Rect pos);
void	resize_tile(uint32_t* pixels, struct tile_s* tile, int x, int y);
void	fill_tile_array(struct gb_cpu_s* gb, struct tile_s* array);
void	main_window_loop(struct gbmu_wrapper_s* wrapper, struct tile_s* array);



#endif