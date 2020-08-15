/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalRunCommand.cpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 19:55:17 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/26 20:08:44 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolNonTerminalRunCommand.hpp"

SymbolNonTerminalRunCommand::SymbolNonTerminalRunCommand(void) : SymbolNonTerminalAbstractCommand("runcommand")
{
	
}

SymbolNonTerminalRunCommand::~SymbolNonTerminalRunCommand(void)
{
	
}

void	SymbolNonTerminalRunCommand::computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg)
{
	addProduction(cfg, {"run"});
}
