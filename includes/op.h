/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 15:18:59 by niragne           #+#    #+#             */
/*   Updated: 2020/01/31 11:55:10 by niragne          ###   ########.fr       */
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
};

/*
** OPCODES
*/
int		nop(struct gb_cpu_s*);
int		jp_a16(struct gb_cpu_s*);
int		xor_a(struct gb_cpu_s* gb);

#endif