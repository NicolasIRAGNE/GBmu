/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalExpansion.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 14:58:56 by ldedier           #+#    #+#             */
/*   Updated: 2020/05/03 15:22:51 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMBOLTERMINALEXPANSION_HPP
# define SYMBOLTERMINALEXPANSION_HPP

# include "AbstractTerminal.hpp"
# include "DebuggerContext.hpp"

class SymbolTerminalExpansion : public AbstractTerminal<int, DebuggerContext &>
{
	public:
		SymbolTerminalExpansion(void);
		~SymbolTerminalExpansion(void);
		virtual int traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const;
		virtual bool isEligibleForCurrent(std::string & current);
		virtual bool staysEligibleForCurrent(std::string & current);
		virtual Token<int, DebuggerContext &> *createToken(std::string tokenContent);
	private:

};

#endif
