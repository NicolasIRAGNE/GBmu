/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalSimpleCommand.cpp                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 16:30:57 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/18 16:30:57 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolNonTerminalSimpleCommand.hpp"

SymbolNonTerminalSimpleCommand::SymbolNonTerminalSimpleCommand(void) : AbstractNonTerminal("simplecommand")
{
	
}

SymbolNonTerminalSimpleCommand::~SymbolNonTerminalSimpleCommand(void)
{
	
}

int	SymbolNonTerminalSimpleCommand::traverse(ASTNode<int, CustomStack &> & ast, CustomStack & context) const
{
	static_cast<void>(ast);
	static_cast<void>(context);
	return (0);
}

void	SymbolNonTerminalSimpleCommand::computeProductions(AbstractGrammar<int, CustomStack &> & cfg)
{
	addProduction(cfg, {"commandname"});
	addProduction(cfg, {"commandname", "commandsuffix"});
}
