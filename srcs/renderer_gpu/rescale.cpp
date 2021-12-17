#include "rescale.h"

#include <stdio.h>

#include "gl_utils/glerr.h"
#include "gl_utils/compile_program.h"
#include "GL/glew.h"

extern "C" {
}

namespace GBMU {

Rescale::Rescale() {}

Rescale::~Rescale()
{
    Destroy();
}

int Rescale::Init(GLuint texture)
{
    m_Texture = texture;

    glGenVertexArrays(1, &m_Vao); GLERR;
    glBindVertexArray(m_Vao); GLERR;

    m_Program = compileProgram(
        "shaders/basic.vert",
        "shaders/basic.frag");

    if (!m_Program) {
        printf("failed to compile program\n");
        return -1;
    }

    glBindAttribLocation(m_Program, 0, "inVertex"); GLERR;
    glBindAttribLocation(m_Program, 1, "inTextCoord"); GLERR;

    int ret = linkProgram(m_Program);
    if (ret < 0) {
        printf("failed to link program\n");
        return -1;
    }

    constexpr float quad[] = {
        -1.f, -1.f,
        -1.f,  1.f,
         1.f, -1.f,
         1.f,  1.f,
    };

    constexpr float textCoord[] = {
        0.f, 0.f,
        0.f, 1.f,
        1.f, 0.f,
        1.f, 1.f
    };

    glGenBuffers(1, &m_Vbo); GLERR;
    glBindBuffer(GL_ARRAY_BUFFER, m_Vbo); GLERR;
    glBufferData(GL_ARRAY_BUFFER, sizeof(quad) + sizeof(textCoord), nullptr, GL_STATIC_DRAW); GLERR;
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(quad), quad); GLERR;
    glBufferSubData(GL_ARRAY_BUFFER, sizeof(quad), sizeof(textCoord), textCoord); GLERR;
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, (void*)0); GLERR;
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (void*)sizeof(quad)); GLERR;

    glEnableVertexAttribArray(0); GLERR;
    glEnableVertexAttribArray(1); GLERR;

    glBindBuffer(GL_ARRAY_BUFFER, 0); GLERR;
    glBindVertexArray(0); GLERR;

    glBindTexture(GL_TEXTURE_2D, m_Texture); GLERR;
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); GLERR;
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); GLERR;
    glBindTexture(GL_TEXTURE_2D, 0); GLERR;

    GLuint staticInfosLoc = glGetUniformBlockIndex(m_Program, "staticInfos"); GLERR;
    glUniformBlockBinding(m_Program, staticInfosLoc, 0); GLERR;

    GLuint dynamicInfosLoc = glGetUniformBlockIndex(m_Program, "dynamicInfos"); GLERR;
    glUniformBlockBinding(m_Program, dynamicInfosLoc, 1); GLERR;

    return 0;
}

int Rescale::Destroy()
{
    glDeleteBuffers(1, &m_Vbo); GLERR;
    glDeleteVertexArrays(1, &m_Vao); GLERR;
    glDeleteProgram(m_Program); GLERR;

    return 0;
}

int Rescale::Draw()
{
    glUseProgram(m_Program); GLERR;
    glBindVertexArray(m_Vao); GLERR;
    glBindBuffer(GL_ARRAY_BUFFER, m_Vbo); GLERR;
    glBindTexture(GL_TEXTURE_2D, m_Texture); GLERR;

    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4); GLERR;

    glBindTexture(GL_TEXTURE_2D, 0); GLERR;
    glBindBuffer(GL_ARRAY_BUFFER, 0); GLERR;
    glBindVertexArray(0); GLERR;
    glUseProgram(0); GLERR;

    return 0;
}

} // namespace GBMU