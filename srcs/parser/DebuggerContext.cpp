/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DebuggerContext.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:38:32 by ldedier            #+#    #+#            */
/*   Updated: 2020/05/01 16:38:32 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "DebuggerContext.hpp"

DebuggerContext::DebuggerContext(void) 
{
	
}

DebuggerContext::DebuggerContext(DebuggerContext const &instance)
{
	*this = instance;
}

DebuggerContext::~DebuggerContext(void)
{
	
}

DebuggerContext & DebuggerContext::operator=(DebuggerContext const &rhs)
{
	static_cast<void>(rhs);
	return *this;
}
