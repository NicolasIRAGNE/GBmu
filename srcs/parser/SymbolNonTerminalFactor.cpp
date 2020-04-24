/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalFactor.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 19:16:33 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/24 19:16:33 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolNonTerminalFactor.hpp"

SymbolNonTerminalFactor::SymbolNonTerminalFactor(void) : AbstractNonTerminal("factor")
{
	
}

SymbolNonTerminalFactor::~SymbolNonTerminalFactor(void)
{
	
}

int	SymbolNonTerminalFactor::traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	static_cast<void>(ast);
	static_cast<void>(context);
	return (0);
}

void	SymbolNonTerminalFactor::computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg)
{
	addProduction(cfg, {"integer"});
	addProduction(cfg, {"(", "andor", ")"});
	addProduction(cfg, {"*", "factor"});
	addProduction(cfg, {"-", "factor"});
	addProduction(cfg, {"+", "factor"});
}
