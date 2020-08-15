/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalTemporaryBreakpointCommand        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 16:09:29 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/26 20:02:44 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMBOLNONTERMINALTEMPORARYBREAKPOINTCOMMAND_HPP
# define SYMBOLNONTERMINALTEMPORARYBREAKPOINTCOMMAND_HPP

# include "DebuggerGrammar.hpp"
# include "SymbolNonTerminalAbstractCommand.hpp"

class SymbolNonTerminalTemporaryBreakpointCommand : public SymbolNonTerminalAbstractCommand
{
	public:
		SymbolNonTerminalTemporaryBreakpointCommand(void);
		~SymbolNonTerminalTemporaryBreakpointCommand(void);
		virtual void computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg);

	private:

};

#endif
