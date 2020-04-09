/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 17:14:49 by niragne           #+#    #+#             */
/*   Updated: 2020/04/09 16:59:49 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gb.h"

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

void	ld_a_a(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.a), gb->reg.a);
}

void	ld_a_b(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.a), gb->reg.b);
}

void	ld_a_c(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.a), gb->reg.c);
}

void	ld_a_d(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.a), gb->reg.d);
}

void	ld_a_e(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.a), gb->reg.e);
}

void	ld_a_h(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.a), gb->reg.h);
}

void	ld_a_l(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.a), gb->reg.l);
}

void	ld_b_a(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.b), gb->reg.a);
}

void	ld_b_b(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.b), gb->reg.b);
}

void	ld_b_c(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.b), gb->reg.c);
}

void	ld_b_d(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.b), gb->reg.d);
}

void	ld_b_e(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.b), gb->reg.e);
}

void	ld_b_h(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.b), gb->reg.h);
}

void	ld_b_l(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.b), gb->reg.l);
}

void	ld_c_a(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.c), gb->reg.a);
}

void	ld_c_b(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.c), gb->reg.b);
}

void	ld_c_c(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.c), gb->reg.c);
}

void	ld_c_d(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.c), gb->reg.d);
}

void	ld_c_e(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.c), gb->reg.e);
}

void	ld_c_h(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.c), gb->reg.h);
}

void	ld_c_l(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.c), gb->reg.l);
}

void	ld_d_a(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.d), gb->reg.a);
}

void	ld_d_b(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.d), gb->reg.b);
}

void	ld_d_c(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.d), gb->reg.c);
}

void	ld_d_d(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.d), gb->reg.d);
}

void	ld_d_e(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.d), gb->reg.e);
}

void	ld_d_h(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.d), gb->reg.h);
}

void	ld_d_l(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.d), gb->reg.l);
}

void	ld_e_a(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.e), gb->reg.a);
}

void	ld_e_b(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.e), gb->reg.b);
}

void	ld_e_c(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.e), gb->reg.c);
}

void	ld_e_d(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.e), gb->reg.d);
}

void	ld_e_e(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.e), gb->reg.e);
}

void	ld_e_h(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.e), gb->reg.h);
}

void	ld_e_l(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.e), gb->reg.l);
}

void	ld_h_a(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.h), gb->reg.a);
}

void	ld_h_b(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.h), gb->reg.b);
}

void	ld_h_c(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.h), gb->reg.c);
}

void	ld_h_d(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.h), gb->reg.d);
}

void	ld_h_e(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.h), gb->reg.e);
}

void	ld_h_h(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.h), gb->reg.h);
}

void	ld_h_l(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.h), gb->reg.l);
}

void	ld_l_a(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.l), gb->reg.a);
}

void	ld_l_b(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.l), gb->reg.b);
}

void	ld_l_c(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.l), gb->reg.c);
}

void	ld_l_d(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.l), gb->reg.d);
}

void	ld_l_e(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.l), gb->reg.e);
}

void	ld_l_h(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.l), gb->reg.h);
}

void	ld_l_l(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.l), gb->reg.l);
}

void	ld_c_a8(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.c), (uint8_t)gb->current_instruction->args);
}

void	ld_b_a8(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.b), (uint8_t)gb->current_instruction->args);
}

void	ld_a_a8(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.a), (uint8_t)gb->current_instruction->args);
}

void	ld_a_ptr_a16(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.a), read_8(gb, gb->current_instruction->args));
}

void	ld_a_ptr_bc(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.a), read_8(gb, gb->reg.bc));
}

void	ld_a_ptr_de(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.a), read_8(gb, gb->reg.de));
}

void	ld_a_ptr_hl(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.a), read_8(gb, gb->reg.hl));
}

void	ld_b_ptr_hl(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.b), read_8(gb, gb->reg.hl));
}

void	ld_l_ptr_hl(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.l), read_8(gb, gb->reg.hl));
}

void	ld_c_ptr_hl(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.c), read_8(gb, gb->reg.hl));
}

void	ld_d_ptr_hl(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.d), read_8(gb, gb->reg.hl));
}

void	ld_e_ptr_hl(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.e), read_8(gb, gb->reg.hl));
}

void	ld_h_ptr_hl(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.h), read_8(gb, gb->reg.hl));
}

void	ldh_a_ptr_c(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.a), read_8(gb, gb->reg.c + 0xFF00));
}

void	ld_d_a8(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.d), (uint8_t)gb->current_instruction->args);
}

void	ld_e_a8(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.e), (uint8_t)gb->current_instruction->args);
}

void	ld_h_a8(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.h), (uint8_t)gb->current_instruction->args);
}

void	ld_l_a8(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.l), (uint8_t)gb->current_instruction->args);
}

void	ld_hl_a16(struct gb_cpu_s* gb)
{
	ld_reg_16(&(gb->reg.hl), gb->current_instruction->args);
}

void	ld_bc_a16(struct gb_cpu_s* gb)
{
	ld_reg_16(&(gb->reg.bc), gb->current_instruction->args);
}

void	ld_sp_a16(struct gb_cpu_s* gb)
{
	ld_reg_16(&(gb->reg.sp), gb->current_instruction->args);
}

void	ld_sp_hl(struct gb_cpu_s* gb)
{
	ld_reg_16(&(gb->reg.sp), gb->reg.hl);
}

void	ld_ptr_bc_a(struct gb_cpu_s* gb)
{
	ld_mem_8(gb, gb->reg.bc, gb->reg.a);
}

void	ldh_a8_a(struct gb_cpu_s* gb)
{
	ld_mem_8(gb, 0xFF00 + gb->current_instruction->args, gb->reg.a);
}

void	ld_ptr_de_a(struct gb_cpu_s* gb)
{
	ld_mem_8(gb, gb->reg.de, gb->reg.a);
}

void	ld_ptr_hl_b(struct gb_cpu_s* gb)
{
	ld_mem_8(gb, gb->reg.hl, gb->reg.b);
}

void	ld_ptr_hl_c(struct gb_cpu_s* gb)
{
	ld_mem_8(gb, gb->reg.hl, gb->reg.c);
}

void	ld_ptr_hl_d(struct gb_cpu_s* gb)
{
	ld_mem_8(gb, gb->reg.hl, gb->reg.d);
}

void	ld_ptr_hl_e(struct gb_cpu_s* gb)
{
	ld_mem_8(gb, gb->reg.hl, gb->reg.e);
}

void	ld_ptr_hl_h(struct gb_cpu_s* gb)
{
	ld_mem_8(gb, gb->reg.hl, gb->reg.h);
}

void	ld_ptr_hl_l(struct gb_cpu_s* gb)
{
	ld_mem_8(gb, gb->reg.hl, gb->reg.l);
}

void	ld_ptr_hl_n(struct gb_cpu_s* gb)
{
	ld_mem_8(gb, gb->reg.hl, gb->current_instruction->args);
}

void	ld_nn_a(struct gb_cpu_s* gb)
{
	ld_mem_8(gb, gb->current_instruction->args, gb->reg.a);
}

void	ld_ptr_nn_sp(struct gb_cpu_s* gb)
{
	ld_mem_16(gb, gb->current_instruction->args, gb->reg.sp);
}

void	ld_de_a16(struct gb_cpu_s* gb)
{
	ld_reg_16(&(gb->reg.de), gb->current_instruction->args);
}

void	ldh_a_ptr_n(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.a), read_8(gb, 0xFF00 + gb->current_instruction->args));
}

void	ldh_ptr_c_a(struct gb_cpu_s* gb)
{
	ld_mem_8(gb, gb->reg.c + 0xFF00, gb->reg.a);
}

void	ldd_hl_a(struct gb_cpu_s* gb)
{
	ld_mem_8(gb, gb->reg.hl, gb->reg.a);
	gb->reg.hl -= 1;
}

void	ldd_a_ptr_hl(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.a), read_8(gb, gb->reg.hl));
	gb->reg.hl -= 1;
}

void	ld_ptr_hl_a(struct gb_cpu_s* gb)
{
	ld_mem_8(gb, gb->reg.hl, gb->reg.a);
}

void	ldi_hl_a(struct gb_cpu_s* gb)
{
	ld_mem_8(gb, gb->reg.hl, gb->reg.a);
	gb->reg.hl += 1;
}

void	ldi_a_ptr_hl(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.a), read_8(gb, gb->reg.hl));
	gb->reg.hl += 1;
}

void	ld_hl_sp_s(struct gb_cpu_s* gb)
{
	// absolutely not sure about this one
	uint16_t ret;
	int8_t value = (int8_t)(gb->current_instruction->args);

	ret = gb->reg.sp + value;

	cpu_toggle_flag(gb, CARRY_FLAG, ((gb->reg.sp ^ value ^ (ret & 0xFFFF)) & 0x100) == 0x100);
	cpu_toggle_flag(gb, HALF_CARRY_FLAG, ((gb->reg.sp ^ value ^ (ret & 0xFFFF)) & 0x10) == 0x10);

	gb->reg.hl = (uint16_t)ret;
	cpu_unset_flag(gb, ZERO_FLAG | SUBSTRACTION_FLAG);
}
