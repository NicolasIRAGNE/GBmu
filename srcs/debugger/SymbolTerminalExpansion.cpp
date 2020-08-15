/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalExpansion.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 14:58:56 by ldedier           #+#    #+#             */
/*   Updated: 2020/05/31 18:32:35 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolTerminalExpansion.hpp"
# include <string.h>

SymbolTerminalExpansion::SymbolTerminalExpansion(void) : AbstractTerminal("expansion", E_PRIORITY_INF, E_ADJACENT_BOTH)
{
	
}

SymbolTerminalExpansion::~SymbolTerminalExpansion(void)
{
	
}

bool is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

int	SymbolTerminalExpansion::traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	std::map<std::string, DebuggerVariable *>::iterator	it;
	int													nb;
	
	nb = -1;
	if (ast.getToken()->getStringValue().empty() || is_number(ast.getToken()->getStringValue()))
	{
		if (ast.getToken()->getStringValue().empty())
		{
			nb = context.debugger->getHistoryCounter();
			context.address_descriptor.variable = &context.debugger->getHistoryVariable(nb);
			return context.address_descriptor.variable->getValue();
		}
		else
		{
			try
			{
				nb = std::stoi(ast.getToken()->getStringValue());
				context.address_descriptor.variable = &context.debugger->getHistoryVariable(nb);
				return context.address_descriptor.variable->getValue();
			}
			catch (std::out_of_range &e)
			{
				context.address_descriptor.variable = context.debugger->getVariable(ast.getToken()->getStringValue());
				return context.address_descriptor.variable->getValue();
			}
		}
	}
	else
	{
		context.address_descriptor.variable = context.debugger->getVariable(ast.getToken()->getStringValue());
		return context.address_descriptor.variable->getValue();
	}
}

bool SymbolTerminalExpansion::isEligibleForCurrent(std::string & current)
{
	return SymbolTerminalExpansion::staysEligibleForCurrent(current);
}

bool SymbolTerminalExpansion::staysEligibleForCurrent(std::string & current)
{
	for (int i = 0; static_cast<size_t>(i) < current.length() ; i++)
	{
		if (i == 0)
		{
			if (current[i] != '$')
				return false;
		}
		else if (isblank(current[i]) || strchr("=+-<>*/", current[i]))
			return false;
	}
	return true;
}

Token<int, DebuggerContext &> *SymbolTerminalExpansion::createToken(std::string tokenContent)
{
	static_cast<void>(tokenContent);
	return new Token<int, DebuggerContext &>(*this, tokenContent.substr(1));
}
