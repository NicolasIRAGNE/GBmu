/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalExpansion.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:38:32 by ldedier           #+#    #+#             */
/*   Updated: 2020/05/02 21:52:34 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolTerminalExpansion.hpp"

SymbolTerminalExpansion::SymbolTerminalExpansion(void) : AbstractTerminal("expansion", E_PRIORITY_INF, E_ADJACENT_DETACHED)
{
	
}

SymbolTerminalExpansion::~SymbolTerminalExpansion(void)
{
	
}

int	SymbolTerminalExpansion::traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	static_cast<void>(ast);
	static_cast<void>(context);
	return (0);
}

