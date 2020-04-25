#pragma once

#include <thread>

#include <SDL.h>
#include <GL/glew.h>

extern "C" {
#include "gb.h"
}

namespace GBMU {

class Renderer {
public:
    Renderer(SDL_Window* window, gb_cpu_s* gb);
    ~Renderer();

    int Init();
    int Destroy();

    int Render();

    int Loop();

private:
    SDL_Window* m_Window;
    gb_cpu_s* m_Gb;

    SDL_GLContext m_GlContext {nullptr};

    GLuint m_Program {0};
    GLuint m_Vao {0};
    GLuint m_Vbo {0};
    GLuint m_Texture {0};
};

}

extern "C" {

void StartRenderer(SDL_Window* window, gb_cpu_s* gb) {
    new std::thread([window, gb]() {
        GBMU::Renderer renderer(window, gb);
        renderer.Init();
        renderer.Loop();
    });
}

}