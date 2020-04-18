/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalInteger.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 14:56:29 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/18 14:56:29 by ldedier           ###   ########.fr      */
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
