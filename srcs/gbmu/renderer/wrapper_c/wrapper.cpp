/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapper.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 15:39:03 by niragne           #+#    #+#             */
/*   Updated: 2020/05/01 14:02:56 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer/renderer_opengl.h"
#include <cstdio>

extern "C"
{

void* new_renderer(struct gb_cpu_s* gb)
{
    return(new GBMU::Renderer());
}

void delete_renderer(void* renderer)
{
    auto ptr = reinterpret_cast<GBMU::Renderer*>(renderer);
    delete ptr;
}

void renderer_clear(void* renderer)
{
    auto ptr = reinterpret_cast<GBMU::Renderer*>(renderer);
    ptr->Clear();
}

void renderer_render(void* renderer, uint32_t m_TextureData[MAIN_SURFACE_HEIGHT][MAIN_SURFACE_WIDTH])
{
    auto ptr = reinterpret_cast<GBMU::Renderer*>(renderer);
    ptr->Render();
}

void renderer_set_window_size(void* renderer, int width, int height)
{
    auto ptr = reinterpret_cast<GBMU::Renderer*>(renderer);
	ptr->SetWindowSize(width, height);
}

} // extern "C"