#pragma once

#include <GL/glew.h>

namespace GBMU {

class Rescale {
public:
    Rescale();
    ~Rescale();

    int Init(GLuint texture);
    int Destroy();

    int Draw();

private:
    GLuint m_Texture {0};

    GLuint m_Program {0};
    GLuint m_Vao {0};
    GLuint m_Vbo {0};
};

} // namespace GBMU