/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalAndOr.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 15:36:19 by ldedier           #+#    #+#             */
/*   Updated: 2020/04/24 16:10:41 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolNonTerminalAndOr.hpp"

SymbolNonTerminalAndOr::SymbolNonTerminalAndOr(void) : AbstractNonTerminal("andor")
{
	
}

SymbolNonTerminalAndOr::~SymbolNonTerminalAndOr(void)
{
	
}

int	SymbolNonTerminalAndOr::traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	if (ast.getChildren().size() == 1)
		return ast.getChild(0)->getTraversed(context);
	if (ast.getChild(1)->getSymbol().getIdentifier() == "&&")
		return ast.getChild(0)->getTraversed(context) && ast.getChild(2)->getTraversed(context);
	else
		return ast.getChild(0)->getTraversed(context) || ast.getChild(2)->getTraversed(context);
}

void	SymbolNonTerminalAndOr::computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg)
{
	addProduction(cfg, {"comparison"});
	addProduction(cfg, {"andor", "&&", "comparison"});
	addProduction(cfg, {"andor", "||", "comparison"});
}
