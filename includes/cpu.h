/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpu.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 16:34:47 by niragne           #+#    #+#             */
/*   Updated: 2020/06/14 17:03:49 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPU_H
# define CPU_H
# include <stdint.h>
# include "mbc.h"

# define VRAM_SIZE 0x2000			// 8kiB
# define WRAM_SIZE 0x2000			// 8kiB
# define HRAM_SIZE 0x100			// 256B
# define RAM_SIZE 0x1000			// 4kiB
# define EXTRA_RAM_SIZE 0x2000		// 8kiB
# define IO_PORTS_SIZE 0x100		// 256B
# define OAM_SIZE 0xa0				// 160B
# define DMG_BOOT_ROM_SIZE 0x100	// 256B

# define VRAM_TILE_BANK_SIZE 0x1800

# define IO_OFFSET			0xFF00
# define JOYP_OFFSET			(IO_OFFSET | 0x00)
# define SERIAL_DATA_OFFSET		(IO_OFFSET | 0x01)
# define SERIAL_CONTROL_OFFSET	(IO_OFFSET | 0x02)

// TIMER
# define DIV_OFFSET				(IO_OFFSET | 0x04)
# define TIMA_OFFSET			(IO_OFFSET | 0x05)
# define TMA_OFFSET				(IO_OFFSET | 0x06)
# define TAC_OFFSET				(IO_OFFSET | 0x07)

// LCD SCREEN
# define LCDC_OFFSET 			(IO_OFFSET | 0x40)
# define STAT_OFFSET 			(IO_OFFSET | 0x41)
# define SCY_OFFSET				(IO_OFFSET | 0x42)
# define SCX_OFFSET				(IO_OFFSET | 0x43)
# define LY_OFFSET				(IO_OFFSET | 0x44)
# define LYC_OFFSET				(IO_OFFSET | 0x45)
# define DMA_OFFSET				(IO_OFFSET | 0x46)
# define BGP_OFFSET				(IO_OFFSET | 0x47)
# define OBP0_OFFSET			(IO_OFFSET | 0x48)
# define OBP1_OFFSET			(IO_OFFSET | 0x49)
# define WY_OFFSET				(IO_OFFSET | 0x4A)
# define WX_OFFSET				(IO_OFFSET | 0x4B)
# define KEY1_OFFSET			(IO_OFFSET | 0x4D)

# define VBK_OFFSET				(IO_OFFSET | 0x4F)
# define SVBK_OFFSET			(IO_OFFSET | 0x70)

# define IF_OFFSET				(IO_OFFSET | 0x0F)

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

# define INT_VBLANK_REQUEST	(1 << 0)
# define INT_STAT_REQUEST	(1 << 1)
# define INT_TIMER_REQUEST	(1 << 2)
# define INT_SERIAL_REQUEST	(1 << 3)
# define INT_JOYPAD_REQUEST	(1 << 4) // useless i think ?

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
# define STAT_LYC_INT			(1 << 6)
# define STAT_MODE_2_INT		(1 << 5)
# define STAT_MODE_1_INT		(1 << 4)
# define STAT_MODE_0_INT		(1 << 3)
# define STAT_LYC_FLAG			(1 << 2)

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

struct	gb_cpu_s;

struct registers_s {
	struct {
		union {
			struct {
				uint8_t f;
				uint8_t a;
			};
			uint16_t af;
		};
	};
	
	struct {
		union {
			struct {
			
				uint8_t c;
				uint8_t b;
			};
			uint16_t bc;
		};
	};
	
	struct {
		union {
			struct {
				uint8_t e;
				uint8_t d;
			};
			uint16_t de;
		};
	};
	
	struct {
		union {
			struct {
				uint8_t l;
				uint8_t h;
			};
			uint16_t hl;
		};
	};
	
	uint16_t	sp; // Stack pointer
	uint16_t	pc; // Program counter
};

enum	tile_type_e
{
	TILE_TYPE_BACKGROUND,
	TILE_TYPE_SPRITE,
	TILE_TYPE_WINDOW,
};

enum	gpu_mode_e
{
	GPU_MODE_HBLANK = 0,
	GPU_MODE_VBLANK,
	GPU_MODE_OAM,
	GPU_MODE_VRAM,
};

struct	gb_gpu_s
{
	uint64_t		tick;
	uint64_t		last_cycle;
	uint8_t			y_coord;
	uint8_t			x_coord;
	uint64_t		tick_save;
	uint32_t		y_coord_save;
	enum gpu_mode_e	mode;
	enum gpu_mode_e	mode_save;
	int lyc_requested : 1;
};

enum	joypad_mode_e
{
	JOYPAD_MODE_NONE,
	JOYPAD_MODE_BUTTONS,
	JOYPAD_MODE_DIRECTIONS,
};

struct	joypad_s
{
	uint8_t		start : 1;
	uint8_t		select : 1;
	uint8_t		b : 1;
	uint8_t		a : 1;
	uint8_t		down : 1;
	uint8_t		up : 1;
	uint8_t		left : 1;
	uint8_t		right : 1;
};

struct tima_s
{
	uint64_t	freq;
	uint64_t	clocks;
	uint64_t	last_cycle;
};

struct Lcd {
    uint32_t lcdc;
    int32_t scx;
    int32_t scy;
    int32_t wx;
    int32_t wy;
};
    
enum	gb_mode_e
{
	GB_MODE_DMG, //<! Original Gameboy mode.
	GB_MODE_CGB, //<! Color Gameboy mode.
	GB_MODE_GBA, //<! Gameboy Advance mode. Not supported.
	GB_MODE_AUTO, //<! Auto-detect the gameboy mode. This is done by reading the ROM header.
	GB_MODE_UNKNOWN //<! Unknown mode. I don't know what this is. Too bad!
};

struct	gb_cpu_s
{
	int					jmp : 1; // Flag used by the emulator. Ugly but hopefully temporary ?

	int					vram_viewer_running : 1;
	int					running : 1;
	int					paused : 1;
	int					draw_background : 1;
	int					draw_window : 1;
	int					draw_sprites : 1;
	uint16_t			interrupt;
	uint64_t			cycle;
	uint64_t			last_sleep;
	uint64_t			last_dma;
	struct gbmu_debugger_s*	debugger;
	enum gb_mode_e		mode;

	int					ime : 1; // Interrupt Master Enable Flag
	int					ram_enabled : 1;
	int					halted : 1;
	int					booted : 1;
	int					debug_palette : 1;
	struct registers_s	reg;
	struct inst_s*		current_instruction;
	struct rom_s*		rom_ptr;
	struct gb_gpu_s		gpu;
	struct mbc_s		mbc;
	struct tima_s		tima;
	struct joypad_s		joypad;
	uint8_t*			boot_rom;
	uint8_t				vram[VRAM_BANKS][VRAM_SIZE];
	int					vram_updated[VRAM_BANKS];
	uint8_t				vram_bank;
	uint8_t				ram[WRAM_BANKS][RAM_SIZE];
	uint8_t				wram_bank;
	uint8_t*			extra_ram;
	uint8_t				hram[HRAM_SIZE];
	uint8_t				io_ports[IO_PORTS_SIZE];
	uint8_t				oam[OAM_SIZE];
	uint8_t				interrupt_enable_register;
	enum joypad_mode_e	joypad_mode;
	uint32_t			bg_palettes[8][4];
	uint32_t			obj_palettes[8][4];
	uint32_t			div_freq;
	uint64_t			last_div_increment;
	uint8_t				current_speed_mode;
};

/*
This is, as far as I understand, the memory map of the gameboy:

0000 - 7FFF (32kb) : ROM AREA
	0100 - 014F : Header
	0150 - 3FFF : Bank 0
	4000 - 7FFF : Bank X
8000 - 97FF : TILE RAM
9800 - 9BFF : Background Data 1
9C00 - 9FFF : Background Data 2
A000 - BFFF : Extra RAM (if any)
C000 - DFFF : RAM
E000 - FDFF : Echo RAM
FE00 - FE9F : OAM
FEA0 - FEFF : Unused
FF00 - FF7F : I/O Registers
FF80 - FFFE : HRAM
FFFF		: Interrupt?

*/

#endif