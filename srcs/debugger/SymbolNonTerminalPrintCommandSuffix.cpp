/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalPrintCommandSuffix.cpp            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 17:37:35 by ldedier           #+#    #+#             */
/*   Updated: 2020/05/14 19:27:43 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolNonTerminalPrintCommandSuffix.hpp"

SymbolNonTerminalPrintCommandSuffix::SymbolNonTerminalPrintCommandSuffix(void) : AbstractNonTerminal("printcommandsuffix")
{
	
}

SymbolNonTerminalPrintCommandSuffix::~SymbolNonTerminalPrintCommandSuffix(void)
{
	
}

int	SymbolNonTerminalPrintCommandSuffix::traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	static_cast<void>(ast);
	static_cast<void>(context);

	if (ast.getChildren().size() == 2)
	{
		ast.getChild(0)->getTraversed(context);
		return ast.getChild(1)->getTraversed(context);
	}
	if (ast.getChildren().size() == 1)
		return ast.getChild(0)->getTraversed(context);
	return (0);
}

void	SymbolNonTerminalPrintCommandSuffix::computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg)
{
	addProduction(cfg, {"printcommandparams", "value"});
	addProduction(cfg, {"value"});
}
