/**
 * @file cpu.h
 * @author Nicolas IRAGNE (nicolas.iragne@alyce.fr)
 * @brief Contains most of the internal functions and macros used by the CPU.
 * @date 2021-12-31
 *
 * @copyright Copyright Alyce (c) 2021
 */

#ifndef CPU_H
# define CPU_H
# include <stdint.h>
# include "mbc.h"
# include "memory.h"
# include "registers.h"
# include "ppu.h"
# include "mode.h"

enum	tile_type_e
{
	TILE_TYPE_BACKGROUND,
	TILE_TYPE_SPRITE,
	TILE_TYPE_WINDOW,
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

/**
 * @brief A simple struct holding 8 bits of data representing each button
 */
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
struct	rtcs_s
{
	uint8_t		rtc[5];
	uint8_t		last_write;
	uint64_t	last_latch;
	uint64_t	last_cycle;
	uint64_t	clocks;

	uint8_t		sec;
	uint8_t		min;
	uint8_t		hour;
	uint8_t		dayl;
	uint8_t		dayh;
};

struct tima_s
{
	uint64_t	freq;
	uint64_t	clocks;
	uint64_t	last_cycle;
};

struct	gb_cpu_s
{
	int					jmp : 1;
	int					vram_viewer_running : 1;
	int					running : 1;
	int					paused : 1;
	int					draw_background : 1;
	int					draw_window : 1;
	int					draw_sprites : 1;
	int					hdma_in_progress : 1;
	uint16_t			remaining_hdma_length;
	uint16_t			hdma_index;
	int					has_rtc : 1;
	uint16_t			interrupt;
	uint64_t			cycle;
	uint64_t			last_sleep;
	uint64_t			last_dma;
	uint64_t			last_hdma;
	struct gbmu_debugger_s*	debugger;
	enum gb_mode_e		mode;

	int					ime : 1; // Interrupt Master Enable Flag
	int					ram_enabled : 1;
	int					halted : 1;
	int					booted : 1;
	int					debug_palette : 1;
    int                 loaded : 1;
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
	uint8_t				cgb_bg_palettes[CRAM_SIZE];
	uint8_t				cgb_obj_palettes[CRAM_SIZE];
	uint8_t				bg_palette_index;
	uint8_t				obj_palette_index;
	uint8_t				bcpd_auto_increment : 1;
	uint8_t				ocpd_auto_increment : 1;
	uint8_t				interrupt_enable_register;
	enum joypad_mode_e	joypad_mode;
	uint32_t			bg_palettes[8][4];
	uint32_t			obj_palettes[8][4];
	uint64_t			last_div_increment;
	uint8_t				current_speed_mode;

	uint8_t				last_x;
	uint8_t				last_y;
	struct rtcs_s		rtc;
};

extern struct gb_cpu_s	gb_global;


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
