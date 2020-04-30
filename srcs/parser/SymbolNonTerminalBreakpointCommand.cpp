/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalBreakpointCommand.cpp             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 16:25:25 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/30 16:25:25 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolNonTerminalBreakpointCommand.hpp"

SymbolNonTerminalBreakpointCommand::SymbolNonTerminalBreakpointCommand(void) : AbstractNonTerminal("breakpointcommand")
{
	
}

SymbolNonTerminalBreakpointCommand::~SymbolNonTerminalBreakpointCommand(void)
{
	
}

int	SymbolNonTerminalBreakpointCommand::traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	static_cast<void>(ast);
	static_cast<void>(context);
	return (0);
}

void	SymbolNonTerminalBreakpointCommand::computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg)
{
	addProduction(cfg, {"breakpoint", "assignable"});
	addProduction(cfg, {"breakpoint"});
}
