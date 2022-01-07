/**
 * @file draw.h
 * @author Nicolas IRAGNE (nicolas.iragne@alyce.fr)
 * @brief
 * @date 2022-01-05
 *
 * @copyright Copyright Alyce (c) 2022
 */

#pragma once

#include <stdint.h>
#include <stdbool.h>

# define MAIN_SURFACE_WIDTH		        (160)
# define MAIN_SURFACE_HEIGHT            (144)
# define MAXIMUM_SPRITES_PER_LINE	    10

# define TILE_SIZE			            16
# define TILES_COUNT                    ((VRAM_TILE_BANK_SIZE + 1) / TILE_SIZE)

# define ATTR_PRIORITY	                (1 << 7)
# define ATTR_Y_FLIP	                (1 << 6)
# define ATTR_X_FLIP 	                (1 << 5)
# define ATTR_PALETTE 	                (1 << 4)
# define ATTR_BANK		                (1 << 3)

enum Priority
{
    kNull = 0,
    kVeryLow = 1,
    kLow = 2,
    kMedium = 3,
    kHigh = 4
};

struct Pixel
{
    enum Priority priority;
    uint16_t color;
};

struct OAMCase
{
    uint8_t y;
    uint8_t x;
    uint8_t tileIndex;
    uint8_t attributes;
};

uint16_t GetBackgroundColor(enum Priority* priority, int line, int pixel, int scx, int scy, int lcdc);
uint16_t GetMenuColor(enum Priority* priority, int line, int pixel, int wx, int wy, int lcdc);
void ScanOAM(int line, int lcdc);
uint16_t GetColor(enum Priority* priority, int offsetX, int offsetY, int lcdc, bool useBgmap2, const uint16_t* debugPalette);
int GetColorIndex(int tileIndex, int tileAttr, int x, int y);
int TransformColorIndex(int colorIndex, int paletteOffset);
void DrawPixel(int line, int pixel);
void DrawPixelToTextureData(int line, int pixel, uint16_t color);
void DrawRange(int start_x, int start_y, int end_x, int end_y);