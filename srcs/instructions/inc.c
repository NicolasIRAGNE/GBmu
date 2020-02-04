/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 19:54:52 by niragne           #+#    #+#             */
/*   Updated: 2020/02/04 20:06:30 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gb.h"

void	inc_reg8(uint8_t* reg)
{
	*reg = *reg + 1;
}

void	inc_reg16(uint16_t* reg)
{
	*reg = *reg + 1;
}

int		inc_a(struct gb_cpu_s* gb)
{
	inc_reg8(&(gb->reg.a));
}

int		inc_b(struct gb_cpu_s* gb)
{
	inc_reg8(&(gb->reg.b));
}

int		inc_c(struct gb_cpu_s* gb)
{
	inc_reg8(&(gb->reg.c));
}

int		inc_d(struct gb_cpu_s* gb)
{
	inc_reg8(&(gb->reg.d));
}

int		inc_e(struct gb_cpu_s* gb)
{
	inc_reg8(&(gb->reg.e));
}

int		inc_h(struct gb_cpu_s* gb)
{
	inc_reg8(&(gb->reg.h));
}

int		inc_l(struct gb_cpu_s* gb)
{
	inc_reg8(&(gb->reg.l));
}