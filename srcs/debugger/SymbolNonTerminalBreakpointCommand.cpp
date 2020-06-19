/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalBreakpointCommand.cpp             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:38:32 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/19 18:20:28 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolNonTerminalBreakpointCommand.hpp"

SymbolNonTerminalBreakpointCommand::SymbolNonTerminalBreakpointCommand(void) : AbstractNonTerminal("breakpointcommand")
{
	
}

SymbolNonTerminalBreakpointCommand::~SymbolNonTerminalBreakpointCommand(void)
{
	
}

int	SymbolNonTerminalBreakpointCommand::traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	DebuggerAddress		address;
	std::list<uint32_t>	list;
	size_t i;

	if (ast.getChildren().size() == 1)
		address = DebuggerAddress(context.debugger->getCPU()->reg.pc);
	else
		address = DebuggerAddress(ast.getChild(1)->getTraversed(context));

	context.debugger->getBreakpointValuesList(address, &list);
	if (list.size())
	{
		std::cout << "note: ";
		if (list.size() == 1)
			std::cout << "breakpoint " << list.front() << " also set at pc " << address << std::endl;
		else
		{
			i = 0;
			std::cout << "breakpoints ";
			for (auto const &elt : list)
			{
				if (++i == list.size())
					std::cout << " and " << elt << " also set at pc " << address << std::endl;
				else
				{
					std::cout << elt;
					if (i != list.size() - 1)
						std::cout << ", ";
				}
			}
		}
	}
	context.debugger->addBreakpointValuesList(address);
	std::cout << "Breakpoint " << context.debugger->getCounter() << " at " << address << std::endl;
	return (0);
}

void	SymbolNonTerminalBreakpointCommand::computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg)
{
	addProduction(cfg, {"break", "address"});
	addProduction(cfg, {"break"});
}
