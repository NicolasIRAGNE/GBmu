/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalWatchModes.hpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 15:59:19 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/15 17:25:47 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMBOLTERMINALWATCHMODES_HPP
# define SYMBOLTERMINALWATCHMODES_HPP

# include "AbstractTerminal.hpp"
# include "DebuggerContext.hpp"

class SymbolTerminalWatchModes : public AbstractTerminal<int, DebuggerContext &>
{
	public:
		SymbolTerminalWatchModes(void);
		~SymbolTerminalWatchModes(void);
		virtual int traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const;
		virtual	bool isEligibleForCurrent(std::string & current);
		virtual bool staysEligibleForCurrent(std::string & current);
		virtual Token<int, DebuggerContext &> *createToken(std::string tokenContent);

	private:

		bool	innerIsEligibleForCurrent(const std::string & current);

};

#endif
