/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Next.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 18:45:13 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/26 18:58:33 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Next.hpp"

Next::Next(void) : AbstractCommand(NEXT_COMMAND)
{
	
}

Next::Next(Next const &instance)
{
	*this = instance;
}

Next::~Next(void)
{
	
}

Next &	Next::operator=(Next const &rhs)
{
	static_cast<void>(rhs);
	return *this;	
}

std::string	Next::getHelp(void)
{
	return (_name + " # go to the next instruction, jumping over calls");
}

std::string	Next::getShortHelp(void)
{
	return ("go to the next instruction, jumping over calls");
}

int Next::execute(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	static_cast<void>(ast);
	static_cast<void>(context);
	return (0);
}