/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalAssignable.cpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:38:32 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/15 15:01:43 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolNonTerminalAssignable.hpp"

SymbolNonTerminalAssignable::SymbolNonTerminalAssignable(void) : AbstractNonTerminal("assignable")
{
	
}

SymbolNonTerminalAssignable::~SymbolNonTerminalAssignable(void)
{
	
}

int	SymbolNonTerminalAssignable::traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	if (ast.getChild(0)->getSymbol().getIdentifier() == "address")
	{
		context.address_descriptor.type = ADDRESS_DESCRIPTOR_TYPE_ADDRESS;
		context.address_descriptor.address = DebuggerAddress(ast.getChild(0)->getTraversed(context));
	}
	else
	{
		context.address_descriptor.type = ADDRESS_DESCRIPTOR_TYPE_VARIABLE;
		ast.getChild(0)->getTraversed(context);
	}
	return (0);
}

void	SymbolNonTerminalAssignable::computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg)
{
	addProduction(cfg, {"expansion"});
	addProduction(cfg, {"address"});
}
