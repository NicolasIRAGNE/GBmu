/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cpu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 15:30:05 by niragne           #+#    #+#             */
/*   Updated: 2020/02/05 14:21:51 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gb.h"

void	init_cpu(struct gb_cpu_s* gb)
{
	gb->reg.pc = 0x100;
	gb->reg.sp = 0xFFFE;
	gb->reg.d = 0xdd;
	gb->reg.c = 0xcc;
	gb->running = 1;
	gb->current_instruction = NULL;
}