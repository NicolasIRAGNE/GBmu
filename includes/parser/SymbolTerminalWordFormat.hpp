/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalWordFormat.hpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 19:29:44 by ldedier           #+#    #+#             */
/*   Updated: 2020/05/02 19:55:33 by ldedier          ###   ########.fr       */
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
		virtual std::string getLexerString(void);

	private:

};

#endif
