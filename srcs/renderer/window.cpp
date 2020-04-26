#include "window.h"

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

Window::Window(gb_cpu_s* gb) : m_Gb(gb) {}

Window::~Window()
{
    Destroy();
}

int Window::Init()
{
    m_Program = compileProgram(
        "C:/Users/iwan/GBmu/srcs/renderer/shaders/window.vert",
        "C:/Users/iwan/GBmu/srcs/renderer/shaders/window.frag");

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

    m_WxLoc  = glGetUniformLocation(m_Program, "wx");
    m_WyLoc  = glGetUniformLocation(m_Program, "wy");
    m_LcdcLoc = glGetUniformLocation(m_Program, "lcdc");

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
    glUseProgram(m_Program);

    uint8_t wx = (read_8(m_Gb, WX_OFFSET)) - 7;
    uint8_t wy = (read_8(m_Gb, WY_OFFSET));
    uint8_t lcdc = (read_8(m_Gb, LCDC_OFFSET));
    glUniform1ui(m_WxLoc, wx);
    glUniform1ui(m_WyLoc, wx);
    glUniform1ui(m_LcdcLoc, lcdc);

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

    float x2 = 1.f;
    float y2 = 1.f;

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

};