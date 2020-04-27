#include "renderer_opengl.h"

#include <iostream>

#include "gl_utils/compile_program.h"

namespace GBMU {

Renderer::Renderer(SDL_Window* window, gb_cpu_s* gb) : m_Window(window), m_Gb(gb) {}

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

    float vertices[] = {
        -0.5f, -0.5f,
         0.5f, -0.5f,
         0.0f,  0.5f,
    };

    m_Program = compileProgram(
        "C:/Users/iwan/GBmu/srcs/renderer/shaders/vertex.glsl",
        "C:/Users/iwan/GBmu/srcs/renderer/shaders/fragment.glsl");

    if (!m_Program) {
        printf("failed to create program\n");
        return -1;
    }
    
    glBindAttribLocation(m_Program, 0, "in_position");
    glBindAttribLocation(m_Program, 1, "in_color");

    float data[] = {
        -1.f,  0.f,
         1.f, -1.f,
         1.f,  1.f,

        1.f, 0.f, 0.f, 1.f,
        0.f, 1.f, 0.f, 1.f,
        0.f, 0.f, 1.f, 1.f,
    };

    glGenVertexArrays(1, &m_Vao);
    glBindVertexArray(m_Vao);
    glGenBuffers(1, &m_Vbo);
    glBindBuffer(GL_ARRAY_BUFFER, m_Vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glVertexAttribPointer(
        1, 4, GL_FLOAT, GL_FALSE, 0, (void*)(sizeof(float) * 6));

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glClearColor(0.5f, 0.5f, 0.5f, 1.0f);

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
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(m_Program);
    glBindVertexArray(m_Vao);
    glBindBuffer(GL_ARRAY_BUFFER, m_Vbo);

    glDrawArrays(GL_TRIANGLES, 0, 3);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    glUseProgram(0);

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