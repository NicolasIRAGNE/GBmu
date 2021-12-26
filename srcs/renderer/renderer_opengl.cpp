#include "renderer_opengl.h"

#include <stdexcept>
#include <string>

constexpr uint16_t kBasicColorMap[4] = {
    28 | (25 << 5) | (20 << 10),
    21 | (18 << 5) | (2  << 10),
    12 | (6  << 5) | (6  << 10),
    7  | (2  << 5) | (2  << 10),
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

    int backgroundIndex = -1;
    int menuIndex = -1;
    int spriteIndex = -1;

    if (m_Gb->draw_background) {
        backgroundIndex = GetBackgroundIndex(line, pixel, scx, scy, lcdc);
    }
    if (m_Gb->draw_window && (lcdc & LCDC_WINDOW_ON)) {
        menuIndex = GetMenuIndex(line, pixel, wx, wy, lcdc);
    }
    bool isSpriteInFront = false;
    if (m_Gb->draw_sprites) {
        spriteIndex = GetSpriteIndex(&isSpriteInFront, line, pixel, lcdc);
    }

    int bgp = read_8(m_Gb, BGP_OFFSET);
    constexpr int kBgpOffsets[4] = {0, 4, 2, 6};
    m_TextureData[line][pixel] = 0;
    if (backgroundIndex != -1) {
        int8_t index = (bgp >> kBgpOffsets[backgroundIndex]) & 0b11;
        m_TextureData[line][pixel] = kBasicColorMap[index];
        if (m_Gb->debug_palette) {
            m_TextureData[line][pixel] = kDebugBackgroundColorMap[index];
        }
    }
    if (menuIndex != -1) {
        int8_t index = (bgp >> kBgpOffsets[menuIndex]) & 0b11;
        m_TextureData[line][pixel] = kBasicColorMap[index];
        if (m_Gb->debug_palette) {
            m_TextureData[line][pixel] = kDebugWindowColorMap[index];
        }
    }
    if (spriteIndex != -1 && (isSpriteInFront || (backgroundIndex <= 0 && menuIndex <= 0))) {
        int8_t index = spriteIndex;
        m_TextureData[line][pixel] = kBasicColorMap[index];
        if (m_Gb->debug_palette) {
            m_TextureData[line][pixel] = kDebugSpriteColorMap[index];
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

int Renderer::GetBackgroundIndex(int line, int pixel, int scx, int scy, int lcdc)
{
    if (!(lcdc & LCDC_DISPLAY_PRIORITY)) {
        return -1;
    }

    int backgroundX = (pixel + scx) % 256;
    int backgroundY = (line + scy) % 256;

    int tileX = backgroundX / 8;
    int tileY = backgroundY / 8;

    int tileOffsetX = backgroundX % 8;
    int tileOffsetY = backgroundY % 8;

    int offset = BGMAP1_OFFSET;
    if (lcdc & LCDC_TILE_MAP_SELECT) {
        offset = BGMAP2_OFFSET;
    }

    int tileIndex = m_Gb->vram[offset + tileY * 32 + tileX];
    if (!(lcdc & LCDC_TILE_DATA_SELECT) && tileIndex + 0x100 < 256 + 128) {
        tileIndex += 0x100;
    }

    int msb = m_Gb->vram[tileIndex * 16 + tileOffsetY * 2];
    int lsb = m_Gb->vram[tileIndex * 16 + tileOffsetY * 2 + 1];

    int posInByte = 7 - tileOffsetX;
    int bit = 1 << posInByte;
    int colorIndex = ((msb & bit) << (posInByte + 1u)) | ((lsb & bit) << posInByte);
    colorIndex >>= posInByte * 2;
    
    return colorIndex;
}

int Renderer::GetMenuIndex(int line, int pixel, int wx, int wy, int lcdc)
{
    if (line < wy) {
        return -1;
    }

    if (pixel < wx) {
        return -1;
    }

    int menuX = pixel - wx;
    int menuY = line - wy;

    int tileX = menuX / 8;
    int tileY = menuY / 8;

    int tileOffsetX = menuX % 8;
    int tileOffsetY = menuY % 8;

    int offset = BGMAP1_OFFSET;
    if (lcdc & LCDC_WINDOW_SELECT) {
        offset = BGMAP2_OFFSET;
    }

    int tileIndex = m_Gb->vram[offset + tileY * 32 + tileX];
    if (!(lcdc & LCDC_TILE_DATA_SELECT) && tileIndex + 0x100 < 256 + 128) {
        tileIndex += 0x100;
    }

    int msb = m_Gb->vram[tileIndex * 16 + tileOffsetY * 2];
    int lsb = m_Gb->vram[tileIndex * 16 + tileOffsetY * 2 + 1];

    int posInByte = 7 - tileOffsetX;
    int bit = 1 << posInByte;
    int colorIndex = ((msb & bit) << (posInByte + 1)) | ((lsb & bit) << posInByte);
    colorIndex >>= posInByte * 2;

    return colorIndex;
}

int Renderer::GetSpriteIndex(bool* isInFront, int line, int pixel, int lcdc)
{
    int spriteIndex = -1;
    for (int i = OAM_SIZE - 4; i >= 0; i -= 4) {
        int y = m_Gb->oam[i + 0];
        int x = m_Gb->oam[i + 1];
        int tileIndex = m_Gb->oam[i + 2];
        int attributes = m_Gb->oam[i + 3];

        if (pixel < x - 8 || pixel >= x) {
            continue;
        }

        if (lcdc & LCDC_SPRITE_SIZE) {
            tileIndex &= 0xFE;
        }

        int posInTileX = pixel - (x - 8);
        int posInTileY = 0;
        if (line >= y - 16 && line < y - 8) {
            posInTileY = line - (y - 16);
            if ((lcdc & LCDC_SPRITE_SIZE) && (attributes & ATTR_Y_FLIP)) {
                tileIndex += 1;
            }
        } else if ((lcdc & LCDC_SPRITE_SIZE) && line >= y - 8 && line < y) {
            posInTileY = line - (y - 8);
            if ((lcdc & LCDC_SPRITE_SIZE) && !(attributes & ATTR_Y_FLIP)) {
                tileIndex += 1;
            }
        } else {
            continue;
        }
        
        if (attributes & ATTR_X_FLIP) {
            posInTileX = 7 - posInTileX;
        }

        if (attributes & ATTR_Y_FLIP) {
            posInTileY = 7 - posInTileY;
        }

        *isInFront = !(attributes & ATTR_PRIORITY);

        int msb = m_Gb->vram[tileIndex * 16 + posInTileY * 2];
        int lsb = m_Gb->vram[tileIndex * 16 + posInTileY * 2 + 1];

        int posInByte = 7 - posInTileX;
        int bit = 1 << posInByte;
        int colorIndex = ((msb & bit) << (posInByte + 1u)) | ((lsb & bit) << posInByte);
        colorIndex >>= posInByte * 2;

        if (colorIndex == 0) {
            continue;
        }

        constexpr int kObpOffsets[4] = {0, 4, 2, 6};
        if (attributes & ATTR_PALETTE) {
            int obp1 = read_8(m_Gb, OBP1_OFFSET);
            spriteIndex = (obp1 >> kObpOffsets[colorIndex]) & 0b11;
        } else {
            int obp0 = read_8(m_Gb, OBP0_OFFSET);
            spriteIndex = (obp0 >> kObpOffsets[colorIndex]) & 0b11;
        }
    }

    return spriteIndex;
}

} // namespace GBMU
