/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gpu.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 13:08:59 by niragne           #+#    #+#             */
/*   Updated: 2020/04/29 15:58:59 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gb.h"

# define HBLANK_TIME	(204 * 2) //204
# define VBLANK_TIME	(456 * 2) //456
# define OAM_TIME		(80)
# define VRAM_TIME		(172)

void	gpu_tick(struct gb_cpu_s* gb)
{
	uint8_t stat = read_8(gb, STAT_OFFSET) | 0b10000000;
	uint8_t lyc = read_8(gb, LYC_OFFSET);
	gb->gpu.tick += gb->current_instruction->cycles;
	if (gb->gpu.mode == GPU_MODE_HBLANK)
	{
		if (gb->gpu.tick >= HBLANK_TIME)
		{
			gb->gpu.y_coord++;
			gb->gpu.tick -= HBLANK_TIME;
			gb->gpu.mode = GPU_MODE_OAM;
		}
		if (gb->gpu.y_coord == 144)
		{
			gb->gpu.mode = GPU_MODE_VBLANK;
			uint8_t interrupt_requests = read_8(gb, IF_OFFSET);
			write_8(gb, IF_OFFSET, interrupt_requests | INT_VBLANK_REQUEST);
			if (stat & STAT_MODE_1_INT)
			{
				uint8_t interrupt_requests = read_8(gb, IF_OFFSET);
				write_8(gb, IF_OFFSET, interrupt_requests | INT_STAT_REQUEST);
			}
		}
	}
	
	else if (gb->gpu.mode == GPU_MODE_VBLANK)
	{
		if (gb->gpu.tick >= VBLANK_TIME)
		{
			gb->gpu.y_coord++;
			gb->gpu.tick -= VBLANK_TIME;
		}
		if (gb->gpu.y_coord == 153)
		{
			gb->gpu.y_coord = 0;
			uint8_t interrupt_requests = read_8(gb, IF_OFFSET);
			write_8(gb, IF_OFFSET, interrupt_requests & ~INT_VBLANK_REQUEST);
			gb->gpu.mode = GPU_MODE_OAM;
			if (stat & STAT_MODE_2_INT)
			{
				uint8_t interrupt_requests = read_8(gb, IF_OFFSET);
				write_8(gb, IF_OFFSET, interrupt_requests | INT_STAT_REQUEST);
			}
		}	
	}
	
	else if (gb->gpu.mode == GPU_MODE_OAM)
	{
		if (gb->gpu.tick >= OAM_TIME)
		{
			gb->gpu.tick -= OAM_TIME;
			gb->gpu.mode = GPU_MODE_VRAM;
		}
	}

	else if (gb->gpu.mode == GPU_MODE_VRAM)
	{
		if (gb->gpu.tick >= VRAM_TIME)
		{
			gb->gpu.tick -= VRAM_TIME;
			gb->gpu.mode = GPU_MODE_HBLANK;
			if (stat & STAT_MODE_0_INT)
			{
				uint8_t interrupt_requests = read_8(gb, IF_OFFSET);
				write_8(gb, IF_OFFSET, interrupt_requests | INT_STAT_REQUEST);
			}
		}
	}

	if (gb->gpu.y_coord == lyc)
	{
		if (stat & STAT_LYC_INT)
		{
			uint8_t interrupt_requests = read_8(gb, IF_OFFSET);
			write_8(gb, IF_OFFSET, interrupt_requests | INT_STAT_REQUEST);
		}
		stat |= STAT_LYC_FLAG;
	}
	else
		stat &= ~STAT_LYC_FLAG;
	stat = (stat & 0b11111100) | gb->gpu.mode;
	write_8(gb, STAT_OFFSET, stat);
	write_8(gb, LY_OFFSET, gb->gpu.y_coord);
}