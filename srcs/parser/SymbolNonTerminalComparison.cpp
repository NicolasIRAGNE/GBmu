/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalComparison.cpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 15:36:19 by ldedier           #+#    #+#             */
/*   Updated: 2020/04/24 16:37:55 by ldedier          ###   ########.fr       */
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
	if (ast.getChildren().size() == 1)
		return ast.getChild(0)->getTraversed(context);
	else if (ast.getChild(1)->getSymbol().getIdentifier() == ">")
		return ast.getChild(0)->getTraversed(context) > ast.getChild(2)->getTraversed(context);
	else if (ast.getChild(1)->getSymbol().getIdentifier() == ">=")
		return ast.getChild(0)->getTraversed(context) >= ast.getChild(2)->getTraversed(context);
	else if (ast.getChild(1)->getSymbol().getIdentifier() == "<")
		return ast.getChild(0)->getTraversed(context) < ast.getChild(2)->getTraversed(context);
	else if (ast.getChild(1)->getSymbol().getIdentifier() == "<=")
		return ast.getChild(0)->getTraversed(context) >= ast.getChild(2)->getTraversed(context);
	else if (ast.getChild(1)->getSymbol().getIdentifier() == "!=")
		return ast.getChild(0)->getTraversed(context) != ast.getChild(2)->getTraversed(context);
	else //if (ast.getChild(1)->getSymbol().getIdentifier() == "==")
		return ast.getChild(0)->getTraversed(context) == ast.getChild(2)->getTraversed(context);
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
