#pragma once

#include <GL/glew.h>

#include "background.h"
#include "window.h"
#include "sprites.h"

#include "rescale.h"

struct gb_cpu_s;

namespace GBMU {

class Renderer {
public:
    Renderer(gb_cpu_s* gb);
    ~Renderer();

    int Init();
    int Destroy();

    int Clear();
    int Draw(int firstLine, int lastLine);
    int Render();

    void SetWindowSize(int width, int height);

private:
    int InitUbos();
    int InitFramebuffer();

    void UpdateStaticInfos();
    void UpdateDynamicInfos();
    void UpdateLcd();
    void UpdateVram();

private:
    gb_cpu_s* m_Gb;

    GLuint m_StaticInfosUbo {0};
    GLuint m_DynamicInfosUbo {0};
    GLuint m_LcdUbo{0};
    GLuint m_VramUbo {0};
    GLuint m_FrameBuffer {0};
    GLuint m_TargetTexture {0};
    GLuint m_DepthBuffer {0};

    Background m_Background;
    Window m_Menu;
    Sprites m_Sprites;

    Rescale m_Rescale;

    int m_WindowWidth {0};
    int m_WindowHeight {0};
};

} // namespace GBMU