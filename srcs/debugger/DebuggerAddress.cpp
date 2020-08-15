/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DebuggerAddress.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 14:50:49 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/25 16:36:27 by ldedier          ###   ########.fr       */
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

bool DebuggerAddress::operator!=(const DebuggerAddress & debuggerAddress) const
{
	return this->_value != debuggerAddress.getValue();	
}

DebuggerAddress DebuggerAddress::operator++(int dummy)
{
	DebuggerAddress copy(*this);

	static_cast<void>(dummy);
	_value++;
	return copy;
}


void DebuggerAddress::operator+=(const int toAdd)
{
	_value += toAdd;
}

std::ostream &	operator<<(std::ostream &o, DebuggerAddress const &instance)
{
	std::ios_base::fmtflags f(o.flags());

	o << DEBUGGER_BLUE << std::setbase(16) << std::showbase << instance.getValue() << DEBUGGER_EOC;
	o.flags(f);
	return o;
}