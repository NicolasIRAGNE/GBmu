/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalExpr.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 14:56:29 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/18 14:56:29 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolNonTerminalExpr.hpp"

SymbolNonTerminalExpr::SymbolNonTerminalExpr(void) : AbstractNonTerminal("expr")
{
	
}

SymbolNonTerminalExpr::~SymbolNonTerminalExpr(void)
{
	
}

int	SymbolNonTerminalExpr::traverse(ASTNode<int, CustomStack &> & ast, CustomStack & context) const
{
	static_cast<void>(ast);
	static_cast<void>(context);
	return (0);
}

void	SymbolNonTerminalExpr::computeProductions(AbstractGrammar<int, CustomStack &> & cfg)
{
	addProduction(cfg, {"term"});
	addProduction(cfg, {"expr", "separatorpipelineoreps", "+", "separatorpipelineoreps", "term"});
	addProduction(cfg, {"expr", "separatorpipelineoreps", "-", "separatorpipelineoreps", "term"});
}
