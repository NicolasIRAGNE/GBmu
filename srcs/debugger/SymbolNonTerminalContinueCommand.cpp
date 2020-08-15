/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalContinueCommand.cpp               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 19:55:17 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/26 20:09:36 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolNonTerminalContinueCommand.hpp"

SymbolNonTerminalContinueCommand::SymbolNonTerminalContinueCommand(void) : SymbolNonTerminalAbstractCommand("continuecommand")
{
	
}

SymbolNonTerminalContinueCommand::~SymbolNonTerminalContinueCommand(void)
{
	
}

void	SymbolNonTerminalContinueCommand::computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg)
{
	addProduction(cfg, {"continue"});
}
