/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalBinary.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 20:06:16 by ldedier           #+#    #+#             */
/*   Updated: 2020/05/02 20:09:46 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMBOLTERMINALBINARY_HPP
# define SYMBOLTERMINALBINARY_HPP

# include "AbstractTerminal.hpp"
# include "DebuggerContext.hpp"

class SymbolTerminalBinary : public AbstractTerminal<int, DebuggerContext &>
{
	public:
		SymbolTerminalBinary(void);
		~SymbolTerminalBinary(void);
		virtual int traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const;
		virtual std::string getLexerString(void);

	private:

};

#endif
