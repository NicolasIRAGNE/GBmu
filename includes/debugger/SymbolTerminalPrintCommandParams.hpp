/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalPrintCommandParams.hpp               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 17:37:35 by ldedier           #+#    #+#             */
/*   Updated: 2020/05/14 20:13:34 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMBOLTERMINALPRINTCOMMANDPARAMS_HPP
# define SYMBOLTERMINALPRINTCOMMANDPARAMS_HPP

# include "AbstractTerminal.hpp"
# include "TokenPrintCommandSuffix.hpp"
# include "DebuggerContext.hpp"

class SymbolTerminalPrintCommandParams : public AbstractTerminal<int, DebuggerContext &>
{
	public:
		SymbolTerminalPrintCommandParams(void);
		~SymbolTerminalPrintCommandParams(void);
		virtual int traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const;
		virtual	bool isEligibleForCurrent(std::string & current);
		virtual bool staysEligibleForCurrent(std::string & current);
		virtual bool canBeAdded(std::deque<Token<int, DebuggerContext &> *>	& res);
		virtual Token<int, DebuggerContext &> *createToken(std::string tokenContent);
	private:

};

#endif
