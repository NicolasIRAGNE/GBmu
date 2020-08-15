/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   XCommand.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 17:45:57 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/27 16:41:51 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "XCommand.hpp"
#include <iomanip>
# include "DebuggerContext.hpp"
# include "DebuggerAddress.hpp"

XCommand::XCommand(void) : AbstractCommand(X_COMMAND)
{
	
}

XCommand::XCommand(XCommand const &instance)
{
	*this = instance;
}

XCommand::~XCommand(void)
{
	
}

XCommand &	XCommand::operator=(XCommand const &rhs)
{
	static_cast<void>(rhs);
	return *this;
}

std::string	XCommand::getHelp(void)
{
	return (_name + "/format offset # print the content of the address at offset \"offset\" in the precised format"\
		"\navailable formats:"
		"\n\td : decimal"
		"\n\tx : hexadecimal"
		"\n\to : octal"
		"\n\tb : binary"
		"\n\ti : instruction");
}

std::string	XCommand::getShortHelp(void)
{
	return ("print the content of the cpu given an offset");
}

uint16_t read_8_as_16(struct gb_cpu_s* cpu, uint16_t a16)
{
	return static_cast<uint16_t>(read_8(cpu, a16));
}

int	XCommand::execute(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	int res;
	DebuggerAddress address;
	DebuggerAddress goalAddress;
	int i;
	uint16_t		(*func)(struct gb_cpu_s*, uint16_t);
	
	res = ast.getChild(1)->getTraversed(context);
	if (context.printCommandSuffixParams.format == PrintCommandSuffixParams::E_FORMAT_DECIMAL
		|| context.printCommandSuffixParams.format == PrintCommandSuffixParams::E_FORMAT_OCTAL
	 	|| context.printCommandSuffixParams.format == PrintCommandSuffixParams::E_FORMAT_HEXADECIMAL)
	{
		std::cout << std::setbase(context.printCommandSuffixParams.format) << std::showbase;
	}

	address = DebuggerAddress(std::min(res, res + context.printCommandSuffixParams.count * context.printCommandSuffixParams.unit));
	int n = 0;
	int goal;
	if (context.printCommandSuffixParams.unit == 2)
		func = &read_16;
	else
		func = &read_8_as_16;

	goal = std::abs(context.printCommandSuffixParams.count);
	while (n < goal)
	{
		i = 0;
		std::cout << address << ":\t";
		while (i < (8 / context.printCommandSuffixParams.unit) && n < goal)
		{
			context.printCommandSuffixParams.printValue<uint16_t>(std::cout, func(context.debugger->getCPU(), address.getValue()), false);
			std::cout << "\t";
			address += context.printCommandSuffixParams.unit;
			i++;
			n++;
		}
		std::cout << std::endl;
	}
	std::cout << std::setbase(10);
	return (0);
}