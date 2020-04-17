/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalFactor.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 03:08:44 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/17 03:08:44 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolNonTerminalFactor.hpp"

SymbolNonTerminalFactor::SymbolNonTerminalFactor(void) : AbstractNonTerminal("factor")
{
	
}

SymbolNonTerminalFactor::~SymbolNonTerminalFactor(void)
{
	
}

int	SymbolNonTerminalFactor::traverse(ASTNode<int, CustomStack &> & ast, CustomStack & context) const
{
	static_cast<void>(ast);
	static_cast<void>(context);
	return (0);
}

void	SymbolNonTerminalFactor::computeProductions(AbstractGrammar<int, CustomStack &> & cfg)
{
	addProduction(cfg, 1, (std::string[]){"integer"});
	addProduction(cfg, 2, (std::string[]){"-", "factor"});
	addProduction(cfg, 2, (std::string[]){"+", "factor"});
}
