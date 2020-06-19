/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalHelpCommand.cpp                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:38:32 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/19 16:59:58 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolNonTerminalHelpCommand.hpp"

SymbolNonTerminalHelpCommand::SymbolNonTerminalHelpCommand(void) : AbstractNonTerminal("helpcommand")
{
	
}

SymbolNonTerminalHelpCommand::~SymbolNonTerminalHelpCommand(void)
{
	
}

int	SymbolNonTerminalHelpCommand::traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	if (ast.getChildren().size() == 1)
		context.debugger->showHelp();
	else
		context.debugger->showHelpCommand(ast.getChild(1)->getChild(0)->getSymbol().getIdentifier());
	return (0);
}

void	SymbolNonTerminalHelpCommand::computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg)
{
	addProduction(cfg, {"help"});
	addProduction(cfg, {"help", "commandname"});
}
