/**
 * @file memory.h
 * @author Nicolas IRAGNE (nicolas.iragne@alyce.fr)
 * @brief Mostly contains defines of memory offsets and masks.
 * @date 2022-01-03
 * 
 * @copyright Copyright Alyce (c) 2022
 */

#pragma once

# define VRAM_SIZE 0x2000			///< 8kiB
# define WRAM_SIZE 0x2000			///< 8kiB
# define HRAM_SIZE 0x100			///< 256B
# define RAM_SIZE 0x1000			///< 4kiB
# define EXTRA_RAM_SIZE 0x2000		///< 8kiB
# define IO_PORTS_SIZE 0x100		///< 256B
# define OAM_SIZE 0xa0				///< 160B
# define CRAM_SIZE	0x40			///< 64B

# define VRAM_TILE_BANK_SIZE 0x1800 ///< 96kiB

# define OAM_OFFSET 0xFE00 ///< 0xFE00 - 0xFE9F

# define IO_OFFSET			0xFF00 ///< 0xFF00 - 0xFF7F
# define JOYP_OFFSET			(IO_OFFSET | 0x00) ///< 0xFF00
# define SERIAL_DATA_OFFSET		(IO_OFFSET | 0x01) ///< 0xFF01
# define SERIAL_CONTROL_OFFSET	(IO_OFFSET | 0x02) ///< 0xFF02

// TIMER
# define DIV_OFFSET				(IO_OFFSET | 0x04) ///< 0xFF04
# define TIMA_OFFSET			(IO_OFFSET | 0x05) ///< 0xFF05
# define TMA_OFFSET				(IO_OFFSET | 0x06) ///< 0xFF06
# define TAC_OFFSET				(IO_OFFSET | 0x07) ///< 0xFF07

// LCD SCREEN
# define LCDC_OFFSET 			(IO_OFFSET | 0x40) ///< 0xFF40
# define STAT_OFFSET 			(IO_OFFSET | 0x41) ///< 0xFF41
# define SCY_OFFSET				(IO_OFFSET | 0x42) ///< 0xFF42
# define SCX_OFFSET				(IO_OFFSET | 0x43) ///< 0xFF43
# define LY_OFFSET				(IO_OFFSET | 0x44) ///< 0xFF44
# define LYC_OFFSET				(IO_OFFSET | 0x45) ///< 0xFF45
# define DMA_OFFSET				(IO_OFFSET | 0x46) ///< 0xFF46
# define BGP_OFFSET				(IO_OFFSET | 0x47) ///< 0xFF47
# define OBP0_OFFSET			(IO_OFFSET | 0x48) ///< 0xFF48
# define OBP1_OFFSET			(IO_OFFSET | 0x49) ///< 0xFF49
# define WY_OFFSET				(IO_OFFSET | 0x4A) ///< 0xFF4A
# define WX_OFFSET				(IO_OFFSET | 0x4B) ///< 0xFF4B
# define KEY1_OFFSET			(IO_OFFSET | 0x4D) ///< 0xFF4D
# define HDMA1_OFFSET			(IO_OFFSET | 0x51) ///< 0xFF51
# define HDMA2_OFFSET			(IO_OFFSET | 0x52) ///< 0xFF52
# define HDMA3_OFFSET			(IO_OFFSET | 0x53) ///< 0xFF53
# define HDMA4_OFFSET			(IO_OFFSET | 0x54) ///< 0xFF54
# define HDMA5_OFFSET			(IO_OFFSET | 0x55) ///< 0xFF55

# define BCPS_OFFSET			(IO_OFFSET | 0x68) ///< 0xFF68
# define BCPD_OFFSET			(IO_OFFSET | 0x69) ///< 0xFF69
# define OCPS_OFFSET			(IO_OFFSET | 0x6A) ///< 0xFF6A
# define OCPD_OFFSET			(IO_OFFSET | 0x6B) ///< 0xFF6B

# define VBK_OFFSET				(IO_OFFSET | 0x4F) ///< 0xFF4F
# define SVBK_OFFSET			(IO_OFFSET | 0x70) ///< 0xFF70

# define IF_OFFSET				(IO_OFFSET | 0x0F) ///< 0xFF0F

// LCDC
# define LCDC_ON					(1 << 7)
# define LCDC_WINDOW_SELECT			(1 << 6)
# define LCDC_WINDOW_ON				(1 << 5)
# define LCDC_TILE_DATA_SELECT		(1 << 4)
# define LCDC_TILE_MAP_SELECT		(1 << 3)
# define LCDC_SPRITE_SIZE			(1 << 2)
# define LCDC_SPRITE_ON				(1 << 1)
# define LCDC_DISPLAY_PRIORITY		(1 << 0)

# define BGMAP1_OFFSET	0x1800
# define BGMAP2_OFFSET	0x1C00
# define BGMAP_SIZE		0x0400

// FLAG REGISTER: ZNHC0000
# define ZERO_FLAG			(1 << 7)
# define SUBSTRACTION_FLAG	(1 << 6)
# define HALF_CARRY_FLAG	(1 << 5)
# define CARRY_FLAG			(1 << 4)

enum gb_intr_e
{
    INT_VBLANK_REQUEST = (1 << 0), ///< Fired when the LCD screen finishes drawing the current frame.
    INT_STAT_REQUEST = (1 << 1), ///< Generic interrupt fired when any of the events enabled by the stat register (#STAT_OFFSET) occur.
    INT_TIMER_REQUEST = (1 << 2), ///< Fired whenever the timer (#TIMA_OFFSET) overflows.
    INT_SERIAL_REQUEST = (1 << 3), ///< yeah i don't remember what this is for.
    INT_JOYPAD_REQUEST = (1 << 4) ///< Fired whenever a button is pressed.
};

# define INT_VBLANK_ADDR		0x40
# define INT_STAT_ADDR			0x48
# define INT_TIMER_ADDR			0x50
# define INT_SERIAL_ADDR		0x58

// Joypad
# define SELECT_NONE			0x30
# define SELECT_DIRECTION_KEYS	0x20
# define SELECT_BUTTON_KEYS		0x10

# define JOYP_INPUT_DOWN		(1 << 3)
# define JOYP_INPUT_UP			(1 << 2)
# define JOYP_INPUT_LEFT		(1 << 1)
# define JOYP_INPUT_RIGHT		(1 << 0)

# define JOYP_INPUT_START		(1 << 3)
# define JOYP_INPUT_SELECT		(1 << 2)
# define JOYP_INPUT_B			(1 << 1)
# define JOYP_INPUT_A			(1 << 0)

// Stat register
# define STAT_LYC_INT			(1 << 6) ///< Interrupt when the LY register (#LY_OFFSET) matches the LYC register (#LYC_OFFSET).
# define STAT_MODE_2_INT		(1 << 5) ///< Interrupt when PPU switches to mode 2.
# define STAT_MODE_1_INT		(1 << 4) ///< Interrupt when PPU switches to mode 1.
# define STAT_MODE_0_INT		(1 << 3) ///< Interrupt when PPU switches to mode 0.
# define STAT_LYC_FLAG			(1 << 2) ///< Set when the LY register (#LY_OFFSET) matches the LYC register (#LYC_OFFSET).

# define DEFAULT_DIV_FREQ		16384
# define SGB_DIV_FREQ			16779
# define DOUBLE_DIV_FREQ		(DEFAULT_DIV_FREQ * 2)

# define TIMER_FREQ_0			4096
# define TIMER_FREQ_1			262144
# define TIMER_FREQ_2			65536
# define TIMER_FREQ_3			16384

# define TAC_ENABLE				(1 << 2)
# define TAC_FREQ				(0b11)

# define NORMAL_SPEED_MODE		0
# define DOUBLE_SPEED_MODE		1

# define VRAM_BANKS				2
# define WRAM_BANKS				8