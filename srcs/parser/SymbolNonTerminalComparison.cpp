/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalComparison.cpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 16:25:25 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/30 16:25:25 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolNonTerminalComparison.hpp"

SymbolNonTerminalComparison::SymbolNonTerminalComparison(void) : AbstractNonTerminal("comparison")
{
	
}

SymbolNonTerminalComparison::~SymbolNonTerminalComparison(void)
{
	
}

int	SymbolNonTerminalComparison::traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	static_cast<void>(ast);
	static_cast<void>(context);
	return (0);
}

void	SymbolNonTerminalComparison::computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg)
{
	addProduction(cfg, {"expr"});
	addProduction(cfg, {"comparison", ">", "expr"});
	addProduction(cfg, {"comparison", ">=", "expr"});
	addProduction(cfg, {"comparison", "<", "expr"});
	addProduction(cfg, {"comparison", "<=", "expr"});
	addProduction(cfg, {"comparison", "!=", "expr"});
	addProduction(cfg, {"comparison", "==", "expr"});
}
