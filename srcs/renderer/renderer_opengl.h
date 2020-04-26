#pragma once

#include <thread>

#include <SDL.h>
#include <GL/glew.h>

#include "background.h"
#include "window.h"
#include "sprites.h"

struct gb_cpu_s;

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
    void UpdateVram();

private:
    SDL_Window* m_Window;
    gb_cpu_s* m_Gb;

    SDL_GLContext m_GlContext {nullptr};

    GLuint m_Texture {0};
    GLuint m_Pbo {0};

    Background m_Background;
    Window m_Menu;
    Sprites m_Sprites;
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