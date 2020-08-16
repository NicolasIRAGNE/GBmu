/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalStart.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 16:09:29 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/26 16:26:47 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolTerminalStart.hpp"

SymbolTerminalStart::SymbolTerminalStart(void) : SymbolTerminalCommand("start")
{
	
}

SymbolTerminalStart::~SymbolTerminalStart(void)
{
	
}

int	SymbolTerminalStart::traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	static_cast<void>(ast);
	static_cast<void>(context);
	return (0);
}

