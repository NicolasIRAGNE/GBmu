/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Info.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 18:25:45 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/27 16:43:56 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Info.hpp"
#include "DebuggerContext.hpp"

Info::Info(void) : AbstractCommand(INFO_COMMAND)
{
	
}

Info::Info(Info const &instance)
{
	*this = instance;	
}

Info::~Info(void)
{
	
}

Info &	Info::operator=(Info const &rhs)
{
	static_cast<void>(rhs);
	return *this;
}

std::string	Info::getHelp(void)
{
	return (_name + " # print info about the current context");
}

std::string	Info::getShortHelp(void)
{
	return ("print info about the current context");
}

int	Info::execute(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	static_cast<void>(ast);
	context.debugger->showInfo();
	return (0);
}