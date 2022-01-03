/**
 * @file ppu.h
 * @author Nicolas IRAGNE (nicolas.iragne@alyce.fr)
 * @brief Information about the PPU
 * @date 2022-01-03
 * 
 * @copyright Copyright Alyce (c) 2022
 */

#pragma once
#include "memory.h"
#include <stdint.h>

/**
 * @brief The current state of the PPU.
 * These modes indicate what the PPU is currently doing and which memory areas are currently accessible.
 */
enum	gpu_mode_e
{
	GPU_MODE_HBLANK = 0, ///< PPU is in HBLANK mode. All memory is accessible
	GPU_MODE_VBLANK = 1, ///< PPU is in VBLANK mode. All memory is accessible. It's free real estate.
	GPU_MODE_OAM = 2, ///< PPU is reading from OAM. Access to these memory areas is blocked: OAM
	GPU_MODE_VRAM = 3, ///< PPU is reading from VRAM and OAM. Access to these memory areas is blocked: VRAM, OAM and palettes
};

/**
 * @brief Contains information about the current state of the PPU.
 */
struct ppu_info_s
{
    enum gpu_mode_e mode; ///< @copydoc gpu_mode_e
    uint8_t lyc_int : 1; ///< @copydoc #STAT_LYC_INT
    uint8_t mode_2_int : 1; ///< @copydoc #STAT_MODE_2_INT
    uint8_t mode_1_int : 1; ///< @copydoc #STAT_MODE_1_INT
    uint8_t mode_0_int : 1; ///< @copydoc #STAT_MODE_0_INT
    uint8_t lyc_flag : 1; ///< @copydoc #STAT_LYC_FLAG
    uint8_t ly;
    uint8_t lyc;
    uint8_t scx;
    uint8_t scy;
    uint8_t wx;
    uint8_t wy;
    uint8_t bg_palette_index;
    uint8_t obj_palette_index;
    uint8_t cgb_bg_palettes[CRAM_SIZE];
    uint8_t cgb_obj_palettes[CRAM_SIZE];
    uint8_t hdma1;
    uint8_t hdma2;
    uint8_t hdma3;
    uint8_t hdma4;
    uint8_t hdma5;
};