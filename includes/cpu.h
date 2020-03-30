/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpu.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 16:34:47 by niragne           #+#    #+#             */
/*   Updated: 2020/03/30 14:29:53 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPU_H
# define CPU_H
# include <stdint.h>

# define VRAM_SIZE 0x2000		// 8kiB
# define WRAM_SIZE 0x2000		// 8kiB
# define HRAM_SIZE 0x100		// 256B
# define RAM_SIZE 0x2000		// 8kiB
# define EXTRA_RAM_SIZE 0x2000	// 8kiB
# define IO_PORTS_SIZE 0x100	// 256B
# define OAM_SIZE 0x9f			// 160B
# define BOOT_ROM_SIZE 0x100	// 256B

# define VRAM_TILE_BANK_SIZE 0x1800

# define IO_OFFSET	 0xFF00

// TIMER
# define DIV_OFFSET		(IO_OFFSET | 0x04)
# define TIMA_OFFSET	(IO_OFFSET | 0x05)
# define TMA_OFFSET		(IO_OFFSET | 0x06)
# define TAC_OFFSET		(IO_OFFSET | 0x07)

# define LCDC_OFFSET 	(IO_OFFSET | 0x40)
# define STAT_OFFSET 	(IO_OFFSET | 0x41)
# define SCY_OFFSET		(IO_OFFSET | 0x42)
# define SCX_OFFSET		(IO_OFFSET | 0x43)
# define LY_OFFSET		(IO_OFFSET | 0x44)
# define LYC_OFFSET		(IO_OFFSET | 0x45)
# define WY_OFFSET		(IO_OFFSET | 0x4a)
# define WX_OFFSET		(IO_OFFSET | 0x4b)

# define IF_OFFSET		(IO_OFFSET | 0x0F)

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
# define INT_JOYPAD_REQUEST	(1 << 4)

# define INT_VBLANK_ADDR		0x40
# define INT_TIMER_ADDR			0x50

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

enum	gpu_mode_e
{
	GPU_MODE_HBLANK = 0,
	GPU_MODE_VBLANK,
	GPU_MODE_OAM,
	GPU_MODE_VRAM,
};

struct	gb_gpu_s
{
	int tick;
	int y_coord;
	enum gpu_mode_e mode;	
};

enum	mbc_mode_e
{
	MBC_MODE_ROM,
	MBC_MODE_RAM
};

struct	mbc_s
{
	uint8_t bank;
	enum mbc_mode_e mode;
};

struct	gb_cpu_s
{
	int					jmp : 1; // Flag used by the emulator. Ugly but hopefully temporary ?

	int					vram_viewer_running : 1;
	int					running : 1;
	int					paused : 1;
	uint16_t			interrupt;
	uint32_t			cycle;
	struct gbmu_debugger_s*	debugger;

	int					ime : 1; // Interrupt Master Enable Flag
	int					ram_enabled : 1;
	int					halted : 1;
	int					booted : 1;
	struct registers_s	reg;
	struct inst_s*		current_instruction;
	struct rom_s*		rom_ptr;
	struct gb_gpu_s		gpu;
	struct mbc_s		mbc;
	uint8_t				boot_rom[BOOT_ROM_SIZE];
	uint8_t				vram[VRAM_SIZE];
	uint8_t				ram[RAM_SIZE];
	uint8_t				extra_ram[EXTRA_RAM_SIZE];
	uint8_t				wram[WRAM_SIZE];
	uint8_t				hram[HRAM_SIZE];
	uint8_t				io_ports[IO_PORTS_SIZE];
	uint8_t				oam[OAM_SIZE];
	uint8_t				interrupt_enable_register;
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