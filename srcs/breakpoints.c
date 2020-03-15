/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   breakpoints.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 16:37:38 by niragne           #+#    #+#             */
/*   Updated: 2020/03/15 17:05:53 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gb.h"
#include <stdlib.h>

struct breakpoint_s*	new_breakpoint(uint16_t addr)
{
	struct breakpoint_s* ret;

	ret = malloc(sizeof(struct breakpoint_s));
	if (ret == NULL)
		return (NULL);
	ret->addr = addr;
	ret->next = NULL;
}

int		add_breakpoint(struct breakpoint_s** lst, uint16_t addr)
{
	struct breakpoint_s* new = new_breakpoint(addr);
	if (new = NULL)
		return (1);
	
	struct breakpoint_s* tmp = *lst;
	if (!tmp)
		tmp->next = new;
	else
	{
		while (tmp)
		{
			tmp = tmp->next;
		}
		tmp->next = new;	
	}
}