/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gpu.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 13:08:59 by niragne           #+#    #+#             */
/*   Updated: 2020/05/02 15:32:53 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gb.h"

# define HBLANK_TIME	(204 * 2) //204
# define OAM_TIME		(80 * 2)
# define VRAM_TIME		(172 * 2)
# define VBLANK_TIME	(HBLANK_TIME + OAM_TIME + VRAM_TIME) //456

void	gpu_tick(struct gb_cpu_s* gb)
{
	uint8_t stat = read_8(gb, STAT_OFFSET);
	uint8_t lyc = read_8(gb, LYC_OFFSET);
	static int lyc_requested = 0;
	gb->gpu.tick += gb->cycle - gb->gpu.last_cycle;
	gb->gpu.last_cycle = gb->cycle;
	
	switch (gb->gpu.mode)
	{
		case GPU_MODE_HBLANK:
		{
			if (gb->gpu.tick >= HBLANK_TIME)
			{
				gb->gpu.y_coord++;
				if (gb->gpu.y_coord == 144)
				{
					gb->gpu.mode = GPU_MODE_VBLANK;
					request_interrupt(gb, INT_VBLANK_REQUEST);
					if (stat & STAT_MODE_1_INT)
						request_interrupt(gb, INT_STAT_REQUEST);
				}
				else
				{
					gb->gpu.mode = GPU_MODE_OAM;
					if (stat & STAT_MODE_2_INT)
						request_interrupt(gb, INT_STAT_REQUEST);
				}
				gb->gpu.tick -= HBLANK_TIME;
			}
			break;
		}

		case GPU_MODE_OAM:
		{
			if (gb->gpu.tick >= OAM_TIME)
			{
				gb->gpu.mode = GPU_MODE_VRAM;
				gb->gpu.tick -= OAM_TIME;
			}
			break;
		}

		case GPU_MODE_VRAM:
		{
			if (gb->gpu.tick >= VRAM_TIME)
			{
				gb->gpu.mode = GPU_MODE_HBLANK;
				if (stat & STAT_MODE_0_INT)
						request_interrupt(gb, INT_STAT_REQUEST);
				gb->gpu.tick -= VRAM_TIME;
			}
			break;
		}
		
		case GPU_MODE_VBLANK:
		{
			if (gb->gpu.tick >= VBLANK_TIME)
			{
				gb->gpu.y_coord++;
				if (gb->gpu.y_coord > 153)
				{
					gb->gpu.y_coord = 0;
					gb->gpu.mode = GPU_MODE_OAM;
					if (stat & STAT_MODE_2_INT)
						request_interrupt(gb, INT_STAT_REQUEST);
				}
				gb->gpu.tick -= VBLANK_TIME;
			}
			break;
		}

		default:
			break;
	}

	if (gb->gpu.y_coord == lyc)
	{
		if (stat & STAT_LYC_INT && !lyc_requested)
		{
			gb->vram_updated = 1;
			lyc_requested = 1;
			uint8_t interrupt_requests = read_8(gb, IF_OFFSET);
			write_8(gb, IF_OFFSET, interrupt_requests | INT_STAT_REQUEST);
		}
		stat |= STAT_LYC_FLAG;
	}
	else
	{
		stat &= ~STAT_LYC_FLAG;
		lyc_requested = 0;
	}
	stat = (stat & 0b11111100) | gb->gpu.mode;
	write_8(gb, STAT_OFFSET, stat);
	write_8(gb, LY_OFFSET, gb->gpu.y_coord);
}