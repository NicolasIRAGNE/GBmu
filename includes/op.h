/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 15:18:59 by niragne           #+#    #+#             */
/*   Updated: 2020/03/27 13:45:02 by niragne          ###   ########.fr       */
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
	int		(*exec)(struct gb_cpu_s*);
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

int			ld_a_a(struct gb_cpu_s* gb);
int			ld_a_b(struct gb_cpu_s* gb);
int			ld_a_c(struct gb_cpu_s* gb);
int			ld_a_d(struct gb_cpu_s* gb);
int			ld_a_e(struct gb_cpu_s* gb);
int			ld_a_h(struct gb_cpu_s* gb);
int			ld_a_l(struct gb_cpu_s* gb);

int			ld_b_a(struct gb_cpu_s* gb);
int			ld_b_b(struct gb_cpu_s* gb);
int			ld_b_c(struct gb_cpu_s* gb);
int			ld_b_d(struct gb_cpu_s* gb);
int			ld_b_e(struct gb_cpu_s* gb);
int			ld_b_h(struct gb_cpu_s* gb);
int			ld_b_l(struct gb_cpu_s* gb);

int			ld_c_a(struct gb_cpu_s* gb);
int			ld_c_b(struct gb_cpu_s* gb);
int			ld_c_c(struct gb_cpu_s* gb);
int			ld_c_d(struct gb_cpu_s* gb);
int			ld_c_e(struct gb_cpu_s* gb);
int			ld_c_h(struct gb_cpu_s* gb);
int			ld_c_l(struct gb_cpu_s* gb);

int			ld_d_a(struct gb_cpu_s* gb);
int			ld_d_b(struct gb_cpu_s* gb);
int			ld_d_c(struct gb_cpu_s* gb);
int			ld_d_d(struct gb_cpu_s* gb);
int			ld_d_e(struct gb_cpu_s* gb);
int			ld_d_h(struct gb_cpu_s* gb);
int			ld_d_l(struct gb_cpu_s* gb);

int			ld_e_a(struct gb_cpu_s* gb);
int			ld_e_b(struct gb_cpu_s* gb);
int			ld_e_c(struct gb_cpu_s* gb);
int			ld_e_d(struct gb_cpu_s* gb);
int			ld_e_e(struct gb_cpu_s* gb);
int			ld_e_h(struct gb_cpu_s* gb);
int			ld_e_l(struct gb_cpu_s* gb);

int			ld_h_a(struct gb_cpu_s* gb);
int			ld_h_b(struct gb_cpu_s* gb);
int			ld_h_c(struct gb_cpu_s* gb);
int			ld_h_d(struct gb_cpu_s* gb);
int			ld_h_e(struct gb_cpu_s* gb);
int			ld_h_f(struct gb_cpu_s* gb);
int			ld_h_h(struct gb_cpu_s* gb);
int			ld_h_l(struct gb_cpu_s* gb);

int			ld_l_a(struct gb_cpu_s* gb);
int			ld_l_b(struct gb_cpu_s* gb);
int			ld_l_c(struct gb_cpu_s* gb);
int			ld_l_d(struct gb_cpu_s* gb);
int			ld_l_e(struct gb_cpu_s* gb);
int			ld_l_f(struct gb_cpu_s* gb);
int			ld_l_h(struct gb_cpu_s* gb);
int			ld_l_l(struct gb_cpu_s* gb);

int			ld_a_a8(struct gb_cpu_s* gb);
int			ld_b_a8(struct gb_cpu_s* gb);
int			ld_c_a8(struct gb_cpu_s* gb);
int			ld_d_a8(struct gb_cpu_s* gb);
int			ld_e_a8(struct gb_cpu_s* gb);
int			ld_h_a8(struct gb_cpu_s* gb);
int			ld_l_a8(struct gb_cpu_s* gb);
int			ldh_a_ptr_c(struct gb_cpu_s* gb);

int			ld_a_ptr_a16(struct gb_cpu_s* gb);
int			ld_a_ptr_bc(struct gb_cpu_s* gb);
int			ld_a_ptr_de(struct gb_cpu_s* gb);
int			ld_a_ptr_hl(struct gb_cpu_s* gb);
int			ldd_a_ptr_hl(struct gb_cpu_s* gb);


int			ld_b_ptr_hl(struct gb_cpu_s* gb);
int			ld_c_ptr_hl(struct gb_cpu_s* gb);
int			ld_d_ptr_hl(struct gb_cpu_s* gb);
int			ld_e_ptr_hl(struct gb_cpu_s* gb);
int			ld_h_ptr_hl(struct gb_cpu_s* gb);
int			ld_l_ptr_hl(struct gb_cpu_s* gb);
int			ld_hl_a16(struct gb_cpu_s* gb);
int			ld_bc_a16(struct gb_cpu_s* gb);
int			ld_de_a16(struct gb_cpu_s* gb);
int			ld_sp_a16(struct gb_cpu_s* gb);
int			ld_sp_hl(struct gb_cpu_s* gb);
int			ldh_a8_a(struct gb_cpu_s* gb);
int			ldh_ptr_c_a(struct gb_cpu_s* gb);
int			ldh_a_ptr_n(struct gb_cpu_s* gb);
int			ldd_hl_a(struct gb_cpu_s* gb);
int			ld_ptr_hl_a(struct gb_cpu_s* gb);
int			ldi_hl_a(struct gb_cpu_s* gb);
int			ld_ptr_bc_a(struct gb_cpu_s* gb);
int			ld_ptr_hl_b(struct gb_cpu_s* gb);
int			ld_ptr_hl_c(struct gb_cpu_s* gb);
int			ld_ptr_hl_d(struct gb_cpu_s* gb);
int			ld_ptr_hl_e(struct gb_cpu_s* gb);
int			ld_ptr_hl_h(struct gb_cpu_s* gb);
int			ld_ptr_hl_l(struct gb_cpu_s* gb);
int			ld_ptr_hl_n(struct gb_cpu_s* gb);
int			ld_ptr_de_a(struct gb_cpu_s* gb);
int			ldi_a_ptr_hl(struct gb_cpu_s* gb);
int			ld_nn_a(struct gb_cpu_s* gb);
int			ld_ptr_nn_sp(struct gb_cpu_s* gb);

int		ld_hl_sp_s(struct gb_cpu_s* gb);
int		add_sp_s(struct gb_cpu_s* gb);


/*
** Misc
*/
int			nop(struct gb_cpu_s*);
int			di(struct gb_cpu_s* gb);
int			ei(struct gb_cpu_s* gb);
int			cb_n(struct gb_cpu_s* gb);
int			cpl(struct gb_cpu_s* gb);
int			stop(struct gb_cpu_s* gb);
int			halt(struct gb_cpu_s* gb);
int			daa(struct gb_cpu_s* gb);
int			scf(struct gb_cpu_s* gb);
int			ccf(struct gb_cpu_s* gb);

/*
** Arithmetic
*/
int			xor_a(struct gb_cpu_s* gb);
int			xor_b(struct gb_cpu_s* gb);
int			xor_c(struct gb_cpu_s* gb);
int			xor_d(struct gb_cpu_s* gb);
int			xor_e(struct gb_cpu_s* gb);
int			xor_h(struct gb_cpu_s* gb);
int			xor_l(struct gb_cpu_s* gb);
int			xor_n(struct gb_cpu_s* gb);
int			xor_ptr_hl(struct gb_cpu_s* gb);

int			or_a(struct gb_cpu_s* gb);
int			or_b(struct gb_cpu_s* gb);
int			or_c(struct gb_cpu_s* gb);
int			or_d(struct gb_cpu_s* gb);
int			or_e(struct gb_cpu_s* gb);
int			or_h(struct gb_cpu_s* gb);
int			or_l(struct gb_cpu_s* gb);
int			or_ptr_hl(struct gb_cpu_s* gb);
int			or_n(struct gb_cpu_s* gb);

int			and_a(struct gb_cpu_s* gb);
int			and_b(struct gb_cpu_s* gb);
int			and_c(struct gb_cpu_s* gb);
int			and_d(struct gb_cpu_s* gb);
int			and_e(struct gb_cpu_s* gb);
int			and_h(struct gb_cpu_s* gb);
int			and_l(struct gb_cpu_s* gb);
int			and_a8(struct gb_cpu_s* gb);
int			and_ptr_hl(struct gb_cpu_s* gb);

int			dec_a(struct gb_cpu_s* gb);
int			dec_b(struct gb_cpu_s* gb);
int			dec_c(struct gb_cpu_s* gb);
int			dec_d(struct gb_cpu_s* gb);
int			dec_e(struct gb_cpu_s* gb);
int			dec_h(struct gb_cpu_s* gb);
int			dec_l(struct gb_cpu_s* gb);
int			dec_hl(struct gb_cpu_s* gb);
int			dec_de(struct gb_cpu_s* gb);
int			dec_sp(struct gb_cpu_s* gb);
int			dec_bc(struct gb_cpu_s* gb);
int			dec_ptr_hl(struct gb_cpu_s* gb);

int			inc_a(struct gb_cpu_s* gb);
int			inc_b(struct gb_cpu_s* gb);
int			inc_c(struct gb_cpu_s* gb);
int			inc_d(struct gb_cpu_s* gb);
int			inc_e(struct gb_cpu_s* gb);
int			inc_h(struct gb_cpu_s* gb);
int			inc_l(struct gb_cpu_s* gb);
int			inc_hl(struct gb_cpu_s* gb);
int			inc_de(struct gb_cpu_s* gb);
int			inc_sp(struct gb_cpu_s* gb);
int			inc_bc(struct gb_cpu_s* gb);
int			inc_ptr_hl(struct gb_cpu_s* gb);

int			add_a(struct gb_cpu_s* gb);
int			add_b(struct gb_cpu_s* gb);
int			add_c(struct gb_cpu_s* gb);
int			add_d(struct gb_cpu_s* gb);
int			add_e(struct gb_cpu_s* gb);
int			add_h(struct gb_cpu_s* gb);
int			add_l(struct gb_cpu_s* gb);
int			add_a8(struct gb_cpu_s* gb);
int			add_bc(struct gb_cpu_s* gb);
int			add_de(struct gb_cpu_s* gb);
int			add_hl(struct gb_cpu_s* gb);
int			add_sp(struct gb_cpu_s* gb);
int			add_ptr_hl(struct gb_cpu_s* gb);

int			adc_n(struct gb_cpu_s* gb);
int			adc_a(struct gb_cpu_s* gb);
int			adc_b(struct gb_cpu_s* gb);
int			adc_c(struct gb_cpu_s* gb);
int			adc_d(struct gb_cpu_s* gb);
int			adc_e(struct gb_cpu_s* gb);
int			adc_h(struct gb_cpu_s* gb);
int			adc_l(struct gb_cpu_s* gb);
int			adc_ptr_hl(struct gb_cpu_s* gb);

int			sbc_n(struct gb_cpu_s* gb);
int			sbc_a(struct gb_cpu_s* gb);
int			sbc_b(struct gb_cpu_s* gb);
int			sbc_c(struct gb_cpu_s* gb);
int			sbc_d(struct gb_cpu_s* gb);
int			sbc_e(struct gb_cpu_s* gb);
int			sbc_h(struct gb_cpu_s* gb);
int			sbc_l(struct gb_cpu_s* gb);
int			sbc_ptr_hl(struct gb_cpu_s* gb);

int			sub_a(struct gb_cpu_s* gb);
int			sub_b(struct gb_cpu_s* gb);
int			sub_c(struct gb_cpu_s* gb);
int			sub_d(struct gb_cpu_s* gb);
int			sub_e(struct gb_cpu_s* gb);
int			sub_h(struct gb_cpu_s* gb);
int			sub_l(struct gb_cpu_s* gb);
int			sub_a8(struct gb_cpu_s* gb);
int			sub_ptr_hl(struct gb_cpu_s* gb);

int			cp_a8(struct gb_cpu_s* gb);
int			cp_ptr_hl(struct gb_cpu_s* gb);
int			cp_a(struct gb_cpu_s* gb);
int			cp_b(struct gb_cpu_s* gb);
int			cp_c(struct gb_cpu_s* gb);
int			cp_d(struct gb_cpu_s* gb);
int			cp_e(struct gb_cpu_s* gb);
int			cp_h(struct gb_cpu_s* gb);
int			cp_l(struct gb_cpu_s* gb);

/*
** Jump
*/
int			jp_a16(struct gb_cpu_s* gb);
int			jp_c_a16(struct gb_cpu_s* gb);
int			jp_nc_a16(struct gb_cpu_s* gb);
int			jp_hl(struct gb_cpu_s* gb);
int			jr_nz_a8(struct gb_cpu_s* gb);
int			jr_z_a8(struct gb_cpu_s* gb);
int			jp_z_a16(struct gb_cpu_s* gb);
int			jp_nz_a16(struct gb_cpu_s* gb);
int			jr_c_a8(struct gb_cpu_s* gb);
int			jr_nc_a8(struct gb_cpu_s* gb);
int			jr_a8(struct gb_cpu_s* gb);

int			ret(struct gb_cpu_s* gb);
int			reti(struct gb_cpu_s* gb);
int			ret_c(struct gb_cpu_s* gb);
int			ret_nc(struct gb_cpu_s* gb);
int			ret_z(struct gb_cpu_s* gb);
int			ret_nz(struct gb_cpu_s* gb);

/*
** Call
*/
int			call_a16(struct gb_cpu_s* gb);
int			interrupt_a16(struct gb_cpu_s* gb, uint16_t addr);
int			call_z_a16(struct gb_cpu_s* gb);
int			call_nz_a16(struct gb_cpu_s* gb);
int			call_c_a16(struct gb_cpu_s* gb);
int			call_nc_a16(struct gb_cpu_s* gb);
int			rst_38(struct gb_cpu_s* gb);
int			rst_28(struct gb_cpu_s* gb);
int			rst_18(struct gb_cpu_s* gb);
int			rst_8(struct gb_cpu_s* gb);
int			rst_30(struct gb_cpu_s* gb);
int			rst_20(struct gb_cpu_s* gb);
int			rst_10(struct gb_cpu_s* gb);
int			rst_0(struct gb_cpu_s* gb);


/*
** Stack
*/
int			push_hl(struct gb_cpu_s* gb);
int			push_af(struct gb_cpu_s* gb);
int			push_bc(struct gb_cpu_s* gb);
int			push_de(struct gb_cpu_s* gb);
int			pop_hl(struct gb_cpu_s* gb);
int			pop_af(struct gb_cpu_s* gb);
int			pop_bc(struct gb_cpu_s* gb);
int			pop_de(struct gb_cpu_s* gb);

#endif