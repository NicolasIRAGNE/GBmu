/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalHelpCommand.cpp                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:38:32 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/26 20:09:19 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolNonTerminalHelpCommand.hpp"

SymbolNonTerminalHelpCommand::SymbolNonTerminalHelpCommand(void) : SymbolNonTerminalAbstractCommand("helpcommand")
{
	
}

SymbolNonTerminalHelpCommand::~SymbolNonTerminalHelpCommand(void)
{
	
}


void	SymbolNonTerminalHelpCommand::computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg)
{
	addProduction(cfg, {"help"});
	addProduction(cfg, {"help", "commandname"});
}
