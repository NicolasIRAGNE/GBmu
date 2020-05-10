/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gb.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 11:08:21 by niragne           #+#    #+#             */
/*   Updated: 2020/05/10 19:59:12 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GB_H
# define GB_H

# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/mman.h>
# include <stdint.h>
# include "op.h"
# include "ext_op.h"
# include <limits.h>

# include "renderer/wrapper_c/wrapper.h"

# define RED	"\x1B[31m"
# define GRN	"\x1B[32m"
# define YEL	"\x1B[33m"
# define BLU	"\x1B[34m"
# define MAG	"\x1B[35m"
# define CYN	"\x1B[36m"
# define WHT	"\x1B[37m"
# define EOC	"\x1B[0m"

# define BOOT_ROM "../DMG_ROM.bin"
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

struct gbmu_debugger_s
{
	int						verbose_level;
	struct breakpoint_s*	breakpoints;
	void					*grammar; //c++ libyacc DebuggerGrammar instance
	void					*parser; //c++ libyacc LRParser instance
};

struct command_s
{
	char*	name;
	int		(*f)(struct gb_cpu_s*, char*, uint16_t);
	char*	desc;
};

int		init_cpu(struct gb_cpu_s* gb, struct rom_s* rom);
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
uint16_t	read_16(struct gb_cpu_s* gb, uint16_t a16);
void		write_8(struct gb_cpu_s* gb, uint16_t a16, uint8_t x);
void		write_16(struct gb_cpu_s* gb, uint16_t a16, uint16_t x);

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
void	process_dma_transfer(struct gb_cpu_s* gb, uint8_t a8);
int		clamp(int val, int min, int max);
void	fatal(struct gb_cpu_s* gb);

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




#endif