/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalTerm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:38:32 by ldedier            #+#    #+#            */
/*   Updated: 2020/05/01 16:38:32 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolNonTerminalTerm.hpp"

SymbolNonTerminalTerm::SymbolNonTerminalTerm(void) : AbstractNonTerminal("term")
{
	
}

SymbolNonTerminalTerm::~SymbolNonTerminalTerm(void)
{
	
}

int	SymbolNonTerminalTerm::traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	static_cast<void>(ast);
	static_cast<void>(context);
	return (0);
}

void	SymbolNonTerminalTerm::computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg)
{
	addProduction(cfg, {"factor"});
	addProduction(cfg, {"term", "*", "factor"});
	addProduction(cfg, {"term", "/", "factor"});
	addProduction(cfg, {"term", ">>", "factor"});
	addProduction(cfg, {"term", "<<", "factor"});
	addProduction(cfg, {"term", "|", "factor"});
	addProduction(cfg, {"term", "&", "factor"});
}
