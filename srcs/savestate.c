/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   savestate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 13:23:51 by niragne           #+#    #+#             */
/*   Updated: 2020/04/28 16:36:35 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE
#include "gb.h"
#include <stdio.h>

int		savestate(struct gb_cpu_s* gb, int number)
{
	char* save_file;
	asprintf(&save_file, SAVESTATE_DIR"%.11s_%d.ss", gb->rom_ptr->header->title, number);

	int fd = open(save_file, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);

	if (fd < 0)
	{
		perror(save_file);
		return (1);
	}
	write(fd, gb, sizeof(*gb));
	write(fd, gb->extra_ram, gb->mbc.ram_size);
	write(fd, gb->debugger, sizeof(*gb->debugger));
	close(fd);
	return(0);
}

int		loadstate(struct gb_cpu_s* gb, int number)
{
	char* save_file;
	asprintf(&save_file, SAVESTATE_DIR"%.11s_%d.ss", gb->rom_ptr->header->title, number);
	int fd = open(save_file, O_RDONLY);
	struct rom_s* ptr_save = gb->rom_ptr;
	struct gbmu_debugger_s* debugger_save = gb->debugger;
	uint8_t* ram_save = gb->extra_ram;
	struct mbc_s mbc_save = gb->mbc;

	if (fd < 0)
	{
		printf("1\n");
		printf("failed to open ?\n");
		perror(save_file);
		return (1);
	}
	int rd = read(fd, gb, sizeof(*gb));
	if (rd < 0)
	{
		printf("2\n");
		perror(save_file);
		close(fd);
		return (1);
	}
	if (rd != sizeof(*gb))
	{
		dprintf(2, "warning: read %d bytes from savestate (expected %ld). file may be corrupted.\n", rd, sizeof(*gb));
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
		printf("3\n");
		perror(save_file);
		close(fd);
		return (1);
	}
	if (rd != (int)gb->mbc.ram_size)
	{
		dprintf(2, "warning: read %d bytes from save data (expected %d). file may be corrupted.\n", rd, gb->mbc.ram_size);
	}
	rd = read(fd, gb->debugger, sizeof(*gb->debugger));
	if (rd < 0)
	{
		printf("5\n");
		perror(save_file);
		close(fd);
		return (1);
	}
	if (rd != sizeof(*gb->debugger))
	{
		dprintf(2, "warning: read %d bytes from save data (expected %ld). file may be corrupted.\n", rd, sizeof(*gb->debugger));
	}
	gb->vram_updated = 1;
	update_current_instruction(gb);
	close(fd);
	return(0);
}