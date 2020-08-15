/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StandardBreakpoint.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 17:57:41 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/30 00:45:26 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "StandardBreakpoint.hpp"

StandardBreakpoint::StandardBreakpoint(void) : AbstractBreakpoint(BREAKPOINT_COMMAND, "standard")
{
	
}

StandardBreakpoint::StandardBreakpoint(StandardBreakpoint const &instance)
{
	*this = instance;
}

StandardBreakpoint::~StandardBreakpoint(void)
{
	
}

StandardBreakpoint &	StandardBreakpoint::operator=(StandardBreakpoint const &rhs)
{
	static_cast<void>(rhs);
	return *this;
}

int	StandardBreakpoint::addBreakpointToDebugger(Debugger *debugger, uint16_t address) const
{
	debugger->addBreakpointValuesList(address);
	return 0;
}

