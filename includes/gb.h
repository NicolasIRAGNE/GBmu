/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gb.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 11:08:21 by niragne           #+#    #+#             */
/*   Updated: 2020/02/16 14:11:09 by niragne          ###   ########.fr       */
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

# define RED	"\x1B[31m"
# define GRN	"\x1B[32m"
# define YEL	"\x1B[33m"
# define BLU	"\x1B[34m"
# define MAG	"\x1B[35m"
# define CYN	"\x1B[36m"
# define WHT	"\x1B[37m"
# define EOC	"\x1B[0m"


# define INT_VBLANK_ADDR 0x0040



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

void	init_cpu(struct gb_cpu_s* gb);
int		handle_instruction(struct gb_cpu_s* gb);
uint8_t	update_current_instruction(struct gb_cpu_s* gb);
void	init_op_tab(void);
void	init_ext_op_tab(void);

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
void	debug_print_flag_register(uint8_t reg);

/*
** Misc
*/
void    cpu_toggle_flag(struct gb_cpu_s* gb, uint8_t flag, int cond);
void    cpu_set_flag(struct gb_cpu_s* gb, uint8_t flag);
void    cpu_unset_flag(struct gb_cpu_s* gb, uint8_t flag);

/*
** Video
*/
void*	thread_entry(void* user_data);


#endif