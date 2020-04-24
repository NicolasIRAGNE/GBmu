/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalClosedParenthesis.cpp                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 16:25:25 by ldedier           #+#    #+#             */
/*   Updated: 2020/04/30 19:40:51 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolTerminalClosedParenthesis.hpp"

SymbolTerminalClosedParenthesis::SymbolTerminalClosedParenthesis(void) : AbstractTerminal(")")
{
	
}

SymbolTerminalClosedParenthesis::~SymbolTerminalClosedParenthesis(void)
{
	
}

int	SymbolTerminalClosedParenthesis::traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	static_cast<void>(ast);
	static_cast<void>(context);
	return (0);
}

