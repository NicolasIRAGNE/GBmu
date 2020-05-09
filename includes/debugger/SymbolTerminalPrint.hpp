/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalPrint.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:38:32 by ldedier           #+#    #+#             */
/*   Updated: 2020/05/03 13:11:45 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMBOLTERMINALPRINT_HPP
# define SYMBOLTERMINALPRINT_HPP

# include "SymbolTerminalPrintingCommand.hpp"
# include "DebuggerContext.hpp"

class SymbolTerminalPrint : public SymbolTerminalPrintingCommand
{
	public:
		SymbolTerminalPrint(void);
		~SymbolTerminalPrint(void);
		virtual int traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const;

	private:

};

#endif
