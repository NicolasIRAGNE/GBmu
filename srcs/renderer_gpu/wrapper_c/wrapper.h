/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapper.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 15:43:40 by niragne           #+#    #+#             */
/*   Updated: 2020/05/01 14:01:41 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

struct gb_cpu_s;

void* new_renderer(struct gb_cpu_s* gb);
void  delete_renderer(void* renderer);

int renderer_init(void* renderer);
int renderer_destroy(void* renderer);
void renderer_update_lcd(void* renderer);
void renderer_update_vram(void* renderer);
int renderer_clear(void* renderer);
int renderer_draw(void* renderer, int firstLine, int lastLine);
int renderer_render(void* renderer);

void renderer_set_window_size(void* renderer, int width, int height);
