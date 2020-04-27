#include "window.h"

#include "gl_utils/compile_program.h"

#include <cstring>

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

Window::Window(gb_cpu_s* gb) : m_Gb(gb) {}

Window::~Window()
{
    Destroy();
}

int Window::Init()
{
    m_Program = compileProgram(
        "../srcs/renderer/shaders/window.vert",
        "../srcs/renderer/shaders/window.frag");

    if (!m_Program) {
        printf("failed to create program\n");
        return -1;
    }

    glBindAttribLocation(m_Program, 0, "inVertex");

    float quad[] = {
        -1.f, -1.f,
        -1.f,  1.f,
         1.f, -1.f,
         1.f,  1.f,
    };

    glGenVertexArrays(1, &m_Vao);
    glBindVertexArray(m_Vao);
    glGenBuffers(1, &m_Vbo);
    glBindBuffer(GL_ARRAY_BUFFER, m_Vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(quad), quad, GL_STREAM_DRAW);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);

    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    m_WxLoc     = glGetUniformLocation(m_Program, "wx");
    m_WyLoc     = glGetUniformLocation(m_Program, "wy");
    m_LcdcLoc   = glGetUniformLocation(m_Program, "lcdc");
    m_ColorsLoc = glGetUniformLocation(m_Program, "colors");
    m_LineLoc	= glGetUniformLocation(m_Program, "line");

    return 0;
}

int Window::Destroy()
{
    glDeleteBuffers(1, &m_Vbo);
    glDeleteVertexArrays(1, &m_Vao);
    glDeleteProgram(m_Program);

    return 0;
}

int Window::Draw()
{
    UpdateColors();

    glUseProgram(m_Program);

    int wx = (read_8(m_Gb, WX_OFFSET)) - 7;
    int wy = (read_8(m_Gb, WY_OFFSET));
	if (wy > m_Gb->gpu.y_coord)
		return 0;
    uint8_t lcdc = (read_8(m_Gb, LCDC_OFFSET));
    glUniform1i(m_WxLoc, wx);
    glUniform1i(m_WyLoc, wy);
    glUniform1ui(m_LcdcLoc, lcdc);
    glUniform1ui(m_LineLoc, m_Gb->gpu.y_coord);

    glUseProgram(0);

    UpdateVertex(wx, wy);

    glUseProgram(m_Program);
    glBindVertexArray(m_Vao);
    glBindBuffer(GL_ARRAY_BUFFER, m_Vbo);

    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    glUseProgram(0);

    return 0;
}

void Window::UpdateVertex(int wx, int wy)
{
    float x1 = (float)wx / 160.f * 2.f - 1.f;
    float y1 = (float)wy / 144 * 2.f - 1.f;
    y1 *= -1.f;

    float x2 =  1.f;
    float y2 = -1.f;

    float quad[] = {
        x1, -1.f,
        x1, -1.f + 2.f / 144.f,
        x2, -1.f,
        x2, -1.f + 2.f / 144.f,
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

};