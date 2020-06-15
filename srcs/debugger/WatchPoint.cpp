/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WatchPoint.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/14 18:08:06 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/15 15:22:49 by ldedier          ###   ########.fr       */
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