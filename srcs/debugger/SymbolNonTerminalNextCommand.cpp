/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalNextCommand.cpp                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:38:32 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/26 20:07:53 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolNonTerminalNextCommand.hpp"

SymbolNonTerminalNextCommand::SymbolNonTerminalNextCommand(void) : SymbolNonTerminalAbstractCommand("nextcommand")
{
	
}

SymbolNonTerminalNextCommand::~SymbolNonTerminalNextCommand(void)
{
	
}

void	SymbolNonTerminalNextCommand::computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg)
{
	addProduction(cfg, {"next"});
}
