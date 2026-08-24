#include "renderer_opengl.h"

#include "gl_utils/glerr.h"
#include <algorithm>
#include <cstring>
#include <stdexcept>
#include <string>
#include <vector>

extern "C" {
    extern uint32_t m_TextureData[MAIN_SURFACE_HEIGHT][MAIN_SURFACE_WIDTH];
}

namespace GBMU
{

Renderer::Renderer()
{
    InitTexture();
    InitPbo();
}

Renderer::~Renderer()
{
    DestroyPbo();
    DestroyTexture();
}

void Renderer::Render()
{
    glBindBuffer(GL_PIXEL_UNPACK_BUFFER, m_Pbo);
    void* mappedBuffer = glMapBuffer(GL_PIXEL_UNPACK_BUFFER, GL_WRITE_ONLY);
    std::memcpy(mappedBuffer, m_TextureData, sizeof(m_TextureData));
    glUnmapBuffer(GL_PIXEL_UNPACK_BUFFER);

    glBindTexture(GL_TEXTURE_2D, m_Texture);
    glTexImage2D(
        GL_TEXTURE_2D,
        0,
        GL_RGBA,
        MAIN_SURFACE_WIDTH,
        MAIN_SURFACE_HEIGHT,
        0,
        GL_RGBA,
        GL_UNSIGNED_BYTE,
        0);
    glBindTexture(GL_TEXTURE_2D, 0);
    glBindBuffer(GL_PIXEL_UNPACK_BUFFER, 0);

    m_Rescale.Draw(m_Texture);
}

void Renderer::Clear()
{
    glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::SetWindowSize(int width, int height)
{
    glViewport(0, 0, width, height);
}

void Renderer::InitTexture()
{
    glGenTextures(1, &m_Texture);
    glBindTexture(GL_TEXTURE_2D, m_Texture);
    glTexImage2D(
        GL_TEXTURE_2D,
        0,
        GL_RGBA,
        MAIN_SURFACE_WIDTH,
        MAIN_SURFACE_HEIGHT,
        0,
        GL_RGBA,
        GL_UNSIGNED_BYTE,
        nullptr);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
}

void Renderer::DestroyTexture()
{
    glDeleteTextures(1, &m_Texture);
}

void Renderer::InitPbo()
{
    int pboSize = sizeof(m_TextureData);

    glGenBuffers(1, &m_Pbo);
    glBindBuffer(GL_PIXEL_UNPACK_BUFFER, m_Pbo);
    glBufferData(GL_PIXEL_UNPACK_BUFFER, pboSize, NULL, GL_STREAM_DRAW);
    glBindBuffer(GL_PIXEL_UNPACK_BUFFER, 0);
}

void Renderer::DestroyPbo()
{
    glDeleteBuffers(1, &m_Pbo);
}



} // namespace GBMU
