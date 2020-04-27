#pragma once

#include <thread>

#include <SDL.h>

namespace GBMU {

class Renderer {
public:
    Renderer(SDL_Window* window);
    ~Renderer();

    int Init();
    int Destroy();

    int Render();

    int Loop();

private:
    SDL_Window* m_Window;

    SDL_GLContext m_GlContext {nullptr};
};

}

extern "C" {

void StartRenderer(SDL_Window* window) {
    new std::thread([window]() {
        GBMU::Renderer renderer(window);
        renderer.Init();
        renderer.Loop();
    });
}

}