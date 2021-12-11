/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpu_toggle_flag.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 13:31:11 by niragne           #+#    #+#             */
/*   Updated: 2020/02/14 13:50:01 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

#include "gb.h"
#include "cpu.h"

void    cpu_set_flag(struct gb_cpu_s* gb, uint8_t flag)
{
	gb->reg.f |= flag;
}

void    cpu_unset_flag(struct gb_cpu_s* gb, uint8_t flag)
{
	gb->reg.f &= ~flag;    
}

void    cpu_toggle_flag(struct gb_cpu_s* gb, uint8_t flag, int cond)
{
   	if (cond)
		gb->reg.f |= flag;
	else
		gb->reg.f &= ~flag;
}