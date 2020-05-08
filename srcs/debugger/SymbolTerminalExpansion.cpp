/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalExpansion.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 14:58:56 by ldedier           #+#    #+#             */
/*   Updated: 2020/05/04 21:11:34 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolTerminalExpansion.hpp"

SymbolTerminalExpansion::SymbolTerminalExpansion(void) : AbstractTerminal("expansion", E_PRIORITY_INF, E_ADJACENT_BOTH)
{
	
}

SymbolTerminalExpansion::~SymbolTerminalExpansion(void)
{
	
}

int	SymbolTerminalExpansion::traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	static_cast<void>(ast);
	static_cast<void>(context);
	return (0);
}

bool SymbolTerminalExpansion::isEligibleForCurrent(std::string & current)
{
	return SymbolTerminalExpansion::staysEligibleForCurrent(current) && current.compare("$");
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
		else if (isblank(current[i]) || current[i] == '=')
			return false;
	}
	return true;
}

Token<int, DebuggerContext &> *SymbolTerminalExpansion::createToken(std::string tokenContent)
{
	static_cast<void>(tokenContent);
	return new Token<int, DebuggerContext &>(*this, tokenContent.substr(1));
}