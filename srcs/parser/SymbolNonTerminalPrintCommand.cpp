/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalPrintCommand.cpp                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:38:32 by ldedier           #+#    #+#             */
/*   Updated: 2020/05/02 19:12:43 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolNonTerminalPrintCommand.hpp"
# include <iomanip>

SymbolNonTerminalPrintCommand::SymbolNonTerminalPrintCommand(void) : AbstractNonTerminal("printcommand")
{
	
}

SymbolNonTerminalPrintCommand::~SymbolNonTerminalPrintCommand(void)
{
	
}

int	SymbolNonTerminalPrintCommand::traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	int res;

	if (ast.getChildren().size() > 2)
	{
		ast.getChild(2)->getTraversed(context); //fill format
		res = ast.getChild(3)->getTraversed(context);
	}
	else
	{
		context.format = DebuggerContext::E_DEBUGGER_FORMAT_DECIMAL;
		res = ast.getChild(1)->getTraversed(context);
	}
	std::cout << std::setbase(context.format);
	std::cout << res << std::endl; 
	return (0);
}

void	SymbolNonTerminalPrintCommand::computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg)
{
	addProduction(cfg, {"print", "value"});
	addProduction(cfg, {"print", "/", "format", "value"});
}
