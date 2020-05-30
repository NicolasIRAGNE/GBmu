/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalFactor.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:38:32 by ldedier           #+#    #+#             */
/*   Updated: 2020/05/23 19:49:54 by ldedier          ###   ########.fr       */
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
	{
		int offset = ast.getChild(1)->getTraversed(context);
		return read_8(context.debugger->getCPU(), offset);
	}
	return (0);
}

void	SymbolNonTerminalFactor::computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg)
{
	addProduction(cfg, {"integer"});
	addProduction(cfg, {"variable"});
	addProduction(cfg, {"(", "andor", ")"});
	addProduction(cfg, {"*", "factor"});
	addProduction(cfg, {"-", "factor"});
	addProduction(cfg, {"+", "factor"});
}
