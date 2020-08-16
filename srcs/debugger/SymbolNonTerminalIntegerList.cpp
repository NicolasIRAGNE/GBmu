/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalIntegerList.cpp                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:38:32 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/18 22:02:26 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolNonTerminalIntegerList.hpp"

SymbolNonTerminalIntegerList::SymbolNonTerminalIntegerList(void) : AbstractNonTerminal("integerlist")
{
	
}

SymbolNonTerminalIntegerList::~SymbolNonTerminalIntegerList(void)
{
	
}

int	SymbolNonTerminalIntegerList::traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	static_cast<void>(ast);
	static_cast<void>(context);
	return (0);
}

void	SymbolNonTerminalIntegerList::computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg)
{
	addProduction(cfg, {"integer"});
	addProduction(cfg, {"integerlist", "integer"}, 1);
}
