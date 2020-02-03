/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 11:37:03 by niragne           #+#    #+#             */
/*   Updated: 2020/02/03 14:13:28 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "SDL.h"
#include "gb.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

int		open_rom(char* name, struct rom_s* rom)
{
	struct stat st;
	int fd;
	int ret;

	ret = stat(name, &st);
	if (ret)
	{
		perror(name);
		return (ret);
	}

	fd = open(name, O_RDONLY);
	if (fd < 0)
	{
		perror(name);
		return (fd);
	}
	
	void* ptr = mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
	if (!ptr)
	{
		perror(name);
		return (1);
	}
	rom->ptr = ptr;

	return (0);
}

int		main(int ac, char** av)
{
	struct rom_s rom;
	struct gb_cpu_s gb;
	if (ac < 2)
	{
		fprintf(stderr, "usage: %s <rom>\n", av[0]);
		return (1);
	}

	if (open_rom(av[1], &rom))
		return (1);
		
	rom.header = rom.ptr + 0x100;
	debug_print_rom(&rom);
	printf("Test: %p\n", (void*)&rom.header->complement_check - (void*)rom.header);

	init_cpu(&gb);
	gb.rom_ptr = &rom;
	update_current_instruction(&gb);
	init_op_tab();
	
	// int i = 0;
	// while (i < 255)
	// {
		// handle_instruction(&gb);
		// i++;
	// }
	// while(!handle_instruction(&gb));
	
	return (0);
}