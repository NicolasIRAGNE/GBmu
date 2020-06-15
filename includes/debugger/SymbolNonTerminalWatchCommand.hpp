/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalWatchCommand.hpp                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:38:32 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/15 19:53:06 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMBOLNONTERMINALWATCHCOMMAND_HPP
# define SYMBOLNONTERMINALWATCHCOMMAND_HPP

# include "DebuggerGrammar.hpp"

class SymbolNonTerminalWatchCommand : public AbstractNonTerminal<int, DebuggerContext &>
{
	public:
		SymbolNonTerminalWatchCommand(void);
		~SymbolNonTerminalWatchCommand(void);
		virtual int traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const;
		virtual void computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg);
		
		static void addWatchPoint(Debugger *debugger, const std::string & mode
			, WatchPoint &watchPoint, Debugger::e_watchpoint_mode_id id);
	private:

};

#endif
