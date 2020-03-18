/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cpu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 15:30:05 by niragne           #+#    #+#             */
/*   Updated: 2020/03/18 12:45:18 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gb.h"
#include <strings.h>
#include <stdlib.h>
#include <stdio.h>

int		init_boot_rom(struct gb_cpu_s* gb)
{
	int fd;
	int rd;

	fd = open(BOOT_ROM, O_RDONLY);
	if (fd < 0)
	{
		perror("fatal: could not open "BOOT_ROM);
		return (1);
	}

	rd = read(fd, gb->boot_rom, BOOT_ROM_SIZE);
	if (rd < 0)
	{
		perror("fatal: could read from "BOOT_ROM);
		return (1);
	}

	if (rd != BOOT_ROM_SIZE)
		fprintf(stderr, "WARNING : read %d bytes from boot rom (expected %d). boot behavior is unexpected.\n", rd, BOOT_ROM_SIZE);
	close(fd);
	return (0);
}

int		init_cpu(struct gb_cpu_s* gb)
{
	bzero(gb, sizeof(*gb));
	if (init_boot_rom(gb))
		return (1);
	gb->reg.sp = 0xFFFE;
	gb->reg.de = 0x0008;
	gb->reg.af = 0x1180;
	gb->reg.hl = 0x007c;
	gb->reg.pc = 0x100;
	gb->running = 1;
	gb->vram_viewer_running = 1;
	gb->paused = 1;
	gb->current_instruction = NULL;
	gb->ime = 0;
	// gb->interrupt_enable_register |= INT_VBLANK_REQUEST;
	return (0);
}