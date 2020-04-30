/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalDe.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 14:28:05 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/30 14:28:05 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolTerminalDe.hpp"

SymbolTerminalDe::SymbolTerminalDe(void) : AbstractNonTerminal("de")
{
	
}

SymbolTerminalDe::~SymbolTerminalDe(void)
{
	
}

int	SymbolTerminalDe::traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	static_cast<void>(ast);
	static_cast<void>(context);
	return (0);
}

void	SymbolTerminalDe::computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg)
{
}
