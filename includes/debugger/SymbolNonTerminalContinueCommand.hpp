/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalContinueCommand.hpp               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 19:55:17 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/26 20:04:16 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMBOLNONTERMINALCONTINUECOMMAND_HPP
# define SYMBOLNONTERMINALCONTINUECOMMAND_HPP

# include "DebuggerGrammar.hpp"
# include "SymbolNonTerminalAbstractCommand.hpp"

class SymbolNonTerminalContinueCommand : public SymbolNonTerminalAbstractCommand
{
	public:
		SymbolNonTerminalContinueCommand(void);
		~SymbolNonTerminalContinueCommand(void);
		virtual void computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg);

	private:

};

#endif
