/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalPrintCommand.cpp                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:38:32 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/26 20:07:59 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolNonTerminalPrintCommand.hpp"
# include <iomanip>
# include <bitset>

SymbolNonTerminalPrintCommand::SymbolNonTerminalPrintCommand(void) : SymbolNonTerminalAbstractCommand("printcommand")
{
	
}

SymbolNonTerminalPrintCommand::~SymbolNonTerminalPrintCommand(void)
{
	
}

void	SymbolNonTerminalPrintCommand::computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg)
{
	addProduction(cfg, {"print", "printcommandsuffix"});
}
