/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalRightShift.hpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 19:16:33 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/24 19:16:33 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMBOLTERMINALRIGHTSHIFT_HPP
# define SYMBOLTERMINALRIGHTSHIFT_HPP

# include "AbstractTerminal.hpp"
# include "DebuggerContext.hpp"

class SymbolTerminalRightShift : public AbstractTerminal<int, DebuggerContext &>
{
	public:
		SymbolTerminalRightShift(void);
		~SymbolTerminalRightShift(void);
		virtual int traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const;

	private:

};

#endif