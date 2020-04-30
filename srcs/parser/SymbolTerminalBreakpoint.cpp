/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalBreakpoint.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 14:52:38 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/30 14:52:38 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolTerminalBreakpoint.hpp"

SymbolTerminalBreakpoint::SymbolTerminalBreakpoint(void) : AbstractTerminal("breakpoint")
{
	
}

SymbolTerminalBreakpoint::~SymbolTerminalBreakpoint(void)
{
	
}

int	SymbolTerminalBreakpoint::traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	static_cast<void>(ast);
	static_cast<void>(context);
	return (0);
}

