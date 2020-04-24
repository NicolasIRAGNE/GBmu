/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalInteger.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 16:30:57 by ldedier           #+#    #+#             */
/*   Updated: 2020/05/02 19:12:58 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolTerminalInteger.hpp"

typedef enum	e_integerFormat
{
	E_INTEGERFORMAT_UNKNOWN = -1,
	E_INTEGERFORMAT_UNDEFINED = 0,
	E_INTEGERFORMAT_DECIMAL = 10,
	E_INTEGERFORMAT_OCTAL = 8,
	E_INTEGERFORMAT_HEXADECIMAL = 16,
}				t_integer_format;

SymbolTerminalInteger::SymbolTerminalInteger(void) : AbstractTerminal("integer")
{
	
}

SymbolTerminalInteger::~SymbolTerminalInteger(void)
{
	
}

int	SymbolTerminalInteger::traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	static_cast<void>(context);
	return ast.getToken()->getIntValue();
}

static bool belongToFormat(char c, t_integer_format format)
{
	int value;

	if (tolower(c) > 'a')
		value = tolower(c) - 'a' + 10;
	else
		value = tolower(c) - '0';
	return value >= 0 && value < format;
}

static t_integer_format getIntegerFormat(std::string string, int *startIndex)
{
	*startIndex = -1;
	if (!string.length())
		return (E_INTEGERFORMAT_UNDEFINED);
	if (string.length() == 1)
	{
		if (string.at(0) == '0')
			return (E_INTEGERFORMAT_UNDEFINED);
		else if (belongToFormat(string.at(0), E_INTEGERFORMAT_DECIMAL))
		{
			*startIndex = 0;
			return (E_INTEGERFORMAT_DECIMAL);
		}
		else
			return (E_INTEGERFORMAT_UNKNOWN);
	}
	else if (string.length() >= 2 && string.at(0) == '0' && tolower(string.at(1)) == 'x')
	{
		*startIndex = 2;
		return (E_INTEGERFORMAT_HEXADECIMAL);
	}
	else if (string.length() >= 1 && string.at(0) == '0')
	{
		*startIndex = 1;
		return (E_INTEGERFORMAT_OCTAL);
	}	
	else
	{
		*startIndex = 0;
		return (E_INTEGERFORMAT_DECIMAL);
	}
}

bool SymbolTerminalInteger::staysEligibleForCurrent(std::string & current)
{
	int					i;
	int					index;
	t_integer_format	format;

	format = getIntegerFormat(current, &index);
	if (format == E_INTEGERFORMAT_UNDEFINED)
		return true;
	if (format == E_INTEGERFORMAT_UNKNOWN)
		return false;
	i = index;
	while (static_cast<size_t>(i) < current.length())
	{
		if (!belongToFormat(current[i], format))
			return false;
		i++;
	}
	return true;
}

bool SymbolTerminalInteger::isEligibleForCurrent(std::string & current)
{
	return SymbolTerminalInteger::staysEligibleForCurrent(current) && current.compare("0x");
}

Token<int, DebuggerContext &> *SymbolTerminalInteger::createToken(std::string tokenContent)
{
	int					index;
	t_integer_format	format;

	format = getIntegerFormat(tokenContent, &index);
	return new Token<int, DebuggerContext &>(*this, stoi(tokenContent, 0, format));
}
