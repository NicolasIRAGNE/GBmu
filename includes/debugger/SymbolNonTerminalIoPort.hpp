/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalIoPort.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:38:32 by ldedier            #+#    #+#            */
/*   Updated: 2020/05/01 16:38:32 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMBOLNONTERMINALIOPORT_HPP
# define SYMBOLNONTERMINALIOPORT_HPP

# include "DebuggerGrammar.hpp"

class SymbolNonTerminalIoPort : public AbstractNonTerminal<int, DebuggerContext &>
{
	public:
		SymbolNonTerminalIoPort(void);
		~SymbolNonTerminalIoPort(void);
		virtual int traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const;
		virtual void computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg);

	private:

};

#endif
