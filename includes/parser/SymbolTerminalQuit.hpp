/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalQuit.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 14:52:38 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/30 14:52:38 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMBOLTERMINALQUIT_HPP
# define SYMBOLTERMINALQUIT_HPP

# include "AbstractTerminal.hpp"
# include "DebuggerContext.hpp"

class SymbolTerminalQuit : public AbstractTerminal<int, DebuggerContext &>
{
	public:
		SymbolTerminalQuit(void);
		~SymbolTerminalQuit(void);
		virtual int traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const;

	private:

};

#endif
