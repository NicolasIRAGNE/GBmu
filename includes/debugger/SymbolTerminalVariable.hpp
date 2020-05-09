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
		SymbolTerminalVariable(void);
		SymbolTerminalVariable(std::string identifier);
		~SymbolTerminalVariable(void);

		virtual	bool isEligibleForCurrent(std::string & current);
		virtual bool staysEligibleForCurrent(std::string & current);
		virtual Token<int, DebuggerContext &> *createToken(std::string tokenContent);
};

#endif
