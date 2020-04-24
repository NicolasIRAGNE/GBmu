/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalCommand.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 21:15:29 by ldedier           #+#    #+#             */
/*   Updated: 2020/04/30 21:36:46 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMBOLTERMINALCOMMAND_HPP
# define SYMBOLTERMINALCOMMAND_HPP

# include "AbstractTerminal.hpp"
# include "DebuggerContext.hpp"

class SymbolTerminalCommand : public AbstractTerminal<int, DebuggerContext &>
{
	public:
		SymbolTerminalCommand(void) : AbstractTerminal()
		{

		}

		SymbolTerminalCommand(std::string identifier) : AbstractTerminal(identifier)
		{

		}

		~SymbolTerminalCommand(void)
		{

		}

		bool isEligibleForCurrent(std::string & current)
		{
			return AbstractTerminal::staysEligibleForCurrent(current);
		}

		bool staysEligibleForCurrent(std::string & current)
		{
			return AbstractTerminal::staysEligibleForCurrent(current);
		}

		virtual int traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const = 0;

};

#endif
