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

void renderer_render(void* renderer);
void renderer_clear(void* renderer);

void renderer_set_window_size(void* renderer, int width, int height);
