/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalCommand.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 03:08:44 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/17 03:08:44 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolNonTerminalCommand.hpp"

SymbolNonTerminalCommand::SymbolNonTerminalCommand(void) : AbstractNonTerminal("command")
{
	
}

SymbolNonTerminalCommand::~SymbolNonTerminalCommand(void)
{
	
}

int	SymbolNonTerminalCommand::traverse(ASTNode<int, CustomStack &> & ast, CustomStack & context) const
{
	static_cast<void>(ast);
	static_cast<void>(context);
	return (0);
}

void	SymbolNonTerminalCommand::computeProductions(AbstractGrammar<int, CustomStack &> & cfg)
{
	addProduction(cfg, 1, (std::string[]){"printcommand"});
	addProduction(cfg, 1, (std::string[]){"xcommand"});
	addProduction(cfg, 1, (std::string[]){"simplecommand"});
	addProduction(cfg, 0, nullptr);
}
