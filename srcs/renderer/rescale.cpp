#include "rescale.h"

#include <cstring>

#include "gl_utils/compile_program.h"

extern "C" {
#include "gb.h"
#include "renderer.h"
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

    glGenVertexArrays(1, &m_Vao);
    glBindVertexArray(m_Vao);

    m_Program = compileProgram(
        "shaders/basic.vert",
        "shaders/basic.frag");

    if (!m_Program) {
        printf("failed to compile program\n");
        return -1;
    }

    glBindAttribLocation(m_Program, 0, "inVertex");
    glBindAttribLocation(m_Program, 1, "inTextCoord");

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

    glBindTexture(GL_TEXTURE_2D, m_Texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glBindTexture(GL_TEXTURE_2D, 0);

    GLuint staticInfosLoc = glGetUniformBlockIndex(m_Program, "staticInfos");
    glUniformBlockBinding(m_Program, staticInfosLoc, 0);

    GLuint dynamicInfosLoc = glGetUniformBlockIndex(m_Program, "dynamicInfos");
    glUniformBlockBinding(m_Program, dynamicInfosLoc, 1);

    return 0;
}

int Rescale::Destroy()
{
    glDeleteBuffers(1, &m_Vbo);
    glDeleteVertexArrays(1, &m_Vao);
    glDeleteProgram(m_Program);

    return 0;
}

int Rescale::Draw()
{
    glUseProgram(m_Program);
    glBindVertexArray(m_Vao);
    glBindBuffer(GL_ARRAY_BUFFER, m_Vbo);
    glBindTexture(GL_TEXTURE_2D, m_Texture);

    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

    glBindTexture(GL_TEXTURE_2D, 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    glUseProgram(0);

    return 0;
}

} // namespace GBMU