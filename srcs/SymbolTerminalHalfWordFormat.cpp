/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalHalfWordFormat.cpp                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 12:47:46 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/17 12:47:46 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolTerminalHalfWordFormat.hpp"

SymbolTerminalHalfWordFormat::SymbolTerminalHalfWordFormat(void) : AbstractTerminal("hh")
{
	
}

SymbolTerminalHalfWordFormat::~SymbolTerminalHalfWordFormat(void)
{
	
}

int	SymbolTerminalHalfWordFormat::traverse(ASTNode<int, CustomStack &> & ast, CustomStack & context) const
{
	static_cast<void>(ast);
	static_cast<void>(context);
	return (0);
}

