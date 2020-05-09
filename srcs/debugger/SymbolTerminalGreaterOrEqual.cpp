/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalGreaterOrEqual.cpp                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:38:32 by ldedier            #+#    #+#            */
/*   Updated: 2020/05/01 16:38:32 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolTerminalGreaterOrEqual.hpp"

SymbolTerminalGreaterOrEqual::SymbolTerminalGreaterOrEqual(void) : AbstractTerminal(">=")
{
	
}

SymbolTerminalGreaterOrEqual::~SymbolTerminalGreaterOrEqual(void)
{
	
}

int	SymbolTerminalGreaterOrEqual::traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	static_cast<void>(ast);
	static_cast<void>(context);
	return (0);
}

