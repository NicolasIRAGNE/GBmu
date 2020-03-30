/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 19:30:21 by niragne           #+#    #+#             */
/*   Updated: 2020/03/30 14:53:57 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gb.h"

void	call(struct gb_cpu_s* gb, uint16_t a16)
{
	gb->reg.sp -= 2;
	write_16(gb, gb->reg.sp, gb->reg.pc + 1 + gb->current_instruction->size);
	gb->reg.pc = a16;
	gb->jmp = 1;
}

int		interrupt_a16(struct gb_cpu_s* gb, uint16_t addr)
{
	if (gb->ime)
	{
		di(gb);
		gb->reg.sp -= 2;
		write_16(gb, gb->reg.sp, gb->reg.pc);
		gb->reg.pc = addr;
		update_current_instruction(gb);
	}
	gb->halted = 0;
}

int		call_a16(struct gb_cpu_s* gb)
{
	call(gb, gb->current_instruction->args);
}

int		call_z_a16(struct gb_cpu_s* gb)
{
	if ((gb->reg.f & ZERO_FLAG))
		call(gb, gb->current_instruction->args);
}

int		call_nz_a16(struct gb_cpu_s* gb)
{
	if (!(gb->reg.f & ZERO_FLAG))
		call(gb, gb->current_instruction->args);
}

int		call_c_a16(struct gb_cpu_s* gb)
{
	if ((gb->reg.f & CARRY_FLAG))
		call(gb, gb->current_instruction->args);
}

int		call_nc_a16(struct gb_cpu_s* gb)
{
	if (!(gb->reg.f & CARRY_FLAG))
		call(gb, gb->current_instruction->args);
}

int		rst_38(struct gb_cpu_s* gb)
{
	call(gb, 0x38);
}

int		rst_28(struct gb_cpu_s* gb)
{
	call(gb, 0x28);
}

int		rst_18(struct gb_cpu_s* gb)
{
	call(gb, 0x18);
}

int		rst_8(struct gb_cpu_s* gb)
{
	call(gb, 0x8);
}

int		rst_0(struct gb_cpu_s* gb)
{
	call(gb, 0x0);
}

int		rst_30(struct gb_cpu_s* gb)
{
	call(gb, 0x30);
}

int		rst_20(struct gb_cpu_s* gb)
{
	call(gb, 0x20);
}

int		rst_10(struct gb_cpu_s* gb)
{
	call(gb, 0x10);
}
