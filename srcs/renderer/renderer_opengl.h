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

constexpr int8_t kWindowDebugPaletteOffset = 5;
constexpr int8_t kSpriteDebugPaletteOffset = 10;
constexpr int8_t kBackgroundDebugPaletteOffset = 15;

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
    enum Priority : int
    {
        kNull = 0,
        kVeryLow = 1,
        kLow = 2,
        kMedium = 3,
        kHigh = 4
    };

private:
    void InitTexture();
    void DestroyTexture();

    void InitPbo();
    void DestroyPbo();

    uint16_t GetBackgroundColor(Priority* priority, int line, int pixel, int scx, int scy, int lcdc);
    uint16_t GetMenuColor(Priority* priority, int line, int pixel, int wx, int wy, int lcdc);

    void ScanOAM(int line, int lcdc);

    uint16_t GetColor(Priority* priority, int offsetX, int offsetY, int lcdc, bool useBgmap2, const uint16_t* debugPalette);
    int GetColorIndex(int tileIndex, int tileAttr, int x, int y);
    int TransformColorIndex(int colorIndex, int paletteOffset);

private:
    struct Pixel
    {   
        Priority priority = kNull;
        uint16_t color = 0;
    };

    struct OAMCase
    {
        uint8_t y;
        uint8_t x;
        uint8_t tileIndex;
        uint8_t attributes;
    };

private:
    gb_cpu_s* m_Gb { nullptr };

    uint16_t m_TextureData[MAIN_SURFACE_HEIGHT][MAIN_SURFACE_WIDTH] {};
    GLuint m_Texture { 0 };
    GLuint m_Pbo { 0 };
    Pixel m_SpriteLine[MAIN_SURFACE_WIDTH] {};
    int m_MenuXOffset { 0 };
    int m_MenuYOffset { 0 };
    uint8_t m_Low3bitsOfSCX { 0 };

    Rescale m_Rescale;
};

} // namespace GBMU
