#pragma once

#include <GL/glew.h>

struct gb_cpu_s;

namespace GBMU {

class Window {
public:
    Window(gb_cpu_s* gb);
    ~Window();

    int Init();
    int Destroy();

    int Draw(int firstLine, int lastLine);

private:
    void UpdateVertex(int wx, int firstLine, int lastLine);
    void UpdateColors();

private:
    gb_cpu_s* m_Gb;

    GLuint m_Program {0};
    GLuint m_Vao {0};
    GLuint m_Vbo {0};

    GLint m_WxLoc {-1};
    GLint m_WyLoc {-1};
    GLint m_LcdcLoc {-1};
    GLint m_ColorsLoc {-1};
};

} // namespace GBMU