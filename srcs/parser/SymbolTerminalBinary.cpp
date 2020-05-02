/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalBinary.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 20:06:16 by ldedier           #+#    #+#             */
/*   Updated: 2020/05/02 20:09:18 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolTerminalBinary.hpp"

SymbolTerminalBinary::SymbolTerminalBinary(void) : AbstractTerminal("binary")
{
	
}

SymbolTerminalBinary::~SymbolTerminalBinary(void)
{
	
}

int	SymbolTerminalBinary::traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	static_cast<void>(ast);
	static_cast<void>(context);
	return (0);
}

std::string SymbolTerminalBinary::getLexerString(void)
{
	return "b";
}