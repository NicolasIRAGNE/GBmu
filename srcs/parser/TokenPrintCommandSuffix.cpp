/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TokenPrintCommandSuffix.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 17:51:50 by ldedier           #+#    #+#             */
/*   Updated: 2020/05/03 21:37:41 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "TokenPrintCommandSuffix.hpp"



TokenPrintCommandSuffix::TokenPrintCommandSuffix(void) : Token()
{

}

TokenPrintCommandSuffix::TokenPrintCommandSuffix(AbstractTerminal<int, DebuggerContext &> &term, std::string content) : Token(term, content)
{

}

TokenPrintCommandSuffix::~TokenPrintCommandSuffix(void)
{


}

TokenPrintCommandSuffix::TokenPrintCommandSuffix(AbstractTerminal<int, DebuggerContext &> &term
	, std::string content
	, int precised
	, int count
	, DebuggerContext::t_debugger_unit unit
	, DebuggerContext::t_debugger_format format) : Token(term, content), _precised(precised), _count(count), _unit(unit), _format(format)
{
	
}

DebuggerContext::t_debugger_unit TokenPrintCommandSuffix::getUnit()
{
	return _unit;
}

DebuggerContext::t_debugger_format TokenPrintCommandSuffix::getFormat()
{
	return _format;
}

int TokenPrintCommandSuffix::getPrecised()
{
	return _precised;
}

int TokenPrintCommandSuffix::getCount()
{
	return _count;
}

std::ostream &TokenPrintCommandSuffix::repr(std::ostream &o)
{
	o << YACC_YELLOW << " (";
	if (_precised & PRECISED_COUNT)
	{
		o << YACC_GREEN << "count: " << YACC_YELLOW << _count;
	}
	if (_precised & PRECISED_UNIT)
	{
		if (_precised & PRECISED_COUNT)
			o << " | ";
		o << YACC_GREEN << "unit: " << YACC_YELLOW << DebuggerContext::getUnitString(_unit);
	}
	if (_precised & PRECISED_FORMAT)
	{
		if (_precised & PRECISED_COUNT || _precised & PRECISED_UNIT)
			o << " | ";
		o << YACC_GREEN << "format: " << YACC_YELLOW << DebuggerContext::getFormatChar(_format);
	}
	if (_precised == 0)
	{
		o << "default";
	}
	o << ") " << YACC_EOC;
	return o;
}
