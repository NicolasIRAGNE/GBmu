/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalWatchCommand.cpp                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 14:52:38 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/30 14:52:38 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolNonTerminalWatchCommand.hpp"

SymbolNonTerminalWatchCommand::SymbolNonTerminalWatchCommand(void) : AbstractNonTerminal("watchcommand")
{
	
}

SymbolNonTerminalWatchCommand::~SymbolNonTerminalWatchCommand(void)
{
	
}

int	SymbolNonTerminalWatchCommand::traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	static_cast<void>(ast);
	static_cast<void>(context);
	return (0);
}

void	SymbolNonTerminalWatchCommand::computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg)
{
	addProduction(cfg, {"watch", "assignablelist", "watchmode"});
	addProduction(cfg, {"watch", "assignablelist"});
	addProduction(cfg, {"watch"});
}
