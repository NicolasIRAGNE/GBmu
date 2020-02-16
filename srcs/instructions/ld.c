/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 17:14:49 by niragne           #+#    #+#             */
/*   Updated: 2020/02/16 12:54:42 by niragne          ###   ########.fr       */
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

int		ld_d_c(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.d), gb->reg.c);
}

int		ld_a_c(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.a), gb->reg.c);
}

int		ld_c_a(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.c), gb->reg.a);
}

int		ld_d_a(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.d), gb->reg.a);
}

int		ld_a_d(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.a), gb->reg.d);
}

int		ld_a_l(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.a), gb->reg.l);
}

int		ld_a_h(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.a), gb->reg.h);
}

int		ld_b_a(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.b), gb->reg.a);
}

int		ld_e_a(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.e), gb->reg.a);
}

int		ld_a_b(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.a), gb->reg.b);
}

int		ld_a_e(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.a), gb->reg.e);
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

int		ld_a_ptr_a16(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.a), read_8(gb, gb->current_instruction->args));
}

int		ld_a_ptr_de(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.a), read_8(gb, gb->reg.de));
}

int		ld_a_ptr_hl(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.a), read_8(gb, gb->reg.hl));
}

int		ld_b_ptr_hl(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.b), read_8(gb, gb->reg.hl));
}

int		ld_l_ptr_hl(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.l), read_8(gb, gb->reg.hl));
}

int		ld_c_ptr_hl(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.c), read_8(gb, gb->reg.hl));
}

int		ld_d_ptr_hl(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.d), read_8(gb, gb->reg.hl));
}

int		ld_h_ptr_hl(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.h), read_8(gb, gb->reg.hl));
}

int		ld_d_a8(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.d), (uint8_t)gb->current_instruction->args);
}

int		ld_e_a8(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.e), (uint8_t)gb->current_instruction->args);
}

int		ld_h_a8(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.h), (uint8_t)gb->current_instruction->args);
}

int		ld_l_a8(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.l), (uint8_t)gb->current_instruction->args);
}

int		ld_hl_a16(struct gb_cpu_s* gb)
{
	ld_reg_16(&(gb->reg.hl), gb->current_instruction->args);
}

int		ld_bc_a16(struct gb_cpu_s* gb)
{
	ld_reg_16(&(gb->reg.bc), gb->current_instruction->args);
}

int		ld_sp_a16(struct gb_cpu_s* gb)
{
	ld_reg_16(&(gb->reg.sp), gb->current_instruction->args);
}

int		ld_ptr_bc_a(struct gb_cpu_s* gb)
{
	ld_mem_8(gb, gb->reg.bc, gb->reg.a);
}

int		ldh_a8_a(struct gb_cpu_s* gb)
{
	ld_mem_8(gb, 0xFF00 + gb->current_instruction->args, gb->reg.a);
}

int		ld_ptr_de_a(struct gb_cpu_s* gb)
{
	ld_mem_8(gb, gb->reg.de, gb->reg.a);
}

int		ld_ptr_hl_b(struct gb_cpu_s* gb)
{
	ld_mem_8(gb, gb->reg.hl, gb->reg.b);
}

int		ld_ptr_hl_c(struct gb_cpu_s* gb)
{
	ld_mem_8(gb, gb->reg.hl, gb->reg.c);
}

int		ld_ptr_hl_d(struct gb_cpu_s* gb)
{
	ld_mem_8(gb, gb->reg.hl, gb->reg.d);
}

int		ld_ptr_hl_e(struct gb_cpu_s* gb)
{
	ld_mem_8(gb, gb->reg.hl, gb->reg.e);
}

int		ld_ptr_hl_h(struct gb_cpu_s* gb)
{
	ld_mem_8(gb, gb->reg.hl, gb->reg.h);
}

int		ld_ptr_hl_l(struct gb_cpu_s* gb)
{
	ld_mem_8(gb, gb->reg.hl, gb->reg.l);
}

int		ld_nn_a(struct gb_cpu_s* gb)
{
	ld_mem_8(gb, gb->current_instruction->args, gb->reg.a);
}

int		ld_de_a16(struct gb_cpu_s* gb)
{
	ld_reg_16(&(gb->reg.de), gb->current_instruction->args);
}

int		ldh_a_ptr_n(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.a), read_8(gb, 0xFF00 + gb->current_instruction->args));
}

int		ldd_hl_a(struct gb_cpu_s* gb)
{
	ld_mem_8(gb, gb->reg.hl, gb->reg.a);
	gb->reg.hl -= 1;
}

int		ld_ptr_hl_a(struct gb_cpu_s* gb)
{
	ld_mem_8(gb, gb->reg.hl, gb->reg.a);
}

int		ldi_hl_a(struct gb_cpu_s* gb)
{
	ld_mem_8(gb, gb->reg.hl, gb->reg.a);
	gb->reg.hl += 1;
}

int		ldi_a_ptr_hl(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.a), read_8(gb, gb->reg.hl));
	gb->reg.hl += 1;
}