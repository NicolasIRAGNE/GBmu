/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cp.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 16:08:31 by niragne           #+#    #+#             */
/*   Updated: 2020/02/05 16:23:16 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gb.h"

void	cp_reg8(struct gb_cpu_s* gb, uint8_t* reg, uint8_t x)
{
	uint16_t ret;
	ret = *reg - x;
	if (ret)
		gb->reg.f &= ~ZERO_FLAG;
	else
		gb->reg.f |= ZERO_FLAG;
	if (ret > 255)
		gb->reg.f |= CARRY_FLAG;
	else
		gb->reg.f &= ~CARRY_FLAG;
	gb->reg.f |= SUBSTRACTION_FLAG;
}

int	cp_a8(struct gb_cpu_s* gb)
{
	cp_reg8(gb, &(gb->reg.a), gb->current_instruction->args);	
}