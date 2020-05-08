/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalWordFormat.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 19:29:45 by ldedier           #+#    #+#             */
/*   Updated: 2020/05/02 22:04:30 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolTerminalWordFormat.hpp"

SymbolTerminalWordFormat::SymbolTerminalWordFormat(void) : AbstractTerminal("hunit", E_PRIORITY_STANDARD, E_ADJACENT_ADJACENT)
{
	
}

SymbolTerminalWordFormat::~SymbolTerminalWordFormat(void)
{
	
}

int	SymbolTerminalWordFormat::traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	static_cast<void>(ast);
	static_cast<void>(context);
	return (0);
}

std::string SymbolTerminalWordFormat::getLexerString(void)
{
	return "h";
}
