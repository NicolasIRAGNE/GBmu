/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DebuggerVariableValue.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 16:10:33 by ldedier           #+#    #+#             */
/*   Updated: 2020/05/30 16:27:54 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DebuggerVariableValue.hpp"

DebuggerVariableValue::DebuggerVariableValue(void) : _value(0)
{
	
}

DebuggerVariableValue::DebuggerVariableValue(int value): _value(value)
{
	
}

DebuggerVariableValue::DebuggerVariableValue(DebuggerVariableValue const &instance)
{
	*this = instance;
}

DebuggerVariableValue::~DebuggerVariableValue(void)
{
	
}

DebuggerVariableValue &	DebuggerVariableValue::operator=(DebuggerVariableValue const &rhs)
{
	this->_value = rhs._value;
	return *this;
}

void	DebuggerVariableValue::setValue(int value)
{
	this->_value = value;
}

int	DebuggerVariableValue::getValue()
{
	return (this->_value);
}