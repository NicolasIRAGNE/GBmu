#include "renderer_opengl.h"

#include <stdint.h>
#include <stdio.h>
#include <cstring>
#include <chrono>

#include "gl_utils/glerr.h"
#include "GL/glew.h"
#include "cpu.h"
#include "renderer/background.h"
#include "renderer/rescale.h"
#include "renderer/sprites.h"
#include "renderer/window.h"

extern "C" {
#include "gb.h"
#include "renderer.h"
}

namespace GBMU {

struct StaticInfos {
    float windowWidth;
    float windowHeight;
};

struct DynamicInfos {
    float timestamp;
};

Renderer::Renderer(gb_cpu_s* gb) :
    m_Gb(gb), m_Background(gb), m_Menu(gb), m_Sprites(gb) {}

Renderer::~Renderer() {
    Destroy();
}

int Renderer::Init()
{
    GLenum err = glewInit();
    if (err != GLEW_OK) {
        printf("Glew error: %s\n", glewGetErrorString(err));
        return -1;
    }

    glEnable(GL_BLEND); GLERR;
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); GLERR;

    glEnable(GL_DEPTH_TEST); GLERR;
    glDepthFunc(GL_ALWAYS); GLERR;

    glClearColor(0.2f, 0.2f, 0.2f, 1.0f); GLERR;

    int ret = InitUbos();
    if (ret < 0) {
        printf("Failed to init Ubos\n");
        return ret;
    }

    ret = InitFramebuffer();
    if (ret < 0) {
        printf("Failed to init Framebuffer\n");
        return ret;
    }

    ret = m_Background.Init();
    if (ret < 0) {
        printf("Failed to init background\n");
        return ret;
    }

    ret = m_Menu.Init();
    if (ret < 0) {
        printf("Failed to init window\n");
        return ret;
    }

    ret = m_Sprites.Init();
    if (ret < 0) {
        printf("Failed to init sprites\n");
        return ret;
    }

    ret = m_Rescale.Init(m_TargetTexture);
    if (ret < 0) {
        printf("Failed to init rescaling\n");
        return ret;
    }

    return 0;
}

int Renderer::Destroy()
{
    m_Sprites.Destroy();
    m_Menu.Destroy();
    m_Background.Destroy();

    glDeleteRenderbuffers(1, &m_DepthBuffer); GLERR;
    glDeleteTextures(1, &m_TargetTexture); GLERR;
    glDeleteFramebuffers(1, &m_FrameBuffer); GLERR;
    glDeleteBuffers(1, &m_VramUbo); GLERR;
    glDeleteBuffers(1, &m_DynamicInfosUbo); GLERR;
    glDeleteBuffers(1, &m_StaticInfosUbo); GLERR;

    return 0;
}

int Renderer::Clear() {
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT); GLERR;

    UpdateDynamicInfos();

    return 0;
}

int Renderer::Draw(int firstLine, int lastLine)
{
	uint8_t lcdc = (read_8(m_Gb, LCDC_OFFSET));

    if (m_WindowWidth == 0 || m_WindowHeight == 0) {
        return 0;
    }

    glBindFramebuffer(GL_FRAMEBUFFER, m_FrameBuffer); GLERR;
    glViewport(0, 0, MAIN_SURFACE_WIDTH, MAIN_SURFACE_HEIGHT); GLERR;

    // the draw_background property from Gb is handled inside (because we have to draw something)
    m_Background.Draw(firstLine, lastLine);

    if (m_Gb->draw_window && (lcdc & LCDC_WINDOW_ON)) {
        m_Menu.Draw(firstLine, lastLine);
    }

    if (m_Gb->draw_sprites)
    {
        glDepthFunc(GL_LEQUAL); GLERR;
        m_Sprites.Draw(firstLine, lastLine);
        glDepthFunc(GL_ALWAYS); GLERR;
    }
    glBindFramebuffer(GL_FRAMEBUFFER, 0); GLERR;
    return 0;
}

int Renderer::Render()
{
    glViewport(0, 0, m_WindowWidth, m_WindowHeight); GLERR;
    m_Rescale.Draw();

    return 0;
}

void Renderer::SetWindowSize(int width, int height)
{
    m_WindowWidth = width;
    m_WindowHeight = height;

    UpdateStaticInfos();
}

int Renderer::InitUbos()
{
    glGenBuffers(1, &m_StaticInfosUbo); GLERR;
    glBindBuffer(GL_UNIFORM_BUFFER, m_StaticInfosUbo); GLERR;
    glBufferData(GL_UNIFORM_BUFFER, sizeof(StaticInfos), nullptr, GL_STATIC_DRAW); GLERR;
    glBindBuffer(GL_UNIFORM_BUFFER, 0); GLERR;
    
    glBindBufferBase(GL_UNIFORM_BUFFER, 0, m_StaticInfosUbo); GLERR;

    glGenBuffers(1, &m_DynamicInfosUbo); GLERR;
    glBindBuffer(GL_UNIFORM_BUFFER, m_DynamicInfosUbo); GLERR;
    glBufferData(GL_UNIFORM_BUFFER, sizeof(DynamicInfos), nullptr, GL_DYNAMIC_DRAW); GLERR;
    glBindBuffer(GL_UNIFORM_BUFFER, 0); GLERR;
    
    glBindBufferBase(GL_UNIFORM_BUFFER, 1, m_DynamicInfosUbo); GLERR;

    glGenBuffers(1, &m_LcdUbo); GLERR;
    glBindBuffer(GL_UNIFORM_BUFFER, m_LcdUbo); GLERR;
    glBufferData(GL_UNIFORM_BUFFER, sizeof(Lcd) * 144, nullptr, GL_DYNAMIC_DRAW); GLERR;
    glBindBuffer(GL_UNIFORM_BUFFER, 0); GLERR;
    
    glBindBufferBase(GL_UNIFORM_BUFFER, 2, m_LcdUbo); GLERR;

    glGenBuffers(1, &m_VramUbo); GLERR;
    glBindBuffer(GL_UNIFORM_BUFFER, m_VramUbo); GLERR;
    glBufferData(GL_UNIFORM_BUFFER, VRAM_SIZE, nullptr, GL_DYNAMIC_DRAW); GLERR;
    glBindBuffer(GL_UNIFORM_BUFFER, 0); GLERR;
    
    glBindBufferBase(GL_UNIFORM_BUFFER, 3, m_VramUbo); GLERR;

    return 0;
}

int Renderer::InitFramebuffer()
{
    glGenFramebuffers(1, &m_FrameBuffer); GLERR;
    glBindFramebuffer(GL_FRAMEBUFFER, m_FrameBuffer); GLERR;

    glGenTextures(1, &m_TargetTexture); GLERR;
    glBindTexture(GL_TEXTURE_2D, m_TargetTexture); GLERR;
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, MAIN_SURFACE_WIDTH, MAIN_SURFACE_HEIGHT, 0, GL_RGB, GL_UNSIGNED_BYTE, nullptr); GLERR;
    glBindTexture(GL_TEXTURE_2D, 0); GLERR;
    
    glGenRenderbuffers(1, &m_DepthBuffer); GLERR;
    glBindRenderbuffer(GL_RENDERBUFFER, m_DepthBuffer); GLERR;
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT, MAIN_SURFACE_WIDTH, MAIN_SURFACE_HEIGHT); GLERR;
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, m_DepthBuffer); GLERR;

    glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, m_FrameBuffer, 0); GLERR;
    GLenum DrawBuffers = GL_COLOR_ATTACHMENT0;
    glDrawBuffers(1, &DrawBuffers); GLERR;

    if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) {
        GLERR;
        return -1;
    }

    glBindFramebuffer(GL_FRAMEBUFFER, 0); GLERR;

    return 0;
}

void Renderer::UpdateStaticInfos()
{
    StaticInfos infos;
    infos.windowWidth = static_cast<float>(m_WindowWidth);
    infos.windowHeight = static_cast<float>(m_WindowHeight);

    glBindBuffer(GL_UNIFORM_BUFFER, m_StaticInfosUbo); GLERR;
    GLvoid* ptr = glMapBuffer(GL_UNIFORM_BUFFER, GL_WRITE_ONLY); GLERR;
    std::memcpy(ptr, &infos, sizeof(infos));
    glUnmapBuffer(GL_UNIFORM_BUFFER); GLERR;
    glBindBuffer(GL_UNIFORM_BUFFER, 0); GLERR;
}

void Renderer::UpdateDynamicInfos()
{
    static auto begin = std::chrono::high_resolution_clock::now();
    auto now = std::chrono::high_resolution_clock::now();

    std::chrono::duration<float> timestamp = now - begin;
 GLERR;
    DynamicInfos infos;
    infos.timestamp = timestamp.count();

    glBindBuffer(GL_UNIFORM_BUFFER, m_DynamicInfosUbo); GLERR;
    GLvoid* ptr = glMapBuffer(GL_UNIFORM_BUFFER, GL_WRITE_ONLY); GLERR;
    std::memcpy(ptr, &infos, sizeof(infos));
    glUnmapBuffer(GL_UNIFORM_BUFFER);
    glBindBuffer(GL_UNIFORM_BUFFER, 0);
}

void Renderer::UpdateLcd()
{
    glBindBuffer(GL_UNIFORM_BUFFER, m_LcdUbo); GLERR;
    GLvoid* ptr = glMapBuffer(GL_UNIFORM_BUFFER, GL_WRITE_ONLY); GLERR;
    std::memcpy(ptr, m_Gb->lcd, sizeof(m_Gb->lcd));
    glUnmapBuffer(GL_UNIFORM_BUFFER); GLERR;
    glBindBuffer(GL_UNIFORM_BUFFER, 0); GLERR;
}

void Renderer::UpdateVram()
{
    glBindBuffer(GL_UNIFORM_BUFFER, m_VramUbo); GLERR;
    GLvoid* ptr = glMapBuffer(GL_UNIFORM_BUFFER, GL_WRITE_ONLY); GLERR;
    std::memcpy(ptr, m_Gb->vram, VRAM_SIZE);
    glUnmapBuffer(GL_UNIFORM_BUFFER); GLERR;
    glBindBuffer(GL_UNIFORM_BUFFER, 0); GLERR;
}

} // namespace GBMU