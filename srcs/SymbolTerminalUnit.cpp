/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalUnit.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 20:53:16 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/16 20:53:16 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolTerminalUnit.hpp"

SymbolTerminalUnit::SymbolTerminalUnit(void) : AbstractNonTerminal("unit")
{
	
}

SymbolTerminalUnit::~SymbolTerminalUnit(void)
{
	
}

int	SymbolTerminalUnit::traverse(ASTNode<int, CustomStack &> & ast, CustomStack & context) const
{
	static_cast<void>(ast);
	static_cast<void>(context);
	return (0);
}

void	SymbolTerminalUnit::computeProductions(AbstractGrammar<int, CustomStack &> & cfg)
{
}
