#include "renderer_opengl.h"

#include <iostream>
#include <vector>
#include <cstring>
#include <chrono>

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

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_ALWAYS);

    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);

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

    glDeleteRenderbuffers(1, &m_DepthBuffer);
    glDeleteTextures(1, &m_TargetTexture);
    glDeleteFramebuffers(1, &m_FrameBuffer);
    glDeleteBuffers(1, &m_VramUbo);
    glDeleteBuffers(1, &m_DynamicInfosUbo);
    glDeleteBuffers(1, &m_StaticInfosUbo);

    return 0;
}

int Renderer::Clear() {
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

    UpdateDynamicInfos();

    return 0;
}

int Renderer::Draw(int firstLine, int lastLine)
{
	uint8_t lcdc = (read_8(m_Gb, LCDC_OFFSET));

    if (m_WindowWidth == 0 || m_WindowHeight == 0) {
        return 0;
    }

    glBindFramebuffer(GL_FRAMEBUFFER, m_FrameBuffer);
    glViewport(0, 0, MAIN_SURFACE_WIDTH, MAIN_SURFACE_HEIGHT);

    // the draw_background property from Gb is handled inside (because we have to draw something)
    m_Background.Draw(firstLine, lastLine);

    if (m_Gb->draw_window && (lcdc & LCDC_WINDOW_ON)) {
        m_Menu.Draw(firstLine, lastLine);
    }

    if (m_Gb->draw_sprites)
    {
        glDepthFunc(GL_LEQUAL);
        m_Sprites.Draw(firstLine, lastLine);
        glDepthFunc(GL_ALWAYS);
    }
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    return 0;
}

int Renderer::Render()
{
    glViewport(0, 0, m_WindowWidth, m_WindowHeight);
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
    glGenBuffers(1, &m_StaticInfosUbo);
    glBindBuffer(GL_UNIFORM_BUFFER, m_StaticInfosUbo);
    glBufferData(GL_UNIFORM_BUFFER, sizeof(StaticInfos), nullptr, GL_STATIC_DRAW);
    glBindBuffer(GL_UNIFORM_BUFFER, 0);
    
    glBindBufferBase(GL_UNIFORM_BUFFER, 0, m_StaticInfosUbo);

    glGenBuffers(1, &m_DynamicInfosUbo);
    glBindBuffer(GL_UNIFORM_BUFFER, m_DynamicInfosUbo);
    glBufferData(GL_UNIFORM_BUFFER, sizeof(DynamicInfos), nullptr, GL_DYNAMIC_DRAW);
    glBindBuffer(GL_UNIFORM_BUFFER, 0);
    
    glBindBufferBase(GL_UNIFORM_BUFFER, 1, m_DynamicInfosUbo);

    glGenBuffers(1, &m_LcdUbo);
    glBindBuffer(GL_UNIFORM_BUFFER, m_LcdUbo);
    glBufferData(GL_UNIFORM_BUFFER, sizeof(Lcd) * 144, nullptr, GL_DYNAMIC_DRAW);
    glBindBuffer(GL_UNIFORM_BUFFER, 0);
    
    glBindBufferBase(GL_UNIFORM_BUFFER, 2, m_LcdUbo);

    glGenBuffers(1, &m_VramUbo);
    glBindBuffer(GL_UNIFORM_BUFFER, m_VramUbo);
    glBufferData(GL_UNIFORM_BUFFER, VRAM_SIZE, nullptr, GL_DYNAMIC_DRAW);
    glBindBuffer(GL_UNIFORM_BUFFER, 0);
    
    glBindBufferBase(GL_UNIFORM_BUFFER, 3, m_VramUbo);

    return 0;
}

int Renderer::InitFramebuffer()
{
    glGenFramebuffers(1, &m_FrameBuffer);
    glBindFramebuffer(GL_FRAMEBUFFER, m_FrameBuffer);

    glGenTextures(1, &m_TargetTexture);
    glBindTexture(GL_TEXTURE_2D, m_TargetTexture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, MAIN_SURFACE_WIDTH, MAIN_SURFACE_HEIGHT, 0, GL_RGB, GL_UNSIGNED_BYTE, nullptr);
    glBindTexture(GL_TEXTURE_2D, 0);
    
    glGenRenderbuffers(1, &m_DepthBuffer);
    glBindRenderbuffer(GL_RENDERBUFFER, m_DepthBuffer);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT, MAIN_SURFACE_WIDTH, MAIN_SURFACE_HEIGHT);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, m_DepthBuffer);

    glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, m_FrameBuffer, 0);
    GLenum DrawBuffers = GL_COLOR_ATTACHMENT0;
    glDrawBuffers(1, &DrawBuffers);

    if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) {
        return -1;
    }

    glBindFramebuffer(GL_FRAMEBUFFER, 0);

    return 0;
}

void Renderer::UpdateStaticInfos()
{
    StaticInfos infos;
    infos.windowWidth = static_cast<float>(m_WindowWidth);
    infos.windowHeight = static_cast<float>(m_WindowHeight);

    glBindBuffer(GL_UNIFORM_BUFFER, m_StaticInfosUbo);
    GLvoid* ptr = glMapBuffer(GL_UNIFORM_BUFFER, GL_WRITE_ONLY);
    std::memcpy(ptr, &infos, sizeof(infos));
    glUnmapBuffer(GL_UNIFORM_BUFFER);
    glBindBuffer(GL_UNIFORM_BUFFER, 0);
}

void Renderer::UpdateDynamicInfos()
{
    static auto begin = std::chrono::high_resolution_clock::now();
    auto now = std::chrono::high_resolution_clock::now();

    std::chrono::duration<float> timestamp = now - begin;

    DynamicInfos infos;
    infos.timestamp = timestamp.count();

    glBindBuffer(GL_UNIFORM_BUFFER, m_DynamicInfosUbo);
    GLvoid* ptr = glMapBuffer(GL_UNIFORM_BUFFER, GL_WRITE_ONLY);
    std::memcpy(ptr, &infos, sizeof(infos));
    glUnmapBuffer(GL_UNIFORM_BUFFER);
    glBindBuffer(GL_UNIFORM_BUFFER, 0);
}

void Renderer::UpdateLcd()
{
    glBindBuffer(GL_UNIFORM_BUFFER, m_LcdUbo);
    GLvoid* ptr = glMapBuffer(GL_UNIFORM_BUFFER, GL_WRITE_ONLY);
    std::memcpy(ptr, m_Gb->lcd, sizeof(m_Gb->lcd));
    glUnmapBuffer(GL_UNIFORM_BUFFER);
    glBindBuffer(GL_UNIFORM_BUFFER, 0);
}

void Renderer::UpdateVram()
{
    glBindBuffer(GL_UNIFORM_BUFFER, m_VramUbo);
    GLvoid* ptr = glMapBuffer(GL_UNIFORM_BUFFER, GL_WRITE_ONLY);
    std::memcpy(ptr, m_Gb->vram, VRAM_SIZE);
    glUnmapBuffer(GL_UNIFORM_BUFFER);
    glBindBuffer(GL_UNIFORM_BUFFER, 0);
}

} // namespace GBMU