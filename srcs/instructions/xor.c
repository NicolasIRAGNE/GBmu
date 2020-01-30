/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 17:15:16 by niragne           #+#    #+#             */
/*   Updated: 2020/01/30 17:15:25 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gb.h"

int		xor(struct gb_cpu_s* gb, uint8_t value)
{
	gb->reg.a ^= value;
}

int		xor_a(struct gb_cpu_s* gb)
{
	xor(gb, gb->reg.a);
	gb->reg.pc += gb->current_instruction->size + 1;
}
