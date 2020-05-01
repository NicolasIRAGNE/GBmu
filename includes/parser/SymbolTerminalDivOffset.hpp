/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalDivOffset.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:38:32 by ldedier            #+#    #+#            */
/*   Updated: 2020/05/01 16:38:32 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMBOLTERMINALDIVOFFSET_HPP
# define SYMBOLTERMINALDIVOFFSET_HPP

# include "AbstractTerminal.hpp"
# include "DebuggerContext.hpp"

class SymbolTerminalDivOffset : public AbstractTerminal<int, DebuggerContext &>
{
	public:
		SymbolTerminalDivOffset(void);
		~SymbolTerminalDivOffset(void);
		virtual int traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const;

	private:

};

#endif