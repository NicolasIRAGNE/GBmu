/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalModulo.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 18:26:20 by ldedier            #+#    #+#            */
/*   Updated: 2020/05/02 18:26:20 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolTerminalModulo.hpp"

SymbolTerminalModulo::SymbolTerminalModulo(void) : AbstractTerminal("%")
{
	
}

SymbolTerminalModulo::~SymbolTerminalModulo(void)
{
	
}

int	SymbolTerminalModulo::traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	static_cast<void>(ast);
	static_cast<void>(context);
	return (0);
}

