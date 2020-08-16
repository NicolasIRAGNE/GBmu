/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalAddress.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 15:21:37 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/06 15:35:21 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolNonTerminalAddress.hpp"

SymbolNonTerminalAddress::SymbolNonTerminalAddress(void) : AbstractNonTerminal("address")
{
	
}

SymbolNonTerminalAddress::~SymbolNonTerminalAddress(void)
{
	
}

int	SymbolNonTerminalAddress::traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	return  ast.getChild(1)->getTraversed(context);
}

void	SymbolNonTerminalAddress::computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg)
{
	addProduction(cfg, {"*", "andor"});
}
