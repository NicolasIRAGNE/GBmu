/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Help.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 18:30:40 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/27 16:45:05 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Help.hpp"
#include "DebuggerContext.hpp"

Help::Help(void) : AbstractCommand(HELP_COMMAND)
{
	
}

Help::Help(Help const &instance) : AbstractCommand(instance)
{
	*this = instance;
}

Help::~Help(void)
{
	
}

Help &	Help::operator=(Help const &rhs)
{
	static_cast<void>(rhs);
	return *this;
}

std::string	Help::getHelp(void)
{
	return (_name + "\t\t# display all commands short description "\
	"\n\t" + _name + " command\t# display information about the given command");
}

std::string	Help::getShortHelp(void)
{
	return ("display this help message, can also be specified one of theses command name");
}

int Help::execute(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	if (ast.getChildren().size() == 1)
		context.debugger->showHelp();
	else
		context.debugger->showHelpCommand(ast.getChild(1)->getChild(0)->getSymbol().getIdentifier());
	return (0);
}
