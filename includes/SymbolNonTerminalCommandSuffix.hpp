/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalCommandSuffix.hpp                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 03:08:44 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/17 03:08:44 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMBOLNONTERMINALCOMMANDSUFFIX_HPP
# define SYMBOLNONTERMINALCOMMANDSUFFIX_HPP

# include "DebuggerGrammar.hpp"

class SymbolNonTerminalCommandSuffix : public AbstractNonTerminal<int, CustomStack &>
{
	public:
		SymbolNonTerminalCommandSuffix(void);
		~SymbolNonTerminalCommandSuffix(void);
		virtual int traverse(ASTNode<int, CustomStack &> & ast, CustomStack & context) const;
		virtual void computeProductions(AbstractGrammar<int, CustomStack &> & cfg);

	private:

};

#endif
