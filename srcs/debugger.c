/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugger.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 14:05:57 by niragne           #+#    #+#             */
/*   Updated: 2020/05/31 18:38:43 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gb.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "libyacc_wrapper.h"

void	execute_debugger(struct gb_cpu_s* gb)
{
	char		*buf;
	int			ret;

	(void)ret;
	while ((buf = readline("gbmu> ")) != NULL)
	{
    	if (strlen(buf) > 0)
		{
      		add_history(buf);
    	}
   		ret = libyacc_execute(gb, buf, 1);
		free(buf);
	}
	gb->running = 0;
}