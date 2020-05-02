/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalRegisterE.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:38:32 by ldedier           #+#    #+#             */
/*   Updated: 2020/05/02 17:01:11 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolTerminalRegisterE.hpp"

SymbolTerminalRegisterE::SymbolTerminalRegisterE(void) : SymbolTerminalVariable("e")
{
	
}

SymbolTerminalRegisterE::~SymbolTerminalRegisterE(void)
{
	
}

int	SymbolTerminalRegisterE::traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	static_cast<void>(ast);
	static_cast<void>(context);
	return (0);
}

