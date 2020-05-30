/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   breakpoints.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 16:37:38 by niragne           #+#    #+#             */
/*   Updated: 2020/05/15 17:08:06 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gb.h"
#include <stdio.h>
#include <stdlib.h>

/*

struct breakpoint_s*	new_breakpoint(uint16_t addr)
{
	struct breakpoint_s* ret;

	ret = malloc(sizeof(struct breakpoint_s));
	if (ret == NULL)
		return (NULL);
	ret->addr = addr;
	ret->next = NULL;
	return (ret);
}

int		breakpoint_pushback(struct breakpoint_s** lst, struct breakpoint_s* toadd)
{
	struct breakpoint_s* ptr;
	struct breakpoint_s* tmp;

	ptr = *lst;
	if (*lst == NULL)
		*lst = toadd;
	else
	{
		while (ptr)
		{
			if (ptr->addr == toadd->addr)
				return (1);
			tmp = ptr;
			ptr = ptr->next;
		}
		tmp->next = toadd;
	}
	return (0);
}

int		add_breakpoint(struct breakpoint_s** lst, uint16_t addr)
{
	struct breakpoint_s* new = new_breakpoint(addr);
	if (new == NULL)
		return (1);
	
	if (breakpoint_pushback(lst, new))
		free(new);
	return (0);
}

int		print_breakpoints(struct breakpoint_s* lst)
{
	while (lst)
	{
		printf("Breakpoint at %x\n", lst->addr);
		lst = lst->next;
	}
	return (0);
}

int		find_breakpoint(struct breakpoint_s* lst, uint16_t addr)
{
	while (lst)
	{
		if (lst->addr == addr)
		{
			return (1);
		}
		lst = lst->next;
	}
	return (0);
}

int		clear_breakpoints(struct breakpoint_s** lst)
{
	struct breakpoint_s* ptr;
	struct breakpoint_s* tmp;

	ptr = *lst;
	if (*lst == NULL)
		return(0);
	else
	{
		while (ptr)
		{
			tmp = ptr;
			ptr = ptr->next;
			free(tmp);
		}
	}
	*lst = NULL;
	return (0);
}
*/