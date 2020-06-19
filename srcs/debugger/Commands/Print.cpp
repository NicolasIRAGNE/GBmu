/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Print.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 17:19:50 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/19 17:45:33 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Print.hpp"

Print::Print(void) : AbstractCommand(PRINT_COMMAND)
{
	
}

Print::Print(Print const &instance)
{
	*this = instance;
}

Print::~Print(void)
{
	
}

Print &	Print::operator=(Print const &rhs)
{
	static_cast<void>(rhs);
	return *this;
}

std::string	Print::getHelp(void)
{
	return (_name + "/format value\t# print value in the precised format"\
		"\navailable formats:"
		"\n\td : decimal"
		"\n\tx : hexadecimal"
		"\n\to : octal"
		"\n\tb : binary"
		"\n\ti : instruction");
}

std::string	Print::getShortHelp(void)
{
	return ("print a given value by a given format");
}