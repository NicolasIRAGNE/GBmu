/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PrintCommandSuffixParams.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 17:14:17 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/25 18:24:21 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PrintCommandSuffixParams.hpp"

PrintCommandSuffixParams::PrintCommandSuffixParams(void)
{
	format = PrintCommandSuffixParams::E_FORMAT_DECIMAL;
	unit = PrintCommandSuffixParams::E_UNIT_WORD;
	count = 1;
	precised = 0;
}

PrintCommandSuffixParams::PrintCommandSuffixParams(PrintCommandSuffixParams const &instance)
{
	*this = instance;
}

PrintCommandSuffixParams::~PrintCommandSuffixParams(void)
{
	
}

PrintCommandSuffixParams &	PrintCommandSuffixParams::operator=(PrintCommandSuffixParams const &rhs)
{
	unit = rhs.unit;
	format = rhs.format;
	precised = rhs.precised;
	count = rhs.count;
	return *this;
}

std::string PrintCommandSuffixParams::getUnitString()
{
	if (unit == E_UNIT_WORD)
		return "h";
	else
		return "hh";
}

char PrintCommandSuffixParams::getFormatChar()
{
	if (format == E_FORMAT_DECIMAL)
		return 'd';
	else if (format == E_FORMAT_HEXADECIMAL)
		return 'x';
	else if (format == E_FORMAT_OCTAL)
		return 'o';
	else if (format == E_FORMAT_BINARY)
		return 'b';
	else
		return 'i';
}