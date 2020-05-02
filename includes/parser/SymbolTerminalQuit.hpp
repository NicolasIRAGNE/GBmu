/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalQuit.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:38:32 by ldedier           #+#    #+#             */
/*   Updated: 2020/05/02 16:54:14 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMBOLTERMINALQUIT_HPP
# define SYMBOLTERMINALQUIT_HPP

# include "SymbolTerminalCommand.hpp"
# include "DebuggerContext.hpp"

class SymbolTerminalQuit : public SymbolTerminalCommand
{
	public:
		SymbolTerminalQuit(void);
		~SymbolTerminalQuit(void);
		virtual int traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const;

	private:

};

#endif
