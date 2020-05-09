/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jp.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 17:15:38 by niragne           #+#    #+#             */
/*   Updated: 2020/04/29 14:14:56 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gb.h"

void	jump(struct gb_cpu_s* gb, uint16_t addr)
{
	gb->reg.pc = addr;
	gb->jmp = 1;
	
}

void	jp_a16(struct gb_cpu_s* gb)
{
	jump(gb, gb->current_instruction->args);
}

void	jp_hl(struct gb_cpu_s* gb)
{
	jump(gb, gb->reg.hl);
}

void	jp_z_a16(struct gb_cpu_s* gb)
{
	if ((gb->reg.f & ZERO_FLAG))
	{
		gb->cycle += 4;
		jump(gb, gb->current_instruction->args);
	}
}

void	jp_nz_a16(struct gb_cpu_s* gb)
{
	if (!(gb->reg.f & ZERO_FLAG))
	{
		gb->cycle += 4;
		jump(gb, gb->current_instruction->args);
	}
}

void	jp_c_a16(struct gb_cpu_s* gb)
{
	if ((gb->reg.f & CARRY_FLAG))
	{
		gb->cycle += 4;
		jump(gb, gb->current_instruction->args);
	}
}

void	jp_nc_a16(struct gb_cpu_s* gb)
{
	if (!(gb->reg.f & CARRY_FLAG))
	{
		gb->cycle += 4;	
		jump(gb, gb->current_instruction->args);
	}
}

void	jr_nz_a8(struct gb_cpu_s* gb)
{
	if (!(gb->reg.f & ZERO_FLAG))
	{
		gb->cycle += 4;	
		jump(gb, gb->reg.pc + (int8_t)gb->current_instruction->args + 2);
	}
}

void	jr_z_a8(struct gb_cpu_s* gb)
{
	if ((gb->reg.f & ZERO_FLAG))
	{
		gb->cycle += 4;	
		jump(gb, gb->reg.pc + (int8_t)gb->current_instruction->args + 2);
	}
}

void	jr_c_a8(struct gb_cpu_s* gb)
{
	if ((gb->reg.f & CARRY_FLAG))
	{
		gb->cycle += 4;	
		jump(gb, gb->reg.pc + (int8_t)gb->current_instruction->args + 2);
	}
}

void	jr_nc_a8(struct gb_cpu_s* gb)
{
	if (!(gb->reg.f & CARRY_FLAG))
	{
		gb->cycle += 4;	
		jump(gb, gb->reg.pc + (int8_t)gb->current_instruction->args + 2);
	}
}

void	jr_a8(struct gb_cpu_s* gb)
{
	jump(gb, gb->reg.pc + (int8_t)gb->current_instruction->args + 2);
}

void	ret(struct gb_cpu_s* gb)
{
	jump(gb, read_16(gb, gb->reg.sp));
	gb->reg.sp += 2;
}

void	reti(struct gb_cpu_s* gb)
{
	ret(gb);
	ei(gb);
}

void	ret_nc(struct gb_cpu_s* gb)
{
	if (!(gb->reg.f & CARRY_FLAG))
	{
		gb->cycle += 12;
		ret(gb);
	}
}

void	ret_c(struct gb_cpu_s* gb)
{
	if (gb->reg.f & CARRY_FLAG)
	{
		gb->cycle += 12;
		ret(gb);
	}
}

void	ret_nz(struct gb_cpu_s* gb)
{
	if (!(gb->reg.f & ZERO_FLAG))
	{
		gb->cycle += 12;
		ret(gb);
	}
}

void	ret_z(struct gb_cpu_s* gb)
{
	if (gb->reg.f & ZERO_FLAG)
	{
		gb->cycle += 12;
		ret(gb);
	}
}