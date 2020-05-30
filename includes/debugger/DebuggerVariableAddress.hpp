/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DebuggerVariableAddress.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 15:47:01 by ldedier           #+#    #+#             */
/*   Updated: 2020/05/29 16:51:33 by ldedier          ###   ########.fr       */
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

	private:
		T *_address;

};

#endif