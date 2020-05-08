#pragma once

#include <GL/glew.h>

#include "background.h"
#include "window.h"
#include "sprites.h"

struct gb_cpu_s;

namespace GBMU {

class Renderer {
public:
    Renderer(gb_cpu_s* gb);
    ~Renderer();

    int Init();
    int Destroy();

    int Render(int firstLine, int lastLine);

private:
    void UpdateVram();

private:
    gb_cpu_s* m_Gb;

    GLuint m_VramUbo {0};

    Background m_Background;
    Window m_Menu;
    Sprites m_Sprites;
};

} // namespace GBMU