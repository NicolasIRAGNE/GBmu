/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalFormat.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 18:54:33 by ldedier           #+#    #+#             */
/*   Updated: 2020/05/02 20:16:14 by ldedier          ###   ########.fr       */
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
	if (ast.getChild(0)->getSymbol().getIdentifier() == "decimal")
		context.format = DebuggerContext::E_DEBUGGER_FORMAT_DECIMAL;
	else if (ast.getChild(0)->getSymbol().getIdentifier() == "hexadecimal")
		context.format = DebuggerContext::E_DEBUGGER_FORMAT_HEXADECIMAL;
	else if (ast.getChild(0)->getSymbol().getIdentifier() == "o")
		context.format = DebuggerContext::E_DEBUGGER_FORMAT_OCTAL;
	else if (ast.getChild(0)->getSymbol().getIdentifier() == "binary")
		context.format = DebuggerContext::E_DEBUGGER_FORMAT_BINARY;
	return (0);
}

void	SymbolNonTerminalFormat::computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg)
{
	addProduction(cfg, {"decimal"});
	addProduction(cfg, {"hexadecimal"});
	addProduction(cfg, {"binary"});
	addProduction(cfg, {"o"});
	addProduction(cfg, {"i"});
}
