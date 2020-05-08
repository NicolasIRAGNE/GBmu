#include "renderer_opengl.h"

#include <iostream>
#include <vector>
#include <cstring>

extern "C" {
#include "gb.h"
}

namespace GBMU {

struct GlobalInfos {
    float windowWidth;
    float windowHeight;
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
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);

    glGenBuffers(1, &m_GlobalInfosUbo);
    glBindBuffer(GL_UNIFORM_BUFFER, m_GlobalInfosUbo);
    glBufferData(GL_UNIFORM_BUFFER, sizeof(GlobalInfos), nullptr, GL_STATIC_DRAW);
    glBindBuffer(GL_UNIFORM_BUFFER, 0);
    
    glBindBufferBase(GL_UNIFORM_BUFFER, 0, m_GlobalInfosUbo);

    glGenBuffers(1, &m_VramUbo);
    glBindBuffer(GL_UNIFORM_BUFFER, m_VramUbo);
    glBufferData(GL_UNIFORM_BUFFER, VRAM_SIZE, nullptr, GL_DYNAMIC_DRAW);
    glBindBuffer(GL_UNIFORM_BUFFER, 0);
    
    glBindBufferBase(GL_UNIFORM_BUFFER, 1, m_VramUbo);

    int ret = m_Background.Init();
    if (ret < 0) {
        return ret;
    }

    ret = m_Menu.Init();
    if (ret < 0) {
        return ret;
    }

    ret = m_Sprites.Init();
    if (ret < 0) {
        return ret;
    }

    return 0;
}

int Renderer::Destroy()
{
    m_Sprites.Destroy();
    m_Menu.Destroy();
    m_Background.Destroy();

    glDeleteBuffers(1, &m_VramUbo);

    return 0;
}

int Renderer::Render(int firstLine, int lastLine) {

    uint8_t lcdc = (read_8(m_Gb, LCDC_OFFSET));
	if (!(lcdc & LCDC_ON) && m_Gb->booted)
	{
		glClear(GL_COLOR_BUFFER_BIT);
		return 0;
	}

    if (m_WindowWidth == 0 || m_WindowHeight == 0) {
        return 0;
    }

	if (m_Gb->vram_updated) {
		m_Gb->vram_updated = 0;
		UpdateVram();
	}

    glBindBuffer(GL_UNIFORM_BUFFER, m_VramUbo);

    m_Background.Draw(firstLine, lastLine);

    if (lcdc & LCDC_WINDOW_ON) {
        m_Menu.Draw(firstLine, lastLine);
    }

    m_Sprites.Draw(firstLine, lastLine);

    glBindBuffer(GL_UNIFORM_BUFFER, 0);

    return 0;
}

void Renderer::SetWindowSize(int width, int height)
{
    glViewport(0, 0, width, height);

    m_WindowWidth = width;
    m_WindowHeight = height;

    GlobalInfos infos;
    infos.windowWidth = static_cast<float>(width);
    infos.windowHeight = static_cast<float>(height);

    glBindBuffer(GL_UNIFORM_BUFFER, m_GlobalInfosUbo);
    GLvoid* ptr = glMapBuffer(GL_UNIFORM_BUFFER, GL_WRITE_ONLY);
    std::memcpy(ptr, &infos, sizeof(GlobalInfos));
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