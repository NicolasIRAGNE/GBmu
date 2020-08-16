/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WatchPoint.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/14 18:08:06 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/15 20:13:01 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WatchPoint.hpp"

WatchPoint::WatchPoint(uint8_t *ptr) : _en(E_WATCHPOINT_POINTER_8)
{
	this->_un.ptr = ptr;	
}

WatchPoint::WatchPoint(uint16_t *ptr) : _en(E_WATCHPOINT_POINTER_16)
{
	this->_un.ptr = ptr;	
}

WatchPoint::WatchPoint(DebuggerAddress address) : _en(E_WATCHPOINT_ADDRESS)
{
	this->_un.address = address;	
}

WatchPoint::WatchPoint(WatchPoint const &instance)
{
	*this = instance;
}

WatchPoint::~WatchPoint(void)
{
	
}

WatchPoint::WatchPoint(void)
{
	
}

WatchPoint &	WatchPoint::operator=(WatchPoint const &rhs)
{
	this->_en = rhs._en;
	if (this->_en == E_WATCHPOINT_ADDRESS)
		this->_un.address = rhs._un.address;
	else
		this->_un.ptr = rhs._un.ptr;
	return *this;
}

bool	WatchPoint::operator<(const WatchPoint & watchPoint) const
{
	int res;

	if ((res = this->_en - watchPoint._en))
		return res < 0;
	else
	{
		if (this->_en == E_WATCHPOINT_ADDRESS)
			return this->_un.address < watchPoint._un.address;
		else
			return this->_un.ptr < watchPoint._un.ptr;
	}
}

int WatchPoint::getEnum(void) const
{
	return _en;
}

DebuggerAddress	WatchPoint::getAddress(void) const
{
	return (this->_un.address);
}

void *	WatchPoint::getPointer(void) const
{
	return (this->_un.ptr);
}

std::ostream &	operator<<(std::ostream &o, WatchPoint const &instance)
{
	if (instance.getEnum() == WatchPoint::E_WATCHPOINT_ADDRESS)
		o << instance.getAddress();
	else
	{
		// if (instance.getEnum() == WatchPoint::E_WATCHPOINT_POINTER_8)
		// 	o << "uint8_t *: ";
		// else
		// 	o << "uint16_t *: ";
		o << instance.getPointer();
	}
	return o;
}
