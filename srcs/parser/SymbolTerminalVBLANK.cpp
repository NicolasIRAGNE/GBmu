/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalVBLANK.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 14:31:18 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/30 14:31:18 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolTerminalVBLANK.hpp"

SymbolTerminalVBLANK::SymbolTerminalVBLANK(void) : AbstractNonTerminal("vblank")
{
	
}

SymbolTerminalVBLANK::~SymbolTerminalVBLANK(void)
{
	
}

int	SymbolTerminalVBLANK::traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	static_cast<void>(ast);
	static_cast<void>(context);
	return (0);
}

void	SymbolTerminalVBLANK::computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg)
{
}
