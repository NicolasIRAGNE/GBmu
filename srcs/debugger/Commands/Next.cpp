/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Next.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 18:45:13 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/19 18:52:54 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Next.hpp"

Next::Next(void) : AbstractCommand(NEXT_COMMAND)
{
	
}

Next::Next(Next const &instance)
{
	*this = instance;
}

Next::~Next(void)
{
	
}

Next &	Next::operator=(Next const &rhs)
{
	static_cast<void>(rhs);
	return *this;	
}

std::string	Next::getHelp(void)
{
	return (_name + " # go to the next instruction, jumping over calls");
}

std::string	Next::getShortHelp(void)
{
	return ("go to the next instruction, jumping over calls");
}