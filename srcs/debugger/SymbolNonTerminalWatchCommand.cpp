/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalWatchCommand.cpp                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:38:32 by ldedier            #+#    #+#            */
/*   Updated: 2020/05/01 16:38:32 by ldedier           ###   ########.fr      */
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
	addProduction(cfg, {"watch", "assignable", "watchmodelist"});
	addProduction(cfg, {"watch"});
}
