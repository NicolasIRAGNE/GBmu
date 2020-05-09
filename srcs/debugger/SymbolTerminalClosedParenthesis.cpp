/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalClosedParenthesis.cpp                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:38:32 by ldedier           #+#    #+#             */
/*   Updated: 2020/05/02 19:12:53 by ldedier          ###   ########.fr       */
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

