/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalVector.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 14:52:38 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/30 14:52:38 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolNonTerminalVector.hpp"

SymbolNonTerminalVector::SymbolNonTerminalVector(void) : AbstractNonTerminal("vector")
{
	
}

SymbolNonTerminalVector::~SymbolNonTerminalVector(void)
{
	
}

int	SymbolNonTerminalVector::traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	static_cast<void>(ast);
	static_cast<void>(context);
	return (0);
}

void	SymbolNonTerminalVector::computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg)
{
	addProduction(cfg, {"vblank"});
	addProduction(cfg, {"stat"});
	addProduction(cfg, {"timer"});
	addProduction(cfg, {"serial"});
	addProduction(cfg, {"joypad"});
}
