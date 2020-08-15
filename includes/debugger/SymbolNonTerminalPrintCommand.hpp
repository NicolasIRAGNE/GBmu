/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalPrintCommand.hpp                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:38:32 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/27 16:18:25 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMBOLNONTERMINALPRINTCOMMAND_HPP
# define SYMBOLNONTERMINALPRINTCOMMAND_HPP

# include "DebuggerGrammar.hpp"
# include "SymbolNonTerminalAbstractCommand.hpp"

class SymbolNonTerminalPrintCommand : public SymbolNonTerminalAbstractCommand
{
	public:
		SymbolNonTerminalPrintCommand(void);
		~SymbolNonTerminalPrintCommand(void);
		virtual void computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg);

	private:

};

#endif
