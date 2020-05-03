/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalPrintingCommand.hpp                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 12:59:25 by ldedier           #+#    #+#             */
/*   Updated: 2020/05/03 13:22:56 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SYMBOLTERMINALPRINTINGCOMMAND_HPP
# define SYMBOLTERMINALPRINTINGCOMMAND_HPP

# include "SymbolTerminalCommand.hpp"
# include "DebuggerContext.hpp"

class SymbolTerminalPrintingCommand : public SymbolTerminalCommand
{
	public:
		SymbolTerminalPrintingCommand(void);
		SymbolTerminalPrintingCommand(std::string identifier);
		virtual ~SymbolTerminalPrintingCommand(void);
		virtual bool shouldCreateToken(std::string tokenContent
		, char delimiter
		, std::deque<Token<int, DebuggerContext &> *>	& res);
		// virtual int traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const = 0;

};

#endif
