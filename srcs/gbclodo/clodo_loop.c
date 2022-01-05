/**
 * @file clodo_loop.c
 * @author Nicolas IRAGNE (nicolas.iragne@alyce.fr)
 * @brief 
 * @date 2022-01-05
 * 
 * @copyright Copyright Alyce (c) 2022
 */

#include "SDL_surface.h"
#include "SDL_video.h"
#include "renderer/wrapper_c/wrapper.h"
#include "renderer.h"
#include "gb.h"

extern uint32_t m_TextureData[MAIN_SURFACE_HEIGHT][MAIN_SURFACE_WIDTH];

void	execute_loop(struct gbmu_wrapper_s* wrapper, void* renderer)
{
	int err = 0;
	struct gb_cpu_s* gb = wrapper->gb;
	uint8_t last_line = 0;
	uint8_t	last_line_drawn = 0;
	uint8_t	last_pixel_drawn = 0;
    // SDL_Surface* tmp_surface = SDL_CreateRGBSurface(0, BGMAP_SIZE, BGMAP_SIZE, 32, 0, 0, 0, 0);
	struct tile_s tiles[2][TILES_COUNT];
	while (gb->running)
	{
		if (set_interrupt(gb))
		{
			// gb->halted = 0;
			if (gb->ime)
			{
				interrupt_a16(gb, gb->interrupt);
				gb->interrupt = 0;
			}
		}
		if (gb->paused)
			execute_debugger(gb);
		else
			err = handle_instruction(gb);
		if (err)
			gb->paused = 1;

		if (gb->gpu.y_coord < 144 && (last_line_drawn != gb->gpu.y_coord || last_pixel_drawn != gb->gpu.x_coord))
		{
			uint8_t lcdc = (read_8(gb, LCDC_OFFSET));
			if ((lcdc & LCDC_ON) || !gb->booted)
			{
				for (int i = last_pixel_drawn; i < gb->gpu.x_coord; i++) {
					DrawPixel(gb->gpu.y_coord, i);
				}
			}
			last_pixel_drawn = gb->gpu.x_coord;
			last_line_drawn = gb->gpu.y_coord;
		}
		last_line = gb->gpu.y_coord;
		gpu_tick(gb);
		if (wrapper->gb->gpu.y_coord == 144 && last_line != 144)
		{
			uint8_t lcdc = (read_8(gb, LCDC_OFFSET));
			if (!(lcdc & LCDC_ON) && gb->booted)
			{
				// renderer_clear(renderer);
			}
			if (wrapper->gb->vram_viewer_running)
			{
				update_palettes(wrapper->gb);
				fill_tile_array(wrapper->gb, tiles);
				vram_viewer_loop(wrapper, tiles);
			}
			// if (!gb->halted)
				renderer_render(renderer);
			SDL_GL_SwapWindow(wrapper->main_context->win);
			// renderer_clear(renderer);
			last_line_drawn = 0;
		}
		if (gb->cycle - gb->last_sleep > (70224 / 4))
		{
			// usleep(128);
			main_window_loop(wrapper, renderer);
			gb->last_sleep = gb->cycle;
		}
		update_div_register(gb);
		update_timer_register(gb);
	}
}