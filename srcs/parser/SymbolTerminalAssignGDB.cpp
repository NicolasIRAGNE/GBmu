/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalAssignGDB.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 14:33:53 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/30 14:33:53 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolTerminalAssignGDB.hpp"

SymbolTerminalAssignGDB::SymbolTerminalAssignGDB(void) : AbstractTerminal(":=")
{
	
}

SymbolTerminalAssignGDB::~SymbolTerminalAssignGDB(void)
{
	
}

int	SymbolTerminalAssignGDB::traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	static_cast<void>(ast);
	static_cast<void>(context);
	return (0);
}

