/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalAssignableList.cpp                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 15:36:21 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/30 15:36:21 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolNonTerminalAssignableList.hpp"

SymbolNonTerminalAssignableList::SymbolNonTerminalAssignableList(void) : AbstractNonTerminal("assignablelist")
{
	
}

SymbolNonTerminalAssignableList::~SymbolNonTerminalAssignableList(void)
{
	
}

int	SymbolNonTerminalAssignableList::traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	static_cast<void>(ast);
	static_cast<void>(context);
	return (0);
}

void	SymbolNonTerminalAssignableList::computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg)
{
	addProduction(cfg, {"assignable"});
	addProduction(cfg, {"assignablelist", "assignable"});
}
