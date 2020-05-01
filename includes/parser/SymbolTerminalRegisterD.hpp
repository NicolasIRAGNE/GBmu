/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalRegisterD.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:38:32 by ldedier           #+#    #+#             */
/*   Updated: 2020/05/01 18:48:42 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMBOLTERMINALREGISTERD_HPP
# define SYMBOLTERMINALREGISTERD_HPP

# include "AbstractTerminal.hpp"
# include "DebuggerContext.hpp"

class SymbolTerminalRegisterD : public AbstractTerminal<int, DebuggerContext &>
{
	public:
		SymbolTerminalRegisterD(void);
		~SymbolTerminalRegisterD(void);
		virtual int traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const;

	private:

};

#endif
