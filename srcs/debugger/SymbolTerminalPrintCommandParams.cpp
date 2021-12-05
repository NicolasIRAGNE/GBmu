/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalPrintCommandParams.cpp               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 17:37:35 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/25 18:31:04 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolTerminalPrintCommandParams.hpp"
# include <string>

SymbolTerminalPrintCommandParams::SymbolTerminalPrintCommandParams(void) : AbstractTerminal("printcommandparams", E_PRIORITY_STANDARD, E_ADJACENT_DETACHED)
{
	
}

SymbolTerminalPrintCommandParams::~SymbolTerminalPrintCommandParams(void)
{
	
}

int	SymbolTerminalPrintCommandParams::traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	TokenPrintCommandSuffix *token = dynamic_cast<TokenPrintCommandSuffix *>(ast.getToken());

	context.printCommandSuffixParams = token->getPrintCommandSuffixParams();
	return (0);
}

bool SymbolTerminalPrintCommandParams::canBeAdded(std::deque<Token<int, DebuggerContext &> *>	& res)
{
	return res.size() == 1;
}

bool SymbolTerminalPrintCommandParams::staysEligibleForCurrent(std::string & current)
{
	size_t i = 1;

	if (current.length() && current[0] != '/')
		return false;
	if (i < current.length())
	{
		if (current[i] == '-')
			i++;
		while (isdigit(current[i]))
			i++;
	}
	if (current[1] == '-' && i == 2 && i < current.length())
	{
		std::cout << current << std::endl;
		return false;
	}
	if (i < current.length())
	{
		if (!current.substr(i, 2).compare("hh"))
			i += 2;
		else if (!current.substr(i, 1).compare("h"))
			i++;
	}
	if (i < current.length())
	{
		if (strchr("dxobi", current.substr(i, 1).at(0)))
			i++;
		else
			return false;
	}
	if (i < current.length())
		return false;
	return true;
}

bool SymbolTerminalPrintCommandParams::isEligibleForCurrent(std::string & current)
{
	return SymbolTerminalPrintCommandParams::staysEligibleForCurrent(current) && current.compare("/-");
}

Token<int, DebuggerContext &> *SymbolTerminalPrintCommandParams::createToken(std::string tokenContent)
{
	PrintCommandSuffixParams params;
	size_t i;

	
	i = 1;
	if (i < tokenContent.length())
	{
		if (tokenContent[i] == '-')
			i++;
		while (isdigit(tokenContent[i]))
			i++;
	}
	if (i > 1)
	{
		params.precised |= PRECISED_COUNT;
		params.count = std::stoi(tokenContent.substr(1, i));
	}
	if (i < tokenContent.length())
	{
		if (!tokenContent.substr(i, 2).compare("hh"))
		{
			i+=2;
			params.precised |= PRECISED_UNIT;
			params.unit = PrintCommandSuffixParams::E_UNIT_HALFWORD;

		}
		else if (!tokenContent.substr(i, 1).compare("h"))
		{
			i++;
			params.precised |= PRECISED_UNIT;
			params.unit = PrintCommandSuffixParams::E_UNIT_WORD;
		}
	}
	if (i < tokenContent.length())
	{
		switch (tokenContent.substr(i, 1).at(0))
		{
			case 'd':
				params.format = PrintCommandSuffixParams::E_FORMAT_DECIMAL;
				break;
			case 'x':
				params.format = PrintCommandSuffixParams::E_FORMAT_HEXADECIMAL;
				break;
			case 'o':
				params.format = PrintCommandSuffixParams::E_FORMAT_OCTAL;
				break;
			case 'b':
				params.format = PrintCommandSuffixParams::E_FORMAT_BINARY;
				break;
			case 'i':
				params.format = PrintCommandSuffixParams::E_FORMAT_INSTRUCTION;
				break;
			default:
				break;
		}
		params.precised |= PRECISED_FORMAT;
	}
	return new TokenPrintCommandSuffix(*this, tokenContent, params);
}
