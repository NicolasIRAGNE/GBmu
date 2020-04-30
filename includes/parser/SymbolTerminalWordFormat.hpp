/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalWordFormat.hpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 14:28:05 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/30 14:28:05 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMBOLTERMINALWORDFORMAT_HPP
# define SYMBOLTERMINALWORDFORMAT_HPP

# include "AbstractTerminal.hpp"
# include "DebuggerContext.hpp"

class SymbolTerminalWordFormat : public AbstractTerminal<int, DebuggerContext &>
{
	public:
		SymbolTerminalWordFormat(void);
		~SymbolTerminalWordFormat(void);
		virtual int traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const;

	private:

};

#endif
