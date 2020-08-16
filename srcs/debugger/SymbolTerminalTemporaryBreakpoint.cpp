/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalTemporaryBreakpoint.cpp              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 16:09:29 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/26 18:43:10 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolTerminalTemporaryBreakpoint.hpp"

SymbolTerminalTemporaryBreakpoint::SymbolTerminalTemporaryBreakpoint(void) : SymbolTerminalCommand("tbreak")
{
	
}

SymbolTerminalTemporaryBreakpoint::~SymbolTerminalTemporaryBreakpoint(void)
{
	
}

int	SymbolTerminalTemporaryBreakpoint::traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	static_cast<void>(ast);
	static_cast<void>(context);
	return (0);
}

