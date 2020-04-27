#pragma once
#define GL_GLEXT_PROTOTYPES

#include <GL/gl.h>
#include <GL/glu.h>

struct gb_cpu_s;

namespace GBMU {

class Window {
public:
    Window(gb_cpu_s* gb);
    ~Window();

    int Init();
    int Destroy();

    int Draw();

private:
    void UpdateVertex(int wx, int wy);
    void UpdateColors();

private:
    gb_cpu_s* m_Gb;

    GLuint m_Program {0};
    GLuint m_Vao {0};
    GLuint m_Vbo {0};

    GLint m_WxLoc {-1};
    GLint m_WyLoc {-1};
    GLint m_LcdcLoc {-1};
    GLint m_ColorsLoc{ -1 };
};

};