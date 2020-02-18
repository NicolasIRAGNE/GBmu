/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 19:54:52 by niragne           #+#    #+#             */
/*   Updated: 2020/02/12 13:57:18 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gb.h"

void	inc_reg8(struct gb_cpu_s* gb, uint8_t* reg)
{
	*reg = *reg + 1;
	cpu_toggle_flag(gb, ZERO_FLAG, !*reg);
	cpu_unset_flag(gb, SUBSTRACTION_FLAG);
}

void	inc_reg16(struct gb_cpu_s* gb, uint16_t* reg)
{
	*reg = *reg + 1;
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

int		inc_hl(struct gb_cpu_s* gb)
{
	inc_reg16(gb, &(gb->reg.hl));
}

int		inc_bc(struct gb_cpu_s* gb)
{
	inc_reg16(gb, &(gb->reg.bc));
}

int		inc_de(struct gb_cpu_s* gb)
{
	inc_reg16(gb, &(gb->reg.de));
}

int		inc_sp(struct gb_cpu_s* gb)
{
	inc_reg16(gb, &(gb->reg.sp));
}