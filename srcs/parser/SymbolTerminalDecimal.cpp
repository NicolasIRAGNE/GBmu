/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalDecimal.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 17:03:31 by ldedier           #+#    #+#             */
/*   Updated: 2020/05/02 18:08:32 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolTerminalDecimal.hpp"

SymbolTerminalDecimal::SymbolTerminalDecimal(void) : AbstractTerminal("decimal")
{
	
}

SymbolTerminalDecimal::~SymbolTerminalDecimal(void)
{
	
}

int	SymbolTerminalDecimal::traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	static_cast<void>(ast);
	static_cast<void>(context);
	return (0);
}

std::string SymbolTerminalDecimal::getLexerString(void)
{
	return "d";
}