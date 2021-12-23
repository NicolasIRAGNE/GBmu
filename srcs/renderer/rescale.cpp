#include "rescale.h"

#include <stdio.h>
#include <stdexcept>

#include "gl_utils/glerr.h"
#include "gl_utils/compile_program.h"
#include "GL/glew.h"

namespace GBMU {

Rescale::Rescale()
{
    GLenum err = glewInit();
    if (err != GLEW_OK) {
        throw std::runtime_error("Glew error: " + std::string((char*)glewGetErrorString(err)));
    }

    glGenVertexArrays(1, &m_Vao);
    glBindVertexArray(m_Vao);

    m_Program = compileProgram(
        "shaders/basic.vert",
        "shaders/basic.frag");

    if (!m_Program) {
        throw std::runtime_error("Failed to compile program");
    }

    glBindAttribLocation(m_Program, 0, "inVertex");
    glBindAttribLocation(m_Program, 1, "inTextCoord");

    int ret = linkProgram(m_Program);
    if (ret < 0) {
        throw std::runtime_error("Failed to link program");
    }

    constexpr float quad[] = {
        -1.f, -1.f,
        -1.f,  1.f,
         1.f, -1.f,
         1.f,  1.f,
    };

    constexpr float textCoord[] = {
        0.f, 1.f,
        0.f, 0.f,
        1.f, 1.f,
        1.f, 0.f
    };

    glGenBuffers(1, &m_Vbo);
    glBindBuffer(GL_ARRAY_BUFFER, m_Vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(quad) + sizeof(textCoord), nullptr, GL_STATIC_DRAW);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(quad), quad);
    glBufferSubData(GL_ARRAY_BUFFER, sizeof(quad), sizeof(textCoord), textCoord);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (void*)sizeof(quad));

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

Rescale::~Rescale()
{
    glDeleteBuffers(1, &m_Vbo);
    glDeleteVertexArrays(1, &m_Vao);
    glDeleteProgram(m_Program);
}

void Rescale::Draw(GLuint texture)
{
    glUseProgram(m_Program);
    glBindVertexArray(m_Vao);
    glBindBuffer(GL_ARRAY_BUFFER, m_Vbo);
    glBindTexture(GL_TEXTURE_2D, texture);

    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

    glBindTexture(GL_TEXTURE_2D, 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    glUseProgram(0);
}

} // namespace GBMU
