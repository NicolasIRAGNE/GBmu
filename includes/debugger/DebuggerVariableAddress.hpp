/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DebuggerVariableAddress.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 15:47:01 by ldedier           #+#    #+#             */
/*   Updated: 2021/06/04 13:02:23 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUGGERVARIABLEADDRESS_HPP
# define DEBUGGERVARIABLEADDRESS_HPP

# include <iostream>
# include "DebuggerVariable.hpp"

template<typename T>
class DebuggerVariableAddress : public DebuggerVariable
{
	public:
	DebuggerVariableAddress(void) : _address(nullptr)
	{
		
	}

	DebuggerVariableAddress(T *address): _address(address)
	{
		
	}

	DebuggerVariableAddress(DebuggerVariableAddress const &instance)
	{
		*this = instance;
	}

	~DebuggerVariableAddress(void)
	{
		
	}

	DebuggerVariableAddress &	operator=(DebuggerVariableAddress const &rhs)
	{
		static_cast<void>(rhs);
		return *this;
	}

	void	setValue(int value)
	{
		*_address = value;
	}

	int	getValue()
	{
		return (static_cast<int>(*this->_address));
	}

	T	*getAddress()
	{
		return _address;
	}

	private:
		T *_address;

};

#endif