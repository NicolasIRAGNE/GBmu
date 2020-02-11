/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jp.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 17:15:38 by niragne           #+#    #+#             */
/*   Updated: 2020/02/11 14:50:06 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gb.h"

int		jump(struct gb_cpu_s* gb, uint16_t addr)
{
	gb->reg.pc = addr;
	gb->jmp = 1;
	
}

int		jp_a16(struct gb_cpu_s* gb)
{
	jump(gb, gb->current_instruction->args);
}

int		jp_z_a16(struct gb_cpu_s* gb)
{
	if ((gb->reg.f & ZERO_FLAG))
		jump(gb, gb->current_instruction->args);
}

int		jr_nz_a8(struct gb_cpu_s* gb)
{
	// printf("%d jump\n", (int8_t)gb->current_instruction->args);
	if (!(gb->reg.f & ZERO_FLAG))
		jump(gb, gb->reg.pc + (int8_t)gb->current_instruction->args + 2);
}

int		jr_z_a8(struct gb_cpu_s* gb)
{
	// printf("%d jump\n", (int8_t)gb->current_instruction->args);
	if ((gb->reg.f & ZERO_FLAG))
		jump(gb, gb->reg.pc + (int8_t)gb->current_instruction->args + 2);
}

int		jr_c_a8(struct gb_cpu_s* gb)
{
	if ((gb->reg.f & CARRY_FLAG))
		jump(gb, gb->reg.pc + (int8_t)gb->current_instruction->args + 2);
}


int		ret(struct gb_cpu_s* gb)
{
	jump(gb, read_16(gb, gb->reg.sp));
	gb->reg.sp += 2;
}