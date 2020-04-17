/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalUnit.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 03:08:44 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/17 03:08:44 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolNonTerminalUnit.hpp"

SymbolNonTerminalUnit::SymbolNonTerminalUnit(void) : AbstractNonTerminal("unit")
{
	
}

SymbolNonTerminalUnit::~SymbolNonTerminalUnit(void)
{
	
}

int	SymbolNonTerminalUnit::traverse(ASTNode<int, CustomStack &> & ast, CustomStack & context) const
{
	static_cast<void>(ast);
	static_cast<void>(context);
	return (0);
}

void	SymbolNonTerminalUnit::computeProductions(AbstractGrammar<int, CustomStack &> & cfg)
{
	addProduction(cfg, 1, (std::string[]){"hh"});
	addProduction(cfg, 1, (std::string[]){"h"});
}
