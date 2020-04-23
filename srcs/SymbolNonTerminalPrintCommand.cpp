/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalPrintCommand.cpp                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 16:30:57 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/18 16:30:57 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolNonTerminalPrintCommand.hpp"

SymbolNonTerminalPrintCommand::SymbolNonTerminalPrintCommand(void) : AbstractNonTerminal("printcommand")
{
	
}

SymbolNonTerminalPrintCommand::~SymbolNonTerminalPrintCommand(void)
{
	
}

int	SymbolNonTerminalPrintCommand::traverse(ASTNode<int, CustomStack &> & ast, CustomStack & context) const
{
	static_cast<void>(ast);
	static_cast<void>(context);
	return (0);
}

void	SymbolNonTerminalPrintCommand::computeProductions(AbstractGrammar<int, CustomStack &> & cfg)
{
	addProduction(cfg, {"print", "value"});
	addProduction(cfg, {"print", "/", "format", "value"});
}
