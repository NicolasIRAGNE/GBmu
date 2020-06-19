/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Set.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 12:29:04 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/19 18:48:25 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Set.hpp"

Set::Set(void) : AbstractCommand("set")
{
	
}

Set::Set(Set const &instance)
{
	*this = instance;
}

Set::~Set(void)
{
	
}

Set &	Set::operator=(Set const &rhs)
{
	static_cast<void>(rhs);
	return *this;
}

std::string	Set::getHelp(void)
{
	return (_name + " *offset = value\t# assigns value at offset in the cpu memory"\
		"\n\t" + _name + " $variable = value\t# assigns value to $variable");
}

std::string	Set::getShortHelp(void)
{
	return ("set registers, variables or directly the CPU memory");
}