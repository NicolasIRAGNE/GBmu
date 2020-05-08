/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalRegisterD.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 16:25:25 by ldedier           #+#    #+#             */
/*   Updated: 2020/05/02 17:01:08 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolTerminalRegisterD.hpp"

SymbolTerminalRegisterD::SymbolTerminalRegisterD(void) : SymbolTerminalVariable("d")
{
	
}

SymbolTerminalRegisterD::~SymbolTerminalRegisterD(void)
{
	
}

int	SymbolTerminalRegisterD::traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	static_cast<void>(ast);
	static_cast<void>(context);
	return (0);
}

