#pragma once

#include <GL/glew.h>

namespace GBMU {

class Rescale {
public:
    Rescale();
    ~Rescale();

    void Draw(GLuint texture);

private:
    GLuint m_Program {0};
    GLuint m_Vao {0};
    GLuint m_Vbo {0};
};

} // namespace GBMU
