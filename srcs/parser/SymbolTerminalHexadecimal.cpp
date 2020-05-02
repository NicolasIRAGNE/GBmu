/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalHexadecimal.cpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:38:32 by ldedier           #+#    #+#             */
/*   Updated: 2020/05/02 19:28:01 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolTerminalHexadecimal.hpp"

SymbolTerminalHexadecimal::SymbolTerminalHexadecimal(void) : AbstractTerminal("hexadecimal")
{
	
}

SymbolTerminalHexadecimal::~SymbolTerminalHexadecimal(void)
{
	
}

int	SymbolTerminalHexadecimal::traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	static_cast<void>(ast);
	static_cast<void>(context);
	return (0);
}

std::string SymbolTerminalHexadecimal::getLexerString(void)
{
	return "x";
}
