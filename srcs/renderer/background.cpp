#include "background.h"

#include "gl_utils/compile_program.h"

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

Background::Background(gb_cpu_s* gb) : m_Gb(gb) {}

Background::~Background()
{
    Destroy();
}

int Background::Init()
{
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

    m_ScxLoc  = glGetUniformLocation(m_Program, "scx");
    m_ScyLoc  = glGetUniformLocation(m_Program, "scy");
    m_LcdcLoc = glGetUniformLocation(m_Program, "lcdc");

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
    glUseProgram(m_Program);

    int scy = read_8(m_Gb, SCY_OFFSET);
    int scx = read_8(m_Gb, SCX_OFFSET);
    uint8_t lcdc = (read_8(m_Gb, LCDC_OFFSET));
    glUniform1i(m_ScxLoc, scx);
    glUniform1i(m_ScyLoc, scy);
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

};