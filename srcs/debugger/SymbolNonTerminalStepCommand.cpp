/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalStepCommand.cpp                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:38:32 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/26 20:08:53 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolNonTerminalStepCommand.hpp"

SymbolNonTerminalStepCommand::SymbolNonTerminalStepCommand(void) : SymbolNonTerminalAbstractCommand("stepcommand")
{
	
}

SymbolNonTerminalStepCommand::~SymbolNonTerminalStepCommand(void)
{
	
}

void	SymbolNonTerminalStepCommand::computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg)
{
	addProduction(cfg, {"step"});
}
