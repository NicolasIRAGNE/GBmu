/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalPc.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 14:28:05 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/30 14:28:05 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolTerminalPc.hpp"

SymbolTerminalPc::SymbolTerminalPc(void) : AbstractNonTerminal("pc")
{
	
}

SymbolTerminalPc::~SymbolTerminalPc(void)
{
	
}

int	SymbolTerminalPc::traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	static_cast<void>(ast);
	static_cast<void>(context);
	return (0);
}

void	SymbolTerminalPc::computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg)
{
}
