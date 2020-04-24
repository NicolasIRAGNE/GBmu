/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalCommand.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 15:36:19 by ldedier           #+#    #+#             */
/*   Updated: 2020/04/24 16:12:10 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolNonTerminalCommand.hpp"

SymbolNonTerminalCommand::SymbolNonTerminalCommand(void) : AbstractNonTerminal("command")
{
	
}

SymbolNonTerminalCommand::~SymbolNonTerminalCommand(void)
{
	
}

int	SymbolNonTerminalCommand::traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	return (ast.getChild(0)->getTraversed(context));
}

void	SymbolNonTerminalCommand::computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg)
{
	addProduction(cfg, {"printcommand"});
	addProduction(cfg, {"xcommand"});
	addProduction(cfg, {"stepcommand"});
	addProduction(cfg, {"nextcommand"});
	addProduction(cfg, {"breakpointcommand"});
	addProduction(cfg, {"deletecommand"});
	addProduction(cfg, {"infocommand"});
	addProduction(cfg, {"registerscommand"});
	addProduction(cfg, {"quitcommand"});
	addProduction(cfg, {"verbosecommand"});
	addProduction(cfg, {});
}
