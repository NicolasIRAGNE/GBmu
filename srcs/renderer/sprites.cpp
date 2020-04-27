#include "sprites.h"

#include "gl_utils/compile_program.h"

#include <cstring>

extern "C" {
#include "gb.h"
#include "renderer.h"
}

namespace GBMU {

Sprites::Sprites(gb_cpu_s* gb) : m_Gb(gb) {}

Sprites::~Sprites()
{
    Destroy();
}

int Sprites::Init()
{
    m_Program = compileProgram(
        "../srcs/renderer/shaders/sprites.vert",
        "../srcs/renderer/shaders/sprites.frag");

    if (!m_Program) {
        printf("failed to create program\n");
        return -1;
    }

    glBindAttribLocation(m_Program, 0, "inVertex");

    glGenVertexArrays(1, &m_Vao);
    glBindVertexArray(m_Vao);
    glGenBuffers(1, &m_Vbo);
    glBindBuffer(GL_ARRAY_BUFFER, m_Vbo);
    glBufferData(GL_ARRAY_BUFFER, OAM_SIZE * 2 * 6 * 4 * sizeof(float), nullptr, GL_STREAM_DRAW);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, (void*)0);

    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    m_Colors1Loc = glGetUniformLocation(m_Program, "colors1");
    m_Colors2Loc = glGetUniformLocation(m_Program, "colors2");

    return 0;
}

int Sprites::Destroy()
{
    glDeleteBuffers(1, &m_Vbo);
    glDeleteVertexArrays(1, &m_Vao);
    glDeleteProgram(m_Program);

    return 0;
}

int Sprites::Draw()
{
    UpdateColors();

    int nbQuad = UpdateVertex();

    glUseProgram(m_Program);
    glBindVertexArray(m_Vao);
    glBindBuffer(GL_ARRAY_BUFFER, m_Vbo);

    glDrawArrays(GL_TRIANGLES, 0, nbQuad * 6);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    glUseProgram(0);

    return 0;
}

int Sprites::UpdateVertex()
{
    float quad[] = {
        -1.f,  1.f, 1.f,
        -1.f, -1.f, 1.f,
         1.f,  1.f, 1.f,
        -1.f, -1.f, 1.f,
         1.f,  1.f, 1.f,
         1.f, -1.f, 1.f,
    };

    float data[OAM_SIZE * 2 * 6 * 4];

    uint8_t lcdc = (read_8(m_Gb, LCDC_OFFSET));

    int dataIndex = 0;
    for (int i = 0; i < OAM_SIZE; i += 4)
    {
        uint8_t y = m_Gb->oam[i + 0];
        uint8_t x = m_Gb->oam[i + 1];
        uint8_t tile = m_Gb->oam[i + 2];
        uint8_t attr = m_Gb->oam[i + 3];

        if (x == 0 || y == 0) {
            continue;
        }

        int x1 = x - 8;
        int y1 = y - 16;

        int x2 = x;
        int y2 = y - 8;

        if (attr & ATTR_X_FLIP) {
            std::swap(x1, x2);
        }

        if (attr & ATTR_Y_FLIP) {
            std::swap(y1, y2);
			if (lcdc & LCDC_SPRITE_SIZE) {
            	y1 += 8;
            	y2 += 8;
			}
        }

        FillData(data + dataIndex, x1, y1, x2, y2, tile, attr);
        dataIndex += 24;

        if (lcdc & LCDC_SPRITE_SIZE) {
            if (attr & 0x40) {
                y1 -= 8;
                y2 -= 8;
            }
            else {
                y1 += 8;
                y2 += 8;
            }
            FillData(data + dataIndex, x1, y1, x2, y2, tile + 1, attr);
            dataIndex += 24;
        }
    }

    glBindBuffer(GL_ARRAY_BUFFER, m_Vbo);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(data), data);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    return dataIndex / 24;
}

void Sprites::FillData(float* data, int x1, int y1, int x2, int y2, int tile, int attr)
{
    float x1f = (float)(x1) / 160.f * 2.f - 1.f;
    float y1f = (float)(y2) / 144.f * 2.f - 1.f;
    y1f *= -1.f;

    float x2f = (float)(x2) / 160.f * 2.f - 1.f;
    float y2f = (float)(y1) / 144.f * 2.f - 1.f;
    y2f *= -1.f;

    data[0]  = x1f; data[1]  = y2f; data[2]  = (float)tile; data[3]  = (float)attr;
    data[4]  = x1f; data[5]  = y1f; data[6]  = (float)tile; data[7]  = (float)attr;
    data[8]  = x2f; data[9]  = y2f; data[10] = (float)tile; data[11] = (float)attr;
    data[12] = x1f; data[13] = y1f; data[14] = (float)tile; data[15] = (float)attr;
    data[16] = x2f; data[17] = y2f; data[18] = (float)tile; data[19] = (float)attr;
    data[20] = x2f; data[21] = y1f; data[22] = (float)tile; data[23] = (float)attr;
}

void Sprites::UpdateColors()
{
    constexpr float monochromePalette[5][4] = {
        {0.8f, 0.8f, 0.8f, 1.f},
        {0.5f, 0.5f, 0.5f, 1.f},
        {0.3f, 0.3f, 0.3f, 1.f},
        {0.1f, 0.1f, 0.1f, 1.f},
        {0.0f, 0.0f, 0.0f, 0.f}
    };

    float colors[4][4];

    uint8_t obp0 = read_8(m_Gb, OBP0_OFFSET);
    std::memcpy(&colors[0], &monochromePalette[5], 4 * sizeof(float));
    std::memcpy(&colors[2], &monochromePalette[(obp0 & 0b00001100) >> 2], 4 * sizeof(float));
    std::memcpy(&colors[1], &monochromePalette[(obp0 & 0b00110000) >> 4], 4 * sizeof(float));
    std::memcpy(&colors[3], &monochromePalette[(obp0 & 0b11000000) >> 6], 4 * sizeof(float));

    glUseProgram(m_Program);
    glUniform4fv(m_Colors1Loc, 4, (const GLfloat*)colors);
    glUseProgram(0);

    uint8_t obp1 = read_8(m_Gb, OBP1_OFFSET);
    std::memcpy(&colors[0], &monochromePalette[5], 4 * sizeof(float));
    std::memcpy(&colors[2], &monochromePalette[(obp1 & 0b00001100) >> 2], 4 * sizeof(float));
    std::memcpy(&colors[1], &monochromePalette[(obp1 & 0b00110000) >> 4], 4 * sizeof(float));
    std::memcpy(&colors[3], &monochromePalette[(obp1 & 0b11000000) >> 6], 4 * sizeof(float));

    glUseProgram(m_Program);
    glUniform4fv(m_Colors2Loc, 4, (const GLfloat*)colors);
    glUseProgram(0);
}

};