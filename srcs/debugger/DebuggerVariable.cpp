/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DebuggerVariable.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 20:01:16 by ldedier           #+#    #+#             */
/*   Updated: 2020/05/30 16:26:30 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DebuggerVariable.hpp"

DebuggerVariable::DebuggerVariable(void)
{
	
}

DebuggerVariable::DebuggerVariable(DebuggerVariable const &instance)
{
	*this = instance;
}

DebuggerVariable::~DebuggerVariable(void)
{
	
}

DebuggerVariable &	DebuggerVariable::operator=(DebuggerVariable const &rhs)
{
	static_cast<void>(rhs);
	return *this;
}