/**
 * @file renderer_sdl.h
 * @author Nicolas IRAGNE (nicolas.iragne@alyce.fr)
 * @brief 
 * @date 2021-12-17
 * 
 * @copyright Copyright Alyce (c) 2021
 */

#pragma once
#include "renderer.h"

struct gb_cpu_s;

void* new_renderer(struct gb_cpu_s* gb);
void  delete_renderer(void* renderer);

int renderer_init(void* renderer, struct sdl_context_s* sdl_context);
int renderer_destroy(void* renderer);
void renderer_update_lcd(void* renderer);
void renderer_update_vram(void* renderer);
int renderer_clear(void* renderer);
int renderer_draw(void* renderer, int firstLine, int lastLine);
int renderer_render(void* renderer);

void renderer_set_window_size(void* renderer, int width, int height);

struct sdl_renderer_s {
    struct sdl_context_s* sdl_context;
};