/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dec.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 20:05:58 by niragne           #+#    #+#             */
/*   Updated: 2020/02/05 13:32:24 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gb.h"

void	dec_reg8(struct gb_cpu_s* gb, uint8_t* reg)
{
	*reg = *reg - 1;
	if (*reg)
		gb->reg.f &= ~ZERO_FLAG;
	else
		gb->reg.f |= ~ZERO_FLAG;
	gb->reg.f |= SUBSTRACTION_FLAG;
}

void	dec_reg16(struct gb_cpu_s* gb, uint16_t* reg)
{
	*reg = *reg - 1;
	if (*reg)
		gb->reg.f &= ~ZERO_FLAG;
	else
		gb->reg.f |= ~ZERO_FLAG;
	gb->reg.f |= SUBSTRACTION_FLAG;
}

int		dec_a(struct gb_cpu_s* gb)
{
	dec_reg8(gb, &(gb->reg.a));
}

int		dec_b(struct gb_cpu_s* gb)
{
	dec_reg8(gb, &(gb->reg.b));
}

int		dec_c(struct gb_cpu_s* gb)
{
	dec_reg8(gb, &(gb->reg.c));
}

int		dec_d(struct gb_cpu_s* gb)
{
	dec_reg8(gb, &(gb->reg.d));
}

int		dec_e(struct gb_cpu_s* gb)
{
	dec_reg8(gb, &(gb->reg.e));
}

int		dec_h(struct gb_cpu_s* gb)
{
	dec_reg8(gb, &(gb->reg.h));
}

int		dec_l(struct gb_cpu_s* gb)
{
	dec_reg8(gb, &(gb->reg.l));
}