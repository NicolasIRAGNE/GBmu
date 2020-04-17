/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalInteger.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 03:08:44 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/17 03:08:44 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMBOLTERMINALINTEGER_HPP
# define SYMBOLTERMINALINTEGER_HPP

# include "AbstractUnsignedIntegerTerminal.hpp"
# include "CustomStack.hpp"

class SymbolTerminalInteger : public AbstractUnsignedIntegerTerminal<int, CustomStack &>
{
	public:
		SymbolTerminalInteger(void);
		~SymbolTerminalInteger(void);
		virtual int traverse(ASTNode<int, CustomStack &> & ast, CustomStack & context) const;

	private:

};

#endif
