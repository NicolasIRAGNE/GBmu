/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalHelpCommand.hpp                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:38:32 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/26 20:04:03 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMBOLNONTERMINALHELPCOMMAND_HPP
# define SYMBOLNONTERMINALHELPCOMMAND_HPP

# include "DebuggerGrammar.hpp"
# include "SymbolNonTerminalAbstractCommand.hpp"

class SymbolNonTerminalHelpCommand : public SymbolNonTerminalAbstractCommand
{
	public:
		SymbolNonTerminalHelpCommand(void);
		~SymbolNonTerminalHelpCommand(void);
		virtual void computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg);

	private:

};

#endif
