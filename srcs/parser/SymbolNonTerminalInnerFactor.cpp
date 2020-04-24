/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalInnerFactor.cpp                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 18:56:50 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/24 18:56:50 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolNonTerminalInnerFactor.hpp"

SymbolNonTerminalInnerFactor::SymbolNonTerminalInnerFactor(void) : AbstractNonTerminal("innerfactor")
{
	
}

SymbolNonTerminalInnerFactor::~SymbolNonTerminalInnerFactor(void)
{
	
}

int	SymbolNonTerminalInnerFactor::traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	static_cast<void>(ast);
	static_cast<void>(context);
	return (0);
}

void	SymbolNonTerminalInnerFactor::computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg)
{
	addProduction(cfg, {"integer"});
	addProduction(cfg, {"(", "andor", ")"});
}
