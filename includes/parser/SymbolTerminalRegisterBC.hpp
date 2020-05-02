/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalRegisterBC.hpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:38:32 by ldedier           #+#    #+#             */
/*   Updated: 2020/05/02 16:55:36 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMBOLTERMINALREGISTERBC_HPP
# define SYMBOLTERMINALREGISTERBC_HPP

# include "SymbolTerminalVariable.hpp"
# include "DebuggerContext.hpp"

class SymbolTerminalRegisterBC : public SymbolTerminalVariable
{
	public:
		SymbolTerminalRegisterBC(void);
		~SymbolTerminalRegisterBC(void);
		virtual int traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const;

	private:

};

#endif
