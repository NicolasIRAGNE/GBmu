/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalRegisterE.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:38:32 by ldedier           #+#    #+#             */
/*   Updated: 2020/05/02 17:14:10 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMBOLTERMINALREGISTERE_HPP
# define SYMBOLTERMINALREGISTERE_HPP

# include "SymbolTerminalVariable.hpp"
# include "DebuggerContext.hpp"

class SymbolTerminalRegisterE : public SymbolTerminalVariable
{
	public:
		SymbolTerminalRegisterE(void);
		~SymbolTerminalRegisterE(void);
		virtual int traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const;

	private:

};

#endif
