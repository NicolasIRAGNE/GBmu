/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalDeleteCommand.cpp                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 15:59:19 by ldedier            #+#    #+#            */
/*   Updated: 2020/06/15 15:59:19 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolNonTerminalDeleteCommand.hpp"

SymbolNonTerminalDeleteCommand::SymbolNonTerminalDeleteCommand(void) : AbstractNonTerminal("deletecommand")
{
	
}

SymbolNonTerminalDeleteCommand::~SymbolNonTerminalDeleteCommand(void)
{
	
}

int	SymbolNonTerminalDeleteCommand::traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	static_cast<void>(ast);
	static_cast<void>(context);
	return (0);
}

void	SymbolNonTerminalDeleteCommand::computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg)
{
	addProduction(cfg, {"delete", "integerlist"});
	addProduction(cfg, {"delete"});
}
