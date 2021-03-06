/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalTerm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:38:32 by ldedier           #+#    #+#             */
/*   Updated: 2020/05/02 19:12:46 by ldedier          ###   ########.fr       */
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
	if (ast.getChildren().size() == 1)
		return ast.getChild(0)->getTraversed(context);
	else if (ast.getChild(1)->getSymbol().getIdentifier() == "*")
		return ast.getChild(0)->getTraversed(context) * ast.getChild(2)->getTraversed(context);
	else if (ast.getChild(1)->getSymbol().getIdentifier() == "/")
		return ast.getChild(0)->getTraversed(context) / ast.getChild(2)->getTraversed(context);
	else if (ast.getChild(1)->getSymbol().getIdentifier() == ">>")
		return ast.getChild(0)->getTraversed(context) >> ast.getChild(2)->getTraversed(context);
	else if (ast.getChild(1)->getSymbol().getIdentifier() == "<<")
		return ast.getChild(0)->getTraversed(context) << ast.getChild(2)->getTraversed(context);
	else if (ast.getChild(1)->getSymbol().getIdentifier() == "|")
		return ast.getChild(0)->getTraversed(context) | ast.getChild(2)->getTraversed(context);
	else if (ast.getChild(1)->getSymbol().getIdentifier() == "&")
		return ast.getChild(0)->getTraversed(context) & ast.getChild(2)->getTraversed(context);
	return (0);
}

void	SymbolNonTerminalTerm::computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg)
{
	addProduction(cfg, {"factor"});
	addProduction(cfg, {"term", "*", "factor"});
	addProduction(cfg, {"term", "%", "factor"});
	addProduction(cfg, {"term", "/", "factor"});
	addProduction(cfg, {"term", ">>", "factor"});
	addProduction(cfg, {"term", "<<", "factor"});
	addProduction(cfg, {"term", "|", "factor"});
	addProduction(cfg, {"term", "&", "factor"});
}
