#include "sprites.h"

#include "gl_utils/compile_program.h"

extern "C" {
#include "gb.h"
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
        "C:/Users/iwan/GBmu/srcs/renderer/shaders/sprites.vert",
        "C:/Users/iwan/GBmu/srcs/renderer/shaders/sprites.frag");

    if (!m_Program) {
        printf("failed to create program\n");
        return -1;
    }

    glBindAttribLocation(m_Program, 0, "inVertex");

    glGenVertexArrays(1, &m_Vao);
    glBindVertexArray(m_Vao);
    glGenBuffers(1, &m_Vbo);
    glBindBuffer(GL_ARRAY_BUFFER, m_Vbo);
    glBufferData(GL_ARRAY_BUFFER, OAM_SIZE * 2 * 6 * 3 * sizeof(float), nullptr, GL_STREAM_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

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

    float data[OAM_SIZE * 2 * 6 * 3] = {};

    uint8_t lcdc = (read_8(m_Gb, LCDC_OFFSET));

    int dataIndex = 0;
    for (int i = 0; i < OAM_SIZE; i += 4)
    {
        uint8_t y = 168 - m_Gb->oam[i + 0];
        uint8_t x = m_Gb->oam[i + 1];
        uint8_t tile = m_Gb->oam[i + 2];
        uint8_t attr = m_Gb->oam[i + 3];

        if (x == 0 || y == 0) {
            continue;
        }

        float x1 = (float)(x - 8) / 160.f * 2.f - 1.f;
        float y1 = (float)(y - 16) / 144.f * 2.f - 1.f;

        float x2 = (float)(x) / 160.f * 2.f - 1.f;
        float y2 = (float)(y - 8) / 144.f * 2.f - 1.f;

        if (attr & 0x20) {
            std::swap(x1, x2);
        }

        if (attr & 0x40) {
            std::swap(y1, y2);
        }

        data[dataIndex + 0]  = x1;
        data[dataIndex + 1]  = y2;
        data[dataIndex + 2]  = (float)tile;

        data[dataIndex + 3]  = x1;
        data[dataIndex + 4]  = y1;
        data[dataIndex + 5]  = (float)tile;

        data[dataIndex + 6]  = x2;
        data[dataIndex + 7]  = y2;
        data[dataIndex + 8]  = (float)tile;

        data[dataIndex + 9]  = x1;
        data[dataIndex + 10] = y1;
        data[dataIndex + 11] = (float)tile;

        data[dataIndex + 12] = x2;
        data[dataIndex + 13] = y2;
        data[dataIndex + 14] = (float)tile;

        data[dataIndex + 15] = x2;
        data[dataIndex + 16] = y1;
        data[dataIndex + 17] = (float)tile;

        dataIndex += 18;
    }

    glBindBuffer(GL_ARRAY_BUFFER, m_Vbo);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(data), data);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    return dataIndex / 18;
}

};