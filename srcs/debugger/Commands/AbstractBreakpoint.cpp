/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractBreakpoint.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 18:21:37 by ldedier           #+#    #+#             */
/*   Updated: 2020/08/15 14:53:22 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AbstractBreakpoint.hpp"
#include "DebuggerContext.hpp"

AbstractBreakpoint::AbstractBreakpoint(std::string name, std::string const type) : AbstractCommand(name), _type(type)
{
	
}

AbstractBreakpoint::~AbstractBreakpoint(void)
{
	
}

AbstractBreakpoint::AbstractBreakpoint(void) 
{

}

AbstractBreakpoint &AbstractBreakpoint::operator=(AbstractBreakpoint const &rhs)
{
	static_cast<void>(rhs);
	return *this;
}

AbstractBreakpoint::AbstractBreakpoint(AbstractBreakpoint const &instance) : AbstractCommand(instance)
{
	*this = instance;
}

std::string	AbstractBreakpoint::getHelp(void)
{
	return (_name + "\t\t# add a " + _type + " breakpoint to the current pc"\
		"\n\t" + _name + " * offset\t# add a " + _type + " breakpoint to offset \"offset\"");
}

std::string	AbstractBreakpoint::getShortHelp(void)
{
	return ("add a " + _type + " breakpoint to the current pc or at some given address");
}

int	AbstractBreakpoint::execute(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	DebuggerAddress		address;
	std::list<uint32_t>	list;
	size_t i;

	if (ast.getChildren().size() == 1)
		address = DebuggerAddress(context.debugger->getCPU()->reg.pc);
	else
		address = DebuggerAddress(ast.getChild(1)->getTraversed(context));

	context.debugger->getBreakpointValuesList(address, &list, nullptr, nullptr);
	if (list.size())
	{
		std::cout << "note: ";
		if (list.size() == 1)
			std::cout << "breakpoint " << list.front() << " also set at pc " << address << std::endl;
		else
		{
			i = 0;
			std::cout << "breakpoints ";
			for (auto const &elt : list)
			{
				if (++i == list.size())
					std::cout << " and " << elt << " also set at pc " << address << std::endl;
				else
				{
					std::cout << elt;
					if (i != list.size() - 1)
						std::cout << ", ";
				}
			}
		}
	}
	addBreakpointToDebugger(context.debugger, address.getValue());
	std::cout << "Breakpoint " << context.debugger->getCounter() << " at " << address << std::endl;
	return (0);
}
