/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalClosedParenthesis.cpp                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 14:56:29 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/18 14:56:29 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolTerminalClosedParenthesis.hpp"

SymbolTerminalClosedParenthesis::SymbolTerminalClosedParenthesis(void) : AbstractTerminal(")")
{
	
}

SymbolTerminalClosedParenthesis::~SymbolTerminalClosedParenthesis(void)
{
	
}

int	SymbolTerminalClosedParenthesis::traverse(ASTNode<int, CustomStack &> & ast, CustomStack & context) const
{
	static_cast<void>(ast);
	static_cast<void>(context);
	return (0);
}
