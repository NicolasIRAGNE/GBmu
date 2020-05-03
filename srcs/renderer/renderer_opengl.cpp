#include "renderer_opengl.h"

#include <iostream>
#include <vector>
#include <cstring>

extern "C" {
#include "gb.h"
}

namespace GBMU {

Renderer::Renderer(gb_cpu_s* gb) :
    m_Gb(gb), m_Background(gb), m_Menu(gb), m_Sprites(gb) {}

Renderer::~Renderer() {
    Destroy();
}

int Renderer::Init()
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glClearColor(1.f, 0.f, 0.f, 1.0f);

    glGenBuffers(1, &m_VramUbo);
    glBindBuffer(GL_UNIFORM_BUFFER, m_VramUbo);
    glBufferData(GL_UNIFORM_BUFFER, VRAM_SIZE, nullptr, GL_DYNAMIC_COPY);
    glBindBuffer(GL_UNIFORM_BUFFER, 0);
    
    glBindBufferBase(GL_UNIFORM_BUFFER, 2, m_VramUbo);

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
		glClear(0);
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

void Renderer::UpdateVram()
{
    glBindBuffer(GL_UNIFORM_BUFFER, m_VramUbo);
    GLvoid* ptr = glMapBuffer(GL_UNIFORM_BUFFER, GL_WRITE_ONLY);
    std::memcpy(ptr, m_Gb->vram, VRAM_SIZE);
    glUnmapBuffer(GL_UNIFORM_BUFFER);
    glBindBuffer(GL_UNIFORM_BUFFER, 0);
}

} // namespace GBMU