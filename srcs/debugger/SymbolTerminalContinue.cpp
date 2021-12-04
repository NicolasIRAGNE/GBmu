/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalContinue.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 19:55:18 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/26 18:55:05 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolTerminalContinue.hpp"

SymbolTerminalContinue::SymbolTerminalContinue(void) : SymbolTerminalCommand("continue")
{
	
}

SymbolTerminalContinue::~SymbolTerminalContinue(void)
{
	
}

int	SymbolTerminalContinue::traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	static_cast<void>(ast);
	static_cast<void>(context);
	return (0);
}

