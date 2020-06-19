/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Info.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 18:25:45 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/19 18:27:25 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Info.hpp"

Info::Info(void) : AbstractCommand(INFO_COMMAND)
{
	
}

Info::Info(Info const &instance)
{
	*this = instance;	
}

Info::~Info(void)
{
	
}

Info &	Info::operator=(Info const &rhs)
{
	static_cast<void>(rhs);
	return *this;
}

std::string	Info::getHelp(void)
{
	return (_name + " # print info about the current context");
}

std::string	Info::getShortHelp(void)
{
	return ("print info about the current context");
}