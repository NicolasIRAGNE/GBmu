/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DebuggerAddress.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 14:50:49 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/15 15:36:47 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DebuggerAddress.hpp"
#include "DebuggerColors.h"
# include <iomanip>


DebuggerAddress::DebuggerAddress(void) : _value(0)
{
	
}

DebuggerAddress::DebuggerAddress(uint16_t value) : _value(value)
{
	
}

DebuggerAddress::DebuggerAddress(DebuggerAddress const &instance)
{
	*this = instance;
}

DebuggerAddress::~DebuggerAddress(void)
{
	
}

DebuggerAddress &	DebuggerAddress::operator=(DebuggerAddress const &rhs)
{
	this->_value = rhs._value;
	return *this;
}

void	DebuggerAddress::setValue(uint16_t value)
{
	this->_value = value;
}

uint16_t	DebuggerAddress::getValue(void) const
{
	return (this->_value);
}

bool	DebuggerAddress::operator<(const DebuggerAddress & debuggerAddress) const
{
	return this->_value < debuggerAddress.getValue();	
}

std::ostream &	operator<<(std::ostream &o, DebuggerAddress const &instance)
{
	o << DEBUGGER_BLUE << std::setbase(16) << std::showbase << instance.getValue() << std::setbase(10) << DEBUGGER_EOC;
	return o;
}

