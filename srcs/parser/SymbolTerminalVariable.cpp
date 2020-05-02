/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalVariable.hpp                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 19:03:18 by ldedier           #+#    #+#             */
/*   Updated: 2020/04/30 20:02:01 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolTerminalVariable.hpp"


SymbolTerminalVariable::SymbolTerminalVariable(void) : AbstractTerminal()
{

}

SymbolTerminalVariable::SymbolTerminalVariable(std::string identifier) : AbstractTerminal(identifier)
{

}

SymbolTerminalVariable::~SymbolTerminalVariable(void)
{

}

static std::string tolower(std::string string)
{
	std::string res = "";

	for (std::string::size_type i=0; i<string.length(); ++i)
		res = res + static_cast<char>(std::tolower(string[i]));
	return res;
}

bool SymbolTerminalVariable::isEligibleForCurrent(std::string & current)
{
	std::string tolowerCurr = tolower(current);
	std::string tolowerLexerString = tolower(getLexerString());
	
	return ("$" + tolowerLexerString).compare(tolowerCurr) == 0;
}

bool SymbolTerminalVariable::staysEligibleForCurrent(std::string & current)
{
	std::string tolowerCurr = tolower(current);
	std::string tolowerLexerString = tolower(getLexerString());
	
	return ("$" + tolowerLexerString).compare(0, tolowerCurr.size(), tolowerCurr) == 0;
}

Token<int, DebuggerContext &> *SymbolTerminalVariable::createToken(std::string tokenContent)
{
	static_cast<void>(tokenContent);
	return new Token<int, DebuggerContext &>(*this, tokenContent.substr(1));
}