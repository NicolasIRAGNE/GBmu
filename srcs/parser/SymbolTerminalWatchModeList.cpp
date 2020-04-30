/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalWatchModeList.cpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 14:32:07 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/30 14:32:07 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolTerminalWatchModeList.hpp"

SymbolTerminalWatchModeList::SymbolTerminalWatchModeList(void) : AbstractNonTerminal("watchmodelist")
{
	
}

SymbolTerminalWatchModeList::~SymbolTerminalWatchModeList(void)
{
	
}

int	SymbolTerminalWatchModeList::traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	static_cast<void>(ast);
	static_cast<void>(context);
	return (0);
}

void	SymbolTerminalWatchModeList::computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg)
{
}
