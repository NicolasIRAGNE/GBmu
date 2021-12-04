/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugger.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 14:05:57 by niragne           #+#    #+#             */
/*   Updated: 2020/06/26 16:03:54 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gb.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
# include <editline/readline.h>
#else 
#include <readline/readline.h>
#include <readline/history.h>
#endif
#ifdef WITH_LIBYACC
#include "libyacc_wrapper.h"
#endif

void	execute_debugger(struct gb_cpu_s* gb)
{
	char		*buf;
	int			quit;

	quit = 0;
	while (!quit && (buf = readline("gbmu> ")) != NULL)
	{
    	if (strlen(buf) > 0)
		{
      		add_history(buf);
    	}
		#ifdef WITH_LIBYACC
   			libyacc_execute(gb, buf, 1, &quit);
		#else
			fallback_execute(gb, buf);
		#endif

		free(buf);
	}
	if (buf == NULL)
		gb->running = 0;
	gb->paused = 0;
}