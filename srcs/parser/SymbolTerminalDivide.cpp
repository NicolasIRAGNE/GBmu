/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalDivide.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:38:32 by ldedier           #+#    #+#             */
/*   Updated: 2020/05/03 19:09:21 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolTerminalDivide.hpp"

SymbolTerminalDivide::SymbolTerminalDivide(void) : AbstractTerminal("/")
{
	
}

SymbolTerminalDivide::~SymbolTerminalDivide(void)
{
	
}

int	SymbolTerminalDivide::traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	static_cast<void>(ast);
	static_cast<void>(context);
	return (0);
}

bool SymbolTerminalDivide::canBeAdded(std::deque<Token<int, DebuggerContext &> *>	& res)
{
	return res.size() > 1;
}