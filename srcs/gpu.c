/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gpu.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 13:08:59 by niragne           #+#    #+#             */
/*   Updated: 2020/02/25 17:31:58 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gb.h"

# define HBLANK_TIME 204 //204
# define VBLANK_TIME 456 //456

void	gpu_tick(struct gb_cpu_s* gb)
{
	gb->gpu.tick += gb->current_instruction->cycles;
	if (gb->gpu.mode == GPU_MODE_HBLANK)
	{
		if (gb->gpu.tick >= HBLANK_TIME)
		{
			gb->gpu.y_coord++;
			gb->gpu.tick -= HBLANK_TIME;
		}
		if (gb->gpu.y_coord == 143)
		{
			gb->gpu.mode = GPU_MODE_VBLANK;
			if (gb->interrupt_enable_register & INT_VBLANK_REQUEST)
			{
				// gb->interrupt = INT_VBLANK;
				gb->interrupt_enable_register &= ~INT_VBLANK_REQUEST;
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

	write_8(gb, LY_OFFSET, 0x90);
	// write_8(gb, LY_OFFSET, gb->gpu.y_coord);

}