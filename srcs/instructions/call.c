/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 19:30:21 by niragne           #+#    #+#             */
/*   Updated: 2020/02/04 19:41:22 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gb.h"

int		call_a16(struct gb_cpu_s* gb)
{
	gb->reg.sp -= 2;
	write_16(gb, gb->reg.sp, gb->reg.pc);
	gb->reg.pc = gb->current_instruction->args;
	gb->jmp = 1;
}
