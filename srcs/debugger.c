/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugger.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 14:05:57 by niragne           #+#    #+#             */
/*   Updated: 2020/02/07 10:45:56 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gb.h"
#include <stdio.h>
#include <string.h>

int		command_next(struct gb_cpu_s* gb, char* s)
{
	handle_instruction(gb);
	return (0);
}

int		command_not_found(struct gb_cpu_s* gb, char* s)
{
	printf("undefined command: \"%s\"\n", s);
	return (0);
}

int		command_quit(struct gb_cpu_s* gb, char* s)
{
	gb->running = 0;	
	return (0);
}

void	parse_command(struct gb_cpu_s* gb)
{
	char buffer[255];
	char command[255];
	static int		(*f)(struct gb_cpu_s*, char*) = command_next;

	fgets(buffer, sizeof(buffer), stdin);
	int rd = sscanf(buffer, "%s", command);
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
		else
		{
			f = command_not_found;
		}
	}
	f(gb, command);
}