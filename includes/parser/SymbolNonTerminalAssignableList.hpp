/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalAssignableList.hpp                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 15:36:20 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/30 15:36:20 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMBOLNONTERMINALASSIGNABLELIST_HPP
# define SYMBOLNONTERMINALASSIGNABLELIST_HPP

# include "DebuggerGrammar.hpp"

class SymbolNonTerminalAssignableList : public AbstractNonTerminal<int, DebuggerContext &>
{
	public:
		SymbolNonTerminalAssignableList(void);
		~SymbolNonTerminalAssignableList(void);
		virtual int traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const;
		virtual void computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg);

	private:

};

#endif
