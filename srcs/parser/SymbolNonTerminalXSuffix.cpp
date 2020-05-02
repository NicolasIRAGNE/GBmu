/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalXSuffix.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:38:32 by ldedier           #+#    #+#             */
/*   Updated: 2020/05/02 19:57:44 by ldedier          ###   ########.fr       */
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
	addProduction(cfg, {"/", "integer", "unit", "format"});
	addProduction(cfg, {"/", "format"});
}
