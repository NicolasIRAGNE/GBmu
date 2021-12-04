/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalAbstractCommand.cpp               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 19:55:17 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/27 16:27:44 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolNonTerminalAbstractCommand.hpp"

SymbolNonTerminalAbstractCommand::SymbolNonTerminalAbstractCommand(std::string identifier) : AbstractNonTerminal(identifier)
{
	
}


SymbolNonTerminalAbstractCommand::SymbolNonTerminalAbstractCommand(void) : AbstractNonTerminal()
{
	
}

SymbolNonTerminalAbstractCommand::~SymbolNonTerminalAbstractCommand(void)
{
	
}

int SymbolNonTerminalAbstractCommand::traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	return context.debugger->executeCommand(ast.getChild(0)->getSymbol().getIdentifier(), ast, context);
}