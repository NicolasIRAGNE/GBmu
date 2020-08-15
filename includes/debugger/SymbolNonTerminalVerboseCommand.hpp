/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalVerboseCommand.hpp                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:38:32 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/27 16:17:21 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMBOLNONTERMINALVERBOSECOMMAND_HPP
# define SYMBOLNONTERMINALVERBOSECOMMAND_HPP

# include "SymbolNonTerminalAbstractCommand.hpp"

class SymbolNonTerminalVerboseCommand : public SymbolNonTerminalAbstractCommand
{
	public:
		SymbolNonTerminalVerboseCommand(void);
		~SymbolNonTerminalVerboseCommand(void);
		virtual void computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg);

	private:

};

#endif
