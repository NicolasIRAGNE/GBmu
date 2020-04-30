/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalWatchModeList.hpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 14:32:07 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/30 14:32:07 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMBOLTERMINALWATCHMODELIST_HPP
# define SYMBOLTERMINALWATCHMODELIST_HPP

# include "DebuggerGrammar.hpp"

class SymbolTerminalWatchModeList : public AbstractNonTerminal<int, DebuggerContext &>
{
	public:
		SymbolTerminalWatchModeList(void);
		~SymbolTerminalWatchModeList(void);
		virtual int traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const;
		virtual void computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg);

	private:

};

#endif
