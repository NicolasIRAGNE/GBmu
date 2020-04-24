/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalFactor.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 15:36:19 by ldedier           #+#    #+#             */
/*   Updated: 2020/04/24 19:38:51 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolNonTerminalFactor.hpp"

SymbolNonTerminalFactor::SymbolNonTerminalFactor(void) : AbstractNonTerminal("factor")
{
	
}

SymbolNonTerminalFactor::~SymbolNonTerminalFactor(void)
{
	
}

int	SymbolNonTerminalFactor::traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	if (ast.getChildren().size() == 1)
		return ast.getChild(0)->getTraversed(context);
	else if (ast.getChild(1)->getSymbol().getIdentifier() == "andor")
		return ast.getChild(1)->getTraversed(context);
	else if (ast.getChild(0)->getSymbol().getIdentifier() == "-")
		return - ast.getChild(1)->getTraversed(context);
	else if (ast.getChild(0)->getSymbol().getIdentifier() == "+")
		return ast.getChild(1)->getTraversed(context);
	else if (ast.getChild(0)->getSymbol().getIdentifier() == "*")
		return ast.getChild(1)->getTraversed(context) + 0xdeadbeef; //TODO : return dereferenced getchild(1) 
	return (0);
}

void	SymbolNonTerminalFactor::computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg)
{
	addProduction(cfg, {"integer"});
	addProduction(cfg, {"(", "andor", ")"});
	addProduction(cfg, {"*", "factor"});
	addProduction(cfg, {"-", "factor"});
	addProduction(cfg, {"+", "factor"});
}
