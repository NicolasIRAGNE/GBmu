/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugger.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 14:05:57 by niragne           #+#    #+#             */
/*   Updated: 2020/02/11 12:11:17 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gb.h"
#include <stdio.h>
#include <string.h>

int		command_next(struct gb_cpu_s* gb, char* s, uint16_t arg)
{
	handle_instruction(gb);
	return (0);
}

int		command_not_found(struct gb_cpu_s* gb, char* s, uint16_t arg)
{
	printf("undefined command: \"%s\"\n", s);
	return (0);
}

int		command_quit(struct gb_cpu_s* gb, char* s, uint16_t arg)
{
	gb->running = 0;	
	return (0);
}

int		command_print(struct gb_cpu_s* gb, char* s, uint16_t arg)
{
	printf("%x: %x\n", arg, read_8(gb, arg));	
	printf("%x: %x\n", arg, read_16(gb, arg));	
	return (0);
}

void	parse_command(struct gb_cpu_s* gb)
{
	char buffer[255];
	char command[255];
	uint16_t arg;
	static int		(*f)(struct gb_cpu_s*, char*, uint16_t) = command_next;

	fgets(buffer, sizeof(buffer), stdin);
	int rd = sscanf(buffer, "%s %hx", command, &arg);
	if (rd > 0)
	{
		if (!strcmp(command, "n"))
		{
			f = command_next;
		}
		else if (!strcmp(command, "q"))
		{
			f = command_quit;
		}
		else if (!strcmp(command, "p"))
		{
			f = command_print;
		}
		else
		{
			f = command_not_found;
		}
	}
	f(gb, command, arg);
}