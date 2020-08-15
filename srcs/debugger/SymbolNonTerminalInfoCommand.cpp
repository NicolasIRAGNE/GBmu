/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalInfoCommand.cpp                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:38:32 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/26 20:07:44 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolNonTerminalInfoCommand.hpp"

SymbolNonTerminalInfoCommand::SymbolNonTerminalInfoCommand(void) : SymbolNonTerminalAbstractCommand("infocommand")
{
	
}

SymbolNonTerminalInfoCommand::~SymbolNonTerminalInfoCommand(void)
{
	
}

void	SymbolNonTerminalInfoCommand::computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg)
{
	addProduction(cfg, {"info"});
}
