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

extern "C"
{

void*    new_renderer(struct gb_cpu_s* gb)
{
    return(new GBMU::Renderer(gb));
}

void    delete_renderer(void* renderer)
{
    auto ptr = reinterpret_cast<GBMU::Renderer*>(renderer);
    delete ptr;
}

void    renderer_init(void* renderer)
{
    auto ptr = reinterpret_cast<GBMU::Renderer*>(renderer);
    ptr->Init();
}

void    renderer_destroy(void* renderer)
{
    auto ptr = reinterpret_cast<GBMU::Renderer*>(renderer);
    ptr->Destroy();
}

void    renderer_render(void* renderer, int firstLine, int lastLine)
{
    auto ptr = reinterpret_cast<GBMU::Renderer*>(renderer);
    ptr->Render(firstLine, lastLine);
}

void    renderer_set_window_size(void* renderer, int width, int height)
{
    auto ptr = reinterpret_cast<GBMU::Renderer*>(renderer);
	ptr->SetWindowSize(width, height);
}

} // extern "C"