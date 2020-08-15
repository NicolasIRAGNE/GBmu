/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalAbstractCommand.hpp               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 19:55:08 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/27 16:26:05 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMBOLNONTERMINALABSTRACTCOMMAND_HPP
# define SYMBOLNONTERMINALABSTRACTCOMMAND_HPP

# include <iostream>
# include "AbstractNonTerminal.hpp"
# include "ASTNode.hpp"
# include "AbstractGrammar.hpp"
# include "DebuggerContext.hpp"

class SymbolNonTerminalAbstractCommand : public AbstractNonTerminal<int, DebuggerContext &>
{
	public:
		SymbolNonTerminalAbstractCommand(std::string identifier);
		SymbolNonTerminalAbstractCommand(SymbolNonTerminalAbstractCommand const &instance);
		SymbolNonTerminalAbstractCommand &operator=(SymbolNonTerminalAbstractCommand const &rhs);
		~SymbolNonTerminalAbstractCommand(void);

		virtual int traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const;
		virtual void computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg) = 0;

	private:
		SymbolNonTerminalAbstractCommand(void);

};

std::ostream &operator<<(std::ostream &o, SymbolNonTerminalAbstractCommand const &instance);
#endif