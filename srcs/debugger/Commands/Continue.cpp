/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Continue.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 18:40:27 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/30 01:35:21 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Continue.hpp"
#include "DebuggerContext.hpp"

Continue::Continue(void) : AbstractCommand(CONTINUE_COMMAND)
{
	
}

Continue::Continue(Continue const &instance)
{
	*this = instance;
}

Continue::~Continue(void)
{
	
}

Continue &	Continue::operator=(Continue const &rhs)
{
	static_cast<void>(rhs);
	return *this;
}

std::string	Continue::getHelp(void)
{
	return (_name + " # continue the rom execution");

}

std::string	Continue::getShortHelp(void)
{
	return ("continue the rom execution");
	
}

int	Continue::execute(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	static_cast<void>(ast);
	context.quit = 1; 
	return (0);
}