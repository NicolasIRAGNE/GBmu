/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 19:30:21 by niragne           #+#    #+#             */
/*   Updated: 2020/04/29 14:15:30 by niragne          ###   ########.fr       */
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

void	interrupt_a16(struct gb_cpu_s* gb, uint16_t addr)
{
	// gb->paused = 1;
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

void	call_a16(struct gb_cpu_s* gb)
{
	call(gb, gb->current_instruction->args);
}

void	call_z_a16(struct gb_cpu_s* gb)
{
	if ((gb->reg.f & ZERO_FLAG))
	{
		gb->cycle += 12;
		call(gb, gb->current_instruction->args);
	}
}

void	call_nz_a16(struct gb_cpu_s* gb)
{
	if (!(gb->reg.f & ZERO_FLAG))
	{
		gb->cycle += 12;
		call(gb, gb->current_instruction->args);
	}
}

void	call_c_a16(struct gb_cpu_s* gb)
{
	if ((gb->reg.f & CARRY_FLAG))
	{
		gb->cycle += 12;
		call(gb, gb->current_instruction->args);
	}
}

void	call_nc_a16(struct gb_cpu_s* gb)
{
	if (!(gb->reg.f & CARRY_FLAG))
	{
		gb->cycle += 12;
		call(gb, gb->current_instruction->args);
	}
}

void	rst_38(struct gb_cpu_s* gb)
{
	call(gb, 0x38);
}

void	rst_28(struct gb_cpu_s* gb)
{
	call(gb, 0x28);
}

void	rst_18(struct gb_cpu_s* gb)
{
	call(gb, 0x18);
}

void	rst_8(struct gb_cpu_s* gb)
{
	call(gb, 0x8);
}

void	rst_0(struct gb_cpu_s* gb)
{
	call(gb, 0x0);
}

void	rst_30(struct gb_cpu_s* gb)
{
	call(gb, 0x30);
}

void	rst_20(struct gb_cpu_s* gb)
{
	call(gb, 0x20);
}

void	rst_10(struct gb_cpu_s* gb)
{
	call(gb, 0x10);
}
