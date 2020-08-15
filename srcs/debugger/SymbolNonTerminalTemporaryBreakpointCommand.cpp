/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalTemporaryBreakpointCommand        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 16:09:29 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/26 20:08:56 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolNonTerminalTemporaryBreakpointCommand.hpp"

SymbolNonTerminalTemporaryBreakpointCommand::SymbolNonTerminalTemporaryBreakpointCommand(void) : SymbolNonTerminalAbstractCommand("temporarybreakpointcommand")
{
	
}

SymbolNonTerminalTemporaryBreakpointCommand::~SymbolNonTerminalTemporaryBreakpointCommand(void)
{
	
}

void	SymbolNonTerminalTemporaryBreakpointCommand::computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg)
{
	addProduction(cfg, {"tbreak", "address"});
	addProduction(cfg, {"tbreak"});
}
