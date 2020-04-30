/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalAssignGDB.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 14:33:53 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/30 14:33:53 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMBOLTERMINALASSIGNGDB_HPP
# define SYMBOLTERMINALASSIGNGDB_HPP

# include "AbstractTerminal.hpp"
# include "DebuggerContext.hpp"

class SymbolTerminalAssignGDB : public AbstractTerminal<int, DebuggerContext &>
{
	public:
		SymbolTerminalAssignGDB(void);
		~SymbolTerminalAssignGDB(void);
		virtual int traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const;

	private:

};

#endif
