/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   savestate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 13:23:51 by niragne           #+#    #+#             */
/*   Updated: 2020/06/14 13:52:59 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "gb.h"
#include "cpu.h"
#include "mbc.h"
#include "rom.h"
#ifdef _WIN32
# include "asprintf.h"
#endif

int		savestate(struct gb_cpu_s* gb, int number)
{
	char* save_file;
	char* user_dir = get_user_data_dir();
	asprintf(&save_file, "%s/%s/%.11s_%d.ss", user_dir, SAVESTATE_DIR, gb->rom_ptr->header->title, number);
	printf("saving current data to %s\n", save_file);	
	free(user_dir);

	FILE* f = fopen(save_file, "wb");
	if (!f)
	{
		perror(save_file);
		return (1);
	}
	fwrite(gb, sizeof(*gb), 1, f);
	fwrite(gb->extra_ram, gb->mbc.ram_size, 1, f);
	fclose(f);
	free(save_file);
	return(0);
}

int		loadstate(struct gb_cpu_s* gb, int number)
{
	char* save_file;
	char* user_dir = get_user_data_dir();
	asprintf(&save_file, "%s/%s/%.11s_%d.ss", user_dir, SAVESTATE_DIR, gb->rom_ptr->header->title, number);
	free(user_dir);
	printf("loading state from %s\n", save_file);	
	struct rom_s* ptr_save = gb->rom_ptr;
	struct gbmu_debugger_s* debugger_save = gb->debugger;
	uint8_t* ram_save = gb->extra_ram;
	struct mbc_s mbc_save = gb->mbc;

	FILE* f = fopen(save_file, "rb");
	if (f == NULL)
	{
		perror(save_file);
		return (1);
	}
	int rd = fread(gb, sizeof(*gb), 1, f) * sizeof(*gb);
	if (rd < 0)
	{
		perror(save_file);
		fclose(f);
		return (1);
	}
	if (rd != sizeof(*gb))
	{
		printf("fatal: save file appears to be corrupted\n");
		gb->rom_ptr = ptr_save; // Restore so we can actually save
		fatal(gb);
		fclose(f);
		return (1);
	}
	gb->rom_ptr = ptr_save;
	gb->debugger = debugger_save;
	gb->extra_ram = ram_save;
	gb->mbc.name = mbc_save.name;
	gb->mbc.read = mbc_save.read;
	gb->mbc.write = mbc_save.write;
	rd = fread(gb->extra_ram, gb->mbc.ram_size, 1, f) * gb->mbc.ram_size;
	if (rd < 0)
	{
		perror(save_file);
		fclose(f);
		return (1);
	}
	if (rd != (int)gb->mbc.ram_size)
	{
		printf("warning: read %d bytes from save data (expected %u). file may be corrupted.\n", rd, gb->mbc.ram_size);
	}
	update_current_instruction(gb);
	fclose(f);
	free(save_file);
	return(0);
}