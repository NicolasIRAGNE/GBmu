/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalStepCommand.hpp                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:38:32 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/26 20:02:53 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMBOLNONTERMINALSTEPCOMMAND_HPP
# define SYMBOLNONTERMINALSTEPCOMMAND_HPP

# include "DebuggerGrammar.hpp"
# include "SymbolNonTerminalAbstractCommand.hpp"

class SymbolNonTerminalStepCommand : public SymbolNonTerminalAbstractCommand
{
	public:
		SymbolNonTerminalStepCommand(void);
		~SymbolNonTerminalStepCommand(void);
		virtual void computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg);

	private:

};

#endif
