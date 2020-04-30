/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalRegisterAF.hpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 14:52:38 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/30 14:52:38 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMBOLTERMINALREGISTERAF_HPP
# define SYMBOLTERMINALREGISTERAF_HPP

# include "AbstractTerminal.hpp"
# include "DebuggerContext.hpp"

class SymbolTerminalRegisterAF : public AbstractTerminal<int, DebuggerContext &>
{
	public:
		SymbolTerminalRegisterAF(void);
		~SymbolTerminalRegisterAF(void);
		virtual int traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const;

	private:

};

#endif
