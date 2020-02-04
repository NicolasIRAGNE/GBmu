/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 15:18:59 by niragne           #+#    #+#             */
/*   Updated: 2020/02/04 17:22:14 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_H
# define OP_H

# include <stdint.h>
# include <unistd.h>
# include "cpu.h"

struct inst_s
{
	char* name;
	uint8_t opcode;
	uint8_t	cycles;
	uint8_t	size;
	int		(*exec)(struct gb_cpu_s*);
	uint16_t	args;
};

/*
** OPCODES
*/

/*
** Load
*/
void		ld_reg_8(uint8_t* dst, uint8_t src);
void		ld_reg_16(uint16_t* dst, uint16_t src);
int			ld_dc(struct gb_cpu_s* gb);
int			ld_a_a8(struct gb_cpu_s* gb);
int			ld_b_a8(struct gb_cpu_s* gb);
int			ld_c_a8(struct gb_cpu_s* gb);
int			ld_hl_a16(struct gb_cpu_s* gb);
int			ld_sp_a16(struct gb_cpu_s* gb);

/*
** Misc
*/
int			nop(struct gb_cpu_s*);
int			di(struct gb_cpu_s* gb);
int			ei(struct gb_cpu_s* gb);

/*
** Arithmetic
*/
int			xor_a(struct gb_cpu_s* gb);

/*
** Jump
*/
int			jp_a16(struct gb_cpu_s*);



#endif