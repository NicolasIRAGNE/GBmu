/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalStartCommand.cpp                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 16:09:29 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/26 20:08:50 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolNonTerminalStartCommand.hpp"

SymbolNonTerminalStartCommand::SymbolNonTerminalStartCommand(void) : SymbolNonTerminalAbstractCommand("startcommand")
{
	
}

SymbolNonTerminalStartCommand::~SymbolNonTerminalStartCommand(void)
{
	
}

void	SymbolNonTerminalStartCommand::computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg)
{
	addProduction(cfg, {"start"});
}
