/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalXCommand.hpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:38:32 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/26 20:11:50 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMBOLNONTERMINALXCOMMAND_HPP
# define SYMBOLNONTERMINALXCOMMAND_HPP

# include "DebuggerGrammar.hpp"

class SymbolNonTerminalXCommand : public SymbolNonTerminalAbstractCommand
{
	public:
		SymbolNonTerminalXCommand(void);
		~SymbolNonTerminalXCommand(void);
		virtual void computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg);

	private:

};

#endif
