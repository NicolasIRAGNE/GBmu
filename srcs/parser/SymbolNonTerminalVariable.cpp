/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalVariable.cpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 14:52:38 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/30 14:52:38 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolNonTerminalVariable.hpp"

SymbolNonTerminalVariable::SymbolNonTerminalVariable(void) : AbstractNonTerminal("variable")
{
	
}

SymbolNonTerminalVariable::~SymbolNonTerminalVariable(void)
{
	
}

int	SymbolNonTerminalVariable::traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	static_cast<void>(ast);
	static_cast<void>(context);
	return (0);
}

void	SymbolNonTerminalVariable::computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg)
{
	addProduction(cfg, {"registername"});
	addProduction(cfg, {"ioport"});
	addProduction(cfg, {"vector"});
}
