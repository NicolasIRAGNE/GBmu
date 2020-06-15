/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalSetCommand.cpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:38:32 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/15 15:11:44 by ldedier          ###   ########.fr       */
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
	DebuggerVariable *variable;
	int toAssign = ast.getChild(3)->getTraversed(context);
	
	ast.getChild(1)->getTraversed(context);
	if (context.address_descriptor.type == ADDRESS_DESCRIPTOR_TYPE_ADDRESS)
	{
		if (toAssign > 0xff)
			write_16(context.debugger->getCPU(), context.address_descriptor.address.getValue(), toAssign);
		else
			write_8(context.debugger->getCPU(), context.address_descriptor.address.getValue(), toAssign);
	}
	else
	{
		variable = context.address_descriptor.variable;
		variable->setValue(toAssign);
	}
	return (0);
}

void	SymbolNonTerminalSetCommand::computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg)
{
	addProduction(cfg, {"set", "assignable", "=", "andor"});
}
