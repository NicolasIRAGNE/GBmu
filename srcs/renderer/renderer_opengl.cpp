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

    glGenTextures(1, &m_Texture);
    glBindTexture(GL_TEXTURE_2D, m_Texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glBindTexture(GL_TEXTURE_2D, 0);

    glGenBuffers(1, &m_Pbo);
    glBindBuffer(GL_PIXEL_UNPACK_BUFFER, m_Pbo);
    glBufferData(GL_PIXEL_UNPACK_BUFFER, VRAM_SIZE, nullptr, GL_DYNAMIC_DRAW);
    glBindBuffer(GL_PIXEL_UNPACK_BUFFER, 0);

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

    glDeleteBuffers(1, &m_Pbo);
    glDeleteTextures(1, &m_Texture);

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

    glBindTexture(GL_TEXTURE_2D, m_Texture);

    m_Background.Draw(firstLine, lastLine);

    if (lcdc & LCDC_WINDOW_ON) {
        m_Menu.Draw(firstLine, lastLine);
    }

    m_Sprites.Draw(firstLine, lastLine);

    glBindTexture(GL_TEXTURE_2D, m_Texture);

    return 0;
}

void Renderer::UpdateVram()
{
    glBindBuffer(GL_PIXEL_UNPACK_BUFFER, m_Pbo);
    void* mappedBuffer = glMapBuffer(GL_PIXEL_UNPACK_BUFFER, GL_WRITE_ONLY);
    std::memcpy(mappedBuffer, m_Gb->vram, VRAM_SIZE);
    glUnmapBuffer(GL_PIXEL_UNPACK_BUFFER);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_R8, 128, 64, 0, GL_RED, GL_UNSIGNED_BYTE, 0);
    glBindBuffer(GL_PIXEL_UNPACK_BUFFER, 0);
}

} // namespace GBMU