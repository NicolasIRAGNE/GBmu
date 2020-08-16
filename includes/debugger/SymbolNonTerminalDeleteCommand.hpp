/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalDeleteCommand.hpp                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 15:59:19 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/27 03:36:24 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMBOLNONTERMINALDELETECOMMAND_HPP
# define SYMBOLNONTERMINALDELETECOMMAND_HPP

# include "DebuggerGrammar.hpp"
# include "SymbolNonTerminalAbstractCommand.hpp"

class SymbolNonTerminalDeleteCommand : public SymbolNonTerminalAbstractCommand
{
	public:
		SymbolNonTerminalDeleteCommand(void);
		~SymbolNonTerminalDeleteCommand(void);
		virtual void computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg);
		

	private:

};

#endif
