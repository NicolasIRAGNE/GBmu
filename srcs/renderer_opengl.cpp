#include "renderer_opengl.h"

#include <iostream>

#include <GL/glew.h>

namespace GBMU {

Renderer::Renderer(SDL_Window* window) : m_Window(window) {}

Renderer::~Renderer() {
    Destroy();
}

int Renderer::Init()
{
    m_GlContext = SDL_GL_CreateContext(m_Window);

    GLenum ret = glewInit();
    if (ret != GLEW_OK) {
        printf("failed to init glew\n");
        return -1;
    }

    return 0;
}

int Renderer::Destroy()
{
    if (m_GlContext) {
        SDL_GL_DeleteContext(m_GlContext);
    }

    return 0;
}

int Renderer::Render() {
    glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    SDL_GL_SwapWindow(m_Window);

    return 0;
}

int Renderer::Loop() {
    while (1) {
        Render();
    }

    return 0;
}

}