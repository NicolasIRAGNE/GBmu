/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalCommandName.cpp                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 16:25:25 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/30 16:25:25 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolNonTerminalCommandName.hpp"

SymbolNonTerminalCommandName::SymbolNonTerminalCommandName(void) : AbstractNonTerminal("commandname")
{
	
}

SymbolNonTerminalCommandName::~SymbolNonTerminalCommandName(void)
{
	
}

int	SymbolNonTerminalCommandName::traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	static_cast<void>(ast);
	static_cast<void>(context);
	return (0);
}

void	SymbolNonTerminalCommandName::computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg)
{
	addProduction(cfg, {"print"});
	addProduction(cfg, {"step"});
	addProduction(cfg, {"next"});
	addProduction(cfg, {"help"});
	addProduction(cfg, {"breakpoint"});
	addProduction(cfg, {"watch"});
	addProduction(cfg, {"unwatch"});
	addProduction(cfg, {"delete"});
	addProduction(cfg, {"info"});
	addProduction(cfg, {"registers"});
	addProduction(cfg, {"quit"});
	addProduction(cfg, {"verbose"});
	addProduction(cfg, {"set"});
}
