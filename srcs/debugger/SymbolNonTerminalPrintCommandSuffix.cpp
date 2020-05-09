/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalPrintCommandSuffix.cpp            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 17:37:35 by ldedier           #+#    #+#             */
/*   Updated: 2020/05/03 17:40:45 by ldedier          ###   ########.fr       */
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
	return (0);
}

void	SymbolNonTerminalPrintCommandSuffix::computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg)
{
	addProduction(cfg, {"printcommandparams", "value"});
	addProduction(cfg, {"value"});
}
