/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 15:18:59 by niragne           #+#    #+#             */
/*   Updated: 2020/02/14 17:26:09 by niragne          ###   ########.fr       */
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

int			ld_d_c(struct gb_cpu_s* gb);
int			ld_b_a(struct gb_cpu_s* gb);
int			ld_a_b(struct gb_cpu_s* gb);
int			ld_a_c(struct gb_cpu_s* gb);
int			ld_a_d(struct gb_cpu_s* gb);
int			ld_a_l(struct gb_cpu_s* gb);
int			ld_a_e(struct gb_cpu_s* gb);
int			ld_a_h(struct gb_cpu_s* gb);
int			ld_e_a(struct gb_cpu_s* gb);
int			ld_c_a(struct gb_cpu_s* gb);
int			ld_d_a(struct gb_cpu_s* gb);
int			ld_a_a8(struct gb_cpu_s* gb);
int			ld_b_a8(struct gb_cpu_s* gb);
int			ld_c_a8(struct gb_cpu_s* gb);
int			ld_d_a8(struct gb_cpu_s* gb);
int			ld_e_a8(struct gb_cpu_s* gb);
int			ld_h_a8(struct gb_cpu_s* gb);
int			ld_l_a8(struct gb_cpu_s* gb);
int			ld_a_ptr_a16(struct gb_cpu_s* gb);
int			ld_a_ptr_de(struct gb_cpu_s* gb);
int			ld_a_ptr_hl(struct gb_cpu_s* gb);
int			ld_b_ptr_hl(struct gb_cpu_s* gb);
int			ld_c_ptr_hl(struct gb_cpu_s* gb);
int			ld_d_ptr_hl(struct gb_cpu_s* gb);
int			ld_h_ptr_hl(struct gb_cpu_s* gb);
int			ld_hl_a16(struct gb_cpu_s* gb);
int			ld_bc_a16(struct gb_cpu_s* gb);
int			ld_de_a16(struct gb_cpu_s* gb);
int			ld_sp_a16(struct gb_cpu_s* gb);
int			ldh_a8_a(struct gb_cpu_s* gb);
int			ldh_a_a8(struct gb_cpu_s* gb);
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
int			ld_ptr_de_a(struct gb_cpu_s* gb);
int			ldi_a_ptr_hl(struct gb_cpu_s* gb);
int			ld_nn_a(struct gb_cpu_s* gb);

/*
** Misc
*/
int			nop(struct gb_cpu_s*);
int			di(struct gb_cpu_s* gb);
int			ei(struct gb_cpu_s* gb);
int			cb_n(struct gb_cpu_s* gb);

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

int			and_a(struct gb_cpu_s* gb);
int			and_b(struct gb_cpu_s* gb);
int			and_c(struct gb_cpu_s* gb);
int			and_d(struct gb_cpu_s* gb);
int			and_e(struct gb_cpu_s* gb);
int			and_h(struct gb_cpu_s* gb);
int			and_l(struct gb_cpu_s* gb);
int			and_a8(struct gb_cpu_s* gb);

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

int			add_a(struct gb_cpu_s* gb);
int			add_b(struct gb_cpu_s* gb);
int			add_c(struct gb_cpu_s* gb);
int			add_d(struct gb_cpu_s* gb);
int			add_e(struct gb_cpu_s* gb);
int			add_h(struct gb_cpu_s* gb);
int			add_l(struct gb_cpu_s* gb);
int			add_a8(struct gb_cpu_s* gb);
int			adc_n(struct gb_cpu_s* gb);

int			sub_a(struct gb_cpu_s* gb);
int			sub_b(struct gb_cpu_s* gb);
int			sub_c(struct gb_cpu_s* gb);
int			sub_d(struct gb_cpu_s* gb);
int			sub_e(struct gb_cpu_s* gb);
int			sub_h(struct gb_cpu_s* gb);
int			sub_l(struct gb_cpu_s* gb);
int			sub_a8(struct gb_cpu_s* gb);

int			cp_a8(struct gb_cpu_s* gb);

/*
** Jump
*/
int			jp_a16(struct gb_cpu_s* gb);
int			jr_nz_a8(struct gb_cpu_s* gb);
int			jr_z_a8(struct gb_cpu_s* gb);
int			jp_z_a16(struct gb_cpu_s* gb);
int			jr_c_a8(struct gb_cpu_s* gb);
int			jr_nc_a8(struct gb_cpu_s* gb);
int			jr_a8(struct gb_cpu_s* gb);

int			ret(struct gb_cpu_s* gb);
int			ret_c(struct gb_cpu_s* gb);
int			ret_nc(struct gb_cpu_s* gb);
int			ret_z(struct gb_cpu_s* gb);
int			ret_nz(struct gb_cpu_s* gb);

/*
** Call
*/
int			call_a16(struct gb_cpu_s* gb);
int			call_nz_a16(struct gb_cpu_s* gb);


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