/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractCommand.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 12:52:34 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/19 13:06:17 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AbstractCommand.hpp"

AbstractCommand::AbstractCommand(void)
{
	
}

AbstractCommand::AbstractCommand(std::string name) : _name(name)
{
	
}

AbstractCommand::AbstractCommand(AbstractCommand const &instance)
{
	*this = instance;
}

AbstractCommand::~AbstractCommand(void)
{
	
}

AbstractCommand &	AbstractCommand::operator=(AbstractCommand const &rhs)
{
	static_cast<void>(rhs);
	return *this;
}