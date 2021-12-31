/**
 * @file fallback_debugger.h
 * @author Nicolas IRAGNE (nicolas.iragne@alyce.fr)
 * @brief 
 * @date 2021-12-05
 * 
 * @copyright Copyright Alyce (c) 2021
 */

#pragma once
#ifdef WITH_LIBYACC
# error "libyacc is not supported with fallback_debugger!"
#endif
#include "gb.h"

int     find_breakpoint(void *debugger, int pc);
int		command_next(struct gb_cpu_s* gb, char* s, uint16_t arg);
int		command_add_breakpoint(struct gb_cpu_s* gb, char* s, uint16_t arg);
int		command_info(struct gb_cpu_s* gb, char* s, uint16_t arg);
int		command_not_found(struct gb_cpu_s* gb, char* s, uint16_t arg);
int		command_set_verbose(struct gb_cpu_s* gb, char* s, uint16_t arg);
int		command_quit(struct gb_cpu_s* gb, char* s, uint16_t arg);
int		command_print(struct gb_cpu_s* gb, char* s, uint16_t arg);
int		command_run(struct gb_cpu_s* gb, char* s, uint16_t arg);
int		command_del(struct gb_cpu_s* gb, char* s, uint16_t arg);
int		command_help(struct gb_cpu_s* gb, char* s, uint16_t arg);
int		get_verbose(struct gbmu_debugger_s* debugger);

