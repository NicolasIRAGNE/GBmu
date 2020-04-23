/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 15:18:59 by niragne           #+#    #+#             */
/*   Updated: 2020/04/23 11:55:47 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_H
# define OP_H

# include <stdint.h>
# include <unistd.h>
# include "cpu.h"
# include "ext_op.h"

struct inst_s
{
	char* name;
	uint8_t	cycles;
	uint8_t	size;
	void	(*exec)(struct gb_cpu_s*);
	uint16_t	args;
};

extern struct inst_s op_tab[256];


/*
** OPCODES
*/

/*
** Load
*/
void		ld_reg_8(uint8_t* dst, uint8_t src);
void		ld_reg_16(uint16_t* dst, uint16_t src);
void		ld_reg_8(uint8_t* dst, uint8_t src);
void		ld_reg_16(uint16_t* dst, uint16_t src);

void		ld_a_a(struct gb_cpu_s* gb);
void		ld_a_b(struct gb_cpu_s* gb);
void		ld_a_c(struct gb_cpu_s* gb);
void		ld_a_d(struct gb_cpu_s* gb);
void		ld_a_e(struct gb_cpu_s* gb);
void		ld_a_h(struct gb_cpu_s* gb);
void		ld_a_l(struct gb_cpu_s* gb);

void		ld_b_a(struct gb_cpu_s* gb);
void		ld_b_b(struct gb_cpu_s* gb);
void		ld_b_c(struct gb_cpu_s* gb);
void		ld_b_d(struct gb_cpu_s* gb);
void		ld_b_e(struct gb_cpu_s* gb);
void		ld_b_h(struct gb_cpu_s* gb);
void		ld_b_l(struct gb_cpu_s* gb);

void		ld_c_a(struct gb_cpu_s* gb);
void		ld_c_b(struct gb_cpu_s* gb);
void		ld_c_c(struct gb_cpu_s* gb);
void		ld_c_d(struct gb_cpu_s* gb);
void		ld_c_e(struct gb_cpu_s* gb);
void		ld_c_h(struct gb_cpu_s* gb);
void		ld_c_l(struct gb_cpu_s* gb);

void		ld_d_a(struct gb_cpu_s* gb);
void		ld_d_b(struct gb_cpu_s* gb);
void		ld_d_c(struct gb_cpu_s* gb);
void		ld_d_d(struct gb_cpu_s* gb);
void		ld_d_e(struct gb_cpu_s* gb);
void		ld_d_h(struct gb_cpu_s* gb);
void		ld_d_l(struct gb_cpu_s* gb);

void		ld_e_a(struct gb_cpu_s* gb);
void		ld_e_b(struct gb_cpu_s* gb);
void		ld_e_c(struct gb_cpu_s* gb);
void		ld_e_d(struct gb_cpu_s* gb);
void		ld_e_e(struct gb_cpu_s* gb);
void		ld_e_h(struct gb_cpu_s* gb);
void		ld_e_l(struct gb_cpu_s* gb);

void		ld_h_a(struct gb_cpu_s* gb);
void		ld_h_b(struct gb_cpu_s* gb);
void		ld_h_c(struct gb_cpu_s* gb);
void		ld_h_d(struct gb_cpu_s* gb);
void		ld_h_e(struct gb_cpu_s* gb);
void		ld_h_f(struct gb_cpu_s* gb);
void		ld_h_h(struct gb_cpu_s* gb);
void		ld_h_l(struct gb_cpu_s* gb);

void		ld_l_a(struct gb_cpu_s* gb);
void		ld_l_b(struct gb_cpu_s* gb);
void		ld_l_c(struct gb_cpu_s* gb);
void		ld_l_d(struct gb_cpu_s* gb);
void		ld_l_e(struct gb_cpu_s* gb);
void		ld_l_f(struct gb_cpu_s* gb);
void		ld_l_h(struct gb_cpu_s* gb);
void		ld_l_l(struct gb_cpu_s* gb);

void		ld_a_a8(struct gb_cpu_s* gb);
void		ld_b_a8(struct gb_cpu_s* gb);
void		ld_c_a8(struct gb_cpu_s* gb);
void		ld_d_a8(struct gb_cpu_s* gb);
void		ld_e_a8(struct gb_cpu_s* gb);
void		ld_h_a8(struct gb_cpu_s* gb);
void		ld_l_a8(struct gb_cpu_s* gb);
void		ldh_a_ptr_c(struct gb_cpu_s* gb);

void		ld_a_ptr_a16(struct gb_cpu_s* gb);
void		ld_a_ptr_bc(struct gb_cpu_s* gb);
void		ld_a_ptr_de(struct gb_cpu_s* gb);
void		ld_a_ptr_hl(struct gb_cpu_s* gb);
void		ldd_a_ptr_hl(struct gb_cpu_s* gb);


void		ld_b_ptr_hl(struct gb_cpu_s* gb);
void		ld_c_ptr_hl(struct gb_cpu_s* gb);
void		ld_d_ptr_hl(struct gb_cpu_s* gb);
void		ld_e_ptr_hl(struct gb_cpu_s* gb);
void		ld_h_ptr_hl(struct gb_cpu_s* gb);
void		ld_l_ptr_hl(struct gb_cpu_s* gb);
void		ld_hl_a16(struct gb_cpu_s* gb);
void		ld_bc_a16(struct gb_cpu_s* gb);
void		ld_de_a16(struct gb_cpu_s* gb);
void		ld_sp_a16(struct gb_cpu_s* gb);
void		ld_sp_hl(struct gb_cpu_s* gb);
void		ldh_a8_a(struct gb_cpu_s* gb);
void		ldh_ptr_c_a(struct gb_cpu_s* gb);
void		ldh_a_ptr_n(struct gb_cpu_s* gb);
void		ldd_hl_a(struct gb_cpu_s* gb);
void		ld_ptr_hl_a(struct gb_cpu_s* gb);
void		ldi_hl_a(struct gb_cpu_s* gb);
void		ld_ptr_bc_a(struct gb_cpu_s* gb);
void		ld_ptr_hl_b(struct gb_cpu_s* gb);
void		ld_ptr_hl_c(struct gb_cpu_s* gb);
void		ld_ptr_hl_d(struct gb_cpu_s* gb);
void		ld_ptr_hl_e(struct gb_cpu_s* gb);
void		ld_ptr_hl_h(struct gb_cpu_s* gb);
void		ld_ptr_hl_l(struct gb_cpu_s* gb);
void		ld_ptr_hl_n(struct gb_cpu_s* gb);
void		ld_ptr_de_a(struct gb_cpu_s* gb);
void		ldi_a_ptr_hl(struct gb_cpu_s* gb);
void		ld_nn_a(struct gb_cpu_s* gb);
void		ld_ptr_nn_sp(struct gb_cpu_s* gb);

void		ld_hl_sp_s(struct gb_cpu_s* gb);
void		add_sp_s(struct gb_cpu_s* gb);


/*
** Misc
*/
void		nop(struct gb_cpu_s*);
void		di(struct gb_cpu_s* gb);
void		ei(struct gb_cpu_s* gb);
void		cb_n(struct gb_cpu_s* gb);
void		cpl(struct gb_cpu_s* gb);
void		stop(struct gb_cpu_s* gb);
void		halt(struct gb_cpu_s* gb);
void		daa(struct gb_cpu_s* gb);
void		scf(struct gb_cpu_s* gb);
void		ccf(struct gb_cpu_s* gb);

/*
** Arithmetic
*/
void		xor_a(struct gb_cpu_s* gb);
void		xor_b(struct gb_cpu_s* gb);
void		xor_c(struct gb_cpu_s* gb);
void		xor_d(struct gb_cpu_s* gb);
void		xor_e(struct gb_cpu_s* gb);
void		xor_h(struct gb_cpu_s* gb);
void		xor_l(struct gb_cpu_s* gb);
void		xor_n(struct gb_cpu_s* gb);
void		xor_ptr_hl(struct gb_cpu_s* gb);

void		or_a(struct gb_cpu_s* gb);
void		or_b(struct gb_cpu_s* gb);
void		or_c(struct gb_cpu_s* gb);
void		or_d(struct gb_cpu_s* gb);
void		or_e(struct gb_cpu_s* gb);
void		or_h(struct gb_cpu_s* gb);
void		or_l(struct gb_cpu_s* gb);
void		or_ptr_hl(struct gb_cpu_s* gb);
void		or_n(struct gb_cpu_s* gb);

void		and_a(struct gb_cpu_s* gb);
void		and_b(struct gb_cpu_s* gb);
void		and_c(struct gb_cpu_s* gb);
void		and_d(struct gb_cpu_s* gb);
void		and_e(struct gb_cpu_s* gb);
void		and_h(struct gb_cpu_s* gb);
void		and_l(struct gb_cpu_s* gb);
void		and_a8(struct gb_cpu_s* gb);
void		and_ptr_hl(struct gb_cpu_s* gb);

void		dec_a(struct gb_cpu_s* gb);
void		dec_b(struct gb_cpu_s* gb);
void		dec_c(struct gb_cpu_s* gb);
void		dec_d(struct gb_cpu_s* gb);
void		dec_e(struct gb_cpu_s* gb);
void		dec_h(struct gb_cpu_s* gb);
void		dec_l(struct gb_cpu_s* gb);
void		dec_hl(struct gb_cpu_s* gb);
void		dec_de(struct gb_cpu_s* gb);
void		dec_sp(struct gb_cpu_s* gb);
void		dec_bc(struct gb_cpu_s* gb);
void		dec_ptr_hl(struct gb_cpu_s* gb);

void		inc_a(struct gb_cpu_s* gb);
void		inc_b(struct gb_cpu_s* gb);
void		inc_c(struct gb_cpu_s* gb);
void		inc_d(struct gb_cpu_s* gb);
void		inc_e(struct gb_cpu_s* gb);
void		inc_h(struct gb_cpu_s* gb);
void		inc_l(struct gb_cpu_s* gb);
void		inc_hl(struct gb_cpu_s* gb);
void		inc_de(struct gb_cpu_s* gb);
void		inc_sp(struct gb_cpu_s* gb);
void		inc_bc(struct gb_cpu_s* gb);
void		inc_ptr_hl(struct gb_cpu_s* gb);

void		add_a(struct gb_cpu_s* gb);
void		add_b(struct gb_cpu_s* gb);
void		add_c(struct gb_cpu_s* gb);
void		add_d(struct gb_cpu_s* gb);
void		add_e(struct gb_cpu_s* gb);
void		add_h(struct gb_cpu_s* gb);
void		add_l(struct gb_cpu_s* gb);
void		add_a8(struct gb_cpu_s* gb);
void		add_bc(struct gb_cpu_s* gb);
void		add_de(struct gb_cpu_s* gb);
void		add_hl(struct gb_cpu_s* gb);
void		add_sp(struct gb_cpu_s* gb);
void		add_ptr_hl(struct gb_cpu_s* gb);

void		adc_n(struct gb_cpu_s* gb);
void		adc_a(struct gb_cpu_s* gb);
void		adc_b(struct gb_cpu_s* gb);
void		adc_c(struct gb_cpu_s* gb);
void		adc_d(struct gb_cpu_s* gb);
void		adc_e(struct gb_cpu_s* gb);
void		adc_h(struct gb_cpu_s* gb);
void		adc_l(struct gb_cpu_s* gb);
void		adc_ptr_hl(struct gb_cpu_s* gb);

void		sbc_n(struct gb_cpu_s* gb);
void		sbc_a(struct gb_cpu_s* gb);
void		sbc_b(struct gb_cpu_s* gb);
void		sbc_c(struct gb_cpu_s* gb);
void		sbc_d(struct gb_cpu_s* gb);
void		sbc_e(struct gb_cpu_s* gb);
void		sbc_h(struct gb_cpu_s* gb);
void		sbc_l(struct gb_cpu_s* gb);
void		sbc_ptr_hl(struct gb_cpu_s* gb);

void		sub_a(struct gb_cpu_s* gb);
void		sub_b(struct gb_cpu_s* gb);
void		sub_c(struct gb_cpu_s* gb);
void		sub_d(struct gb_cpu_s* gb);
void		sub_e(struct gb_cpu_s* gb);
void		sub_h(struct gb_cpu_s* gb);
void		sub_l(struct gb_cpu_s* gb);
void		sub_a8(struct gb_cpu_s* gb);
void		sub_ptr_hl(struct gb_cpu_s* gb);

void		cp_a8(struct gb_cpu_s* gb);
void		cp_ptr_hl(struct gb_cpu_s* gb);
void		cp_a(struct gb_cpu_s* gb);
void		cp_b(struct gb_cpu_s* gb);
void		cp_c(struct gb_cpu_s* gb);
void		cp_d(struct gb_cpu_s* gb);
void		cp_e(struct gb_cpu_s* gb);
void		cp_h(struct gb_cpu_s* gb);
void		cp_l(struct gb_cpu_s* gb);

void		rla(struct gb_cpu_s* gb);
void		rlca(struct gb_cpu_s* gb);
void		rrca(struct gb_cpu_s* gb);
void		rra(struct gb_cpu_s* gb);

/*
** Jump
*/
void		jp_a16(struct gb_cpu_s* gb);
void		jp_c_a16(struct gb_cpu_s* gb);
void		jp_nc_a16(struct gb_cpu_s* gb);
void		jp_hl(struct gb_cpu_s* gb);
void		jr_nz_a8(struct gb_cpu_s* gb);
void		jr_z_a8(struct gb_cpu_s* gb);
void		jp_z_a16(struct gb_cpu_s* gb);
void		jp_nz_a16(struct gb_cpu_s* gb);
void		jr_c_a8(struct gb_cpu_s* gb);
void		jr_nc_a8(struct gb_cpu_s* gb);
void		jr_a8(struct gb_cpu_s* gb);

void		ret(struct gb_cpu_s* gb);
void		reti(struct gb_cpu_s* gb);
void		ret_c(struct gb_cpu_s* gb);
void		ret_nc(struct gb_cpu_s* gb);
void		ret_z(struct gb_cpu_s* gb);
void		ret_nz(struct gb_cpu_s* gb);

/*
** Call
*/
void		call_a16(struct gb_cpu_s* gb);
void		interrupt_a16(struct gb_cpu_s* gb, uint16_t addr);
void		call_z_a16(struct gb_cpu_s* gb);
void		call_nz_a16(struct gb_cpu_s* gb);
void		call_c_a16(struct gb_cpu_s* gb);
void		call_nc_a16(struct gb_cpu_s* gb);
void		rst_38(struct gb_cpu_s* gb);
void		rst_28(struct gb_cpu_s* gb);
void		rst_18(struct gb_cpu_s* gb);
void		rst_8(struct gb_cpu_s* gb);
void		rst_30(struct gb_cpu_s* gb);
void		rst_20(struct gb_cpu_s* gb);
void		rst_10(struct gb_cpu_s* gb);
void		rst_0(struct gb_cpu_s* gb);


/*
** Stack
*/
void		push_hl(struct gb_cpu_s* gb);
void		push_af(struct gb_cpu_s* gb);
void		push_bc(struct gb_cpu_s* gb);
void		push_de(struct gb_cpu_s* gb);
void		pop_hl(struct gb_cpu_s* gb);
void		pop_af(struct gb_cpu_s* gb);
void		pop_bc(struct gb_cpu_s* gb);
void		pop_de(struct gb_cpu_s* gb);

#endif