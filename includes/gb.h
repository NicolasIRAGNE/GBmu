#ifndef GB_H
# define GB_H

# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/mman.h>
# include <stdint.h>
# include "op.h"

extern struct inst_s op_tab[256];

struct rom_hdr_s
{
	char	entry[4];
	char	logo[48];
	char	title[11];
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

/*
** Debug
*/
void	debug_print_registers(struct registers_s reg);
void	debug_print_gb(struct gb_cpu_s* gb);
void	debug_print_instruction(struct inst_s* inst);

#endif