/**
 * @file debug.h
 * @author Nicolas IRAGNE (nicolas.iragne@alyce.fr)
 * @brief Debug functions.
 * @date 2022-01-03
 * 
 * @copyright Copyright Alyce (c) 2022
 */

# include "gb.h"

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