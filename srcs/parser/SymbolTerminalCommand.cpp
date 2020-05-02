/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalCommand.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 21:15:29 by ldedier           #+#    #+#             */
/*   Updated: 2020/05/02 18:51:20 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "SymbolTerminalCommand.hpp"

SymbolTerminalCommand::SymbolTerminalCommand(void) : AbstractTerminal()
{

}

SymbolTerminalCommand::SymbolTerminalCommand(std::string identifier) : AbstractTerminal(identifier)
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