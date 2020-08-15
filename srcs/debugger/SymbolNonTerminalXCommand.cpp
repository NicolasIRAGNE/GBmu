/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalXCommand.cpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:38:32 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/26 20:09:09 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolNonTerminalXCommand.hpp"
# include <iomanip>

SymbolNonTerminalXCommand::SymbolNonTerminalXCommand(void) : SymbolNonTerminalAbstractCommand("xcommand")
{
	
}

SymbolNonTerminalXCommand::~SymbolNonTerminalXCommand(void)
{
	
}

void	SymbolNonTerminalXCommand::computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg)
{
	addProduction(cfg, {"x", "printcommandsuffix"});
}
