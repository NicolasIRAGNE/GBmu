/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalRunCommand.hpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 19:55:17 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/26 20:03:15 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMBOLNONTERMINALRUNCOMMAND_HPP
# define SYMBOLNONTERMINALRUNCOMMAND_HPP

# include "DebuggerGrammar.hpp"
# include "SymbolNonTerminalAbstractCommand.hpp"

class SymbolNonTerminalRunCommand : public SymbolNonTerminalAbstractCommand
{
	public:
		SymbolNonTerminalRunCommand(void);
		~SymbolNonTerminalRunCommand(void);
		virtual void computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg);

	private:

};

#endif
