/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Quit.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 18:08:14 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/27 16:41:30 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Quit.hpp"
# include "DebuggerContext.hpp"

Quit::Quit(void) : AbstractCommand(QUIT_COMMAND)
{
	
}

Quit::Quit(Quit const &instance)
{
	*this = instance;
}

Quit::~Quit(void)
{
	
}

Quit &	Quit::operator=(Quit const &rhs)
{
	static_cast<void>(rhs);
	return *this;
}

std::string	Quit::getHelp(void)
{
	return (_name + " # exit the debugger");
}

std::string	Quit::getShortHelp(void)
{
	return ("exit the debugger");
}

int	Quit::execute(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	static_cast<void>(ast);
	context.quit = true;
	context.debugger->getCPU()->running = false;
	return (0);
}