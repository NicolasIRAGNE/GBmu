/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   video_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 13:27:32 by niragne           #+#    #+#             */
/*   Updated: 2020/02/16 14:57:22 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gb.h"
#include "SDL.h"

void	video_loop(struct gb_cpu_s* gb)
{
	int err = 0;
	uint8_t	y_coord = 0;
	
	while(gb->running)
	{
		while (gb->paused)
			;
		write_8(gb, LCDC_OFFSET, y_coord);
		if (y_coord == 144)
			gb->interrupt = INT_VBLANK;
		if (y_coord == 153)
			y_coord = 0;
		y_coord++;
		usleep(104);
	}
}

void*	thread_entry(void* user_data)
{
	video_loop((struct gb_cpu_s*) user_data);
	return (NULL);
}

