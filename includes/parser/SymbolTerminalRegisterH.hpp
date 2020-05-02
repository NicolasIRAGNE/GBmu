/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalRegisterH.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:38:32 by ldedier           #+#    #+#             */
/*   Updated: 2020/05/02 16:56:10 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMBOLTERMINALREGISTERH_HPP
# define SYMBOLTERMINALREGISTERH_HPP

# include "SymbolTerminalVariable.hpp"
# include "DebuggerContext.hpp"

class SymbolTerminalRegisterH : public SymbolTerminalVariable
{
	public:
		SymbolTerminalRegisterH(void);
		~SymbolTerminalRegisterH(void);
		virtual int traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const;

	private:

};

#endif
