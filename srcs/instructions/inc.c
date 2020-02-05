/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 19:54:52 by niragne           #+#    #+#             */
/*   Updated: 2020/02/05 13:35:08 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gb.h"

void	inc_reg8(struct gb_cpu_s* gb, uint8_t* reg)
{
	*reg = *reg + 1;
	if (*reg)
		gb->reg.f &= ~ZERO_FLAG;
	else
		gb->reg.f |= ~ZERO_FLAG;
	gb->reg.f &= ~SUBSTRACTION_FLAG;
}

void	inc_reg16(struct gb_cpu_s* gb, uint16_t* reg)
{
	*reg = *reg + 1;
	if (*reg)
		gb->reg.f &= ~ZERO_FLAG;
	else
		gb->reg.f |= ~ZERO_FLAG;
	gb->reg.f &= ~SUBSTRACTION_FLAG;
}

int		inc_a(struct gb_cpu_s* gb)
{
	inc_reg8(gb, &(gb->reg.a));
}

int		inc_b(struct gb_cpu_s* gb)
{
	inc_reg8(gb, &(gb->reg.b));
}

int		inc_c(struct gb_cpu_s* gb)
{
	inc_reg8(gb, &(gb->reg.c));
}

int		inc_d(struct gb_cpu_s* gb)
{
	inc_reg8(gb, &(gb->reg.d));
}

int		inc_e(struct gb_cpu_s* gb)
{
	inc_reg8(gb, &(gb->reg.e));
}

int		inc_h(struct gb_cpu_s* gb)
{
	inc_reg8(gb, &(gb->reg.h));
}

int		inc_l(struct gb_cpu_s* gb)
{
	inc_reg8(gb, &(gb->reg.l));
}