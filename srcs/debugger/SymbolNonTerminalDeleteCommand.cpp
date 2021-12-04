/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalDeleteCommand.cpp                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 15:59:19 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/26 20:09:23 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolNonTerminalDeleteCommand.hpp"

SymbolNonTerminalDeleteCommand::SymbolNonTerminalDeleteCommand(void) : SymbolNonTerminalAbstractCommand("deletecommand")
{
	
}

SymbolNonTerminalDeleteCommand::~SymbolNonTerminalDeleteCommand(void)
{
	
}

void	SymbolNonTerminalDeleteCommand::computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg)
{
	addProduction(cfg, {"delete", "integerlist"});
	addProduction(cfg, {"delete"});
}
