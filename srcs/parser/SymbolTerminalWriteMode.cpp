/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalWriteMode.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:38:32 by ldedier           #+#    #+#             */
/*   Updated: 2020/05/02 22:03:32 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolTerminalWriteMode.hpp"

SymbolTerminalWriteMode::SymbolTerminalWriteMode(void) : AbstractTerminal("w", E_PRIORITY_STANDARD, E_ADJACENT_ADJACENT)
{
	
}

SymbolTerminalWriteMode::~SymbolTerminalWriteMode(void)
{
	
}

int	SymbolTerminalWriteMode::traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	static_cast<void>(ast);
	static_cast<void>(context);
	return (0);
}

