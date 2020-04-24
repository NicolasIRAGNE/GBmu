/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalVariable.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 14:56:29 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/18 14:56:29 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMBOLTERMINALVARIABLE_HPP
# define SYMBOLTERMINALVARIABLE_HPP

# include "AbstractStringTerminal.hpp"
# include "CustomStack.hpp"

class SymbolTerminalVariable : public AbstractStringTerminal<int, CustomStack &>
{
	public:
		SymbolTerminalVariable(void);
		~SymbolTerminalVariable(void);
		virtual int traverse(ASTNode<int, CustomStack &> & ast, CustomStack & context) const;

	private:

};

#endif
