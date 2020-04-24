/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalRegisterAF.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 16:25:25 by ldedier           #+#    #+#             */
/*   Updated: 2020/04/30 20:56:17 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolTerminalRegisterAF.hpp"

SymbolTerminalRegisterAF::SymbolTerminalRegisterAF(void) : SymbolTerminalVariable("af")
{
	
}

SymbolTerminalRegisterAF::~SymbolTerminalRegisterAF(void)
{
	
}

int	SymbolTerminalRegisterAF::traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	static_cast<void>(ast);
	static_cast<void>(context);
	return (0);
}

