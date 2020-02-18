/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gpu.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 13:08:59 by niragne           #+#    #+#             */
/*   Updated: 2020/02/18 13:36:44 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gb.h"

void	gpu_tick(struct gb_cpu_s* gb)
{
	gb->gpu.tick += gb->current_instruction->cycles;
	if (gb->gpu.mode == GPU_MODE_HBLANK)
	{
		if (gb->gpu.tick >= 204)
		{
			gb->gpu.y_coord++;
			gb->gpu.tick -= 204;
		}
		if (gb->gpu.y_coord == 143)
		{
			gb->gpu.mode = GPU_MODE_VBLANK;
			if (gb->interrupt_enable_register & INT_VBLANK_REQUEST)
			{
				gb->interrupt = INT_VBLANK;
				gb->interrupt_enable_register &= ~INT_VBLANK_REQUEST;
			}
		}	
	}
	
	else if (gb->gpu.mode == GPU_MODE_VBLANK)
	{
		if (gb->gpu.tick >= 456)
		{
			gb->gpu.y_coord++;
			gb->gpu.tick -= 456;
		}
		if (gb->gpu.y_coord == 153)
		{
			gb->gpu.y_coord = 0;
			gb->interrupt_enable_register |= INT_VBLANK_REQUEST;
			gb->gpu.mode = GPU_MODE_OAM;
		}	
	}
	
	else if (gb->gpu.mode == GPU_MODE_OAM)
	{
		gb->gpu.mode = GPU_MODE_VRAM;
	}

	else if (gb->gpu.mode == GPU_MODE_VRAM)
	{
		gb->gpu.mode = GPU_MODE_HBLANK;		
	}

	write_8(gb, LY_OFFSET, gb->gpu.y_coord);	

}