/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Run.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 18:07:11 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/30 01:33:04 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Run.hpp"
#include "DebuggerContext.hpp"

Run::Run(void) : AbstractCommand(RUN_COMMAND)
{
	
}

Run::Run(Run const &instance) : AbstractCommand(instance)
{
	*this = instance;
}

Run::~Run(void)
{
	
}

Run &	Run::operator=(Run const &rhs)
{
	static_cast<void>(rhs);
	return *this;
}

std::string	Run::getHelp(void)
{
	return (_name + " # run the program from the beginning");
}

std::string	Run::getShortHelp(void)
{
	return ("run the program from the beginning");
}

int	Run::execute(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	static_cast<void>(ast);
	context.quit = 1; 
	return (0);
}
