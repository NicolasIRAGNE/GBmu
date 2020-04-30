/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalTodoOffset.hpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 14:52:38 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/30 14:52:38 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMBOLTERMINALTODOOFFSET_HPP
# define SYMBOLTERMINALTODOOFFSET_HPP

# include "AbstractTerminal.hpp"
# include "DebuggerContext.hpp"

class SymbolTerminalTodoOffset : public AbstractTerminal<int, DebuggerContext &>
{
	public:
		SymbolTerminalTodoOffset(void);
		~SymbolTerminalTodoOffset(void);
		virtual int traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const;

	private:

};

#endif
