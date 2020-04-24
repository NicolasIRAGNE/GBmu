/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalVariable.hpp                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 19:03:18 by ldedier           #+#    #+#             */
/*   Updated: 2020/04/30 20:02:01 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMBOLTERMINALVARIABLE_HPP
# define SYMBOLTERMINALVARIABLE_HPP

# include "AbstractTerminal.hpp"
# include "DebuggerContext.hpp"

class SymbolTerminalVariable : public AbstractTerminal<int , DebuggerContext &>
{
	public:
		SymbolTerminalVariable(void) : AbstractTerminal()
		{

		}

		SymbolTerminalVariable(std::string identifier) : AbstractTerminal(identifier)
		{

		}

		~SymbolTerminalVariable(void)
		{

		}

		bool isEligibleForCurrent(std::string & current)
		{
			return ("$" + this->_identifier).compare(current) == 0;
		}

		bool staysEligibleForCurrent(std::string & current)
		{
			return ("$" + this->_identifier).compare(0, current.size(), current) == 0;
		}

		Token<int, DebuggerContext &> *createToken(std::string tokenContent)
		{
			static_cast<void>(tokenContent);
			return new Token<int, DebuggerContext &>(*this, tokenContent.substr(1));
		}

		virtual int traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const = 0;

};

#endif
