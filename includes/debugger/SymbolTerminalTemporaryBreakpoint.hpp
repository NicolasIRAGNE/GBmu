/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalTemporaryBreakpoint.hpp              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 16:09:29 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/26 16:25:46 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMBOLTERMINALTEMPORARYBREAKPOINT_HPP
# define SYMBOLTERMINALTEMPORARYBREAKPOINT_HPP

# include "DebuggerContext.hpp"
# include "SymbolTerminalCommand.hpp"

class SymbolTerminalTemporaryBreakpoint : public SymbolTerminalCommand
{
	public:
		SymbolTerminalTemporaryBreakpoint(void);
		~SymbolTerminalTemporaryBreakpoint(void);
		virtual int traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const;

	private:

};

#endif
