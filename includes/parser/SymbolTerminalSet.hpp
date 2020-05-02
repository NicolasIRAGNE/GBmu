/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalSet.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:38:32 by ldedier           #+#    #+#             */
/*   Updated: 2020/05/02 17:12:10 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMBOLTERMINALSET_HPP
# define SYMBOLTERMINALSET_HPP

# include "SymbolTerminalCommand.hpp"
# include "DebuggerContext.hpp"

class SymbolTerminalSet : public SymbolTerminalCommand
{
	public:
		SymbolTerminalSet(void);
		~SymbolTerminalSet(void);
		virtual int traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const;

	private:

};

#endif
