#include "background.h"

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
    glGenVertexArrays(1, &m_Vao);
    glBindVertexArray(m_Vao);

    m_Program = compileProgram(
        "shaders/background.vert",
        "shaders/background.frag");

    if (!m_Program) {
        printf("failed to compile program for background\n");
        return -1;
    }

    glBindAttribLocation(m_Program, 0, "inVertex");

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
    glGenBuffers(1, &m_Vbo);
    glBindBuffer(GL_ARRAY_BUFFER, m_Vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(quad), quad, GL_DYNAMIC_DRAW);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);

    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    m_ColorsLoc = glGetUniformLocation(m_Program, "colors");

    GLuint staticInfosLoc = glGetUniformBlockIndex(m_Program, "staticInfos");
    glUniformBlockBinding(m_Program, staticInfosLoc, 0);

    GLuint dynamicInfosLoc = glGetUniformBlockIndex(m_Program, "dynamicInfos");
    glUniformBlockBinding(m_Program, dynamicInfosLoc, 1);

    GLuint lcdLoc = glGetUniformBlockIndex(m_Program, "lcd");
    glUniformBlockBinding(m_Program, lcdLoc, 2);

    GLuint vramLoc = glGetUniformBlockIndex(m_Program, "vram");
    glUniformBlockBinding(m_Program, vramLoc, 3);

    return 0;
}

int Background::Destroy()
{
    glDeleteBuffers(1, &m_Vbo);
    glDeleteVertexArrays(1, &m_Vao);
    glDeleteProgram(m_Program);

    return 0;
}

int Background::Draw(int firstLine, int lastLine)
{
    UpdateVertex(firstLine, lastLine);
    UpdateColors();

    glUseProgram(m_Program);
    glBindVertexArray(m_Vao);
    glBindBuffer(GL_ARRAY_BUFFER, m_Vbo);

    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    glUseProgram(0);

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

    glBindBuffer(GL_ARRAY_BUFFER, m_Vbo);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(quad), quad);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
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

    glUseProgram(m_Program);
    glUniform4fv(m_ColorsLoc, 4, (const GLfloat*)colors);
    glUseProgram(0);
}

} // namespace GBMU