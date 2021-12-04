/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalDivOffset.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:38:32 by ldedier           #+#    #+#             */
/*   Updated: 2021/06/04 13:32:45 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolTerminalDivOffset.hpp"

SymbolTerminalDivOffset::SymbolTerminalDivOffset(void) : SymbolTerminalVariable("divoffset")
{
	
}

SymbolTerminalDivOffset::~SymbolTerminalDivOffset(void)
{
	
}

int	SymbolTerminalDivOffset::traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	static_cast<void>(ast);
	static_cast<void>(context);
	return (0);
}

