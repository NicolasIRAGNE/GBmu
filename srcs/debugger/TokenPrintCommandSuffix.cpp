/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TokenPrintCommandSuffix.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 17:51:50 by ldedier           #+#    #+#             */
/*   Updated: 2020/05/14 17:42:31 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "TokenPrintCommandSuffix.hpp"



TokenPrintCommandSuffix::TokenPrintCommandSuffix(void) : Token()
{

}

TokenPrintCommandSuffix::TokenPrintCommandSuffix(AbstractTerminal<int, DebuggerContext &> &term, std::string content) : Token(term, content)
{

}

TokenPrintCommandSuffix::~TokenPrintCommandSuffix(void)
{


}

TokenPrintCommandSuffix::TokenPrintCommandSuffix(AbstractTerminal<int, DebuggerContext &> &term
	, std::string content
	, PrintCommandSuffixParams printCommandSuffixParams
	) : Token(term, content), _printCommandSuffixParams(printCommandSuffixParams)
{

}

PrintCommandSuffixParams TokenPrintCommandSuffix::getPrintCommandSuffixParams()
{
	return _printCommandSuffixParams;
}

std::ostream &TokenPrintCommandSuffix::repr(std::ostream &o)
{
	o << YACC_YELLOW << " (";
	if (_printCommandSuffixParams.precised & PRECISED_COUNT)
	{
		o << YACC_GREEN << "count: " << YACC_YELLOW << _printCommandSuffixParams.count;
	}
	if (_printCommandSuffixParams.precised & PRECISED_UNIT)
	{
		if (_printCommandSuffixParams.precised & PRECISED_COUNT)
			o << " | ";
		o << YACC_GREEN << "unit: " << YACC_YELLOW << _printCommandSuffixParams.getUnitString();
	}
	if (_printCommandSuffixParams.precised & PRECISED_FORMAT)
	{
		if (_printCommandSuffixParams.precised & PRECISED_COUNT || _printCommandSuffixParams.precised & PRECISED_UNIT)
			o << " | ";
		o << YACC_GREEN << "format: " << YACC_YELLOW << _printCommandSuffixParams.getFormatChar();
	}
	if (_printCommandSuffixParams.precised == 0)
	{
		o << "default";
	}
	o << ") " << YACC_EOC;
	return o;
}
