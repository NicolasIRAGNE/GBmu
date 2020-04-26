#include "background.h"

#include "gl_utils/compile_program.h"

extern "C" {
#include "gb.h"
}

namespace GBMU {

Background::Background(gb_cpu_s* gb) : m_Gb(gb) {}

Background::~Background()
{
    Destroy();
}

int Background::Init()
{
    float vertices[] = {
        -0.5f, -0.5f,
         0.5f, -0.5f,
         0.0f,  0.5f,
    };

    m_Program = compileProgram(
        "C:/Users/iwan/GBmu/srcs/renderer/shaders/background.vert",
        "C:/Users/iwan/GBmu/srcs/renderer/shaders/background.frag");

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
    glBufferData(GL_ARRAY_BUFFER, sizeof(quad), quad, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);

    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glClearColor(1.f, 0.f, 0.f, 1.0f);

    m_InfosLoc = glGetUniformLocation(m_Program, "infos");

    return 0;
}

int Background::Destroy()
{
    glDeleteBuffers(1, &m_Vbo);
    glDeleteVertexArrays(1, &m_Vao);
    glDeleteProgram(m_Program);

    return 0;
}

int Background::Draw()
{


    int scy = read_8(m_Gb, SCY_OFFSET);
    int scx = read_8(m_Gb, SCX_OFFSET);
    uint8_t lcdc = (read_8(m_Gb, LCDC_OFFSET));
    glUniform3ui(m_InfosLoc, scx, scy, lcdc);

    glUseProgram(m_Program);
    glBindVertexArray(m_Vao);
    glBindBuffer(GL_ARRAY_BUFFER, m_Vbo);

    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    glUseProgram(0);

    return 0;
}

};