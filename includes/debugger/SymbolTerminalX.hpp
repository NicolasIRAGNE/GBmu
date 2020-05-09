/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalX.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 19:29:44 by ldedier           #+#    #+#             */
/*   Updated: 2020/05/03 13:11:39 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMBOLTERMINALX_HPP
# define SYMBOLTERMINALX_HPP

# include "SymbolTerminalPrintingCommand.hpp"
# include "DebuggerContext.hpp"

class SymbolTerminalX : public SymbolTerminalPrintingCommand
{
	public:
		SymbolTerminalX(void);
		~SymbolTerminalX(void);
		virtual int traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const;

	private:

};

#endif
