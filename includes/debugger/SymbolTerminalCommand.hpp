/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalCommand.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 21:15:29 by ldedier           #+#    #+#             */
/*   Updated: 2020/05/03 20:44:19 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMBOLTERMINALCOMMAND_HPP
# define SYMBOLTERMINALCOMMAND_HPP

# include "AbstractTerminal.hpp"
# include "DebuggerContext.hpp"

class SymbolTerminalCommand : public AbstractTerminal<int, DebuggerContext &>
{
	public:
		SymbolTerminalCommand(void);
		SymbolTerminalCommand(std::string identifier);
		virtual ~SymbolTerminalCommand(void);
		virtual bool isEligibleForCurrent(std::string & current);
		virtual bool staysEligibleForCurrent(std::string & current);
		bool canBeAdded(std::deque<Token<int, DebuggerContext &> *>	& res);

		// virtual int traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const = 0;

};


#endif
