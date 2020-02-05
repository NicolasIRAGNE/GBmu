/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 17:14:49 by niragne           #+#    #+#             */
/*   Updated: 2020/02/05 12:02:22 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gb.h"

/*
** LD = 0x40 => 0x7F (excluding 0x76)
*/

void	ld_reg_8(uint8_t* dst, uint8_t src)
{
	*dst = src;
}

void	ld_reg_16(uint16_t* dst, uint16_t src)
{
	*dst = src;
}

void	ld_mem_8(struct gb_cpu_s* gb, uint16_t a16, uint8_t x)
{
	write_8(gb, a16, x);
}

void	ld_mem_16(struct gb_cpu_s* gb, uint16_t a16, uint16_t x)
{
	write_16(gb, a16, x);
}

int		ld_dc(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.d), gb->reg.c);
}

int		ld_c_a8(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.c), (uint8_t)gb->current_instruction->args);
}

int		ld_b_a8(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.b), (uint8_t)gb->current_instruction->args);
}

int		ld_a_a8(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.a), (uint8_t)gb->current_instruction->args);
}

int		ld_hl_a16(struct gb_cpu_s* gb)
{
	ld_reg_16(&(gb->reg.hl), gb->current_instruction->args);
}

int		ld_sp_a16(struct gb_cpu_s* gb)
{
	ld_reg_16(&(gb->reg.sp), gb->current_instruction->args);
}

int		ld_c_hl(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.c), read_8(gb, gb->reg.hl));
}

int		ldh_a8_a(struct gb_cpu_s* gb)
{
	ld_mem_8(gb, gb->current_instruction->args | 0xff00, gb->reg.a);
}

int		ldh_a_a8(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.a), read_8(gb, gb->current_instruction->args | 0xff00));
}

int		ldd_hl_a(struct gb_cpu_s* gb)
{
	ld_mem_8(gb, gb->reg.hl, gb->reg.a);
	gb->reg.hl -= 1;
}