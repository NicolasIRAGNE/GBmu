/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalUnwatchCommand.cpp                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:38:32 by ldedier            #+#    #+#            */
/*   Updated: 2020/05/01 16:38:32 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolNonTerminalUnwatchCommand.hpp"

SymbolNonTerminalUnwatchCommand::SymbolNonTerminalUnwatchCommand(void) : AbstractNonTerminal("unwatchcommand")
{
	
}

SymbolNonTerminalUnwatchCommand::~SymbolNonTerminalUnwatchCommand(void)
{
	
}

int	SymbolNonTerminalUnwatchCommand::traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	static_cast<void>(ast);
	static_cast<void>(context);
	return (0);
}

void	SymbolNonTerminalUnwatchCommand::computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg)
{
	addProduction(cfg, {"unwatch", "integerlist"});
}
