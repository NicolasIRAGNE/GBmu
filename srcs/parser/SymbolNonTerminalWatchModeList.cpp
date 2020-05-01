/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalWatchModeList.cpp                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:38:32 by ldedier            #+#    #+#            */
/*   Updated: 2020/05/01 16:38:32 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolNonTerminalWatchModeList.hpp"

SymbolNonTerminalWatchModeList::SymbolNonTerminalWatchModeList(void) : AbstractNonTerminal("watchmodelist")
{
	
}

SymbolNonTerminalWatchModeList::~SymbolNonTerminalWatchModeList(void)
{
	
}

int	SymbolNonTerminalWatchModeList::traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	static_cast<void>(ast);
	static_cast<void>(context);
	return (0);
}

void	SymbolNonTerminalWatchModeList::computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg)
{
	addProduction(cfg, {"watchmode"});
	addProduction(cfg, {"watchmodelist", "watchmode"});
}
