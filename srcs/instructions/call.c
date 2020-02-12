/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 19:30:21 by niragne           #+#    #+#             */
/*   Updated: 2020/02/12 13:09:41 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gb.h"

void	call(struct gb_cpu_s* gb, uint16_t a16)
{
	gb->reg.sp -= 2;
	write_16(gb, gb->reg.sp, gb->reg.pc + 3);
	gb->reg.pc = a16;
	gb->jmp = 1;
}

int		call_a16(struct gb_cpu_s* gb)
{
	call(gb, gb->current_instruction->args);
}

int		call_nz_a16(struct gb_cpu_s* gb)
{
	if (!(gb->reg.f & ZERO_FLAG))
		call(gb, gb->current_instruction->args);
}
