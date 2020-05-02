/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalRegisterL.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:38:32 by ldedier           #+#    #+#             */
/*   Updated: 2020/05/02 16:56:25 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMBOLTERMINALREGISTERL_HPP
# define SYMBOLTERMINALREGISTERL_HPP

# include "SymbolTerminalVariable.hpp"
# include "DebuggerContext.hpp"

class SymbolTerminalRegisterL : public SymbolTerminalVariable
{
	public:
		SymbolTerminalRegisterL(void);
		~SymbolTerminalRegisterL(void);
		virtual int traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const;

	private:

};

#endif
