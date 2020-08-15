/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Registers.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 18:37:39 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/27 16:44:29 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Registers.hpp"
#include "DebuggerContext.hpp"

Registers::Registers(void) : AbstractCommand(REGISTERS_COMMAND)
{
	
}

Registers::Registers(Registers const &instance)
{
	*this = instance;
}

Registers::~Registers(void)
{
	
}

Registers &	Registers::operator=(Registers const &rhs)
{
	static_cast<void>(rhs);
	return *this;
}

std::string	Registers::getHelp(void)
{
	return (_name + " # show the registers values");
}

std::string	Registers::getShortHelp(void)
{
	return ("show the registers values");
}


int	Registers::execute(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	static_cast<void>(ast);
	context.debugger->showRegisters();
	return (0);
}
