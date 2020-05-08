/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalInterruptVBlank.cpp                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:38:32 by ldedier           #+#    #+#             */
/*   Updated: 2020/05/02 17:05:50 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolTerminalInterruptVBlank.hpp"

SymbolTerminalInterruptVBlank::SymbolTerminalInterruptVBlank(void) : SymbolTerminalVariable("vblank")
{
	
}

SymbolTerminalInterruptVBlank::~SymbolTerminalInterruptVBlank(void)
{
	
}

int	SymbolTerminalInterruptVBlank::traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	static_cast<void>(ast);
	static_cast<void>(context);
	return (0);
}

