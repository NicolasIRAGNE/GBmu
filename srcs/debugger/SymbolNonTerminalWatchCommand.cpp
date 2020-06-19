/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalWatchCommand.cpp                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:38:32 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/18 21:57:37 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolNonTerminalWatchCommand.hpp"
# include "WatchModes.hpp"
# include "DebuggerVariableAddress.hpp"
# include "libyacc_wrapper.h"

SymbolNonTerminalWatchCommand::SymbolNonTerminalWatchCommand(void) : AbstractNonTerminal("watchcommand")
{
	
}

SymbolNonTerminalWatchCommand::~SymbolNonTerminalWatchCommand(void)
{
	
}

void SymbolNonTerminalWatchCommand::addWatchPoint(Debugger *debugger, const std::string & mode
	, WatchPoint &watchPoint, Debugger::e_watchpoint_mode_id id)
{
	std::list<uint32_t> list;
	size_t i;

	debugger->getWatchpointValuesList(watchPoint, &list, id);
	if (list.size())
	{
		std::cout << "note: ";
		if (list.size() == 1)
			std::cout << mode << " watchpoint " << list.front() << " also set at " << watchPoint << std::endl;
		else
		{
			i = 0;
			std::cout << mode << " watchpoints ";
			for (auto const &elt : list)
			{
				if (++i == list.size())
					std::cout << " and " << elt << " also set at " << watchPoint << std::endl;
				else
				{
					std::cout << elt;
					if (i != list.size() - 1)
						std::cout << ", ";
				}
			}
		}
	}
	debugger->addWatchpointValuesList(watchPoint, id);
	std::cout << mode << " watchpoint " << debugger->getCounter() << " at " << watchPoint << std::endl;
}

int	SymbolNonTerminalWatchCommand::traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	WatchPoint							watchPoint;
	DebuggerVariableAddress<uint8_t>	*addressVariable8;
	DebuggerVariableAddress<uint16_t>	*addressVariable16;
	
	if (ast.getChildren().size() == 3)
	{
		ast.getChild(1)->getTraversed(context); // fill context.watchModes
		ast.getChild(2)->getTraversed(context); // fill assignable
	}
	else
	{
		context.watchModes = WATCH_MODE_WRITE;
		ast.getChild(1)->getTraversed(context); // fill assignable
	}
	if (context.address_descriptor.type == ADDRESS_DESCRIPTOR_TYPE_ADDRESS)
		watchPoint = WatchPoint(context.address_descriptor.address);
	else
	{
		if ((addressVariable8 = dynamic_cast<DebuggerVariableAddress<uint8_t> *>(context.address_descriptor.variable)) != nullptr)
			watchPoint = WatchPoint(addressVariable8->getAddress());
		else if ((addressVariable16 = dynamic_cast<DebuggerVariableAddress<uint16_t> *>(context.address_descriptor.variable)) != nullptr)
			watchPoint = WatchPoint(addressVariable16->getAddress());
		else
		{
			std::cerr << "Not a watchable value." << std::endl;
			return (1);
		}
	}
	if (context.watchModes & WATCH_MODE_WRITE)
		addWatchPoint(context.debugger, "write", watchPoint, Debugger::E_WATCHPOINTS_WRITE);
	if (context.watchModes & WATCH_MODE_READ)
		addWatchPoint(context.debugger, "read", watchPoint, Debugger::E_WATCHPOINTS_READ);
	return (0);
}

void	SymbolNonTerminalWatchCommand::computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg)
{
	addProduction(cfg, {"watch", "watchmodes", "assignable"});
	addProduction(cfg, {"watch", "assignable"});
}
