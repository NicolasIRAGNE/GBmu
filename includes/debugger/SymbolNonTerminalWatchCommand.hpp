/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalWatchCommand.hpp                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:38:32 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/27 16:06:38 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMBOLNONTERMINALWATCHCOMMAND_HPP
# define SYMBOLNONTERMINALWATCHCOMMAND_HPP

# include "SymbolNonTerminalAbstractCommand.hpp"

class SymbolNonTerminalWatchCommand : public SymbolNonTerminalAbstractCommand
{
	public:
		SymbolNonTerminalWatchCommand(void);
		~SymbolNonTerminalWatchCommand(void);
		virtual void computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg);
	private:

};

#endif
