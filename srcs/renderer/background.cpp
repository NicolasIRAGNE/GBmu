#include "background.h"
#include "gl_utils/glerr.h"

#include <cstring>

#include "gl_utils/compile_program.h"

extern "C" {
#include "gb.h"
#include "renderer.h"
}

namespace GBMU {

Background::Background(gb_cpu_s* gb) : m_Gb(gb) {}

Background::~Background()
{
    Destroy();
}

int Background::Init()
{
    glGenVertexArrays(1, &m_Vao); GLERR;
    glBindVertexArray(m_Vao); GLERR;

    m_Program = compileProgram(
        "shaders/background.vert",
        "shaders/background.frag");

    if (!m_Program) {
        printf("failed to compile program for background\n");
        return -1;
    }

    glBindAttribLocation(m_Program, 0, "inVertex"); GLERR;

    int ret = linkProgram(m_Program);
    if (ret < 0) {
        printf("failed to link program for background\n");
        return -1;
    }

    constexpr float quad[] = {
        -1.f, -1.f,
        -1.f,  1.f,
         1.f, -1.f,
         1.f,  1.f,
    };
    glGenBuffers(1, &m_Vbo); GLERR;
    glBindBuffer(GL_ARRAY_BUFFER, m_Vbo); GLERR;
    glBufferData(GL_ARRAY_BUFFER, sizeof(quad), quad, GL_DYNAMIC_DRAW); GLERR;
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, (void*)0); GLERR;

    glEnableVertexAttribArray(0); GLERR;

    glBindBuffer(GL_ARRAY_BUFFER, 0); GLERR;
    glBindVertexArray(0); GLERR;

    m_ColorsLoc = glGetUniformLocation(m_Program, "colors"); GLERR;

    GLuint staticInfosLoc = glGetUniformBlockIndex(m_Program, "staticInfos"); GLERR;
    glUniformBlockBinding(m_Program, staticInfosLoc, 0); GLERR;

    GLuint dynamicInfosLoc = glGetUniformBlockIndex(m_Program, "dynamicInfos"); GLERR;
    glUniformBlockBinding(m_Program, dynamicInfosLoc, 1); GLERR;

    GLuint lcdLoc = glGetUniformBlockIndex(m_Program, "lcd"); GLERR;
    glUniformBlockBinding(m_Program, lcdLoc, 2); GLERR;

    GLuint vramLoc = glGetUniformBlockIndex(m_Program, "vram"); GLERR;
    glUniformBlockBinding(m_Program, vramLoc, 3); GLERR;

    return 0;
}

int Background::Destroy()
{
    glDeleteBuffers(1, &m_Vbo); GLERR;
    glDeleteVertexArrays(1, &m_Vao); GLERR;
    glDeleteProgram(m_Program); GLERR;

    return 0;
}

int Background::Draw(int firstLine, int lastLine)
{
    UpdateVertex(firstLine, lastLine);
    UpdateColors();

    glUseProgram(m_Program); GLERR;
    glBindVertexArray(m_Vao); GLERR;
    glBindBuffer(GL_ARRAY_BUFFER, m_Vbo); GLERR;

    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4); GLERR;

    glBindBuffer(GL_ARRAY_BUFFER, 0); GLERR;
    glBindVertexArray(0); GLERR;
    glUseProgram(0); GLERR;

    return 0;
}

void Background::UpdateVertex(int firstLine, int lastLine)
{
    constexpr float GBHeight = static_cast<float>(MAIN_SURFACE_HEIGHT);

    float y1 = static_cast<float>(firstLine) / GBHeight * 2.f - 1.f;
    float y2 = static_cast<float>(lastLine + 1) / GBHeight * 2.f - 1.f;
    y1 *= -1.f;
    y2 *= -1.f;

    float quad[] = {
        -1.f, y1,
        -1.f, y2,
         1.f, y1,
         1.f, y2,
    };

    glBindBuffer(GL_ARRAY_BUFFER, m_Vbo); GLERR;
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(quad), quad); GLERR;
    glBindBuffer(GL_ARRAY_BUFFER, 0); GLERR;
}

void Background::UpdateColors()
{
    constexpr float debug_palette[4][4] = {
        {1.0f, 0.f, 0.f, 1.f},
        {0.8f, 0.f, 0.f, 1.f},
        {0.6f, 0.f, 0.f, 1.f},
        {0.4f, 0.f, 0.f, 1.f},
    };
    constexpr float palette[4][4] = {
        {0.86f, 0.79f, 0.62f, 1.f},
        {0.67f, 0.55f, 0.06f, 1.f},
        {0.38f, 0.19f, 0.19f, 1.f},
        {0.22f, 0.06f, 0.06f, 1.f},
    };
    constexpr float black[4][4] = {
        {0.f, 0.f, 0.f, 1.f},
        {0.f, 0.f, 0.f, 1.f},
        {0.f, 0.f, 0.f, 1.f},
        {0.f, 0.f, 0.f, 1.f},
    };

    float colors[4][4];

    uint8_t bgp = read_8(m_Gb, BGP_OFFSET);
    
    auto bg_palette = (m_Gb->debug_palette) ? debug_palette : palette;
    if (!m_Gb->draw_background)
      bg_palette = black;
    std::memcpy(&colors[0], &bg_palette[(bgp & 0b00000011) >> 0], 4 * sizeof(float));
    std::memcpy(&colors[2], &bg_palette[(bgp & 0b00001100) >> 2], 4 * sizeof(float));
    std::memcpy(&colors[1], &bg_palette[(bgp & 0b00110000) >> 4], 4 * sizeof(float));
    std::memcpy(&colors[3], &bg_palette[(bgp & 0b11000000) >> 6], 4 * sizeof(float));

    glUseProgram(m_Program); GLERR;
    glUniform4fv(m_ColorsLoc, 4, (const GLfloat*)colors); GLERR;
    glUseProgram(0); GLERR;
}

} // namespace GBMU