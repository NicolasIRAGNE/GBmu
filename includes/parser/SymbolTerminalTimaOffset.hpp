/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalTimaOffset.hpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:38:32 by ldedier           #+#    #+#             */
/*   Updated: 2020/05/02 17:15:36 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMBOLTERMINALTIMAOFFSET_HPP
# define SYMBOLTERMINALTIMAOFFSET_HPP

# include "SymbolTerminalVariable.hpp"
# include "DebuggerContext.hpp"

class SymbolTerminalTimaOffset : public SymbolTerminalVariable
{
	public:
		SymbolTerminalTimaOffset(void);
		~SymbolTerminalTimaOffset(void);
		virtual int traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const;

	private:

};

#endif
