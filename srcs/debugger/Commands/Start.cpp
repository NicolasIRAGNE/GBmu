/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Start.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 17:58:51 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/30 01:34:31 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Start.hpp"
#include "DebuggerContext.hpp"

Start::Start(void) : AbstractCommand(START_COMMAND)
{
	
}

Start::Start(Start const &instance) : AbstractCommand(instance)
{
	*this = instance;
}

Start::~Start(void)
{
	
}

Start &	Start::operator=(Start const &rhs)
{
	static_cast<void>(rhs);
	return *this;
}

std::string	Start::getHelp(void)
{
	return (_name + " # run the program from the beginning");

}

std::string	Start::getShortHelp(void)
{
	return ("run the program from the beginning");
}

int	Start::execute(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	static_cast<void>(ast);
	context.debugger->getCPU()->reg.pc = 150;
	context.quit = 1;
	return (0);
}
