/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalCommand.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 21:15:29 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/19 19:05:41 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "SymbolTerminalCommand.hpp"

SymbolTerminalCommand::SymbolTerminalCommand(void) : AbstractTerminal()
{

}

SymbolTerminalCommand::SymbolTerminalCommand(std::string identifier) : AbstractTerminal(identifier, E_PRIORITY_STANDARD, E_ADJACENT_DETACHED)
{

}

SymbolTerminalCommand::~SymbolTerminalCommand(void)
{

}

bool SymbolTerminalCommand::isEligibleForCurrent(std::string & current)
{
	return AbstractTerminal::staysEligibleForCurrent(current);
}

bool SymbolTerminalCommand::staysEligibleForCurrent(std::string & current)
{
	return AbstractTerminal::staysEligibleForCurrent(current);
}