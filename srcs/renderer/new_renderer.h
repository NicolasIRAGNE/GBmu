#pragma once

#include <GL/glew.h>

#include "rescale.h"

extern "C"
{
#include "gb.h"
#include "renderer.h"
}

namespace GBMU
{

class Renderer
{
public:
    explicit Renderer(gb_cpu_s* gb);
    ~Renderer();

    void DrawPixel(int line, int pixel);
    void Render();
    void Clear();

    void SetWindowSize(int width, int height);

private:
    void InitTexture();
    void DestroyTexture();

    int GetBackgroundIndex(int line, int pixel, int scx, int scy, int lcdc);
    int GetMenuIndex(int line, int pixel, int wx, int wy, int lcdc);
    int GetSpriteIndex(bool* isInFront, int line, int pixel, int lcdc);

    void UpdateColorMapIndex();

private:
    gb_cpu_s* m_Gb {nullptr};

    uint8_t m_TextureData[MAIN_SURFACE_HEIGHT][MAIN_SURFACE_WIDTH] {};
    GLuint m_Texture {0};

    int8_t m_BackgroundAndMenuColorMapIndex[4] {};
    int8_t m_SpriteColorMapIndex1[4] {};
    int8_t m_SpriteColorMapIndex2[4] {};

    Rescale m_Rescale;
};

} // namespace GBMU
