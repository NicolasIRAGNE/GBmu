#include "window.h"

#include <cstring>

#include "gl_utils/compile_program.h"

extern "C" {
#include "gb.h"
}

namespace GBMU {

Window::Window(gb_cpu_s* gb) : m_Gb(gb) {}

Window::~Window()
{
    Destroy();
}

int Window::Init()
{
	glGenVertexArrays(1, &m_Vao);
    glBindVertexArray(m_Vao);
    
	m_Program = compileProgram(
        "shaders/window.vert",
        "shaders/window.frag");

    if (!m_Program) {
        printf("failed to create program\n");
        return -1;
    }

    glBindAttribLocation(m_Program, 0, "inVertex");

    constexpr float quad[] = {
        -1.f, -1.f,
        -1.f,  1.f,
         1.f, -1.f,
         1.f,  1.f,
    };

  
    glGenBuffers(1, &m_Vbo);
    glBindBuffer(GL_ARRAY_BUFFER, m_Vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(quad), quad, GL_DYNAMIC_DRAW);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);

    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    m_WxLoc     = glGetUniformLocation(m_Program, "wx");
    m_WyLoc     = glGetUniformLocation(m_Program, "wy");
    m_LcdcLoc   = glGetUniformLocation(m_Program, "lcdc");
    m_ColorsLoc = glGetUniformLocation(m_Program, "colors");

    return 0;
}

int Window::Destroy()
{
    glDeleteBuffers(1, &m_Vbo);
    glDeleteVertexArrays(1, &m_Vao);
    glDeleteProgram(m_Program);

    return 0;
}

int Window::Draw(int firstLine, int lastLine)
{
    UpdateColors();

    glUseProgram(m_Program);

    int wx = (read_8(m_Gb, WX_OFFSET)) - 7;
    int wy = (read_8(m_Gb, WY_OFFSET));
    
    if (lastLine < wy) {
        return 0;
    }

    if (firstLine < wy) {
        firstLine = wy;
    }

    UpdateVertex(wx, firstLine, lastLine);

    uint8_t lcdc = (read_8(m_Gb, LCDC_OFFSET));
    glUniform1i(m_WxLoc, wx);
    glUniform1i(m_WyLoc, wy);
    glUniform1ui(m_LcdcLoc, lcdc);

    glUseProgram(0);

    glUseProgram(m_Program);
    glBindVertexArray(m_Vao);
    glBindBuffer(GL_ARRAY_BUFFER, m_Vbo);

    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    glUseProgram(0);

    return 0;
}

void Window::UpdateVertex(int wx, int firstLine, int lastLine)
{
    float x1 = static_cast<float>(wx) / 160.f * 2.f - 1.f;
    float x2 = 1.f;

    float y1 = static_cast<float>(firstLine) / 144.f * 2.f - 1.f;
    float y2 = static_cast<float>(lastLine + 1) / 144.f * 2.f - 1.f;
    y1 *= -1.f;
    y2 *= -1.f;

    float quad[] = {
        x1, y1,
        x1, y2,
        x2, y1,
        x2, y2,
    };

    glBindBuffer(GL_ARRAY_BUFFER, m_Vbo);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(quad), quad);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Window::UpdateColors()
{
    constexpr float monochromePalette[4][4] = {
        {0.8f, 0.8f, 0.8f, 1.f},
        {0.5f, 0.5f, 0.5f, 1.f},
        {0.3f, 0.3f, 0.3f, 1.f},
        {0.1f, 0.1f, 0.1f, 1.f},
    };

    float colors[4][4];

    uint8_t bgp = read_8(m_Gb, BGP_OFFSET);
    std::memcpy(&colors[0], &monochromePalette[(bgp & 0b00000011) >> 0], 4 * sizeof(float));
    std::memcpy(&colors[2], &monochromePalette[(bgp & 0b00001100) >> 2], 4 * sizeof(float));
    std::memcpy(&colors[1], &monochromePalette[(bgp & 0b00110000) >> 4], 4 * sizeof(float));
    std::memcpy(&colors[3], &monochromePalette[(bgp & 0b11000000) >> 6], 4 * sizeof(float));

    glUseProgram(m_Program);
    glUniform4fv(m_ColorsLoc, 4, (const GLfloat*)colors);
    glUseProgram(0);
}

} // namespace GBMU