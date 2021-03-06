/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalXCommand.cpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:38:32 by ldedier           #+#    #+#             */
/*   Updated: 2020/05/03 18:29:22 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolNonTerminalXCommand.hpp"

SymbolNonTerminalXCommand::SymbolNonTerminalXCommand(void) : AbstractNonTerminal("xcommand")
{
	
}

SymbolNonTerminalXCommand::~SymbolNonTerminalXCommand(void)
{
	
}

int	SymbolNonTerminalXCommand::traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	static_cast<void>(ast);
	static_cast<void>(context);
	return (0);
}

void	SymbolNonTerminalXCommand::computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg)
{
	addProduction(cfg, {"x", "printcommandsuffix"});
}
