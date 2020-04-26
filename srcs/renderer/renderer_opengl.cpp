#include "renderer_opengl.h"

#include <iostream>
#include <vector>

extern "C" {
#include "gb.h"
}

static void checkGlError() {
    GLenum aaa = glGetError();
    if (aaa != GL_NO_ERROR) {
        printf("%#x\n", aaa);
    }
}

namespace GBMU {

Renderer::Renderer(SDL_Window* window, gb_cpu_s* gb) :
    m_Window(window), m_Gb(gb), m_Background(gb) {}

Renderer::~Renderer() {
    Destroy();
}

int Renderer::Init()
{
    m_GlContext = SDL_GL_CreateContext(m_Window);

    GLenum glewRet = glewInit();
    if (glewRet != GLEW_OK) {
        printf("failed to init glew\n");
        return -1;
    }

    glGenTextures(1, &m_Texture);
    glBindTexture(GL_TEXTURE_2D, m_Texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glBindTexture(GL_TEXTURE_2D, 0);

    glGenBuffers(1, &m_Pbo);

    int ret = m_Background.Init();
    if (ret < 0) {
        return ret;
    }

    return 0;
}

int Renderer::Destroy()
{
    m_Background.Destroy();

    glDeleteBuffers(1, &m_Pbo);
    glDeleteTextures(1, &m_Texture);

    if (m_GlContext) {
        SDL_GL_DeleteContext(m_GlContext);
    }

    return 0;
}

int Renderer::Render() {
    glClear(GL_COLOR_BUFFER_BIT);

    UpdateVram();

    glBindTexture(GL_TEXTURE_2D, m_Texture);

    m_Background.Draw();

    glBindTexture(GL_TEXTURE_2D, m_Texture);

    SDL_GL_SwapWindow(m_Window);

    return 0;
}

int Renderer::Loop() {
    while (m_Gb->running) {
        Render();
    }

    return 0;
}

void Renderer::UpdateVram()
{
    glBindBuffer(GL_PIXEL_UNPACK_BUFFER, m_Pbo);
    glBufferData(GL_PIXEL_UNPACK_BUFFER, VRAM_SIZE, NULL, GL_STREAM_DRAW);
    void* mappedBuffer = glMapBuffer(GL_PIXEL_UNPACK_BUFFER, GL_WRITE_ONLY);

    memcpy(mappedBuffer, m_Gb->vram, VRAM_SIZE);

    glBindBuffer(GL_PIXEL_UNPACK_BUFFER, m_Pbo);
    glUnmapBuffer(GL_PIXEL_UNPACK_BUFFER);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_R8, 128, 64, 0, GL_RED, GL_UNSIGNED_BYTE, 0);
    glBindBuffer(GL_PIXEL_UNPACK_BUFFER, 0);
}

}