/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalAddress.hpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 15:21:36 by ldedier            #+#    #+#            */
/*   Updated: 2020/06/06 15:21:36 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMBOLNONTERMINALADDRESS_HPP
# define SYMBOLNONTERMINALADDRESS_HPP

# include "DebuggerGrammar.hpp"

class SymbolNonTerminalAddress : public AbstractNonTerminal<int, DebuggerContext &>
{
	public:
		SymbolNonTerminalAddress(void);
		~SymbolNonTerminalAddress(void);
		virtual int traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const;
		virtual void computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg);

	private:

};

#endif
