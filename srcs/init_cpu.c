/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cpu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 15:30:05 by niragne           #+#    #+#             */
/*   Updated: 2020/02/07 11:35:33 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gb.h"
#include <strings.h>

void	init_cpu(struct gb_cpu_s* gb)
{
	bzero(&gb->reg, sizeof(gb->reg));
	gb->reg.sp = 0xFFFE;
	gb->reg.pc = 0x100;
	gb->running = 1;
	gb->current_instruction = NULL;
}