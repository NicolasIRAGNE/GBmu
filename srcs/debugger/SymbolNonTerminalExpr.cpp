/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalExpr.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:38:32 by ldedier           #+#    #+#             */
/*   Updated: 2020/05/02 19:12:32 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolNonTerminalExpr.hpp"

SymbolNonTerminalExpr::SymbolNonTerminalExpr(void) : AbstractNonTerminal("expr")
{
	
}

SymbolNonTerminalExpr::~SymbolNonTerminalExpr(void)
{
	
}

int	SymbolNonTerminalExpr::traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	if (ast.getChildren().size() == 1)
		return ast.getChild(0)->getTraversed(context);
	else if (ast.getChild(1)->getSymbol().getIdentifier() == "+")
		return ast.getChild(0)->getTraversed(context) + ast.getChild(2)->getTraversed(context);
	else //if (ast.getChild(1)->getSymbol().getIdentifier() == "-")
		return ast.getChild(0)->getTraversed(context) - ast.getChild(2)->getTraversed(context);
}

void	SymbolNonTerminalExpr::computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg)
{
	addProduction(cfg, {"term"});
	addProduction(cfg, {"expr", "+", "term"});
	addProduction(cfg, {"expr", "-", "term"});
}
