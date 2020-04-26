#pragma once

#include <GL/glew.h>

struct gb_cpu_s;

namespace GBMU {

class Background {
public:
    Background(gb_cpu_s* gb);
    ~Background();

    int Init();
    int Destroy();

    int Draw();

private:
    gb_cpu_s* m_Gb;

    GLuint m_Program {0};
    GLuint m_Vao {0};
    GLuint m_Vbo {0};
    GLint m_ScxLoc {-1};
    GLint m_ScyLoc {-1};
    GLint m_LcdcLoc {-1};
};

};