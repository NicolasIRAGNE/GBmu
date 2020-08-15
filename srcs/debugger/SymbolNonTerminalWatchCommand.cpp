/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalWatchCommand.cpp                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:38:32 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/26 20:09:04 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolNonTerminalWatchCommand.hpp"
# include "WatchModes.hpp"
# include "DebuggerVariableAddress.hpp"
# include "libyacc_wrapper.h"

SymbolNonTerminalWatchCommand::SymbolNonTerminalWatchCommand(void) : SymbolNonTerminalAbstractCommand("watchcommand")
{
	
}

SymbolNonTerminalWatchCommand::~SymbolNonTerminalWatchCommand(void)
{
	
}

void	SymbolNonTerminalWatchCommand::computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg)
{
	addProduction(cfg, {"watch", "watchmodes", "assignable"});
	addProduction(cfg, {"watch", "assignable"});
}
