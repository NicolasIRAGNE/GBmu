/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalFormat.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 14:52:38 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/30 14:52:38 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolNonTerminalFormat.hpp"

SymbolNonTerminalFormat::SymbolNonTerminalFormat(void) : AbstractNonTerminal("format")
{
	
}

SymbolNonTerminalFormat::~SymbolNonTerminalFormat(void)
{
	
}

int	SymbolNonTerminalFormat::traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	static_cast<void>(ast);
	static_cast<void>(context);
	return (0);
}

void	SymbolNonTerminalFormat::computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg)
{
	addProduction(cfg, {"d"});
	addProduction(cfg, {"x"});
	addProduction(cfg, {"o"});
	addProduction(cfg, {"b"});
	addProduction(cfg, {"i"});
}
