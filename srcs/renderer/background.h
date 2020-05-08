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

    int Draw(int firstLine, int lastLine);

private:
    void UpdateVertex(int firstLine, int lastLine);
    void UpdateColors();

private:
    gb_cpu_s* m_Gb;

    GLuint m_Program {0};
    GLuint m_Vao {0};
    GLuint m_Vbo {0};

    GLint m_ScxLoc {-1};
    GLint m_ScyLoc {-1};
    GLint m_LcdcLoc {-1};
    GLint m_ColorsLoc {-1};
};

} // namespace GBMU