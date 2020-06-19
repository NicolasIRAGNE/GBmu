/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Breakpoint.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 17:57:41 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/19 18:06:03 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Breakpoint.hpp"

Breakpoint::Breakpoint(void) : AbstractCommand(BREAKPOINT_COMMAND)
{
	
}

Breakpoint::Breakpoint(Breakpoint const &instance)
{
	*this = instance;
}

Breakpoint::~Breakpoint(void)
{
	
}

Breakpoint &	Breakpoint::operator=(Breakpoint const &rhs)
{
	static_cast<void>(rhs);
	return *this;
}

std::string	Breakpoint::getHelp(void)
{
	return (_name + "\t\t# add a breakpoint to the current pc"\
		"\n\t" + _name + " * offset\t# add a breakpoint to offset \"offset\"");
}

std::string	Breakpoint::getShortHelp(void)
{
	return ("add a breakpoint to the current pc or at some given address");
}