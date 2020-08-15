/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalCommandName.cpp                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:38:32 by ldedier           #+#    #+#             */
/*   Updated: 2020/08/15 14:10:07 by ldedier          ###   ########.fr       */
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
	addProduction(cfg, {"x"}); //TODO i format
	addProduction(cfg, {"step"}); // TODO
	addProduction(cfg, {"next"}); // TODO
	addProduction(cfg, {"help"});
	addProduction(cfg, {"break"});
	addProduction(cfg, {"tbreak"}); //todo
	addProduction(cfg, {"watch"});
	addProduction(cfg, {"delete"});
	addProduction(cfg, {"info"});
	addProduction(cfg, {"start"});
	addProduction(cfg, {"run"});
	addProduction(cfg, {"continue"});
	addProduction(cfg, {"registers"});
	addProduction(cfg, {"quit"}); // TODO
	addProduction(cfg, {"verbose"});
	addProduction(cfg, {"set"});
}
