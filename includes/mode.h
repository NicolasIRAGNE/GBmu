/**
 * @file mode.h
 * @author Nicolas IRAGNE (nicolas.iragne@alyce.fr)
 * @brief 
 * @date 2022-01-03
 * 
 * @copyright Copyright Alyce (c) 2022
 */

#pragma once

enum	gb_mode_e
{
	GB_MODE_DMG, ///< Original Gameboy mode.
	GB_MODE_CGB, ///< Color Gameboy mode.
	GB_MODE_GBA, ///< Gameboy Advance mode. Not supported.
	GB_MODE_AUTO, ///< Auto-detect the gameboy mode. This is done by reading the ROM header.
	GB_MODE_UNKNOWN ///< Unknown mode. This is not used but is here for completeness.
};