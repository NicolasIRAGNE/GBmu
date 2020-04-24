/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalXSuffix.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 19:16:33 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/24 19:16:33 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolNonTerminalXSuffix.hpp"

SymbolNonTerminalXSuffix::SymbolNonTerminalXSuffix(void) : AbstractNonTerminal("xsuffix")
{
	
}

SymbolNonTerminalXSuffix::~SymbolNonTerminalXSuffix(void)
{
	
}

int	SymbolNonTerminalXSuffix::traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	static_cast<void>(ast);
	static_cast<void>(context);
	return (0);
}

void	SymbolNonTerminalXSuffix::computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg)
{
	addProduction(cfg, {"/", "integer", "format", "unit"});
	addProduction(cfg, {"/", "integer", "format"});
	addProduction(cfg, {"/", "format"});
}
