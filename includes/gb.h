/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gb.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 11:08:21 by niragne           #+#    #+#             */
/*   Updated: 2020/06/11 13:31:02 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GB_H
# define GB_H
#ifdef __cplusplus
extern "C" {
#endif

# include <sys/stat.h>
# include <sys/types.h>
// # include <unistd.h>
#include <stdlib.h>
# include <fcntl.h>
// # include <sys/mman.h>
# include <stdint.h>
# include "op.h"
# include "ext_op.h"
# include <limits.h>
# include <mbc.h>
# include <stdio.h>
# include "renderer/wrapper_c/wrapper.h"

# define RED	"\x1B[31m"
# define GRN	"\x1B[32m"
# define YEL	"\x1B[33m"
# define BLU	"\x1B[34m"
# define MAG	"\x1B[35m"
# define CYN	"\x1B[36m"
# define WHT	"\x1B[37m"
# define EOC	"\x1B[0m"

# define DMG_BOOT_ROM "../DMG_ROM.bin"
# define SAVE_DIR "../saves/"
# define SAVESTATE_DIR "../savestates/"

# define DEFAULT_VERBOSE 0

struct rom_hdr_s
{
	uint8_t	entry[4];
	uint8_t	logo[48];
	uint8_t	title[16];
	uint8_t	manufacturer_code[2];
	uint8_t	sgb_flag;
	uint8_t type;
	uint8_t	rom_size;
	uint8_t ram_size;
	uint8_t lang;
	uint8_t manufacturer_code_extend;
	uint8_t version;
	uint8_t complement_check;
	uint8_t checksum[2];
};

struct rom_s
{
	struct stat			st;
	struct rom_hdr_s*	header;
	void*				ptr;
};

struct gbmu_wrapper_s
{
	struct gb_cpu_s* gb;
	struct sdl_context_s* vram_viewer_context;
	struct sdl_context_s* main_context;
};

struct breakpoint_s
{
	uint16_t	addr;
	struct breakpoint_s* next;
};

//	int						verbose_level;
//	struct breakpoint_s*	breakpoints;


#ifdef WITH_LIBYACC
struct gbmu_debugger_s
{
	void					*grammar;	//c++ libyacc DebuggerGrammar instance
	void					*parser;	//c++ libyacc LRParser instance
	void					*instance;	//c++ DebuggerContext instance
};
#else
struct gbmu_debugger_s
{
	int						verbose_level;
	struct breakpoint_s*	breakpoints;
	void*					instance;
};
void	fallback_execute(struct gb_cpu_s* gb, char* str);
#endif


struct command_s
{
	char*	name;
	int		(*f)(struct gb_cpu_s*, char*, uint16_t);
	char*	desc;
};

int		init_cpu(struct gb_cpu_s* gb, struct rom_s* rom, enum gb_mode_e mode);
int		init_mbc(struct gb_cpu_s* gb);
int		handle_instruction(struct gb_cpu_s* gb);
uint8_t	update_current_instruction(struct gb_cpu_s* gb);
void	init_op_tab(void);
void	init_ext_op_tab(void);
void	gpu_tick(struct gb_cpu_s* gb);
void	execute_loop(struct gbmu_wrapper_s* wrapper, void* renderer);
void	request_interrupt(struct gb_cpu_s* gb, uint8_t request);
void	update_timer_register(struct gb_cpu_s* gb);
void	update_div_register(struct gb_cpu_s* gb);

/*
** Memory
*/
uint8_t		read_8(struct gb_cpu_s* gb, uint16_t a16);
uint8_t		read_8_debug(struct gb_cpu_s* gb, uint16_t a16);
uint8_t		read_8_force(struct gb_cpu_s* gb, uint16_t a16);

uint16_t	read_16(struct gb_cpu_s* gb, uint16_t a16);
uint16_t	read_16_debug(struct gb_cpu_s* gb, uint16_t a16);
uint16_t	read_16_force(struct gb_cpu_s* gb, uint16_t a16);

void		write_8(struct gb_cpu_s* gb, uint16_t a16, uint8_t x);
void		write_8_debug(struct gb_cpu_s* gb, uint16_t a16, uint8_t x);
void		write_8_force(struct gb_cpu_s* gb, uint16_t a16, uint8_t x);

void		write_16(struct gb_cpu_s* gb, uint16_t a16, uint16_t x);
void		write_16_debug(struct gb_cpu_s* gb, uint16_t a16, uint16_t x);
void		write_16_force(struct gb_cpu_s* gb, uint16_t a16, uint16_t x);

uint8_t		read_io(struct gb_cpu_s* gb, uint16_t addr);
void		write_io(struct gb_cpu_s* gb, uint16_t addr, uint8_t x, uint8_t lcdc, enum memory_mode_e mode);


/*
** Debugger
*/
void		execute_debugger(struct gb_cpu_s* gb);

/*
** Debug
*/
void	debug_print_registers(struct registers_s reg);
void	debug_print_gb(struct gb_cpu_s* gb);
void	debug_print_instruction(struct inst_s* inst);
void	debug_print_rom(struct rom_s* rom);
void	debug_print_rom_hdr(struct rom_hdr_s* hdr);
void	debug_print_gb_flags(struct gb_cpu_s* gb);
void	debug_print_stack(struct gb_cpu_s* gb);
void	debug_print_mbc(struct gb_cpu_s* gb);
void	debug_print_flag_register(uint8_t reg);

/*
** Misc
*/
void    cpu_toggle_flag(struct gb_cpu_s* gb, uint8_t flag, int cond);
void    cpu_set_flag(struct gb_cpu_s* gb, uint8_t flag);
void    cpu_unset_flag(struct gb_cpu_s* gb, uint8_t flag);
void	memset_4(uint32_t* ptr, uint32_t c, size_t n);
/**
 * @brief Transfer data from memory to OAM with a fixed length.
 * This function is available on both CGB and DMG.
 * @param gb 
 * @param a8 The address to start the transfer.
 */
void	process_dma_transfer(struct gb_cpu_s* gb, uint8_t a8);
/**
 * @brief Transfer data from memory to VRAM with an arbitrary length.
 * This function is only available on CGB.
 * 
 * @param gb 
 * @param a8 The first bit of a8 indicates the transfer mode (0: General, 1: H-Blank). The lower 7 bits of a8 are the length of the transfer.
 */
void	process_hdma_transfer(struct gb_cpu_s* gb, uint8_t a8);
int		clamp(int val, int min, int max);
void	fatal(struct gb_cpu_s* gb);
int		get_debugger_verbose(struct gb_cpu_s* gb);
int		open_rom(char* name, struct rom_s* rom);

/*
** Video
*/
void*	thread_entry(void* user_data);

/*
** Saving & Loading
*/
int		save_game(struct gb_cpu_s* gb);
int		load_game(struct gb_cpu_s* gb);
int		save_game_crash(struct gb_cpu_s* gb);
int		savestate(struct gb_cpu_s* gb, int number);
int		loadstate(struct gb_cpu_s* gb, int number);


#ifdef __cplusplus
}
#endif
#endif