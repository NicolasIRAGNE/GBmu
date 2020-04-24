/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalInteger.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 16:30:57 by ldedier           #+#    #+#             */
/*   Updated: 2020/04/30 19:51:53 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMBOLTERMINALINTEGER_HPP
# define SYMBOLTERMINALINTEGER_HPP

# include "AbstractUnsignedIntegerTerminal.hpp"
# include "DebuggerContext.hpp"

class SymbolTerminalInteger : public AbstractTerminal<int, DebuggerContext &>
{
	public:
		SymbolTerminalInteger(void);
		~SymbolTerminalInteger(void);
		virtual int traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const;
		virtual bool isEligibleForCurrent(std::string & current);
		virtual bool staysEligibleForCurrent(std::string & current);
		virtual Token<int, DebuggerContext &> *createToken(std::string tokenContent);
	private:

};

#endif
