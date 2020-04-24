/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalDivOffset.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 16:25:25 by ldedier           #+#    #+#             */
/*   Updated: 2020/04/30 21:38:59 by ldedier          ###   ########.fr       */
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

