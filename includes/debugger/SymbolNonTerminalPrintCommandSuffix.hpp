/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalPrintCommandSuffix.hpp            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 17:37:35 by ldedier            #+#    #+#            */
/*   Updated: 2020/05/03 17:37:35 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMBOLNONTERMINALPRINTCOMMANDSUFFIX_HPP
# define SYMBOLNONTERMINALPRINTCOMMANDSUFFIX_HPP

# include "DebuggerGrammar.hpp"

class SymbolNonTerminalPrintCommandSuffix : public AbstractNonTerminal<int, DebuggerContext &>
{
	public:
		SymbolNonTerminalPrintCommandSuffix(void);
		~SymbolNonTerminalPrintCommandSuffix(void);
		virtual int traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const;
		virtual void computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg);

	private:

};

#endif
