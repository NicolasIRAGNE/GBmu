/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   XCommand.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 17:45:57 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/19 17:56:44 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "XCommand.hpp"

XCommand::XCommand(void) : AbstractCommand(X_COMMAND)
{
	
}

XCommand::XCommand(XCommand const &instance)
{
	*this = instance;
}

XCommand::~XCommand(void)
{
	
}

XCommand &	XCommand::operator=(XCommand const &rhs)
{
	static_cast<void>(rhs);
	return *this;
}

std::string	XCommand::getHelp(void)
{
	return (_name + "/format offset # print the content of the address at offset \"offset\" in the precised format"\
		"\navailable formats:"
		"\n\td : decimal"
		"\n\tx : hexadecimal"
		"\n\to : octal"
		"\n\tb : binary"
		"\n\ti : instruction");
}

std::string	XCommand::getShortHelp(void)
{
	return ("print the content of the cpu given an offset");
}