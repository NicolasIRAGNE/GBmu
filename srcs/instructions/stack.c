/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 11:49:47 by niragne           #+#    #+#             */
/*   Updated: 2020/04/09 17:02:21 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gb.h"
#include "cpu.h"
#include "op.h"

void	push_hl(struct gb_cpu_s* gb)
{
	gb->reg.sp -= 2;
	write_16(gb, gb->reg.sp, gb->reg.hl);
}

void	push_af(struct gb_cpu_s* gb)
{
	gb->reg.sp -= 2;
	write_16(gb, gb->reg.sp, gb->reg.af);
}

void	push_bc(struct gb_cpu_s* gb)
{
	gb->reg.sp -= 2;
	write_16(gb, gb->reg.sp, gb->reg.bc);
}

void	push_de(struct gb_cpu_s* gb)
{
	gb->reg.sp -= 2;
	write_16(gb, gb->reg.sp, gb->reg.de);
}

void	pop_hl(struct gb_cpu_s* gb)
{
	gb->reg.hl = read_16(gb, gb->reg.sp);
	gb->reg.sp += 2;
}

void	pop_af(struct gb_cpu_s* gb)
{

	//wtf is this
	gb->reg.af = read_16(gb, gb->reg.sp);
	gb->reg.f &= 0xf0;
	gb->reg.sp += 2;
}

void	pop_bc(struct gb_cpu_s* gb)
{
	gb->reg.bc = read_16(gb, gb->reg.sp);
	gb->reg.sp += 2;
}

void	pop_de(struct gb_cpu_s* gb)
{
	gb->reg.de = read_16(gb, gb->reg.sp);
	gb->reg.sp += 2;
}
