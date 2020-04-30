/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalAssignable.hpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 14:52:38 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/30 14:52:38 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMBOLNONTERMINALASSIGNABLE_HPP
# define SYMBOLNONTERMINALASSIGNABLE_HPP

# include "DebuggerGrammar.hpp"

class SymbolNonTerminalAssignable : public AbstractNonTerminal<int, DebuggerContext &>
{
	public:
		SymbolNonTerminalAssignable(void);
		~SymbolNonTerminalAssignable(void);
		virtual int traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const;
		virtual void computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg);

	private:

};

#endif
