/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalCommandSuffix.cpp                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 14:56:29 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/18 14:56:29 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolNonTerminalCommandSuffix.hpp"

SymbolNonTerminalCommandSuffix::SymbolNonTerminalCommandSuffix(void) : AbstractNonTerminal("commandsuffix")
{
	
}

SymbolNonTerminalCommandSuffix::~SymbolNonTerminalCommandSuffix(void)
{
	
}

int	SymbolNonTerminalCommandSuffix::traverse(ASTNode<int, CustomStack &> & ast, CustomStack & context) const
{
	static_cast<void>(ast);
	static_cast<void>(context);
	return (0);
}

void	SymbolNonTerminalCommandSuffix::computeProductions(AbstractGrammar<int, CustomStack &> & cfg)
{
	addProduction(cfg, {"variable", "commandsuffix", "separatorpipeline"});
	addProduction(cfg, {"variable"});
}
