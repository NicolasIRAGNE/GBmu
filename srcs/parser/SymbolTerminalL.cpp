/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalL.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 14:28:05 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/30 14:28:05 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolTerminalL.hpp"

SymbolTerminalL::SymbolTerminalL(void) : AbstractNonTerminal("l")
{
	
}

SymbolTerminalL::~SymbolTerminalL(void)
{
	
}

int	SymbolTerminalL::traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	static_cast<void>(ast);
	static_cast<void>(context);
	return (0);
}

void	SymbolTerminalL::computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg)
{
}
