/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalHalfWordFormat.cpp                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:38:32 by ldedier           #+#    #+#             */
/*   Updated: 2020/05/02 21:59:15 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolTerminalHalfWordFormat.hpp"

SymbolTerminalHalfWordFormat::SymbolTerminalHalfWordFormat(void) : AbstractTerminal("hh", E_PRIORITY_STANDARD, E_ADJACENT_ADJACENT)
{
	
}

SymbolTerminalHalfWordFormat::~SymbolTerminalHalfWordFormat(void)
{
	
}

int	SymbolTerminalHalfWordFormat::traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	static_cast<void>(ast);
	static_cast<void>(context);
	return (0);
}

