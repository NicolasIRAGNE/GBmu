/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalVBLANK.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 14:31:18 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/30 14:31:18 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMBOLTERMINALVBLANK_HPP
# define SYMBOLTERMINALVBLANK_HPP

# include "DebuggerGrammar.hpp"

class SymbolTerminalVBLANK : public AbstractNonTerminal<int, DebuggerContext &>
{
	public:
		SymbolTerminalVBLANK(void);
		~SymbolTerminalVBLANK(void);
		virtual int traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const;
		virtual void computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg);

	private:

};

#endif
