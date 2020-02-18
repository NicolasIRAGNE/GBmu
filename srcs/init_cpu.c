/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cpu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 15:30:05 by niragne           #+#    #+#             */
/*   Updated: 2020/02/18 13:25:43 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gb.h"
#include <strings.h>
#include <stdlib.h>

void	init_cpu(struct gb_cpu_s* gb)
{
	bzero(gb, sizeof(*gb));
	gb->reg.sp = 0xFFFE;
	gb->reg.de = 0xFF56;
	gb->reg.af = 0x1180;
	gb->reg.hl = 0x000d;
	gb->reg.pc = 0x100;
	gb->running = 1;
	gb->paused = 1;
	gb->current_instruction = NULL;
	gb->ime = 1;
	gb->interrupt_enable_register |= INT_VBLANK_REQUEST;
}