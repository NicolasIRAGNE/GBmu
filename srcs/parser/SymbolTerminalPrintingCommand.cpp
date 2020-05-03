/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalPrintingCommand.cpp                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 12:58:03 by ldedier           #+#    #+#             */
/*   Updated: 2020/05/03 13:23:20 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "SymbolTerminalPrintingCommand.hpp"

SymbolTerminalPrintingCommand::SymbolTerminalPrintingCommand(void) : SymbolTerminalCommand()
{

}

SymbolTerminalPrintingCommand::SymbolTerminalPrintingCommand(std::string identifier) : SymbolTerminalCommand(identifier)
{

}

SymbolTerminalPrintingCommand::~SymbolTerminalPrintingCommand(void)
{

}

bool SymbolTerminalPrintingCommand::shouldCreateToken(std::string tokenContent
	, char delimiter
	, std::deque<Token<int, DebuggerContext &> *>	& res)
{
	static_cast<void>(tokenContent);
	static_cast<void>(res);

	return (delimiter == '/' || isblank(delimiter));
}