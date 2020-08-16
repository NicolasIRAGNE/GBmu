/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalRun.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 19:55:18 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/26 16:26:44 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolTerminalRun.hpp"

SymbolTerminalRun::SymbolTerminalRun(void) : SymbolTerminalCommand("run")
{
	
}

SymbolTerminalRun::~SymbolTerminalRun(void)
{
	
}

int	SymbolTerminalRun::traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	static_cast<void>(ast);
	static_cast<void>(context);
	return (0);
}

