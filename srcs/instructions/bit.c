/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 16:56:55 by niragne           #+#    #+#             */
/*   Updated: 2020/02/25 17:04:56 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ext_op.h"

int		bit_reg8(struct gb_cpu_s* gb, int bit, uint8_t reg)
{
	cpu_toggle_flag(gb, ZERO_FLAG, !(reg & (1 << bit)));
	cpu_set_flag(gb, HALF_CARRY_FLAG);
	cpu_unset_flag(gb, SUBSTRACTION_FLAG);
}

int		bit7_h(struct gb_cpu_s* gb)
{
	bit_reg8(gb, 7, gb->reg.h);
}