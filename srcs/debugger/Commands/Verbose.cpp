/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Verbose.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 18:48:42 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/19 18:51:47 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Verbose.hpp"

Verbose::Verbose(void) : AbstractCommand(VERBOSE_COMMAND)
{
	
}

Verbose::Verbose(Verbose const &instance)
{
	*this = instance;
}

Verbose::~Verbose(void)
{
	
}

Verbose &	Verbose::operator=(Verbose const &rhs)
{
	static_cast<void>(rhs);
	return *this;
}

std::string	Verbose::getHelp(void)
{
	return (_name + " number\t# set the verbose level to number");
}

std::string	Verbose::getShortHelp(void)
{
	return ("set the verbose level to some value");
}