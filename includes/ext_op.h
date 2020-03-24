/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ext_op.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 11:04:14 by niragne           #+#    #+#             */
/*   Updated: 2020/03/24 16:25:12 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXT_OP_H
# define EXT_OP_H

# include "gb.h"

struct ext_inst_s
{
	char*	name;
	int		(*exec)(struct gb_cpu_s*);
};

extern struct ext_inst_s ext_op_tab[256];

int		srl_a(struct gb_cpu_s* gb);
int		srl_b(struct gb_cpu_s* gb);
int		srl_c(struct gb_cpu_s* gb);
int		srl_d(struct gb_cpu_s* gb);
int		srl_e(struct gb_cpu_s* gb);
int		srl_h(struct gb_cpu_s* gb);
int		srl_l(struct gb_cpu_s* gb);
int		srl_hl(struct gb_cpu_s* gb);

int		rr_a(struct gb_cpu_s* gb);
int		rr_b(struct gb_cpu_s* gb);
int		rr_c(struct gb_cpu_s* gb);
int		rr_d(struct gb_cpu_s* gb);
int		rr_e(struct gb_cpu_s* gb);
int		rr_h(struct gb_cpu_s* gb);
int		rr_l(struct gb_cpu_s* gb);
int		rr_hl(struct gb_cpu_s* gb);

int		rl_a(struct gb_cpu_s* gb);
int		rl_b(struct gb_cpu_s* gb);
int		rl_c(struct gb_cpu_s* gb);
int		rl_d(struct gb_cpu_s* gb);
int		rl_e(struct gb_cpu_s* gb);
int		rl_h(struct gb_cpu_s* gb);
int		rl_l(struct gb_cpu_s* gb);
int		rl_hl(struct gb_cpu_s* gb);

int		rrc_a(struct gb_cpu_s* gb);

int		rlc_a(struct gb_cpu_s* gb);

int		bit7_b(struct gb_cpu_s* gb);
int		bit7_c(struct gb_cpu_s* gb);
int		bit7_d(struct gb_cpu_s* gb);
int		bit7_e(struct gb_cpu_s* gb);
int		bit7_h(struct gb_cpu_s* gb);
int		bit7_l(struct gb_cpu_s* gb);
int		bit7_a(struct gb_cpu_s* gb);

int		res0_a(struct gb_cpu_s* gb);

int		swap_a(struct gb_cpu_s* gb);


#endif