/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 11:49:47 by niragne           #+#    #+#             */
/*   Updated: 2020/02/12 12:14:03 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gb.h"

int		push_hl(struct gb_cpu_s* gb)
{
	gb->reg.sp -= 2;
	write_16(gb, gb->reg.sp, gb->reg.hl);
}

int		push_af(struct gb_cpu_s* gb)
{
	gb->reg.sp -= 2;
	write_16(gb, gb->reg.sp, gb->reg.af);
}

int		push_bc(struct gb_cpu_s* gb)
{
	gb->reg.sp -= 2;
	write_16(gb, gb->reg.sp, gb->reg.bc);
}

int		push_de(struct gb_cpu_s* gb)
{
	gb->reg.sp -= 2;
	write_16(gb, gb->reg.sp, gb->reg.de);
}

int		pop_hl(struct gb_cpu_s* gb)
{
	gb->reg.hl = read_16(gb, gb->reg.sp);
	gb->reg.sp += 2;
}

int		pop_af(struct gb_cpu_s* gb)
{
	gb->reg.af = read_16(gb, gb->reg.sp);
	gb->reg.sp += 2;
}

int		pop_bc(struct gb_cpu_s* gb)
{
	gb->reg.bc = read_16(gb, gb->reg.sp);
	gb->reg.sp += 2;
}

int		pop_de(struct gb_cpu_s* gb)
{
	gb->reg.de = read_16(gb, gb->reg.sp);
	gb->reg.sp += 2;
}
