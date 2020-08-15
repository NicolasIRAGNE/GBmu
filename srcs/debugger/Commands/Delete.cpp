/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Delete.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 18:39:55 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/27 16:43:21 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Delete.hpp"
# include "DebuggerContext.hpp"
# include "Token.hpp"

Delete::Delete(void) : AbstractCommand(DELETE_COMMAND)
{
	
}

Delete::Delete(Delete const &instance)
{
	*this = instance;
}

Delete::~Delete(void)
{
	
}

Delete &	Delete::operator=(Delete const &rhs)
{
	static_cast<void>(rhs);
	return *this;
}

std::string	Delete::getHelp(void)
{
	return (_name +  "\t\t\t\t# delete all breakpoints"\
		"\n\t" + _name + " index1 index2 index3 ...\t# delete all breakpoints with index{1, 2, 3, ...}");
}

std::string	Delete::getShortHelp(void)
{
	return ("delete a breakpoint or a watchpoint given the corresponding index");
}

int	Delete::execute(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	if (ast.getChildren().size() == 1)
		context.debugger->removeAllBreakpoints();
	else
	{
		for (auto & elt : ast.getChild(1)->getChildren())
		{
			context.debugger->deleteValue(elt->getToken()->getIntValue());
		}
	}
	return (0);
}
