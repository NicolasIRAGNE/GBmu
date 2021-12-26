#include "renderer_opengl.h"

#include "gl_utils/glerr.h"
#include <algorithm>
#include <stdexcept>
#include <string>
#include <vector>

constexpr uint16_t kBasicColorMap[4] = {
    28 | (25 << 5) | (20 << 10),
    21 | (18 << 5) | (2 << 10),
    12 | (6 << 5) | (6 << 10),
    7 | (2 << 5) | (2 << 10),
};

constexpr uint16_t kDebugWindowColorMap[4] = {
    31 | (0 << 5) | (0 << 10),
    25 | (0 << 5) | (0 << 10),
    19 | (0 << 5) | (0 << 10),
    12 | (0 << 5) | (0 << 10),
};

constexpr uint16_t kDebugSpriteColorMap[4] = {
    0 | (31 << 5) | (0 << 10),
    0 | (25 << 5) | (0 << 10),
    0 | (19 << 5) | (0 << 10),
    0 | (12 << 5) | (0 << 10),
};

constexpr uint16_t kDebugBackgroundColorMap[4] = {
    0 | (0 << 5) | (31 << 10),
    0 | (0 << 5) | (25 << 10),
    0 | (0 << 5) | (19 << 10),
    0 | (0 << 5) | (12 << 10),
};

namespace GBMU
{

Renderer::Renderer(gb_cpu_s* gb)
    : m_Gb(gb)
{
    InitTexture();
}

Renderer::~Renderer()
{
    DestroyTexture();
}

void Renderer::DrawPixel(int line, int pixel)
{
    int lcdc = read_8(m_Gb, LCDC_OFFSET);
    int scx = read_8(m_Gb, SCX_OFFSET);
    int scy = read_8(m_Gb, SCY_OFFSET);
    int wx = read_8(m_Gb, WX_OFFSET) - 7;
    int wy = read_8(m_Gb, WY_OFFSET);

    if (pixel == 0)
    {
        ScanOAM(line, lcdc);
    }

    int backgroundIndex = -1;
    int menuIndex = -1;

    if (m_Gb->draw_background)
    {
        backgroundIndex = GetBackgroundIndex(line, pixel, scx, scy, lcdc);
    }
    if (m_Gb->draw_window && (lcdc & LCDC_WINDOW_ON))
    {
        menuIndex = GetMenuIndex(line, pixel, wx, wy, lcdc);
    }

    int bgp = read_8(m_Gb, BGP_OFFSET);
    constexpr int kBgpOffsets[4] = { 0, 4, 2, 6 };
    m_TextureData[line][pixel] = 0;
    if (backgroundIndex != -1)
    {
        int8_t index = (bgp >> kBgpOffsets[backgroundIndex]) & 0b11;
        m_TextureData[line][pixel] = kBasicColorMap[index];
        if (m_Gb->debug_palette)
        {
            m_TextureData[line][pixel] = kDebugBackgroundColorMap[index];
        }
    }
    if (menuIndex != -1)
    {
        int8_t index = (bgp >> kBgpOffsets[menuIndex]) & 0b11;
        m_TextureData[line][pixel] = kBasicColorMap[index];
        if (m_Gb->debug_palette)
        {
            m_TextureData[line][pixel] = kDebugWindowColorMap[index];
        }
    }

    if (m_Gb->draw_sprites)
    {
        const auto& sprite = m_SpriteLine[pixel];
        if (sprite.isExist && (sprite.isInFront || (backgroundIndex <= 0 && menuIndex <= 0)))
        {
            m_TextureData[line][pixel] = sprite.color;
        }
    }
}

void Renderer::Render()
{
    // Copy the texture data to the texture
    glBindTexture(GL_TEXTURE_2D, m_Texture);
    glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, MAIN_SURFACE_WIDTH, MAIN_SURFACE_HEIGHT, GL_RGBA, GL_UNSIGNED_SHORT_1_5_5_5_REV, m_TextureData);
    glBindTexture(GL_TEXTURE_2D, 0);

    m_Rescale.Draw(m_Texture);
}

void Renderer::Clear()
{
    glClear(GL_COLOR_BUFFER_BIT);
    GLERR;
}

void Renderer::SetWindowSize(int width, int height)
{
    glViewport(0, 0, width, height);
    GLERR;
}

void Renderer::InitTexture()
{
    glGenTextures(1, &m_Texture);
    GLERR;
    glBindTexture(GL_TEXTURE_2D, m_Texture);
    GLERR;
    glTexImage2D(
        GL_TEXTURE_2D,
        0,
        GL_RGBA,
        MAIN_SURFACE_WIDTH,
        MAIN_SURFACE_HEIGHT,
        0,
        GL_RGBA,
        GL_UNSIGNED_SHORT_1_5_5_5_REV,
        nullptr);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
}

void Renderer::DestroyTexture()
{
    glDeleteTextures(1, &m_Texture);
    GLERR;
}

int Renderer::GetBackgroundIndex(int line, int pixel, int scx, int scy, int lcdc)
{
    if (!(lcdc & LCDC_DISPLAY_PRIORITY))
    {
        return -1;
    }

    int backgroundX = (pixel + scx) % 256;
    int backgroundY = (line + scy) % 256;

    int tileX = backgroundX / 8;
    int tileY = backgroundY / 8;

    int tileOffsetX = backgroundX % 8;
    int tileOffsetY = backgroundY % 8;

    int offset = BGMAP1_OFFSET;
    if (lcdc & LCDC_TILE_MAP_SELECT)
    {
        offset = BGMAP2_OFFSET;
    }

    int tileIndex = m_Gb->vram[0][offset + tileY * 32 + tileX];
    if (!(lcdc & LCDC_TILE_DATA_SELECT) && tileIndex + 0x100 < 256 + 128)
    {
        tileIndex += 0x100;
    }

    int msb = m_Gb->vram[0][tileIndex * 16 + tileOffsetY * 2];
    int lsb = m_Gb->vram[0][tileIndex * 16 + tileOffsetY * 2 + 1];

    int posInByte = 7 - tileOffsetX;
    int bit = 1 << posInByte;
    int colorIndex = ((msb & bit) << (posInByte + 1u)) | ((lsb & bit) << posInByte);
    colorIndex >>= posInByte * 2;

    return colorIndex;
}

int Renderer::GetMenuIndex(int line, int pixel, int wx, int wy, int lcdc)
{
    if (line < wy)
    {
        return -1;
    }

    if (pixel < wx)
    {
        return -1;
    }

    int menuX = pixel - wx;
    int menuY = line - wy;

    int tileX = menuX / 8;
    int tileY = menuY / 8;

    int tileOffsetX = menuX % 8;
    int tileOffsetY = menuY % 8;

    int offset = BGMAP1_OFFSET;
    if (lcdc & LCDC_WINDOW_SELECT)
    {
        offset = BGMAP2_OFFSET;
    }

    int tileIndex = m_Gb->vram[0][offset + tileY * 32 + tileX];
    if (!(lcdc & LCDC_TILE_DATA_SELECT) && tileIndex + 0x100 < 256 + 128)
    {
        tileIndex += 0x100;
    }

    int msb = m_Gb->vram[0][tileIndex * 16 + tileOffsetY * 2];
    int lsb = m_Gb->vram[0][tileIndex * 16 + tileOffsetY * 2 + 1];

    int posInByte = 7 - tileOffsetX;
    int bit = 1 << posInByte;
    int colorIndex = ((msb & bit) << (posInByte + 1)) | ((lsb & bit) << posInByte);
    colorIndex >>= posInByte * 2;

    return colorIndex;
}

void Renderer::ScanOAM(int line, int lcdc)
{
    std::memset(m_SpriteLine, 0, sizeof(m_SpriteLine));

    bool isBigSprite = lcdc & LCDC_SPRITE_SIZE;
    std::vector<OAMCase> oamCases;

    int count = 0;
    for (int i = 0; i < OAM_SIZE; i += 4)
    {
        if (count == 10)
        {
            break;
        }

        OAMCase oamCase = { m_Gb->oam[i], m_Gb->oam[i + 1], m_Gb->oam[i + 2], m_Gb->oam[i + 3] };
        bool isInRange = line >= oamCase.y - 16 && line < oamCase.y - 8;
        bool isInRangeForBigSprite = line >= oamCase.y - 16 && line < oamCase.y;

        if (isInRange || (isBigSprite && isInRangeForBigSprite))
        {
            oamCases.push_back(oamCase);
            count++;
        }
    }

    if (m_Gb->mode == GB_MODE_DMG)
    {
        std::sort(oamCases.begin(), oamCases.end(), [](const OAMCase& a, const OAMCase& b)
            { return a.x < b.x; });
    }

    for (int i = oamCases.size() - 1; i >= 0; i--)
    {
        auto& oamCase = oamCases[i];

        if (isBigSprite)
        {
            oamCase.tileIndex &= 0xFE;
        }

        bool isFlipX = oamCase.attributes & ATTR_X_FLIP;
        bool isFlipY = oamCase.attributes & ATTR_Y_FLIP;
        bool isTopSprite = line >= oamCase.y - 8;

        if (isBigSprite && isTopSprite != isFlipY)
        {
            oamCase.tileIndex |= 1;
        }

        int posInTileY = (line - (oamCase.y - 16)) % 8;
        if (isFlipY)
        {
            posInTileY = 7 - posInTileY;
        }

        for (int x = oamCase.x - 8; x < oamCase.x; x++)
        {
            if (x < 0 || x >= MAIN_SURFACE_WIDTH)
            {
                continue;
            }

            int posInTileX = x - (oamCase.x - 8);
            if (isFlipX)
            {
                posInTileX = 7 - posInTileX;
            }

            int msb = m_Gb->vram[0][oamCase.tileIndex * 16 + posInTileY * 2];
            int lsb = m_Gb->vram[0][oamCase.tileIndex * 16 + posInTileY * 2 + 1];

            int posInByte = 7 - posInTileX;
            int bit = 1 << posInByte;
            int colorIndex = ((msb & bit) << (posInByte + 1u)) | ((lsb & bit) << posInByte);
            colorIndex >>= posInByte * 2;

            if (colorIndex == 0)
            {
                continue;
            }

            int obp = 0;
            if (oamCase.attributes & ATTR_PALETTE)
            {
                obp = read_8(m_Gb, OBP1_OFFSET);
            }
            else
            {
                obp = read_8(m_Gb, OBP0_OFFSET);
            }

            constexpr int kObpOffsets[4] = { 0, 4, 2, 6 };
            colorIndex = (obp >> kObpOffsets[colorIndex]) & 0b11;
            
            uint16_t color = kBasicColorMap[colorIndex];
            if (m_Gb->debug_palette) {
                color = kDebugSpriteColorMap[colorIndex];
            }

            m_SpriteLine[x].isExist = true;
            m_SpriteLine[x].color = color;
            m_SpriteLine[x].isInFront = !(oamCase.attributes & ATTR_PRIORITY);
        }
    }
}

} // namespace GBMU
