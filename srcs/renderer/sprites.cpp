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
    glBufferData(GL_ARRAY_BUFFER, OAM_SIZE * 2 * 6 * 3 * 4, nullptr, GL_STREAM_DRAW);
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
    UpdateVertex();

    glUseProgram(m_Program);
    glBindVertexArray(m_Vao);
    glBindBuffer(GL_ARRAY_BUFFER, m_Vbo);

    glDrawArrays(GL_TRIANGLES, 0, 6);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    glUseProgram(0);

    return 0;
}

void Sprites::UpdateVertex()
{
    float quad[] = {
        -1.f,  1.f, 1.f,
        -1.f, -1.f, 1.f,
         1.f,  1.f, 1.f,
        -1.f, -1.f, 1.f,
         1.f,  1.f, 1.f,
         1.f, -1.f, 1.f,
    };

    glBindBuffer(GL_ARRAY_BUFFER, m_Vbo);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(quad), quad);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

};