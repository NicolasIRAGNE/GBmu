/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalIoPort.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 16:25:25 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/30 16:25:25 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolNonTerminalIoPort.hpp"

SymbolNonTerminalIoPort::SymbolNonTerminalIoPort(void) : AbstractNonTerminal("ioport")
{
	
}

SymbolNonTerminalIoPort::~SymbolNonTerminalIoPort(void)
{
	
}

int	SymbolNonTerminalIoPort::traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	static_cast<void>(ast);
	static_cast<void>(context);
	return (0);
}

void	SymbolNonTerminalIoPort::computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg)
{
	addProduction(cfg, {"divoffset"});
	addProduction(cfg, {"timaoffset"});
	addProduction(cfg, {"todooffset"});
}
