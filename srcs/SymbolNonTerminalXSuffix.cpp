/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalXSuffix.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 03:08:44 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/17 03:08:44 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolNonTerminalXSuffix.hpp"

SymbolNonTerminalXSuffix::SymbolNonTerminalXSuffix(void) : AbstractNonTerminal("xsuffix")
{
	
}

SymbolNonTerminalXSuffix::~SymbolNonTerminalXSuffix(void)
{
	
}

int	SymbolNonTerminalXSuffix::traverse(ASTNode<int, CustomStack &> & ast, CustomStack & context) const
{
	static_cast<void>(ast);
	static_cast<void>(context);
	return (0);
}

void	SymbolNonTerminalXSuffix::computeProductions(AbstractGrammar<int, CustomStack &> & cfg)
{
	addProduction(cfg, 4, (std::string[]){"/", "integer", "format", "unit"});
	addProduction(cfg, 3, (std::string[]){"/", "integer", "format"});
	addProduction(cfg, 2, (std::string[]){"/", "format"});
}
