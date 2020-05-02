/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalInterruptJoypad.cpp                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:38:32 by ldedier           #+#    #+#             */
/*   Updated: 2020/05/02 17:05:40 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolTerminalInterruptJoypad.hpp"

SymbolTerminalInterruptJoypad::SymbolTerminalInterruptJoypad(void) : SymbolTerminalVariable("joypad")
{
	
}

SymbolTerminalInterruptJoypad::~SymbolTerminalInterruptJoypad(void)
{
	
}

int	SymbolTerminalInterruptJoypad::traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	static_cast<void>(ast);
	static_cast<void>(context);
	return (0);
}

