/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalCommand.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:38:32 by ldedier           #+#    #+#             */
/*   Updated: 2020/05/30 17:47:22 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolNonTerminalCommand.hpp"
# include "libyacc_wrapper.h"

SymbolNonTerminalCommand::SymbolNonTerminalCommand(void) : AbstractNonTerminal("command")
{
	
}

SymbolNonTerminalCommand::~SymbolNonTerminalCommand(void)
{
	
}

int	SymbolNonTerminalCommand::traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	if (ast.getChildren().size())
		return (ast.getChild(0)->getTraversed(context));
	else if (!context.debugger->getLastCommand().empty())
	{
		context.shouldSaveAsLastCommand = false;
		return libyacc_execute(context.debugger->getCPU(), context.debugger->getLastCommand().c_str(), 0);
	}
	return 0;
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
