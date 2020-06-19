/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalCommand.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 21:15:29 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/19 19:05:30 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMBOLTERMINALCOMMAND_HPP
# define SYMBOLTERMINALCOMMAND_HPP

# include "AbstractTerminal.hpp"
# include "DebuggerContext.hpp"
# include "AbstractCommand.hpp"

class SymbolTerminalCommand : public AbstractTerminal<int, DebuggerContext &>
{
	public:
		SymbolTerminalCommand(void);
		SymbolTerminalCommand(std::string identifier);
		virtual ~SymbolTerminalCommand(void);
		virtual bool isEligibleForCurrent(std::string & current);
		virtual bool staysEligibleForCurrent(std::string & current);

};


#endif
