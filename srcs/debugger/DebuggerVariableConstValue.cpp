/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DebuggerVariableConstValue.cpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 18:26:28 by ldedier           #+#    #+#             */
/*   Updated: 2020/05/30 11:50:49 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DebuggerVariableConstValue.hpp"

DebuggerVariableConstValue::DebuggerVariableConstValue(void) : DebuggerVariableValue()
{
	
}

DebuggerVariableConstValue::DebuggerVariableConstValue(int value) : DebuggerVariableValue(value)
{
	
}

DebuggerVariableConstValue::~DebuggerVariableConstValue(void)
{
	
}

void	DebuggerVariableConstValue::setValue(int value)
{
	static_cast<void>(value);
	std::cerr << "Left operand of assignment is not a modifiable lvalue." << std::endl;
}