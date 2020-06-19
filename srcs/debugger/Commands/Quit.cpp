/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Quit.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 18:08:14 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/19 18:13:54 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Quit.hpp"

Quit::Quit(void) : AbstractCommand(QUIT_COMMAND)
{
	
}

Quit::Quit(Quit const &instance)
{
	*this = instance;
}

Quit::~Quit(void)
{
	
}

Quit &	Quit::operator=(Quit const &rhs)
{
	static_cast<void>(rhs);
	return *this;
}

std::string	Quit::getHelp(void)
{
	return (_name + " # exit the debugger");
}

std::string	Quit::getShortHelp(void)
{
	return ("exit the debugger");
}