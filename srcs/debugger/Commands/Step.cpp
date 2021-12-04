/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Step.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 18:46:38 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/27 16:44:38 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Step.hpp"

Step::Step(void) : AbstractCommand(STEP_COMMAND)
{
	
}

Step::Step(Step const &instance) : AbstractCommand(instance)
{
	*this = instance;
}

Step::~Step(void)
{
	
}

Step &	Step::operator=(Step const &rhs)
{
	static_cast<void>(rhs);
	return *this;
}

std::string	Step::getHelp(void)
{
	return (_name + " # go to the next instruction");
}

std::string	Step::getShortHelp(void)
{
	return ("go to the next instruction");
}

int	Step::execute(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	static_cast<void>(ast);
	static_cast<void>(context);
	return (0);
}
