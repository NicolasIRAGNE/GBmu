/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalCommand.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:38:32 by ldedier           #+#    #+#             */
/*   Updated: 2020/05/02 19:12:24 by ldedier          ###   ########.fr       */
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
	addProduction(cfg, {"helpcommand"});
	addProduction(cfg, {"nextcommand"});
	addProduction(cfg, {"breakpointcommand"});
	addProduction(cfg, {"watchcommand"});
	addProduction(cfg, {"unwatchcommand"});
	addProduction(cfg, {"deletecommand"});
	addProduction(cfg, {"infocommand"});
	addProduction(cfg, {"setcommand"});
	addProduction(cfg, {"registerscommand"});
	addProduction(cfg, {"quitcommand"});
	addProduction(cfg, {"verbosecommand"});
	addProduction(cfg, {});
}