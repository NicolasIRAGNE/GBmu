/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalAssignable.cpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:38:32 by ldedier           #+#    #+#             */
/*   Updated: 2020/05/29 17:07:33 by ldedier          ###   ########.fr       */
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
	// int addressOffset;

	if (ast.getChildren().size() == 2)
	{
		context.address_descriptor.type = ADDRESS_DESCRIPTOR_TYPE_INDEX;
		context.address_descriptor.index = ast.getChild(1)->getTraversed(context);
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
	addProduction(cfg, {"variable"});
	addProduction(cfg, {"*", "andor"});
}
