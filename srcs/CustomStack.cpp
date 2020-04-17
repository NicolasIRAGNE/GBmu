/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CustomStack.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 03:08:44 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/17 03:08:44 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "CustomStack.hpp"

CustomStack::CustomStack(void) 
{
	
}

CustomStack::CustomStack(CustomStack const &instance)
{
	*this = instance;
}

CustomStack::~CustomStack(void)
{
	
}

CustomStack & CustomStack::operator=(CustomStack const &rhs)
{
	static_cast<void>(rhs);
	return *this;
}
