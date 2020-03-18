/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugger.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 14:05:57 by niragne           #+#    #+#             */
/*   Updated: 2020/03/18 13:31:58 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gb.h"
#include <stdio.h>
#include <string.h>

int		command_next(struct gb_cpu_s* gb, char* s, uint16_t arg)
{
	return (handle_instruction(gb));
}

int		command_add_breakpoint(struct gb_cpu_s* gb, char* s, uint16_t arg)
{
	printf("Adding breakpoint %x\n", arg);
	add_breakpoint(&(gb->debugger->breakpoints), arg);
	print_breakpoints(gb->debugger->breakpoints);
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

int		command_run(struct gb_cpu_s* gb, char* s, uint16_t arg)
{
	gb->paused = 0;
	return (0);
}

int		command_print(struct gb_cpu_s* gb, char* s, uint16_t arg)
{
	printf("%x: %x\n", arg, read_8(gb, arg));	
	printf("%x: %x\n", arg, read_16(gb, arg));	
	return (0);
}

int		command_del(struct gb_cpu_s* gb, char* s, uint16_t arg)
{
	clear_breakpoints(&(gb->debugger->breakpoints));
	return (0);
}

void	parse_command(struct gb_cpu_s* gb)
{
	char buffer[255];
	char command[255];
	int ret;
	uint16_t arg;
	static int		(*f)(struct gb_cpu_s*, char*, uint16_t) = command_next;

	if (fgets(buffer, sizeof(buffer), stdin) == NULL)
	{
		gb->running = 0;
		return ;
	}
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
		else if (!strcmp(command, "r"))
		{
			f = command_run;
		}
		else if (!strcmp(command, "b"))
		{
			f = command_add_breakpoint;
		}
		else if (!strcmp(command, "del"))
		{
			f = command_del;
		}
		else
		{
			f = command_not_found;
		}
	}
	ret = f(gb, command, arg);
	if (ret)
		gb->running = 0;
}