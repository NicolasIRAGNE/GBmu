/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 11:40:08 by niragne           #+#    #+#             */
/*   Updated: 2020/01/31 12:06:35 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gb.h"
#include <stdio.h>

void	debug_print_gb(struct gb_cpu_s* gb)
{
	printf("-------------------\n");
	debug_print_registers(gb->reg);
	printf("\n");
	debug_print_instruction(gb->current_instruction);
	printf("-------------------\n");
	printf("\n");
}

void	debug_print_registers(struct registers_s reg)
{
	printf("REGISTERS:\n");
	printf("af = %04x\n", reg.af);
	printf("bc = %04x\n", reg.bc);
	printf("de = %04x\n", reg.de);
	printf("hl = %04x\n", reg.hl);
	printf("sp = %04x\n", reg.sp);
	printf("pc = %04x\n", reg.pc);
}

void	debug_print_instruction(struct inst_s* inst)
{
	printf("INSTRUCTION:\n");
	if (inst->name)
		printf("%s\n", inst->name);
	else
		printf("%s\n", "UNDEFINED");	
}