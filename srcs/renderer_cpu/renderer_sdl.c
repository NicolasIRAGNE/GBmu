/**
 * @file renderer_sdl.c
 * @author Nicolas IRAGNE (nicolas.iragne@alyce.fr)
 * @brief 
 * @date 2021-12-17
 * 
 * @copyright Copyright Alyce (c) 2021
 */

#include "renderer_sdl.h"
#include "gb.h"

int renderer_init(void* renderer, struct sdl_context_s* sdl_context)
{
    struct sdl_renderer_s* sdl_renderer = (struct sdl_renderer_s*)renderer;
    sdl_renderer->sdl_context = sdl_context;
    return (0);
}

void* new_renderer(struct gb_cpu_s* gb) 
{
    void* res = malloc(sizeof(struct sdl_context_s));
    return res;
}

void delete_renderer(void* renderer) 
{
    if (renderer)
        free(renderer);
}

void renderer_update_lcd(void* renderer) 
{
    
}

void renderer_update_vram(void* renderer) 
{
    
}

int renderer_clear(void* renderer) 
{
    return 0;   
}

int renderer_draw(void* renderer, int firstLine, int lastLine) 
{
    return 0;
}

int renderer_render(void* renderer) 
{
    return 0;
}

void renderer_set_window_size(void* renderer, int width, int height) 
{
    struct sdl_renderer_s* sdl_renderer = (struct sdl_renderer_s*)renderer;
SDL_SetWindowSize(sdl_renderer->sdl_context->win, width, height);
}
