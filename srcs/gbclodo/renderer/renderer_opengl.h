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
    explicit Renderer();
    ~Renderer();

    void Render();
    void Clear();

    void SetWindowSize(int width, int height);

private:

private:
    void InitTexture();
    void DestroyTexture();

    void InitPbo();
    void DestroyPbo();

private:

    GLuint m_Texture { 0 };
    GLuint m_Pbo { 0 };

    Rescale m_Rescale;
};

} // namespace GBMU
