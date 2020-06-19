/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalDeleteCommand.cpp                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 15:59:19 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/18 22:39:08 by ldedier          ###   ########.fr       */
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
	if (ast.getChildren().size() == 1)
		context.debugger->removeAllBreakpoints();
	else
	{
		for (auto & elt : ast.getChild(1)->getChildren())
		{
			context.debugger->deleteValue(elt->getToken()->getIntValue());
		}
	}
	return (0);
}

void	SymbolNonTerminalDeleteCommand::computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg)
{
	addProduction(cfg, {"delete", "integerlist"});
	addProduction(cfg, {"delete"});
}
