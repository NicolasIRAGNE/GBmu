/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 11:40:08 by niragne           #+#    #+#             */
/*   Updated: 2020/02/04 19:08:31 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gb.h"
#include <stdio.h>

void	debug_print_gb(struct gb_cpu_s* gb)
{
	printf("-------------------\n");
	debug_print_registers(gb->reg);
	printf("\n");
	debug_print_gb_flags(gb);
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

void	debug_print_gb_flags(struct gb_cpu_s* gb)
{
	printf("FLAGS:\n");
	printf("IME: %d\n", gb->ime);
	printf("IER: %.4x\n", gb->interrupt_enable_register);
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