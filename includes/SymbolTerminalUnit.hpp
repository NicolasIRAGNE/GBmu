/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalUnit.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 20:53:16 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/16 20:53:16 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMBOLTERMINALUNIT_HPP
# define SYMBOLTERMINALUNIT_HPP

# include "DebuggerGrammar.hpp"

class SymbolTerminalUnit : public AbstractNonTerminal<int, CustomStack &>
{
	public:
		SymbolTerminalUnit(void);
		~SymbolTerminalUnit(void);
		virtual int traverse(ASTNode<int, CustomStack &> & ast, CustomStack & context) const;
		virtual void computeProductions(AbstractGrammar<int, CustomStack &> & cfg);

	private:

};

#endif
