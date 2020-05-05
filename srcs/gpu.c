/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gpu.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 13:08:59 by niragne           #+#    #+#             */
/*   Updated: 2020/05/05 16:13:20 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gb.h"

# define HBLANK_TIME	(204 * 1) //204
# define OAM_TIME		(80 * 1)
# define VRAM_TIME		(172 * 1)
# define VBLANK_TIME	(HBLANK_TIME + OAM_TIME + VRAM_TIME) //456

void	compare_ly(struct gb_cpu_s* gb, uint8_t lyc, uint8_t *stat, uint8_t lcdc)
{
	if (gb->gpu.y_coord == lyc)
	{
		if (*stat & STAT_LYC_INT && !gb->gpu.lyc_requested)
		{
			gb->gpu.lyc_requested = 1;
			if (lcdc & LCDC_ON)
				request_interrupt(gb, INT_STAT_REQUEST);
		}
		*stat |= STAT_LYC_FLAG;
	}
	else
	{
		*stat &= ~STAT_LYC_FLAG;
		gb->gpu.lyc_requested = 0;
	}
}

void	gpu_tick(struct gb_cpu_s* gb)
{
	uint8_t stat = read_8(gb, STAT_OFFSET);
	uint8_t lyc = read_8(gb, LYC_OFFSET);
	uint8_t lcdc = read_8(gb, LCDC_OFFSET);
	gb->gpu.tick += (gb->cycle - gb->gpu.last_cycle) / 4;
	gb->gpu.last_cycle = gb->cycle;
	// printf("gpu tick = %d\n", gb->gpu.tick);
	switch (gb->gpu.mode)
	{
		case GPU_MODE_HBLANK:
		{
			if (gb->gpu.tick >= HBLANK_TIME)
			{
				gb->gpu.y_coord++;
				write_8(gb, LY_OFFSET, gb->gpu.y_coord);
				compare_ly(gb, lyc, &stat, lcdc);
				if (gb->gpu.y_coord == 144)
				{
					gb->gpu.mode = GPU_MODE_VBLANK;
					if (lcdc & LCDC_ON)
						request_interrupt(gb, INT_VBLANK_REQUEST);
					if (stat & STAT_MODE_1_INT && (lcdc & LCDC_ON))
						request_interrupt(gb, INT_STAT_REQUEST);
				}
				else
				{
					gb->gpu.mode = GPU_MODE_OAM;
					if (stat & STAT_MODE_2_INT && (lcdc & LCDC_ON))
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
				if (stat & STAT_MODE_0_INT && (lcdc & LCDC_ON))
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
				write_8(gb, LY_OFFSET, gb->gpu.y_coord);
				compare_ly(gb, lyc, &stat, lcdc);
				if (gb->gpu.y_coord > 153)
				{
					gb->gpu.y_coord = 0;
					compare_ly(gb, lyc, &stat, lcdc);
					write_8(gb, LY_OFFSET, gb->gpu.y_coord);
					gb->gpu.mode = GPU_MODE_OAM;
					if (stat & STAT_MODE_2_INT && (lcdc & LCDC_ON))
						request_interrupt(gb, INT_STAT_REQUEST);
				}
				gb->gpu.tick -= VBLANK_TIME;
			}
			break;
		}

		default:
			break;
	}
	compare_ly(gb, lyc, &stat, lcdc);
	stat = (stat & 0b11111100) | gb->gpu.mode;
	write_8(gb, STAT_OFFSET, stat);
}