/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ext_op.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 11:04:14 by niragne           #+#    #+#             */
/*   Updated: 2020/02/13 11:49:03 by niragne          ###   ########.fr       */
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


#endif