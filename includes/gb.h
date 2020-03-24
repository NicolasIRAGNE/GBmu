/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gb.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 11:08:21 by niragne           #+#    #+#             */
/*   Updated: 2020/03/24 12:32:18 by niragne          ###   ########.fr       */
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

# define RED	"\x1B[31m"
# define GRN	"\x1B[32m"
# define YEL	"\x1B[33m"
# define BLU	"\x1B[34m"
# define MAG	"\x1B[35m"
# define CYN	"\x1B[36m"
# define WHT	"\x1B[37m"
# define EOC	"\x1B[0m"

# define BOOT_ROM "../DMG_ROM.bin"

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
	struct breakpoint_s* breakpoints;
};

struct command_s
{
	char*	name;
	int		(*f)(struct gb_cpu_s*, char*, uint16_t);
	char*	desc;
};

int		init_cpu(struct gb_cpu_s* gb);
int		handle_instruction(struct gb_cpu_s* gb);
uint8_t	update_current_instruction(struct gb_cpu_s* gb);
void	init_op_tab(void);
void	init_ext_op_tab(void);
void	gpu_tick(struct gb_cpu_s* gb);
void*	execute_thread_entry(void* user_data);

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
void		parse_command(struct gb_cpu_s* gb);
struct breakpoint_s*	new_breakpoint(uint16_t addr);
int		add_breakpoint(struct breakpoint_s** lst, uint16_t addr);
int		print_breakpoints(struct breakpoint_s* lst);
int		find_breakpoint(struct breakpoint_s* lst, uint16_t addr);
int		clear_breakpoints(struct breakpoint_s** lst);

int		command_next(struct gb_cpu_s* gb, char* s, uint16_t arg);
int		command_add_breakpoint(struct gb_cpu_s* gb, char* s, uint16_t arg);
int		command_info(struct gb_cpu_s* gb, char* s, uint16_t arg);
int		command_not_found(struct gb_cpu_s* gb, char* s, uint16_t arg);
int		command_quit(struct gb_cpu_s* gb, char* s, uint16_t arg);
int		command_print(struct gb_cpu_s* gb, char* s, uint16_t arg);
int		command_run(struct gb_cpu_s* gb, char* s, uint16_t arg);
int		command_del(struct gb_cpu_s* gb, char* s, uint16_t arg);
int		command_help(struct gb_cpu_s* gb, char* s, uint16_t arg);

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

/*
** Video
*/
void*	thread_entry(void* user_data);



#endif