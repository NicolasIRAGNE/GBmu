/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalFormat.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 16:25:25 by ldedier           #+#    #+#             */
/*   Updated: 2020/04/30 23:38:13 by ldedier          ###   ########.fr       */
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
	if (ast.getChild(0)->getSymbol().getIdentifier() == "d")
		context.format = DebuggerContext::E_DEBUGGER_FORMAT_DECIMAL;
	else if (ast.getChild(0)->getSymbol().getIdentifier() == "x")
		context.format = DebuggerContext::E_DEBUGGER_FORMAT_HEXADECIMAL;
	else if (ast.getChild(0)->getSymbol().getIdentifier() == "o")
		context.format = DebuggerContext::E_DEBUGGER_FORMAT_OCTAL;
	else if (ast.getChild(0)->getSymbol().getIdentifier() == "b")
		context.format = DebuggerContext::E_DEBUGGER_FORMAT_BINARY;
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
