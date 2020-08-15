/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalQuitCommand.cpp                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:38:32 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/26 20:08:39 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolNonTerminalQuitCommand.hpp"

SymbolNonTerminalQuitCommand::SymbolNonTerminalQuitCommand(void) : SymbolNonTerminalAbstractCommand("quitcommand")
{
	
}

SymbolNonTerminalQuitCommand::~SymbolNonTerminalQuitCommand(void)
{
	
}

void	SymbolNonTerminalQuitCommand::computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg)
{
	addProduction(cfg, {"quit"});
}
