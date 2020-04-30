/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 16:49:30 by niragne           #+#    #+#             */
/*   Updated: 2020/04/30 11:07:03 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE
#include "gb.h"
#include <stdio.h>
#include <stdlib.h>

#define TMP_SAVE_FILE "tmp.sav"

int		save_game(struct gb_cpu_s* gb)
{
	char* save_file;
	asprintf(&save_file, SAVE_DIR"%.11s.sav", gb->rom_ptr->header->title);
	printf("saving data to %s\n", save_file);	

	int fd = open(save_file, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);

	if (fd < 0)
	{
		perror(save_file);
		return (1);
	}
	write(fd, gb->extra_ram, gb->mbc.ram_size);
	close(fd);
	free(save_file);
	return(0);
}

int		load_game(struct gb_cpu_s* gb)
{
	char* save_file;
	asprintf(&save_file, SAVE_DIR"%.11s.sav", gb->rom_ptr->header->title);
	printf("loading save data from %s\n", save_file);	
	int fd = open(save_file, O_RDONLY);

	if (fd < 0)
	{
		perror(save_file);
		return (1);
	}
	int rd = read(fd, gb->extra_ram, gb->mbc.ram_size);
	if (rd < 0)
	{
		perror(save_file);
		close(fd);
		return (0);
	}
	if (rd != (int)gb->mbc.ram_size)
	{
		fprintf(stderr, "warning: read %d bytes from save data (expected %d). file may be corrupted.\n", rd, gb->mbc.ram_size);
	}
	close(fd);
	free(save_file);
	return(0);
}