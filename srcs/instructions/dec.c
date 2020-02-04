/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dec.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 20:05:58 by niragne           #+#    #+#             */
/*   Updated: 2020/02/04 20:15:06 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gb.h"

void	dec_reg8(uint8_t* reg)
{
	*reg = *reg - 1;
}

void	dec_reg16(uint16_t* reg)
{
	*reg = *reg - 1;
}

int		dec_a(struct gb_cpu_s* gb)
{
	dec_reg8(&(gb->reg.a));
}

int		dec_b(struct gb_cpu_s* gb)
{
	dec_reg8(&(gb->reg.b));
}

int		dec_c(struct gb_cpu_s* gb)
{
	dec_reg8(&(gb->reg.c));
}

int		dec_d(struct gb_cpu_s* gb)
{
	dec_reg8(&(gb->reg.d));
}

int		dec_e(struct gb_cpu_s* gb)
{
	dec_reg8(&(gb->reg.e));
}

int		dec_h(struct gb_cpu_s* gb)
{
	dec_reg8(&(gb->reg.h));
}

int		dec_l(struct gb_cpu_s* gb)
{
	dec_reg8(&(gb->reg.l));
}