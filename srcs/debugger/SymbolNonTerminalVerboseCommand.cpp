/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalVerboseCommand.cpp                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:38:32 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/27 16:16:45 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolNonTerminalVerboseCommand.hpp"

SymbolNonTerminalVerboseCommand::SymbolNonTerminalVerboseCommand(void) : SymbolNonTerminalAbstractCommand("verbosecommand")
{
	
}

SymbolNonTerminalVerboseCommand::~SymbolNonTerminalVerboseCommand(void)
{
	
}

void	SymbolNonTerminalVerboseCommand::computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg)
{
	addProduction(cfg, {"verbose", "andor"});
}
