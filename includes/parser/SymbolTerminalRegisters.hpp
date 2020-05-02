/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalRegisters.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:38:32 by ldedier           #+#    #+#             */
/*   Updated: 2020/05/02 17:07:29 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMBOLTERMINALREGISTERS_HPP
# define SYMBOLTERMINALREGISTERS_HPP

# include "SymbolTerminalCommand.hpp"
# include "DebuggerContext.hpp"

class SymbolTerminalRegisters : public SymbolTerminalCommand
{
	public:
		SymbolTerminalRegisters(void);
		~SymbolTerminalRegisters(void);
		virtual int traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const;

	private:

};

#endif
