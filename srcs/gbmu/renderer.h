/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 10:37:45 by niragne           #+#    #+#             */
/*   Updated: 2020/04/28 23:31:39 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H
# include "gb.h"
# include "cpu.h"
# include "SDL.h"
# include "draw.h"

# define VRAM_WINDOW_WIDTH (256 * 2)
# define VRAM_WINDOW_HEIGHT 512
# define VRAM_SURFACE_WIDTH (128 * 2)
# define VRAM_SURFACE_HEIGHT (256)

# define MAIN_WINDOW_WIDTH (160 * 2)
# define MAIN_WINDOW_HEIGHT (144 * 2)

# define TILE_SURFACE_WIDTH		8
# define TILE_SURFACE_HEIGHT	8

# define USERSCREEN_WIDTH		(160)
# define USERSCREEN_HEIGHT		(144)



struct	sdl_context_s
{
	SDL_Window *win;
	SDL_Renderer *renderer;
    SDL_Surface *surface;
    SDL_Texture *texture;
	SDL_GameController* controller;
	SDL_GLContext* glcontext;
};

struct 	tile_s
{
	uint16_t	pixels_raw[8];
	uint8_t		index[8][8];
	SDL_Surface	*surface;
};


void	vram_viewer_loop(struct gbmu_wrapper_s* wrapper, struct tile_s array[2][TILES_COUNT]);
int     init_vram_viewer(struct sdl_context_s* context);
int     init_main_window(struct sdl_context_s* context);
int     init_sdl(void);
void	destroy_context(struct sdl_context_s* context);
void	renderer_loop(struct gbmu_wrapper_s* wrapper);
struct tile_s	create_tile(struct gb_cpu_s* gb, uint16_t index, uint8_t bank);
uint32_t	get_color_from_palette(uint8_t index, uint32_t* palette);
int		print_tile(struct gb_cpu_s* gb, SDL_Surface* surface, struct tile_s* tile, int index, SDL_Rect pos, enum tile_type_e type);
void	resize_tile(uint32_t* pixels, struct tile_s* tile, int x, int y);
void	fill_tile_array(struct gb_cpu_s* gb, struct tile_s array[2][TILES_COUNT]);
void	main_window_loop(struct gbmu_wrapper_s* wrapper, void* renderer);
void	handle_joypad(struct gb_cpu_s* gb, SDL_GameController* controller, const Uint8* state);
void	check_savestate(struct gb_cpu_s* gb, const Uint8* state, SDL_Event event);
void	update_palettes(struct gb_cpu_s* gb);

void	display_background(struct gbmu_wrapper_s* wrapper, uint8_t lcdc, struct tile_s** array, SDL_Surface* tmp_surface);
void	display_sprites(struct gbmu_wrapper_s* wrapper, uint8_t lcdc, struct tile_s** array);


#endif