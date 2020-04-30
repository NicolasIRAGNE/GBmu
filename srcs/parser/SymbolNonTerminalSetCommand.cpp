/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalSetCommand.cpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 14:52:38 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/30 14:52:38 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolNonTerminalSetCommand.hpp"

SymbolNonTerminalSetCommand::SymbolNonTerminalSetCommand(void) : AbstractNonTerminal("setcommand")
{
	
}

SymbolNonTerminalSetCommand::~SymbolNonTerminalSetCommand(void)
{
	
}

int	SymbolNonTerminalSetCommand::traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	static_cast<void>(ast);
	static_cast<void>(context);
	return (0);
}

void	SymbolNonTerminalSetCommand::computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg)
{
	addProduction(cfg, {"set", "assignable", "=", "andor"});
	addProduction(cfg, {"set", "assignable", "andor"});
}
