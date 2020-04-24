/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalInnerFactor.hpp                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 18:56:50 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/24 18:56:50 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMBOLNONTERMINALINNERFACTOR_HPP
# define SYMBOLNONTERMINALINNERFACTOR_HPP

# include "DebuggerGrammar.hpp"

class SymbolNonTerminalInnerFactor : public AbstractNonTerminal<int, DebuggerContext &>
{
	public:
		SymbolNonTerminalInnerFactor(void);
		~SymbolNonTerminalInnerFactor(void);
		virtual int traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const;
		virtual void computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg);

	private:

};

#endif
