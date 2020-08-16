/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SetCommand.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 12:29:04 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/27 16:32:03 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SetCommand.hpp"
#include "DebuggerContext.hpp"

// class DebuggerVariable;
class DebuggerContext;

SetCommand::SetCommand(void) : AbstractCommand("set")
{
	
}

SetCommand::SetCommand(SetCommand const &instance) : AbstractCommand(instance)
{
	*this = instance;
}

SetCommand::~SetCommand(void)
{
	
}

SetCommand &	SetCommand::operator=(SetCommand const &rhs)
{
	static_cast<void>(rhs);
	return *this;
}

std::string	SetCommand::getHelp(void)
{
	return (_name + " *offset = value\t# assigns value at offset in the cpu memory"\
		"\n\t" + _name + " $variable = value\t# assigns value to $variable");
}

std::string	SetCommand::getShortHelp(void)
{
	return ("set registers, variables or directly the CPU memory");
}

int	SetCommand::execute(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	DebuggerVariable *variable;
	int toAssign = ast.getChild(3)->getTraversed(context);
	
	ast.getChild(1)->getTraversed(context);
	if (context.address_descriptor.type == ADDRESS_DESCRIPTOR_TYPE_ADDRESS)
	{
		if (toAssign > 0xff)
			write_16(context.debugger->getCPU(), context.address_descriptor.address.getValue(), toAssign);
		else
			write_8(context.debugger->getCPU(), context.address_descriptor.address.getValue(), toAssign);
	}
	else
	{
		variable = context.address_descriptor.variable;
		variable->setValue(toAssign);
	}
	return (0);
}
