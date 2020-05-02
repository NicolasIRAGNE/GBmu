/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   savestate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 13:23:51 by niragne           #+#    #+#             */
/*   Updated: 2020/05/02 16:48:48 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE
#include "gb.h"
#include <stdio.h>
#include <SDL.h>
#include <stdlib.h>

void	check_savestate(struct gb_cpu_s* gb, const Uint8* state, SDL_Event event)
{
	Uint8 slots[] = 
	{
		SDL_SCANCODE_1,
		SDL_SCANCODE_2,
		SDL_SCANCODE_3,
		SDL_SCANCODE_4,
		SDL_SCANCODE_5,
		SDL_SCANCODE_6,
		SDL_SCANCODE_7,
		SDL_SCANCODE_8,
		SDL_SCANCODE_9,
	};

	for (size_t i = 0; i < sizeof(slots); i++)
	{
		if (event.key.keysym.scancode == slots[i])
		{
			if (state[SDL_SCANCODE_LSHIFT])
				loadstate(gb, i + 1);
			else
				savestate(gb, i + 1);
			return ;
		}
	}
}

int		savestate(struct gb_cpu_s* gb, int number)
{
	char* save_file;
	asprintf(&save_file, SAVESTATE_DIR"%.11s_%d.ss", gb->rom_ptr->header->title, number);

	int fd = open(save_file, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	printf("saving current state to %s\n", save_file);
	if (fd < 0)
	{
		perror(save_file);
		return (1);
	}
	write(fd, gb, sizeof(*gb));
	write(fd, gb->extra_ram, gb->mbc.ram_size);
	close(fd);
	free(save_file);
	return(0);
}

int		loadstate(struct gb_cpu_s* gb, int number)
{
	char* save_file;
	asprintf(&save_file, SAVESTATE_DIR"%.11s_%d.ss", gb->rom_ptr->header->title, number);
	printf("loading state from %s\n", save_file);	
	int fd = open(save_file, O_RDONLY);
	struct rom_s* ptr_save = gb->rom_ptr;
	struct gbmu_debugger_s* debugger_save = gb->debugger;
	uint8_t* ram_save = gb->extra_ram;
	struct mbc_s mbc_save = gb->mbc;

	if (fd < 0)
	{
		perror(save_file);
		return (1);
	}
	int rd = read(fd, gb, sizeof(*gb));
	if (rd < 0)
	{
		perror(save_file);
		close(fd);
		return (1);
	}
	if (rd != sizeof(*gb))
	{
		dprintf(2, "fatal: save file appears to be corrupted\n");
		fatal(gb);
		return (1);
	}
	gb->rom_ptr = ptr_save;
	gb->debugger = debugger_save;
	gb->extra_ram = ram_save;
	gb->mbc.name = mbc_save.name;
	gb->mbc.read = mbc_save.read;
	gb->mbc.write = mbc_save.write;
	rd = read(fd, gb->extra_ram, gb->mbc.ram_size);
	if (rd < 0)
	{
		perror(save_file);
		close(fd);
		return (1);
	}
	if (rd != (int)gb->mbc.ram_size)
	{
		dprintf(2, "warning: read %d bytes from save data (expected %u). file may be corrupted.\n", rd, gb->mbc.ram_size);
	}
	gb->vram_updated = 1;
	update_current_instruction(gb);
	close(fd);
	free(save_file);
	return(0);
}