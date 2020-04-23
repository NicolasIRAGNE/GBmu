/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalAndOr.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 16:30:57 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/18 16:30:57 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolNonTerminalAndOr.hpp"

SymbolNonTerminalAndOr::SymbolNonTerminalAndOr(void) : AbstractNonTerminal("andor")
{
	
}

SymbolNonTerminalAndOr::~SymbolNonTerminalAndOr(void)
{
	
}

int	SymbolNonTerminalAndOr::traverse(ASTNode<int, CustomStack &> & ast, CustomStack & context) const
{
	static_cast<void>(ast);
	static_cast<void>(context);
	return (0);
}

void	SymbolNonTerminalAndOr::computeProductions(AbstractGrammar<int, CustomStack &> & cfg)
{
	addProduction(cfg, {"comparison"});
	addProduction(cfg, {"andor", "&&", "comparison"});
	addProduction(cfg, {"andor", "||", "comparison"});
}
