/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 11:40:08 by niragne           #+#    #+#             */
/*   Updated: 2020/02/17 14:12:11 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gb.h"
#include <stdio.h>

void	debug_print_gb(struct gb_cpu_s* gb)
{
	printf("-------------------\n");
	debug_print_registers(gb->reg);
	printf("\n");
	printf("CYCLE: %d\n", gb->cycle);
	debug_print_gb_flags(gb);
	printf("\n");
	debug_print_stack(gb);
	printf("\n");
	debug_print_instruction(gb->current_instruction);
	printf("-------------------\n");
	printf("\n");
}

void	debug_print_registers(struct registers_s reg)
{
	printf("REGISTERS:\n");
	printf("af = %04x | ", reg.af);
	debug_print_flag_register(reg.f);
	printf("bc = %04x\n", reg.bc);
	printf("de = %04x\n", reg.de);
	printf("hl = %04x\n", reg.hl);
	printf("sp = %04x\n", reg.sp);
	printf("pc = %04x\n", reg.pc);
}

void	debug_print_flag_register(uint8_t reg)
{
	if (reg & ZERO_FLAG)
		printf(GRN"Z"EOC);
	else
		printf(RED"Z"EOC);
	if (reg & SUBSTRACTION_FLAG)
		printf(GRN"N"EOC);
	else
		printf(RED"N"EOC);
	if (reg & HALF_CARRY_FLAG)
		printf(GRN"H"EOC);
	else
		printf(RED"H"EOC);
	if (reg & CARRY_FLAG)
		printf(GRN"C"EOC);
	else
		printf(RED"C"EOC);
	printf("\n");
}

void	debug_print_gb_flags(struct gb_cpu_s* gb)
{
	printf("FLAGS:\n");
	printf("IME : %d\n", gb->ime);
	printf("IER : %.4x\n", gb->interrupt_enable_register);
	printf("LCDC: %.2x\n", read_8(gb, LCDC_OFFSET));
}

void	debug_print_instruction(struct inst_s* inst)
{
	printf("INSTRUCTION:\n");
	if (inst && inst->name)
	{
		if (inst->size > 0)
		{
			printf("%s %x\n", inst->name, inst->args);			
		}
		else
		{
			printf("%s\n", inst->name);
		}	
	}
	else
		printf("%s\n", "UNDEFINED");	
}

void	debug_print_rom_hdr(struct rom_hdr_s* hdr)
{
	printf("NAME: %.11s\n", hdr->title);
	printf("MANUFACTURER CODE: %x %x\n", hdr->manufacturer_code[0], hdr->manufacturer_code[1]);
	printf("SGB FLAG: %x\n", hdr->sgb_flag);
	printf("CARTRIDGE TYPE: %x\n", hdr->type);
	printf("ROM SIZE: %x\n", hdr->rom_size);
	printf("RAM SIZE: %x\n", hdr->ram_size);
	printf("LANG: %x\n", hdr->lang);
	printf("MANUFACTURER CODE (EXTEND): %x\n", hdr->manufacturer_code_extend);
	printf("VERSION NUMBER: %x\n", hdr->version);
	printf("COMPLEMENT CHECK: %x\n", hdr->complement_check);
}

void	debug_print_rom(struct rom_s* rom)
{
	printf("-------------------\n");
	debug_print_rom_hdr(rom->header);
	printf("-------------------\n");
	printf("\n");
}

void	debug_print_stack(struct gb_cpu_s* gb)
{
	printf("STACK:\n");
	printf("%04x\n", read_16(gb, gb->reg.sp));
	printf("%04x\n", read_16(gb, gb->reg.sp + 2));
}
