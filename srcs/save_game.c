/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 16:49:30 by niragne           #+#    #+#             */
/*   Updated: 2020/05/04 19:19:30 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

#include "gb.h"
#include "cpu.h"
#include "mbc.h"
#include "rom.h"

#ifdef _WIN32
#include "asprintf.h"
#endif

#define TMP_SAVE_FILE "tmp.sav"

int		save_game_crash(struct gb_cpu_s* gb)
{
	char* save_file;
	asprintf(&save_file, SAVE_DIR"%.11s_CRASH.sav", gb->rom_ptr->header->title);
	printf("saving current data to %s\n", save_file);	

	FILE* f = fopen(save_file, "wb");
	if (!f)
	{
		perror(save_file);
		return (1);
	}
	fwrite(gb->extra_ram, gb->mbc.ram_size, 1, f);
	fclose(f);
	free(save_file);
	return(0);
}

int		save_game(struct gb_cpu_s* gb)
{
	char* save_file;
	asprintf(&save_file, SAVE_DIR"%.11s.sav", gb->rom_ptr->header->title);
	printf("saving current data to %s\n", save_file);	

	FILE* f = fopen(save_file, "wb");
	if (!f)
	{
		perror(save_file);
		free(save_file);
		return (1);
	}
	fwrite(gb->extra_ram, gb->mbc.ram_size, 1, f);
	fclose(f);
	free(save_file);
	return(0);
}

int		load_game_from_file(struct gb_cpu_s* gb, const char* save_file)
{
	printf("loading save data from %s\n", save_file);	
	FILE* f = fopen(save_file, "rb");

	if (f == NULL)
	{
		perror(save_file);
		return (1);
	}
	size_t rd = fread(gb->extra_ram, gb->mbc.ram_size, 1, f) * gb->mbc.ram_size;
	if (rd < 0)
	{
		perror(save_file);
		fclose(f);
		return (0);
	}
	if (rd != (int)gb->mbc.ram_size)
	{
		fprintf(stderr, "warning: read %zu bytes from save data (expected %d). file may be corrupted.\n", rd, gb->mbc.ram_size);
	}
	fclose(f);
	free(save_file);
	return(0);
}

int		load_game(struct gb_cpu_s* gb)
{
	char* save_file;
	asprintf(&save_file, SAVE_DIR"%.11s.sav", gb->rom_ptr->header->title);
	return (load_game_from_file(gb, save_file));
}

