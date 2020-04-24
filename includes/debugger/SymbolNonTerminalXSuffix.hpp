/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalXSuffix.hpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 14:56:29 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/18 14:56:29 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMBOLNONTERMINALXSUFFIX_HPP
# define SYMBOLNONTERMINALXSUFFIX_HPP

# include "DebuggerGrammar.hpp"

class SymbolNonTerminalXSuffix : public AbstractNonTerminal<int, CustomStack &>
{
	public:
		SymbolNonTerminalXSuffix(void);
		~SymbolNonTerminalXSuffix(void);
		virtual int traverse(ASTNode<int, CustomStack &> & ast, CustomStack & context) const;
		virtual void computeProductions(AbstractGrammar<int, CustomStack &> & cfg);

	private:

};

#endif