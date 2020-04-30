/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalC.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 14:28:05 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/30 14:28:05 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMBOLTERMINALC_HPP
# define SYMBOLTERMINALC_HPP

# include "DebuggerGrammar.hpp"

class SymbolTerminalC : public AbstractNonTerminal<int, DebuggerContext &>
{
	public:
		SymbolTerminalC(void);
		~SymbolTerminalC(void);
		virtual int traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const;
		virtual void computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg);

	private:

};

#endif
