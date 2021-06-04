/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalRegisterName.cpp                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:38:32 by ldedier           #+#    #+#             */
/*   Updated: 2021/06/04 13:26:26 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolNonTerminalRegisterName.hpp"

SymbolNonTerminalRegisterName::SymbolNonTerminalRegisterName(void) : AbstractNonTerminal("registername")
{
	
}

SymbolNonTerminalRegisterName::~SymbolNonTerminalRegisterName(void)
{
	
}

int	SymbolNonTerminalRegisterName::traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	static_cast<void>(ast);
	static_cast<void>(context);
	return (0);
}

void	SymbolNonTerminalRegisterName::computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg)
{
	addProduction(cfg, {"f"});
	addProduction(cfg, {"a"});
	addProduction(cfg, {"af"});
	addProduction(cfg, {"b"});
	addProduction(cfg, {"c"});
	addProduction(cfg, {"bc"});
	addProduction(cfg, {"d"});
	addProduction(cfg, {"e"});
	addProduction(cfg, {"de"});
	addProduction(cfg, {"h"});
	addProduction(cfg, {"l"});
	addProduction(cfg, {"hl"});
	addProduction(cfg, {"sp"});
	addProduction(cfg, {"pc"});
}
