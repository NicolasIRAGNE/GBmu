/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TemporaryBreakpoint.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 18:09:00 by ldedier           #+#    #+#             */
/*   Updated: 2021/06/04 13:07:10 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TemporaryBreakpoint.hpp"

TemporaryBreakpoint::TemporaryBreakpoint(void) : AbstractBreakpoint(TBREAKPOINT_COMMAND, "temporary")
{
	
}

TemporaryBreakpoint::TemporaryBreakpoint(TemporaryBreakpoint const &instance) : AbstractBreakpoint(instance)
{
	*this = instance;
}

TemporaryBreakpoint::~TemporaryBreakpoint(void)
{
	
}

TemporaryBreakpoint &	TemporaryBreakpoint::operator=(TemporaryBreakpoint const &rhs)
{
	static_cast<void>(rhs);
	return *this;
}

int	TemporaryBreakpoint::addBreakpointToDebugger(Debugger *debugger, uint16_t address) const
{
	debugger->addTemporaryBreakpointValuesList(address);
	return 0;
}
