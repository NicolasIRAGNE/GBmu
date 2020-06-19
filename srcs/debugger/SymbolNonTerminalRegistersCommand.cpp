/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalRegistersCommand.cpp              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:38:32 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/18 22:55:16 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolNonTerminalRegistersCommand.hpp"

SymbolNonTerminalRegistersCommand::SymbolNonTerminalRegistersCommand(void) : AbstractNonTerminal("registerscommand")
{
	
}

SymbolNonTerminalRegistersCommand::~SymbolNonTerminalRegistersCommand(void)
{
	
}

int	SymbolNonTerminalRegistersCommand::traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	static_cast<void>(ast);
	context.debugger->showRegisters();
	return (0);
}

void	SymbolNonTerminalRegistersCommand::computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg)
{
	addProduction(cfg, {"registers"});
}
