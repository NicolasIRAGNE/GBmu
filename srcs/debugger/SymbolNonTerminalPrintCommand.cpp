/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalPrintCommand.cpp                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:38:32 by ldedier           #+#    #+#             */
/*   Updated: 2020/05/14 20:25:03 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolNonTerminalPrintCommand.hpp"
# include <iomanip>
# include <bitset>

SymbolNonTerminalPrintCommand::SymbolNonTerminalPrintCommand(void) : AbstractNonTerminal("printcommand")
{
	
}

SymbolNonTerminalPrintCommand::~SymbolNonTerminalPrintCommand(void)
{
	
}

int	SymbolNonTerminalPrintCommand::traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	int res;

	res = ast.getChild(1)->getTraversed(context);
	if (context.printCommandSuffixParams.precised & PRECISED_UNIT)
	{
		std::cerr << "Size letters are meaningless in \"print\" command." << std::endl;
		return (1);
	}
	if (context.printCommandSuffixParams.count != 1)
	{
		std::cerr << "Item count other than 1 is meaningless in \"print\" command." << std::endl;
		return (1);
	}
	if (context.printCommandSuffixParams.format == PrintCommandSuffixParams::E_FORMAT_DECIMAL
		|| context.printCommandSuffixParams.format == PrintCommandSuffixParams::E_FORMAT_OCTAL
	 	|| context.printCommandSuffixParams.format == PrintCommandSuffixParams::E_FORMAT_HEXADECIMAL)
	{
		std::cout << std::setbase(context.printCommandSuffixParams.format) << std::showbase << res << std::endl;
		std::cout << std::setbase(10);
	}
	else if (context.printCommandSuffixParams.format == PrintCommandSuffixParams::E_FORMAT_BINARY)
	{
		std::cout << std::bitset<32>(res) << std::endl;
	}
	else
	{
		std::cerr << context.printCommandSuffixParams.getFormatChar() << " : format not implemented yet" << std::endl;
	}
	return (0);
}

void	SymbolNonTerminalPrintCommand::computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg)
{
	addProduction(cfg, {"print", "printcommandsuffix"});
}
