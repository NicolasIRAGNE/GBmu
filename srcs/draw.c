/**
 * @file draw.c
 * @author Nicolas IRAGNE (nicolas.iragne@alyce.fr)
 * @brief
 * @date 2022-01-05
 *
 * @copyright Copyright Alyce (c) 2022
 */

#include "draw.h"
#include "cpu.h"
#include "gb.h"
#include <stdbool.h>
#include <string.h>

uint16_t kBasicColorMap[4] = {
    28 | (25 << 5) | (20 << 10),
    21 | (18 << 5) | (2 << 10),
    12 | (6 << 5) | (6 << 10),
    7 | (2 << 5) | (2 << 10),
};

uint16_t kDebugMenuColorMap[4] = {
    31 | (0 << 5) | (0 << 10),
    25 | (0 << 5) | (0 << 10),
    19 | (0 << 5) | (0 << 10),
    12 | (0 << 5) | (0 << 10),
};

uint16_t kDebugSpriteColorMap[4] = {
    0 | (31 << 5) | (0 << 10),
    0 | (25 << 5) | (0 << 10),
    0 | (19 << 5) | (0 << 10),
    0 | (12 << 5) | (0 << 10),
};

uint16_t kDebugBackgroundColorMap[4] = {
    0 | (0 << 5) | (31 << 10),
    0 | (0 << 5) | (25 << 10),
    0 | (0 << 5) | (19 << 10),
    0 | (0 << 5) | (12 << 10),
};

static struct Pixel m_SpriteLine[MAIN_SURFACE_WIDTH];

uint32_t m_TextureData[MAIN_SURFACE_HEIGHT][MAIN_SURFACE_WIDTH];
int m_MenuXOffset;
int m_MenuYOffset;
uint8_t m_Low3bitsOfSCX;

uint16_t GetBackgroundColor(enum Priority* priority, int line, int pixel, int scx, int scy, int lcdc)
{
    int offsetX = (pixel + scx) % 256;
    int offsetY = (line + scy) % 256;

    bool useBgmap2 = lcdc & LCDC_TILE_MAP_SELECT;

    return GetColor(priority, offsetX, offsetY, lcdc, useBgmap2, kDebugBackgroundColorMap);
}

uint16_t GetMenuColor(enum Priority* priority, int line, int pixel, int wx, int wy, int lcdc)
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

/**
 * @brief Sort OAM using bubble sort
 *
 * @param oam
 * @param size
 */
void    sort_oam(struct OAMCase* oam, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (oam[j].x > oam[j + 1].x)
            {
                struct OAMCase tmp = oam[j];
                oam[j] = oam[j + 1];
                oam[j + 1] = tmp;
            }
        }
    }
}

void    quicksort_oam(struct OAMCase* oam, int size)
{
    if (size <= 1)
    {
        return;
    }

    int pivot = oam[size / 2].x;
    int i = 0;
    int j = size - 1;

    while (i <= j)
    {
        while (oam[i].x <= pivot && i < size)
        {
            i++;
        }

        while (oam[j].x > pivot && j >= 0)
        {
            j--;
        }

        if (i <= j)
        {
            struct OAMCase tmp = oam[i];
            oam[i] = oam[j];
            oam[j] = tmp;
            i++;
            j--;
        }
    }

    quicksort_oam(oam, j);
    quicksort_oam(oam + i, size - i);
}

void ScanOAM(int line, int lcdc)
{
    memset(m_SpriteLine, 0, sizeof(m_SpriteLine));

    bool isBigSprite = lcdc & LCDC_SPRITE_SIZE;
    struct OAMCase oamCases[MAXIMUM_SPRITES_PER_LINE];

    int count = 0;
    for (int i = 0; i < OAM_SIZE; i += 4)
    {
        if (count == MAXIMUM_SPRITES_PER_LINE)
        {
            break;
        }

        struct OAMCase oamCase = { gb_global.oam[i], gb_global.oam[i + 1], gb_global.oam[i + 2], gb_global.oam[i + 3] };
        bool isInRange = line >= oamCase.y - 16 && line < oamCase.y - 8;
        bool isInRangeForBigSprite = line >= oamCase.y - 16 && line < oamCase.y;

        if (isInRange || (isBigSprite && isInRangeForBigSprite))
        {
            oamCases[count] = oamCase;
            count++;
        }
    }

    if (gb_global.mode == GB_MODE_DMG)
    {
        quicksort_oam(oamCases, count);
    }

    for (int i = count - 1; i >= 0; i--)
    {
        struct OAMCase oamCase = oamCases[i];

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

            if (gb_global.mode == GB_MODE_DMG)
            {
                int obp = 0;
                if (oamCase.attributes & ATTR_PALETTE)
                {
                    obp = read_8(&gb_global, OBP1_OFFSET);
                }
                else
                {
                    obp = read_8(&gb_global, OBP0_OFFSET);
                }
                colorIndex = TransformColorIndex(colorIndex, obp);
            }

            uint16_t color = 0;
            if (gb_global.debug_palette)
            {
                color = kDebugSpriteColorMap[colorIndex];
            }
            else if (gb_global.mode == GB_MODE_DMG)
            {
                color = kBasicColorMap[colorIndex];
            }
            else if (gb_global.mode == GB_MODE_CGB)
            {
                int nPalette = oamCase.attributes & 0b111;
                uint16_t* objPalette = (uint16_t*)(gb_global.cgb_obj_palettes);
                if (colorIndex == 1)
                    colorIndex = 2;
                else if (colorIndex == 2)
                    colorIndex = 1;
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

uint16_t GetColor(enum Priority* priority, int offsetX, int offsetY, int lcdc, bool useBgmap2, const uint16_t* debugPalette)
{
    if (!(lcdc & LCDC_DISPLAY_PRIORITY) && gb_global.mode == GB_MODE_DMG)
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

    int tileIndex = gb_global.vram[0][offset + tileY * 32 + tileX];
    if (!(lcdc & LCDC_TILE_DATA_SELECT) && tileIndex + 0x100 < 256 + 128)
    {
        tileIndex += 0x100;
    }

    int tileAttr = 0;
    if (gb_global.mode == GB_MODE_CGB)
    {
        tileAttr = gb_global.vram[1][offset + tileY * 32 + tileX];
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

    if (gb_global.mode == GB_MODE_DMG)
    {
        int bgp = read_8(&gb_global, BGP_OFFSET);
        colorIndex = TransformColorIndex(colorIndex, bgp);
    }

    if (gb_global.debug_palette)
    {
        return debugPalette[colorIndex];
    }

    if (gb_global.mode == GB_MODE_DMG)
    {
        return kBasicColorMap[colorIndex];
    }

    if (gb_global.mode == GB_MODE_CGB)
    {
        int paletteNumber = tileAttr & 0b111;
        uint16_t* palettes = (uint16_t*)(gb_global.cgb_bg_palettes);
        if (colorIndex == 1)
            colorIndex = 2;
        else if (colorIndex == 2)
            colorIndex = 1;
        return palettes[4 * paletteNumber + colorIndex];
    }

    return 0;
}

int GetColorIndex(int tileIndex, int tileAttr, int x, int y)
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

    int msb = gb_global.vram[tileBank][tileIndex * 16 + y * 2];
    int lsb = gb_global.vram[tileBank][tileIndex * 16 + y * 2 + 1];

    int posInByte = 7 - x;
    int bit = 1 << posInByte;
    int colorIndex = ((msb & bit) << (posInByte + 1u)) | ((lsb & bit) << posInByte);
    colorIndex >>= posInByte * 2;

    return colorIndex;
}

int TransformColorIndex(int colorIndex, int paletteOffset)
{
    int kObpOffsets[4] = { 0, 4, 2, 6 };
    colorIndex = (paletteOffset >> kObpOffsets[colorIndex]) & 0b11;

    return colorIndex;
}

void DrawPixel(int line, int pixel)
{
    int lcdc = read_8(&gb_global, LCDC_OFFSET);
    int scx = read_8(&gb_global, SCX_OFFSET);
    int scy = read_8(&gb_global, SCY_OFFSET);

    if (!(pixel < 160 && line < 144))
    {
        return;
    }

    if (pixel == 0)
    {
        m_MenuXOffset = read_8(&gb_global, WX_OFFSET) - 7;
        m_Low3bitsOfSCX = scx & 0b111;
        if (line == 0)
        {
            m_MenuYOffset = read_8(&gb_global, WY_OFFSET);
        }
    }

    scx = (scx & ~0b111) | m_Low3bitsOfSCX;

    DrawPixelToTextureData(line, pixel, 0);

    struct Pixel sprite = m_SpriteLine[pixel];
    if (!gb_global.draw_sprites || !(lcdc & LCDC_SPRITE_ON))
    {
        sprite.priority = kNull;
    }
    if (gb_global.draw_sprites && sprite.priority != kNull)
    {
        DrawPixelToTextureData(line, pixel, sprite.color);
    }

    enum Priority menuPriority = kNull;
    if (gb_global.draw_window && (lcdc & LCDC_WINDOW_ON))
    {
        uint16_t color = GetMenuColor(&menuPriority, line, pixel, m_MenuXOffset, m_MenuYOffset, lcdc);
        if (menuPriority > sprite.priority)
        {
            DrawPixelToTextureData(line, pixel, color);
        }
    }

    enum Priority backgroundPriority = kLow;
    if (gb_global.draw_background && menuPriority == kNull)
    {
        uint16_t color = GetBackgroundColor(&backgroundPriority, line, pixel, scx, scy, lcdc);
        if (backgroundPriority > menuPriority && backgroundPriority > sprite.priority)
        {
            DrawPixelToTextureData(line, pixel, color);
        }
    }
}

void DrawPixelToTextureData(int line, int pixel, uint16_t color)
{
    uint8_t r = ((color >> 10) & 0x1F) * 0xFF / 0x1F;
    uint8_t g = ((color >> 5) & 0x1F) * 0xFF / 0x1F;
    uint8_t b = ((color >> 0) & 0x1F) * 0xFF / 0x1F;
    uint32_t pixelColor = (r << 16) | (g << 8) | b;

    m_TextureData[line][pixel] = pixelColor;
}

void DrawRange(int start_x, int start_y, int end_x, int end_y)
{
    for (int line = start_y; line <= end_y; line++)
    {
        for (int pixel = start_x; pixel < end_x; pixel++)
        {
            DrawPixel(line, pixel);
        }
    }
}
