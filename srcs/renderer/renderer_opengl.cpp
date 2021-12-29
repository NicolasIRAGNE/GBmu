#include "renderer_opengl.h"

#include "gl_utils/glerr.h"
#include <algorithm>
#include <cstring>
#include <stdexcept>
#include <string>
#include <vector>

constexpr uint16_t kBasicColorMap[4] = {
    28 | (25 << 5) | (20 << 10),
    21 | (18 << 5) | (2 << 10),
    12 | (6 << 5) | (6 << 10),
    7 | (2 << 5) | (2 << 10),
};

constexpr uint16_t kDebugMenuColorMap[4] = {
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
    InitPbo();
}

Renderer::~Renderer()
{
    DestroyPbo();
    DestroyTexture();
}

void Renderer::DrawPixel(int line, int pixel)
{
    int lcdc = read_8(m_Gb, LCDC_OFFSET);
    int scx = read_8(m_Gb, SCX_OFFSET);
    int scy = read_8(m_Gb, SCY_OFFSET);

    if (pixel == 0)
    {
        ScanOAM(line, lcdc);
        m_MenuXOffset = read_8(m_Gb, WX_OFFSET) - 7;
        m_Low3bitsOfSCX = scx & 0b111;
        if (line == 0)
        {
            m_MenuYOffset = read_8(m_Gb, WY_OFFSET);
        }
    }

    scx = (scx & ~0b111) | m_Low3bitsOfSCX;

    m_TextureData[line][pixel] = 0;

    auto& sprite = m_SpriteLine[pixel];
    if (!(lcdc & LCDC_SPRITE_ON))
    {
        sprite.priority = Priority::kNull;
    }
    if (m_Gb->draw_sprites && sprite.priority != Priority::kNull)
    {
        m_TextureData[line][pixel] = sprite.color;
    }

    Priority menuPriority = Priority::kNull;
    if (m_Gb->draw_window && (lcdc & LCDC_WINDOW_ON))
    {
        uint16_t color = GetMenuColor(&menuPriority, line, pixel, m_MenuXOffset, m_MenuYOffset, lcdc);
        if (menuPriority > sprite.priority)
        {
            m_TextureData[line][pixel] = color;
        }
    }

    Priority backgroundPriority = Priority::kLow;
    if (m_Gb->draw_background && menuPriority == kNull)
    {
        uint16_t color = GetBackgroundColor(&backgroundPriority, line, pixel, scx, scy, lcdc);
        if (backgroundPriority > menuPriority && backgroundPriority > sprite.priority)
        {
            m_TextureData[line][pixel] = color;
        }
    }
}

void Renderer::Render()
{
    glBindBuffer(GL_PIXEL_UNPACK_BUFFER, m_Pbo);
    void* mappedBuffer = glMapBuffer(GL_PIXEL_UNPACK_BUFFER, GL_WRITE_ONLY);
    std::memcpy(mappedBuffer, m_TextureData, sizeof(m_TextureData));
    glUnmapBuffer(GL_PIXEL_UNPACK_BUFFER);

    glBindTexture(GL_TEXTURE_2D, m_Texture);
    glTexImage2D(
        GL_TEXTURE_2D,
        0,
        GL_RGBA,
        MAIN_SURFACE_WIDTH,
        MAIN_SURFACE_HEIGHT,
        0,
        GL_RGBA,
        GL_UNSIGNED_SHORT_1_5_5_5_REV,
        0);
    glBindTexture(GL_TEXTURE_2D, 0);
    glBindBuffer(GL_PIXEL_UNPACK_BUFFER, 0);

    m_Rescale.Draw(m_Texture);
}

void Renderer::Clear()
{
    glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::SetWindowSize(int width, int height)
{
    glViewport(0, 0, width, height);
}

void Renderer::InitTexture()
{
    glGenTextures(1, &m_Texture);
    glBindTexture(GL_TEXTURE_2D, m_Texture);
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
}

void Renderer::InitPbo()
{
    int pboSize = MAIN_SURFACE_WIDTH * MAIN_SURFACE_HEIGHT * sizeof(uint16_t);

    glGenBuffers(1, &m_Pbo);
    glBindBuffer(GL_PIXEL_UNPACK_BUFFER, m_Pbo);
    glBufferData(GL_PIXEL_UNPACK_BUFFER, pboSize, NULL, GL_STREAM_DRAW);
    glBindBuffer(GL_PIXEL_UNPACK_BUFFER, 0);
}

void Renderer::DestroyPbo()
{
    glDeleteBuffers(1, &m_Pbo);
}

uint16_t Renderer::GetBackgroundColor(Priority* priority, int line, int pixel, int scx, int scy, int lcdc)
{
    int offsetX = (pixel + scx) % 256;
    int offsetY = (line + scy) % 256;

    bool useBgmap2 = lcdc & LCDC_TILE_MAP_SELECT;

    return GetColor(priority, offsetX, offsetY, lcdc, useBgmap2, kDebugBackgroundColorMap);
}

uint16_t Renderer::GetMenuColor(Priority* priority, int line, int pixel, int wx, int wy, int lcdc)
{
    if (pixel < wx || line < wy)
    {
        return 0;
    }

    int offsetX = pixel - wx;
    int offsetY = line - wy;

    bool useBgmap2 = lcdc & LCDC_WINDOW_SELECT;

    return GetColor(priority, offsetX, offsetY, lcdc, useBgmap2, kDebugMenuColorMap);
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

        for (int x = oamCase.x - 8; x < oamCase.x; x++)
        {
            if (x < 0 || x >= MAIN_SURFACE_WIDTH)
            {
                continue;
            }

            int posInTileX = x - (oamCase.x - 8);
            int colorIndex = GetColorIndex(oamCase.tileIndex, oamCase.attributes, posInTileX, posInTileY);

            if (colorIndex == 0)
            {
                continue;
            }

            if (m_Gb->mode == GB_MODE_DMG)
            {
                int obp = 0;
                if (oamCase.attributes & ATTR_PALETTE)
                {
                    obp = read_8(m_Gb, OBP1_OFFSET);
                }
                else
                {
                    obp = read_8(m_Gb, OBP0_OFFSET);
                }
                colorIndex = TransformColorIndex(colorIndex, obp);
            }

            uint16_t color = 0;
            if (m_Gb->debug_palette)
            {
                color = kDebugSpriteColorMap[colorIndex];
            }
            else if (m_Gb->mode == GB_MODE_DMG)
            {
                color = kBasicColorMap[colorIndex];
            }
            else if (m_Gb->mode == GB_MODE_CGB)
            {
                int nPalette = oamCase.attributes & 0b111;
                uint16_t* objPalette = reinterpret_cast<uint16_t*>(m_Gb->cgb_obj_palettes);
                color = objPalette[4 * nPalette + colorIndex];
            }

            m_SpriteLine[x].priority = kMedium;
            if (oamCase.attributes & ATTR_PRIORITY)
            {
                m_SpriteLine[x].priority = kLow;
            }
            m_SpriteLine[x].color = color;
        }
    }
}

uint16_t Renderer::GetColor(Priority* priority, int offsetX, int offsetY, int lcdc, bool useBgmap2, const uint16_t* debugPalette)
{
    if (!(lcdc & LCDC_DISPLAY_PRIORITY) && m_Gb->mode == GB_MODE_DMG)
    {
        return kBasicColorMap[0];
    }

    int tileX = offsetX / 8;
    int tileY = offsetY / 8;

    int tileOffsetX = offsetX % 8;
    int tileOffsetY = offsetY % 8;

    int offset = BGMAP1_OFFSET;
    if (useBgmap2)
    {
        offset = BGMAP2_OFFSET;
    }

    int tileIndex = m_Gb->vram[0][offset + tileY * 32 + tileX];
    if (!(lcdc & LCDC_TILE_DATA_SELECT) && tileIndex + 0x100 < 256 + 128)
    {
        tileIndex += 0x100;
    }

    int tileAttr = 0;
    if (m_Gb->mode == GB_MODE_CGB)
    {
        tileAttr = m_Gb->vram[1][offset + tileY * 32 + tileX];
    }
    int colorIndex = GetColorIndex(tileIndex, tileAttr, tileOffsetX, tileOffsetY);

    *priority = kLow;
    if (!(lcdc & LCDC_DISPLAY_PRIORITY))
    {
        *priority = kVeryLow;
    }
    else if (tileAttr & ATTR_PRIORITY)
    {
        *priority = kHigh;
    }
    else if (colorIndex != 0)
    {
        *priority = kMedium;
    }

    if (m_Gb->mode == GB_MODE_DMG)
    {
        int bgp = read_8(m_Gb, BGP_OFFSET);
        colorIndex = TransformColorIndex(colorIndex, bgp);
    }

    if (m_Gb->debug_palette)
    {
        return debugPalette[colorIndex];
    }

    if (m_Gb->mode == GB_MODE_DMG)
    {
        return kBasicColorMap[colorIndex];
    }

    if (m_Gb->mode == GB_MODE_CGB)
    {
        int paletteNumber = tileAttr & 0b111;
        uint16_t* palettes = reinterpret_cast<uint16_t*>(m_Gb->cgb_bg_palettes);
        return palettes[4 * paletteNumber + colorIndex];
    }

    return 0;
}

int Renderer::GetColorIndex(int tileIndex, int tileAttr, int x, int y)
{
    int tileBank = (tileAttr & ATTR_BANK) ? 1 : 0;

    if (tileAttr & ATTR_X_FLIP)
    {
        x = 7 - x;
    }

    if (tileAttr & ATTR_Y_FLIP)
    {
        y = 7 - y;
    }

    int msb = m_Gb->vram[tileBank][tileIndex * 16 + y * 2];
    int lsb = m_Gb->vram[tileBank][tileIndex * 16 + y * 2 + 1];

    int posInByte = 7 - x;
    int bit = 1 << posInByte;
    int colorIndex = ((msb & bit) << (posInByte + 1u)) | ((lsb & bit) << posInByte);
    colorIndex >>= posInByte * 2;

    return colorIndex;
}

int Renderer::TransformColorIndex(int colorIndex, int paletteOffset)
{
    constexpr int kObpOffsets[4] = { 0, 4, 2, 6 };
    colorIndex = (paletteOffset >> kObpOffsets[colorIndex]) & 0b11;

    return colorIndex;
}

} // namespace GBMU
