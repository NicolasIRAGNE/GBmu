/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Print.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 17:19:50 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/27 16:35:51 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Print.hpp"
#include "DebuggerContext.hpp"
#include <iomanip>

Print::Print(void) : AbstractCommand(PRINT_COMMAND)
{
	
}

Print::Print(Print const &instance) : AbstractCommand(instance)
{
	*this = instance;
}

Print::~Print(void)
{
	
}

Print &	Print::operator=(Print const &rhs)
{
	static_cast<void>(rhs);
	return *this;
}

std::string	Print::getHelp(void)
{
	return (_name + "/format value\t# print value in the precised format"\
		"\navailable formats:"
		"\n\td : decimal"
		"\n\tx : hexadecimal"
		"\n\to : octal"
		"\n\tb : binary"
		"\n\ti : instruction");
}

std::string	Print::getShortHelp(void)
{
	return ("print a given value by a given format");
}

int	Print::execute(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	int res;

	res = ast.getChild(1)->getTraversed(context);
	if (context.printCommandSuffixParams.precised & PRECISED_UNIT)
	{
		std::cerr << "Size letters are meaningless in \"print\" command." << std::endl;
		return (1);
	}
	if (context.printCommandSuffixParams.count != 1)
	{
		std::cerr << "Item count other than 1 is meaningless in \"print\" command." << std::endl;
		return (1);
	}

	context.debugger->addValue(res);
	std::cout << "$" << context.debugger->getHistoryCounter() << " = ";

	if (context.printCommandSuffixParams.format == PrintCommandSuffixParams::E_FORMAT_DECIMAL
		|| context.printCommandSuffixParams.format == PrintCommandSuffixParams::E_FORMAT_OCTAL
	 	|| context.printCommandSuffixParams.format == PrintCommandSuffixParams::E_FORMAT_HEXADECIMAL)
	{
		std::cout << std::setbase(context.printCommandSuffixParams.format) << std::showbase;
	}
	context.printCommandSuffixParams.printValue<int>(std::cout, res, true);
	std::cout << std::endl << std::setbase(10);
	return (0);
}
