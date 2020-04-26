#pragma once

#include <GL/glew.h>

struct gb_cpu_s;

namespace GBMU {

class Sprites {
public:
    Sprites(gb_cpu_s* gb);
    ~Sprites();

    int Init();
    int Destroy();

    int Draw();

private:
    gb_cpu_s* m_Gb;

    GLuint m_Program {0};
    GLuint m_Vao {0};
    GLuint m_Vbo {0};
    GLint m_InfosLoc {-1};
};

};