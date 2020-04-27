#pragma once

#include <stdint.h>
#define GL_GLEXT_PROTOTYPES

#include <GL/gl.h>
#include <GL/glu.h>

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
    int UpdateVertex();
    void FillData(float* data, int x1, int y1, int x2, int y2, int tile, int attr);
	void FillPosInTile(float* data, int y, uint8_t attr);
    void UpdateColors();

private:
    gb_cpu_s* m_Gb;

    GLuint m_Program {0};
    GLuint m_Vao {0};
    GLuint m_Vbo {0};

    GLint m_Colors1Loc {-1};
    GLint m_Colors2Loc {-1};
};

};