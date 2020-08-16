/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalSetCommand.cpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:38:32 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/26 20:08:47 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolNonTerminalSetCommand.hpp"

SymbolNonTerminalSetCommand::SymbolNonTerminalSetCommand(void) : SymbolNonTerminalAbstractCommand("setcommand")
{
	
}

SymbolNonTerminalSetCommand::~SymbolNonTerminalSetCommand(void)
{
	
}


void	SymbolNonTerminalSetCommand::computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg)
{
	addProduction(cfg, {"set", "assignable", "=", "andor"});
}
