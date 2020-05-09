/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalPrintCommandParams.cpp               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 17:37:35 by ldedier           #+#    #+#             */
/*   Updated: 2020/05/03 21:24:58 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolTerminalPrintCommandParams.hpp"
# include <string.h>

SymbolTerminalPrintCommandParams::SymbolTerminalPrintCommandParams(void) : AbstractTerminal("printcommandparams", E_PRIORITY_STANDARD, E_ADJACENT_DETACHED)
{
	
}

SymbolTerminalPrintCommandParams::~SymbolTerminalPrintCommandParams(void)
{
	
}

int	SymbolTerminalPrintCommandParams::traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	static_cast<void>(ast);
	static_cast<void>(context);
	return (0);
}



bool SymbolTerminalPrintCommandParams::staysEligibleForCurrent(std::string & current)
{
		size_t i = 1;
	if (current.length() && current[0] != '/')
		return false;
	if (i < current.length())
	{
		if (current[i] == '-')
			i++;
		while (isdigit(current[i]))
			i++;
	}
	if (current[1] == '-' && i == 2 && i < current.length())
	{
		std::cout << current << std::endl;
		return false;
	}
	if (i < current.length())
	{
		if (!current.substr(i, 2).compare("hh"))
			i+=2;
		else if (!current.substr(i, 1).compare("h"))
			i++;
	}
	if (i < current.length())
	{
		if (strchr("dxobi", current.substr(i, 1).at(0)))
			i++;
		else
			return false;
	}
	if (i < current.length())
		return false;
	return true;
}

bool SymbolTerminalPrintCommandParams::isEligibleForCurrent(std::string & current)
{
	return SymbolTerminalPrintCommandParams::staysEligibleForCurrent(current) && current.compare("/-");
}

Token<int, DebuggerContext &> *SymbolTerminalPrintCommandParams::createToken(std::string tokenContent)
{
	int precised;
	int count;
	DebuggerContext::t_debugger_format format;
	DebuggerContext::t_debugger_unit unit;
	size_t i;

	format = DebuggerContext::E_DEBUGGER_FORMAT_DECIMAL;
	unit = DebuggerContext::E_DEBUGGER_UNIT_WORD;
	count = 1;
	precised = 0;
	i = 1;
	if (i < tokenContent.length())
	{
		if (tokenContent[i] == '-')
			i++;
		while (isdigit(tokenContent[i]))
			i++;
	}
	if (i > 1)
	{
		precised |= PRECISED_COUNT;
		count = std::stoi(tokenContent.substr(1, i));
	}
	if (i < tokenContent.length())
	{
		if (!tokenContent.substr(i, 2).compare("hh"))
		{
			i+=2;
			precised |= PRECISED_UNIT;
			unit = DebuggerContext::E_DEBUGGER_UNIT_HALFWORD;

		}
		else if (!tokenContent.substr(i, 1).compare("h"))
		{
			i++;
			precised |= PRECISED_UNIT;
			unit = DebuggerContext::E_DEBUGGER_UNIT_WORD;
		}
	}
	if (i < tokenContent.length())
	{
		switch (tokenContent.substr(i, 1).at(0))
		{
			case 'd':
				format = DebuggerContext::E_DEBUGGER_FORMAT_DECIMAL;
				break;
			case 'x':
				format = DebuggerContext::E_DEBUGGER_FORMAT_HEXADECIMAL;
				break;
			case 'o':
				format = DebuggerContext::E_DEBUGGER_FORMAT_OCTAL;
				break;
			case 'b':
				format = DebuggerContext::E_DEBUGGER_FORMAT_BINARY;
				break;
			case 'i':
				format = DebuggerContext::E_DEBUGGER_FORMAT_INSTRUCTION;
				break;
			default:
				break;
		}
		precised |= PRECISED_FORMAT;
	}
	return new TokenPrintCommandSuffix(*this, tokenContent, precised, count, unit, format);
}
