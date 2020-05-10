/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DebuggerContext.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:38:32 by ldedier           #+#    #+#             */
/*   Updated: 2020/05/10 19:06:43 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DebuggerContext.hpp"

DebuggerContext::DebuggerContext(void) 
{
	
}

DebuggerContext::DebuggerContext(struct gb_cpu_s *cpu) : cpu(cpu)
{

}

DebuggerContext::DebuggerContext(DebuggerContext const &instance)
{
	*this = instance;
}

DebuggerContext::~DebuggerContext(void)
{
	
}

std::string DebuggerContext::getUnitString(t_debugger_unit unit)
{
	if (unit == E_DEBUGGER_UNIT_WORD)
		return "h";
	else
		return "hh";
}

char DebuggerContext::getFormatChar(t_debugger_format format)
{
	if (format == E_DEBUGGER_FORMAT_DECIMAL)
		return 'd';
	else if (format == E_DEBUGGER_FORMAT_HEXADECIMAL)
		return 'x';
	else if (format == E_DEBUGGER_FORMAT_OCTAL)
		return 'o';
	else if (format == E_DEBUGGER_FORMAT_BINARY)
		return 'b';
	else
		return 'i';
}

DebuggerContext & DebuggerContext::operator=(DebuggerContext const &rhs)
{
	static_cast<void>(rhs);
	return *this;
}
