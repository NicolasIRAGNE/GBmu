/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dec.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 20:05:58 by niragne           #+#    #+#             */
/*   Updated: 2020/02/07 13:38:57 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gb.h"

void	dec_reg8(struct gb_cpu_s* gb, uint8_t* reg)
{
	*reg = *reg - 1;
	cpu_toggle_flag(gb, ZERO_FLAG, !*reg);
	cpu_set_flag(gb, SUBSTRACTION_FLAG);
}

void	dec_reg16(struct gb_cpu_s* gb, uint16_t* reg)
{
	*reg = *reg - 1;
	cpu_toggle_flag(gb, ZERO_FLAG, !*reg);
	cpu_set_flag(gb, SUBSTRACTION_FLAG);
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