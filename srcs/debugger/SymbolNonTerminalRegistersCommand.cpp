/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalRegistersCommand.cpp              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:38:32 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/26 20:08:42 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolNonTerminalRegistersCommand.hpp"

SymbolNonTerminalRegistersCommand::SymbolNonTerminalRegistersCommand(void) : SymbolNonTerminalAbstractCommand("registerscommand")
{
	
}

SymbolNonTerminalRegistersCommand::~SymbolNonTerminalRegistersCommand(void)
{
	
}

void	SymbolNonTerminalRegistersCommand::computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg)
{
	addProduction(cfg, {"registers"});
}
